#include "pch-il2cpp.h"
#include "MapTeleport.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>

namespace cheat::feature
{

	MapTeleport::MapTeleport() : Feature(),
		NF(f_Enabled, u8"地图传送", "MapTeleport", false),
		NF(f_DetectHeight, u8"自动高度检测", "MapTeleport", true),
		NF(f_DefaultHeight, u8"默认传送高度", "MapTeleport", 300.0f),
		NF(f_Key, u8"指定键位", "MapTeleport", Hotkey('T'))
	{
		// Map touch
		HookManager::install(app::MoleMole_InLevelMapPageContext_OnMarkClicked, InLevelMapPageContext_OnMarkClicked_Hook);
		HookManager::install(app::MoleMole_InLevelMapPageContext_OnMapClicked, InLevelMapPageContext_OnMapClicked_Hook);

		// Stage 1
		HookManager::install(app::MoleMole_LoadingManager_NeedTransByServer, LoadingManager_NeedTransByServer_Hook);

		// Stage 2
		HookManager::install(app::MoleMole_LoadingManager_PerformPlayerTransmit, LoadingManager_PerformPlayerTransmit_Hook);

		// Stage 3
		HookManager::install(app::MoleMole_BaseEntity_SetAbsolutePosition, MoleMole_BaseEntity_SetAbsolutePosition_Hook);

		events::GameUpdateEvent += MY_METHOD_HANDLER(MapTeleport::OnGameUpdate);
	}

	const FeatureGUIInfo& MapTeleport::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ u8"地图传送", u8"传送", true };
		return info;
	}

	void MapTeleport::DrawMain()
	{
		ConfigWidget(u8"启用",
			f_Enabled,
			u8"启用传送到标记功能。\n" \
			u8"用法: \n" \
			u8"\t1. 打开地图.\n" \
			u8"\t2. 鼠标移动到你要去的地方并按下设置的键，默认为T\n" \
			u8"\t完毕。 您已被传送到选定的位置。\n" \
			u8"如果传送到极高的位置，传送可能会出现故障。\n" \
			u8"相应地调整覆盖高度以帮助避免。"
		);

		if (!f_Enabled)
			ImGui::BeginDisabled();

		ConfigWidget(u8"覆盖高度 (m)", f_DefaultHeight, 1.0F, 200.0F, 800.0F,
			u8"如果传送无法获取目标位置的地面高度，\n 会将您传送到此处指定的高度。\n" \
			u8"建议将此值设置为至少与一座山一样高。\n否则，您可能会从地面跌落。");

		ConfigWidget(u8"指定键位", f_Key, true,
			u8"在单击目标位置之前按住的键。");

		if (!f_Enabled)
			ImGui::EndDisabled();
	}

	MapTeleport& MapTeleport::GetInstance()
	{
		static MapTeleport instance;
		return instance;
	}

	// Hook for game manager needs for starting teleport in game update thread.
	// Because, when we use Teleport call in non game thread (imgui update thread for example)
	// the game just skip this call, and only with second call you start teleporting, 
	// but to prev selected location.
	void MapTeleport::OnGameUpdate()
	{
		if (taskInfo.waitingThread)
		{
			taskInfo.waitingThread = false;
			auto someSingleton = GET_SINGLETON(MoleMole_LoadingManager);
			app::MoleMole_LoadingManager_RequestSceneTransToPoint(someSingleton, taskInfo.sceneId, taskInfo.waypointId, nullptr, nullptr);
		}
	}

	// Finding nearest waypoint to position, and request teleport to it.
	// After, in teleport events, change waypoint position to target position.
	void MapTeleport::TeleportTo(app::Vector3 position, bool needHeightCalc, uint32_t sceneId)
	{
		LOG_DEBUG("Stage 0. Target location at %s", il2cppi_to_string(position).c_str());

		auto avatarPosition = app::ActorUtils_GetAvatarPos(nullptr);
		auto nearestWaypoint = game::FindNearestWaypoint(position, sceneId);

		if (nearestWaypoint.data == nullptr)
		{
			LOG_ERROR("Stage 0. Failed to find the nearest unlocked waypoint. Maybe you haven't unlocked anyone or the scene has no waypoints.");
			return;
		}
		else
		{
			float dist = app::Vector3_Distance(position, nearestWaypoint.position, nullptr);
			LOG_DEBUG("Stage 0. Found nearest waypoint { sceneId: %d; waypointId: %d } with distance %fm.",
				nearestWaypoint.sceneId, nearestWaypoint.waypointId, dist);
		}
		taskInfo = { true, needHeightCalc, 3, position, nearestWaypoint.sceneId, nearestWaypoint.waypointId };
	}

	static bool ScreenToMapPosition(app::InLevelMapPageContext* context, app::Vector2 screenPos, app::Vector2* outMapPos)
	{
		auto mapBackground = app::MonoInLevelMapPage_get_mapBackground(context->fields._pageMono, nullptr);
		if (!mapBackground)
			return false;

		auto uimanager = GET_SINGLETON(MoleMole_UIManager);
		if (uimanager == nullptr)
			return false;

		auto screenCamera = uimanager->fields._uiCamera;
		if (screenCamera == nullptr)
			return false;

		bool result = app::RectTransformUtility_ScreenPointToLocalPointInRectangle(mapBackground, screenPos, screenCamera, outMapPos, nullptr);
		if (!result)
			return false;

		auto mapRect = app::MonoInLevelMapPage_get_mapRect(context->fields._pageMono, nullptr);
		auto mapViewRect = context->fields._mapViewRect;

		// Map rect pos to map view rect pos
		outMapPos->x = (outMapPos->x - mapRect.m_XMin) / mapRect.m_Width;
		outMapPos->x = (outMapPos->x * mapViewRect.m_Width) + mapViewRect.m_XMin;

		outMapPos->y = (outMapPos->y - mapRect.m_YMin) / mapRect.m_Height;
		outMapPos->y = (outMapPos->y * mapViewRect.m_Height) + mapViewRect.m_YMin;

		return true;
	}

	void MapTeleport::TeleportTo(app::Vector2 mapPosition)
	{
		auto worldPosition = app::Miscs_GenWorldPos(mapPosition, nullptr);

		auto relativePos = app::WorldShiftManager_GetRelativePosition(worldPosition, nullptr);
		auto groundHeight = app::Miscs_CalcCurrentGroundHeight(relativePos.x, relativePos.z, nullptr);

		TeleportTo({ worldPosition.x, groundHeight > 0 ? groundHeight + 5 : f_DefaultHeight, worldPosition.z }, true, game::GetCurrentMapSceneID());
	}

	// Calling teleport if map clicked.
	// This event invokes only when free space of map clicked,
	// if clicked mark, invokes InLevelMapPageContext_OnMarkClicked_Hook.
	void MapTeleport::InLevelMapPageContext_OnMapClicked_Hook(app::InLevelMapPageContext* __this, app::Vector2 screenPos, MethodInfo* method)
	{
		MapTeleport& mapTeleport = GetInstance();

		if (!mapTeleport.f_Enabled || !mapTeleport.f_Key.value().IsPressed())
			return CALL_ORIGIN(InLevelMapPageContext_OnMapClicked_Hook, __this, screenPos, method);

		app::Vector2 mapPosition{};
		bool mapPosResult = ScreenToMapPosition(__this, screenPos, &mapPosition);
		if (!mapPosResult)
			return;

		mapTeleport.TeleportTo(mapPosition);
	}

	// Calling teleport if map marks clicked.
	void MapTeleport::InLevelMapPageContext_OnMarkClicked_Hook(app::InLevelMapPageContext* __this, app::MonoMapMark* mark, MethodInfo* method)
	{
		MapTeleport& mapTeleport = GetInstance();
		if (!mapTeleport.f_Enabled || !mapTeleport.f_Key.value().IsPressed())
			return CALL_ORIGIN(InLevelMapPageContext_OnMarkClicked_Hook, __this, mark, method);

		mapTeleport.TeleportTo(mark->fields._levelMapPos);
	}

	// Checking is teleport is far (>60m), if it isn't we clear stage.
	bool MapTeleport::IsNeedTransByServer(bool originResult, app::Vector3& position)
	{
		if (taskInfo.currentStage != 3)
			return originResult;
		
		auto& entityManager = game::EntityManager::instance();
		bool needServerTrans = entityManager.avatar()->distance(taskInfo.targetPosition) > 60.0f;
		if (needServerTrans)
			LOG_DEBUG("Stage 1. Distance is more than 60m. Performing server tp.");
		else
			LOG_DEBUG("Stage 1. Distance is less than 60m. Performing fast tp.");

		taskInfo.currentStage--;
		return needServerTrans;
	}

	// After server responded, it will give us the waypoint target location to load. 
	// Change it to teleport location.
	void MapTeleport::OnPerformPlayerTransmit(app::Vector3& position)
	{
		if (taskInfo.currentStage == 2)
		{
			LOG_DEBUG("Stage 2. Changing loading location.");
			position = taskInfo.targetPosition;
			taskInfo.currentStage--;
		}
	}

	// Last event in teleportation is avatar teleport, we just change avatar position from
	// waypoint location to teleport location. And also recalculate ground position if it needed.
	void MapTeleport::OnSetAvatarPosition(app::Vector3& position)
	{
		if (taskInfo.currentStage == 1)
		{
			app::Vector3 originPosition = position;
			position = taskInfo.targetPosition;
			LOG_DEBUG("Stage 3. Changing avatar entity position.");

			if (taskInfo.needHeightCalculation)
			{
				auto relativePos = app::WorldShiftManager_GetRelativePosition(position, nullptr);
				float groundHeight;
				switch (taskInfo.sceneId)
				{
					// Underground mines has tunnel structure, so we need to calculate height from waypoint height to prevent tp above world.
				case 6: // Underground mines scene id, if it was changed, please create issue
					groundHeight = app::Miscs_CalcCurrentGroundHeight_1(relativePos.x, relativePos.z, originPosition.y, 100,
						app::Miscs_GetSceneGroundLayerMask(nullptr), nullptr);
					break;
				default:
					groundHeight = app::Miscs_CalcCurrentGroundWaterHeight(relativePos.x, relativePos.z, nullptr);
					break;
				}
				if (groundHeight > 0 && position.y != groundHeight)
				{
					position.y = groundHeight + 5;
					LOG_DEBUG("Stage 3. Changing height to %f", position.y);
				}
			}

			LOG_DEBUG("Finish.  Teleport to mark finished.");
			taskInfo.currentStage--;
		}
	}

	bool MapTeleport::LoadingManager_NeedTransByServer_Hook(app::MoleMole_LoadingManager* __this, uint32_t sceneId, app::Vector3 position, MethodInfo* method)
	{
		auto result = CALL_ORIGIN(LoadingManager_NeedTransByServer_Hook, __this, sceneId, position, method);

		auto& mapTeleport = GetInstance();
		return mapTeleport.IsNeedTransByServer(result, position);
	}


	void MapTeleport::LoadingManager_PerformPlayerTransmit_Hook(app::MoleMole_LoadingManager* __this, app::Vector3 position, app::EnterType__Enum someEnum,
		uint32_t someUint1, app::EvtTransmitAvatar_EvtTransmitAvatar_TransmitType__Enum teleportType, uint32_t someUint2, MethodInfo* method)
	{
		MapTeleport& mapTeleport = MapTeleport::GetInstance();
		mapTeleport.OnPerformPlayerTransmit(position);

		CALL_ORIGIN(LoadingManager_PerformPlayerTransmit_Hook, __this, position, someEnum, someUint1, teleportType, someUint2, method);
	}


	void MapTeleport::MoleMole_BaseEntity_SetAbsolutePosition_Hook(app::BaseEntity* __this, app::Vector3 position, bool someBool, MethodInfo* method)
	{
		auto& manager = game::EntityManager::instance();
		if (manager.avatar()->raw() == __this)
		{
			MapTeleport& mapTeleport = MapTeleport::GetInstance();
			mapTeleport.OnSetAvatarPosition(position);
		}

		CALL_ORIGIN(MoleMole_BaseEntity_SetAbsolutePosition_Hook, __this, position, someBool, method);
	}

}

