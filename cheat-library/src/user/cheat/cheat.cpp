#include <pch-il2cpp.h>
#include "cheat.h"

#include <helpers.h>

#include <cheat/events.h>

#include <cheat-base/cheat/misc/Settings.h>

#include <cheat/misc/ProtectionBypass.h>
#include <cheat/misc/Hotkeys.h>
#include <cheat/misc/Debug.h>
#include <cheat/misc/sniffer/PacketSniffer.h>

#include <cheat/player/GodMode.h>
#include <cheat/player/InfiniteStamina.h>
#include <cheat/player/NoCD.h>
#include <cheat/player/NoClip.h>
#include <cheat/player/RapidFire.h>
#include <cheat/player/AutoRun.h>

#include <cheat/world/AutoLoot.h>
#include <cheat/world/DialogSkip.h>
#include <cheat/world/DumbEnemies.h>
#include <cheat/world/FreezeEnemies.h>
#include <cheat/world/ElementalSight.h>
#include <cheat/world/KillAura.h>
#include <cheat/world/MobVacuum.h>
#include <cheat/world/AutoTreeFarm.h>
#include <cheat/world/AutoDestroy.h>
#include <cheat/world/FakeTime.h>
#include <cheat/world/AutoSeelie.h>
#include <cheat/world/VacuumLoot.h>

#include <cheat/teleport/ChestTeleport.h>
#include <cheat/teleport/MapTeleport.h>
#include <cheat/teleport/OculiTeleport.h>
#include <cheat/teleport/CustomTeleports.h>

#include <cheat/esp/ESP.h>
#include <cheat/imap/InteractiveMap.h>

#include <cheat/world/AutoFish.h>
#include <cheat/world/AutoCook.h>
#include <cheat/world/CustomWeather.h>

#include <cheat/visuals/NoFog.h>
#include <cheat/visuals/FPSUnlock.h>
#include <cheat/visuals/CameraZoom.h>
#include <cheat/visuals/ShowChestIndicator.h>
#include <cheat/visuals/ProfileChanger.h>
#include <cheat/visuals/PaimonFollow.h>
#include <cheat/visuals/HideUI.h>
#include <cheat/visuals/Browser.h>
#include <cheat/visuals/EnablePeeking.h>
#include <cheat/visuals/TextureChanger.h>
#include <cheat/visuals/FreeCamera.h>
#include <cheat/visuals/AnimationChanger.h>

#include "GenshinCM.h"

namespace cheat 
{
	static void InstallEventHooks();

	void Init()
	{
		config::SetupUpdate(&events::GameUpdateEvent);

		auto& protectionBypass = feature::ProtectionBypass::GetInstance();
		protectionBypass.Init();

		GenshinCM& manager = GenshinCM::instance();

#define FEAT_INST(name) &feature::##name##::GetInstance()
		manager.AddFeatures({
			&protectionBypass,
			FEAT_INST(Settings),
			FEAT_INST(Hotkeys),
			FEAT_INST(Debug),
			FEAT_INST(PacketSniffer),

			FEAT_INST(GodMode),
			FEAT_INST(InfiniteStamina),
			FEAT_INST(NoCD),
			FEAT_INST(NoClip),
			FEAT_INST(RapidFire),
			FEAT_INST(AutoRun),

			FEAT_INST(AutoLoot),
			FEAT_INST(AutoTreeFarm),
			FEAT_INST(AutoDestroy),
			FEAT_INST(AutoSeelie),
			FEAT_INST(VacuumLoot),
			FEAT_INST(DialogSkip),
			FEAT_INST(DumbEnemies),
			FEAT_INST(FreezeEnemies),
			FEAT_INST(ElementalSight),
			FEAT_INST(KillAura),
			FEAT_INST(MobVacuum),
			FEAT_INST(FakeTime),

			FEAT_INST(ChestTeleport),
			FEAT_INST(OculiTeleport),
			FEAT_INST(MapTeleport),
			FEAT_INST(CustomTeleports),

			FEAT_INST(ESP),
			FEAT_INST(InteractiveMap),

			FEAT_INST(AutoFish),
			FEAT_INST(AutoCook),

			FEAT_INST(CustomWeather),

			FEAT_INST(NoFog),
			FEAT_INST(FPSUnlock),
			FEAT_INST(CameraZoom),
			FEAT_INST(ChestIndicator),
			FEAT_INST(ProfileChanger),
			FEAT_INST(PaimonFollow),
			FEAT_INST(HideUI),
			FEAT_INST(Browser),
			FEAT_INST(EnablePeeking),
			FEAT_INST(TextureChanger),
			FEAT_INST(FreeCamera),
			FEAT_INST(AnimationChanger)
			
			});
#undef FEAT_INST

		manager.SetModuleOrder({
			"Player",
			"World",
			"Teleport",
			"ESP",
			"Visuals",
			"Hotkeys",
			"Settings",
			"Debug"
			});

		LPBYTE pFontData = nullptr;
		DWORD dFontSize = 0;
		if (!ResourceLoader::LoadEx("ImGui_Font", RT_RCDATA, pFontData, dFontSize))
			LOG_WARNING("Failed to get font from resources.");

		manager.Init(pFontData, dFontSize);

		InstallEventHooks();
	}

	static void CheckAccountChanged()
	{
		UPDATE_DELAY(2000U);

		static uint32_t _lastUserID = 0;

		auto playerModule = GET_SINGLETON(MoleMole_PlayerModule);
		if (playerModule == nullptr || playerModule->fields._accountData_k__BackingField == nullptr)
			return;

		auto& accountData = playerModule->fields._accountData_k__BackingField->fields;
		if (_lastUserID != accountData.userId)
			events::AccountChangedEvent(accountData.userId);

		_lastUserID = accountData.userId;
	}

	static void GameManager_Update_Hook(app::GameManager* __this, MethodInfo* method)
	{
		SAFE_BEGIN();
		events::GameUpdateEvent();
		CheckAccountChanged();
		SAFE_EEND();
		
		CALL_ORIGIN(GameManager_Update_Hook, __this, method);
	}

	static void LevelSyncCombatPlugin_RequestSceneEntityMoveReq_Hook(app::LevelSyncCombatPlugin* __this, uint32_t entityId, app::MotionInfo* syncInfo,
		bool isReliable, uint32_t relseq, MethodInfo* method)
	{
		events::MoveSyncEvent(entityId, syncInfo);
		CALL_ORIGIN(LevelSyncCombatPlugin_RequestSceneEntityMoveReq_Hook, __this, entityId, syncInfo, isReliable, relseq, method);
	}

	static void InstallEventHooks() 
	{
		HookManager::install(app::GameManager_Update, GameManager_Update_Hook);
		HookManager::install(app::MoleMole_LevelSyncCombatPlugin_RequestSceneEntityMoveReq, LevelSyncCombatPlugin_RequestSceneEntityMoveReq_Hook);
	}

}

