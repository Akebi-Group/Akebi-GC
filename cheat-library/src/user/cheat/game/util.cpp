#include <pch-il2cpp.h>
#include "util.h"

#include <helpers.h>
#include "EntityManager.h"

namespace cheat::game
{
	std::vector<WaypointInfo> GetUnlockedWaypoints(uint32_t targetSceneId)
	{
		auto mapModule = GET_SINGLETON(MoleMole_MapModule);
		if (mapModule == nullptr)
			return {};

		if (targetSceneId == 0)
			targetSceneId = GetCurrentPlayerSceneID();

		auto result = std::vector<WaypointInfo>();

		auto waypointGroups = TO_UNI_DICT(mapModule->fields._scenePointDics, uint32_t, UniDict<uint32_t COMMA app::MapModule_ScenePointData>*);
		for (const auto& [sceneId, waypoints] : waypointGroups->pairs())
		{
			if (sceneId != targetSceneId)
				continue;

			for (const auto& [waypointId, waypoint] : waypoints->pairs())
			{
				if (waypoint.config == nullptr)
					continue;

				auto& config = waypoint.config->fields;
				uint16_t areaId = app::MoleMole_SimpleSafeUInt16_get_Value(config.areaIdRawNum, nullptr);
				bool isAreaUnlocked = app::MoleMole_MapModule_IsAreaUnlock(mapModule, sceneId, areaId, nullptr);

				if (waypoint.isUnlocked && isAreaUnlocked && !config._unlocked && !waypoint.isGroupLimit && !waypoint.isModelHidden)
					result.push_back(WaypointInfo{ sceneId, waypointId, waypoint.config->fields._tranPos, (app::MapModule_ScenePointData*)&waypoint });
			}
		}
		return result;
	}

	// Finding nearest unlocked waypoint to the position
	WaypointInfo FindNearestWaypoint(app::Vector3& position, uint32_t targetSceneId)
	{
		float minDistance = -1;
		WaypointInfo result{};
		for (const auto& info : GetUnlockedWaypoints(targetSceneId)) {
			float distance = app::Vector3_Distance(position, info.position, nullptr);
			if (minDistance < 0 || distance < minDistance)
			{
				minDistance = distance;
				result = info;
			}
		}
		return result;
	}

	uint32_t GetCurrentPlayerSceneID()
	{
		auto playerModule = GET_SINGLETON(MoleMole_PlayerModule);
		if (playerModule == nullptr)
			return 0;

		return playerModule->fields.curSceneID;
	}

	uint32_t GetCurrentMapSceneID()
	{
		auto mapManager = GET_SINGLETON(MoleMole_MapManager);
		if (mapManager == nullptr)
			return 0;

		return mapManager->fields.mapSceneID;
	}

	app::GadgetEntity* GetGadget(uint32_t runtimeID)
	{
		auto& manager = EntityManager::instance();
		return GetGadget(manager.entity(runtimeID));
	}

	app::GadgetEntity* GetGadget(app::BaseEntity* entity)
	{
		if (entity == nullptr)
			return nullptr;

		auto ent = Entity(entity);
		if (!ent.isGadget())
			return nullptr;

		return reinterpret_cast<app::GadgetEntity*>(entity);
	}

	app::GadgetEntity* GetGadget(Entity* entity)
	{
		if (entity == nullptr || !entity->isGadget())
			return nullptr;
		
		return reinterpret_cast<app::GadgetEntity*>(entity);
	}

	game::Entity* FindNearestEntity(const IEntityFilter& filter)
	{
		auto& manager = game::EntityManager::instance();
		auto entities = manager.entities(filter);
		return FindNearestEntity(entities);
	}

	game::Entity* FindNearestEntity(std::vector<game::Entity*>& entities)
	{
		if (entities.size() == 0)
			return nullptr;

		auto avatar = game::EntityManager::instance().avatar();
		return *std::min_element(entities.begin(), entities.end(),
			[avatar](game::Entity* a, game::Entity* b) { return avatar->distance(a) < avatar->distance(b); });
	}

	app::AccountDataItem* GetAccountData()
	{
		auto playerModule = GET_SINGLETON(MoleMole_PlayerModule);
		if (playerModule == nullptr || playerModule->fields._accountData_k__BackingField == nullptr)
			return nullptr;

		return playerModule->fields._accountData_k__BackingField;
	}
}
