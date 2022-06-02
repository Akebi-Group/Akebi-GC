#pragma once

#include <il2cpp-appdata.h>

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class MapTeleport : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<bool> f_DetectHeight;
		config::Field<float> f_DefaultHeight;
		config::Field<Hotkey> f_Key;

		static MapTeleport& GetInstance();

		void TeleportTo(app::Vector3 position, bool needHeightCalc = false, uint32_t sceneId = 0);

		void TeleportTo(app::Vector2 mapPosition);

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		
	private:
		struct TeleportTaskInfo
		{
			bool waitingThread = false;
			bool needHeightCalculation = false;
			int currentStage = 0;
			app::Vector3 targetPosition = {};
			uint32_t sceneId = 0;
			uint32_t waypointId = 0;
		};
		TeleportTaskInfo taskInfo;

		void OnGetTargetPos(app::Vector3& position);
		bool IsNeedTransByServer(bool originResult, app::Vector3& position);
		void OnPerformPlayerTransmit(app::Vector3& position);
		void OnSetAvatarPosition(app::Vector3& position);
		void OnGameUpdate();

		// Map client interactions
		static void InLevelMapPageContext_OnMapClicked_Hook(app::InLevelMapPageContext* __this, app::Vector2 screenPos, MethodInfo* method);
		static void InLevelMapPageContext_OnMarkClicked_Hook(app::InLevelMapPageContext* __this, app::MonoMapMark* mark, MethodInfo* method);

		// Teleporting
		static bool LoadingManager_NeedTransByServer_Hook(app::MoleMole_LoadingManager* __this, uint32_t sceneId, app::Vector3 position, MethodInfo* method);
		static void LoadingManager_PerformPlayerTransmit_Hook(app::MoleMole_LoadingManager* __this, app::Vector3 position, app::EnterType__Enum someEnum,
			uint32_t someUint1, app::EvtTransmitAvatar_EvtTransmitAvatar_TransmitType__Enum teleportType, uint32_t someUint2, MethodInfo* method);
		static void MoleMole_BaseEntity_SetAbsolutePosition_Hook(app::BaseEntity* __this, app::Vector3 position, bool someBool, MethodInfo* method);

		MapTeleport();
	};
}

