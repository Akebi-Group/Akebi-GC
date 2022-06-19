#include "pch-il2cpp.h"
#include "AutoTreeFarm.h"

#include <helpers.h>
#include <algorithm>

#include <cheat/events.h>
#include <cheat/game/util.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature
{
	AutoTreeFarm::AutoTreeFarm() : Feature(),
		NF(m_Enabled, "Auto tree farm", "AutoTreeFarm", false),
		NF(m_AttackDelay, "Attack delay", "AutoTreeFarm", 150),
		NF(m_RepeatDelay, "Repeat delay", "AutoTreeFarm", 500),
		NF(m_AttackPerTree, "Attack per tree", "AutoTreeFarm", 5),
		NF(m_Range, "Range", "AutoTreeFarm", 15.0f)
	{
		events::GameUpdateEvent += MY_METHOD_HANDLER(AutoTreeFarm::OnGameUpdate);
	}

	const FeatureGUIInfo& AutoTreeFarm::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Auto Tree Farm", "World", true };
		return info;
	}

	void AutoTreeFarm::DrawMain()
	{
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Note. This feature is not fully tested detection-wise.\n"
			"Not recommended for main accounts or used with high values.");

		ConfigWidget("Enabled", m_Enabled, "Automatically attack trees in range.");
		ConfigWidget("Attack Delay (ms)", m_AttackDelay, 1, 0, 1000, "Delay before attacking the next tree (in ms).");
		ConfigWidget("Repeat Delay (ms)", m_RepeatDelay, 1, 500, 1000, "Delay before attacking the same tree (in ms).\nValues <500ms will not work.");

		ConfigWidget("Attacks per Tree", m_AttackPerTree, 1, 0, 100, "Count of attacks for one tree.\n" \
			"Recommended to set to 10 or lower to avoid attacking empty trees.\n" \
			"Set to 0 for unlimited attacks (even empty trees, extremely high risk).\n" \
			"Note: Memorized trees' attacks are reset after game restart."
		);

		ConfigWidget("Range (m)", m_Range, 0.1f, 1.0f, 15.0f);
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Range is softly limited to ~15m for safety purposes.");
	}

	bool AutoTreeFarm::NeedStatusDraw() const
	{
		return m_Enabled;
	}

	void AutoTreeFarm::DrawStatus()
	{
		ImGui::Text("Tree Farm\n[%dms|%dms|%d|%.1fm]",
			m_AttackDelay.value(),
			m_RepeatDelay.value(),
			m_AttackPerTree.value(),
			m_Range.value());
	}

	AutoTreeFarm& AutoTreeFarm::GetInstance()
	{
		static AutoTreeFarm instance;
		return instance;
	}


	std::unordered_set<app::SceneTreeObject*> GetTreeSet()
	{
		auto scenePropManager = GET_SINGLETON(MoleMole_ScenePropManager);
		if (scenePropManager == nullptr)
			return {};

		auto scenePropDict = TO_UNI_DICT(scenePropManager->fields._scenePropDict, int32_t, app::Object*);
		if (scenePropDict == nullptr)
			return {};

		std::unordered_set<app::SceneTreeObject*> trees;
		for (auto& [id, propObject] : scenePropDict->pairs())
		{
			auto tree = CastTo<app::SceneTreeObject>(propObject, *app::SceneTreeObject__TypeInfo);
			if (tree == nullptr)
				continue;

			trees.insert(tree);
		}

		return trees;
	}


	struct Vector3d
	{
		float x, y, z;

		Vector3d(const app::Vector3& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
		}

		bool operator==(const Vector3d& b) const
		{
			return x == b.x && y == b.y && z == b.z;
		}

	};

	struct hash_fn
	{
		std::size_t operator() (const Vector3d& vector) const
		{
			return std::hash<float>()(vector.x) ^ std::hash<float>()(vector.y) ^ std::hash<float>()(vector.z);
		}
	};

	template <typename KeyT, typename ValT, uint32_t Size, class /*forward*/ _Hasher = std::hash<KeyT>>
	class lra_map {
		using key_value_pair = std::pair<KeyT, ValT>;
		using list_iterator = typename std::list<key_value_pair>::iterator;

	public:
		void put(const KeyT& key, const ValT& val) {
			auto it = elem_map.find(key);
			// if element already in the map, don't modify it.
			if (it != elem_map.end())
				return;

			items_list.push_front(key_value_pair(key, val));
			elem_map[key] = items_list.begin();

			if (Size < elem_map.size()) {
				{
					const KeyT& last_key = items_list.back().first;
					elem_map.erase(last_key);
				}
				items_list.pop_back();
			}
		}

		ValT& get(const KeyT& key) {
			auto it = elem_map.find(key);
			if (it == elem_map.end())
				throw std::runtime_error("Tried to access key not present in map");
			return it->second->second;
		}

		bool exists(const KeyT& key) const {
			return elem_map.find(key) != elem_map.end();
		}
	protected:
		std::list<key_value_pair> items_list;
		std::unordered_map<KeyT, list_iterator, _Hasher> elem_map;
	};

	void AutoTreeFarm::OnGameUpdate()
	{
		static lra_map<Vector3d, uint32_t, 10, hash_fn> s_AttackCountMap;
		static std::queue<app::SceneTreeObject*> s_AttackQueue;
		static std::unordered_set<app::SceneTreeObject*> s_AttackQueueSet;
		static uint64_t s_LastAttackTimestamp = 0;

		uint64_t timestamp = app::MoleMole_TimeUtil_get_NowTimeStamp(nullptr);
		if (!m_Enabled || s_LastAttackTimestamp + m_AttackDelay > timestamp)
			return;

		auto& manager = game::EntityManager::instance();
		auto scenePropManager = GET_SINGLETON(MoleMole_ScenePropManager);
		auto networkManager = GET_SINGLETON(MoleMole_NetworkManager);
		if (networkManager == nullptr || scenePropManager == nullptr)
			return;

		auto treeSet = GetTreeSet();
		for (auto& tree : treeSet)
		{
			if (s_AttackQueueSet.count(tree) > 0)
				continue;

			if (s_LastAttackTimestamp + m_RepeatDelay > timestamp)
				continue;

			auto position = tree->fields._.realBounds.m_Center;
			if (manager.avatar()->distance(app::WorldShiftManager_GetRelativePosition(position, nullptr)) > m_Range)
				continue;

			s_AttackQueueSet.insert(tree);
			s_AttackQueue.push(tree);
		}

		while (!s_AttackQueue.empty())
		{
			auto tree = s_AttackQueue.front();
			s_AttackQueue.pop();
			s_AttackQueueSet.erase(tree);

			if (treeSet.count(tree) == 0)
				continue;

			auto position = tree->fields._.realBounds.m_Center;
			if (manager.avatar()->distance(app::WorldShiftManager_GetRelativePosition(position, nullptr)) > m_Range)
				continue;

			app::MoleMole_Config_TreeType__Enum treeType;
			auto pattern = tree->fields._config->fields._._.scenePropPatternName;
			if (!app::MoleMole_ScenePropManager_GetTreeTypeByPattern(scenePropManager, pattern, &treeType, nullptr))
				continue;

			if (m_AttackPerTree > 0)
			{
				if (!s_AttackCountMap.exists(position))
					s_AttackCountMap.put(position, 0);

				auto& attackCount = s_AttackCountMap.get(position);
				attackCount++;

				if (attackCount > static_cast<uint32_t>(m_AttackPerTree))
					continue;
			}

			s_LastAttackTimestamp = timestamp;
			app::MoleMole_NetworkManager_RequestHitTreeDropNotify(networkManager, position, position, treeType, nullptr);
			break;
		}
	}
}

