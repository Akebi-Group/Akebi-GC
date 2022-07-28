#include "pch-il2cpp.h"
#include "KillAura.h"

#include <helpers.h>
#include <algorithm>

#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>
#include <cheat/game/filters.h>

namespace cheat::feature 
{
	static void BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo_Hook(app::BaseMoveSyncPlugin* __this, MethodInfo* method);

    KillAura::KillAura() : Feature(),
        NF(f_Enabled,      u8"杀戮光环", "KillAura", false),
		NF(f_DamageMode, u8"伤害模式", "Damage mode", false),
		NF(f_InstantDeathMode, u8"瞬间死亡", "Instant death", false),
        NF(f_OnlyTargeted, u8"单目标", "KillAura", true),
        NF(f_Range, u8"距离", "KillAura", 15.0f),
        NF(f_AttackDelay, u8"攻击周期 (ms)", u8"KillAura", 100),
        NF(f_RepeatDelay, u8"重复周期 (ms)", "KillAura", 1000)
    { 
		events::GameUpdateEvent += MY_METHOD_HANDLER(KillAura::OnGameUpdate);
		HookManager::install(app::MoleMole_BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo, BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo_Hook);
	}

    const FeatureGUIInfo& KillAura::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ u8"杀戮光环", u8"世界", true };
        return info;
    }

    void KillAura::DrawMain()
    {
		ConfigWidget(u8"启用杀戮光环", f_Enabled, u8"启用杀戮光环。 需要选择一种模式才能工作.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"选择以下任何一种或两种模式。");

		ConfigWidget(u8"碰撞损坏模式", f_DamageMode, u8"杀死光环会对你周围的怪物造成碰撞伤害。");
		ConfigWidget(u8"瞬间杀死模式", f_InstantDeathMode, u8"杀戮光环会尝试杀死任何有效目标。");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"对派蒙等Boss无效(不确切翻译)");
		ConfigWidget(u8"杀戮范围", f_Range, 0.1f, 5.0f, 100.0f);
		ConfigWidget(u8"只有敌对/仇恨", f_OnlyTargeted, u8"如果启用，杀戮光环只会杀死瞄准/攻击你的怪物。");
		ConfigWidget(u8"碰撞攻击周期 (ms)", f_AttackDelay, 1, 0, 1000, u8"下一次碰撞损坏前的延迟毫秒数.");
		ConfigWidget(u8"碰撞重复周期 (ms)", f_RepeatDelay, 1, 100, 2000, u8"崩溃损坏同一个怪物之前的延迟毫秒.");
    }

    bool KillAura::NeedStatusDraw() const
	{
        return f_Enabled;
    }

    void KillAura::DrawStatus() 
    { 
        ImGui::Text(u8"杀戮光环 [%s]\n[%.01fm|%s|%dms|%dms]",
			f_DamageMode && f_InstantDeathMode ? "极端" : f_DamageMode ? "碰撞" : f_InstantDeathMode ? "瞬间" : "无",
			f_Range.value(),
			f_OnlyTargeted ? "仇恨" : "所有",
			f_AttackDelay.value(),
			f_RepeatDelay.value());
    }

    KillAura& KillAura::GetInstance()
    {
        static KillAura instance;
        return instance;
    }

	// Kill aura logic is just emulate monster fall crash, so simple but works.
	// Note. No work on mob with shield, maybe update like auto ore destroy.
	void KillAura::OnGameUpdate()
	{
		static std::default_random_engine generator;
		static std::uniform_int_distribution<int> distribution(-50, 50);

		static int64_t nextAttackTime = 0;
		static std::map<uint32_t, int64_t> monsterRepeatTimeMap;
		static std::queue<game::Entity*> attackQueue;
		static std::unordered_set<uint32_t> attackSet;

		if (!f_Enabled || !f_DamageMode)
			return;

		auto eventManager = GET_SINGLETON(MoleMole_EventManager);
		if (eventManager == nullptr || *app::MoleMole_EventHelper_Allocate_103__MethodInfo == nullptr)
			return;

		auto currentTime = util::GetCurrentTimeMillisec();
		if (currentTime < nextAttackTime)
			return;

		auto& manager = game::EntityManager::instance();

		for (const auto& monster : manager.entities(game::filters::combined::Monsters))
		{
			auto monsterID = monster->runtimeID();

			if (attackSet.count(monsterID) > 0)
				continue;

			if (monsterRepeatTimeMap.count(monsterID) > 0 && monsterRepeatTimeMap[monsterID] > currentTime)
				continue;

			auto combat = monster->combat();
			if (combat == nullptr)
				continue;

			auto combatProp = combat->fields._combatProperty_k__BackingField;
			if (combatProp == nullptr)
				continue;

			auto maxHP = app::MoleMole_SafeFloat_get_Value(combatProp->fields.maxHP, nullptr);
			auto isLockHp = combatProp->fields.islockHP == nullptr || app::MoleMole_FixedBoolStack_get_value(combatProp->fields.islockHP, nullptr);
			auto isInvincible = combatProp->fields.isInvincible == nullptr || app::MoleMole_FixedBoolStack_get_value(combatProp->fields.isInvincible, nullptr);
			auto HP = app::MoleMole_SafeFloat_get_Value(combatProp->fields.HP, nullptr);
			if (maxHP < 10 || HP < 2 || isLockHp || isInvincible)
				continue;

			if (f_OnlyTargeted && combat->fields._attackTarget.runtimeID != manager.avatar()->runtimeID())
				continue;

			if (manager.avatar()->distance(monster) > f_Range)
				continue;

			attackQueue.push(monster);
			attackSet.insert(monsterID);
		}

		if (attackQueue.empty())
			return;

		auto monster = attackQueue.front();
		attackQueue.pop();

		if (!monster->isLoaded())
		{
			// If monster entity isn't active means that it was unloaded (it happen when player teleport or moving fast)
			// And we don't have way to get id
			// So better to clear all queue, to prevent memory leak
			// This happen rarely, so don't give any performance issues
			std::queue<game::Entity*> empty;
			std::swap(attackQueue, empty);

			attackSet.clear();
			return;
		}

		attackSet.erase(monster->runtimeID());

		auto combat = monster->combat();
		auto maxHP = app::MoleMole_SafeFloat_get_Value(combat->fields._combatProperty_k__BackingField->fields.maxHP, nullptr);

		auto crashEvt = app::MoleMole_EventHelper_Allocate_103(*app::MoleMole_EventHelper_Allocate_103__MethodInfo);
		app::MoleMole_EvtCrash_Init(crashEvt, monster->runtimeID(), nullptr);
		crashEvt->fields.maxHp = maxHP;
		crashEvt->fields.velChange = 1000;
		crashEvt->fields.hitPos = monster->absolutePosition();

		app::MoleMole_EventManager_FireEvent(eventManager, reinterpret_cast<app::BaseEvent*>(crashEvt), false, nullptr);

		monsterRepeatTimeMap[monster->runtimeID()] = currentTime + (int)f_RepeatDelay + distribution(generator);

		nextAttackTime = currentTime + (int)f_AttackDelay + distribution(generator);
	}

	static void OnSyncTask(app::BaseMoveSyncPlugin* moveSync)
	{
		KillAura& killAura = KillAura::GetInstance();
		if (!killAura.f_Enabled || !killAura.f_InstantDeathMode)
			return;

		auto& manager = game::EntityManager::instance();
		auto avatarID = manager.avatar()->runtimeID();
		auto entityID = moveSync->fields._.owner->fields.entityRuntimeID;

		if (entityID == avatarID)
			return;

		auto monster = manager.entity(entityID);
		auto combat = monster->combat();
		if (combat == nullptr)
			return;

		if (killAura.f_OnlyTargeted && combat->fields._attackTarget.runtimeID != avatarID)
			return;

		if (manager.avatar()->distance(monster) > killAura.f_Range)
			return;

		moveSync->fields._syncTask.position.x = 1000000.0f;
	}

	static void BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo_Hook(app::BaseMoveSyncPlugin* __this, MethodInfo* method)
	{
		OnSyncTask(__this);
		CALL_ORIGIN(BaseMoveSyncPlugin_ConvertSyncTaskToMotionInfo_Hook, __this, method);
	}
}

