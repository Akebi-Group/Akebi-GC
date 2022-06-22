#include "pch-il2cpp.h"
#include "GodMode.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature 
{
    GodMode::GodMode() : Feature(),
        NFEX(f_Enabled, "God mode", "m_GodMode", "Player", false, false),
        NF(f_AltGodMode, "Alternative God Mode", "Player", false)
    {
		HookManager::install(app::VCHumanoidMove_NotifyLandVelocity, VCHumanoidMove_NotifyLandVelocity_Hook);
		HookManager::install(app::Miscs_CheckTargetAttackable, Miscs_CheckTargetAttackable_Hook);
        HookManager::install(app::MoleMole_LCBaseCombat_FireBeingHitEvent, LCBaseCombat_FireBeingHitEvent_Hook);
        HookManager::install(app::MoleMole_ActorAbilityPlugin_HanlderModifierThinkTimerUp, MoleMole_ActorAbilityPlugin_HanlderModifierThinkTimerUp_Hook);
    }

    const FeatureGUIInfo& GodMode::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "Player", false };
        return info;
    }

    void GodMode::DrawMain()
    {
        ConfigWidget("God Mode", f_Enabled, 
                     "Enables god mode, i.e. no incoming damage.\n" \
                     "May not work with some types of damage.");
        ImGui::Indent();
        ConfigWidget("Alternative God Mode", f_AltGodMode,
            "Alternative god mode that ignores incoming damage\n" \
            "including environmental damage.");
        ImGui::Unindent();
    }

    bool GodMode::NeedStatusDraw() const
    {
        return f_Enabled || f_AltGodMode;
    }

    void GodMode::DrawStatus() 
    {
        ImGui::Text("God Mode%s", f_AltGodMode ? "+Alt " : " ");
    }

    GodMode& GodMode::GetInstance()
    {
        static GodMode instance;
        return instance;
    }

	// Attack immunity (return false when target is avatar, that mean avatar entity isn't attackable)
	bool GodMode::Miscs_CheckTargetAttackable_Hook(app::BaseEntity* attacker, app::BaseEntity* target, MethodInfo* method)
	{
        auto& gm = GodMode::GetInstance();
        auto& manager = game::EntityManager::instance();
        auto entity = manager.entity(target);
		if (gm.f_Enabled && entity->isAvatar())
			return false;

		return CALL_ORIGIN(Miscs_CheckTargetAttackable_Hook, attacker, target, method);
	}

	// Raised when avatar fall on ground.
    // Sending fall speed, and how many time pass from gain max fall speed (~30m/s).
    // To disable fall damage reset reachMaxDownVelocityTime and decrease fall velocity.
	void GodMode::VCHumanoidMove_NotifyLandVelocity_Hook(app::VCHumanoidMove* __this, app::Vector3 velocity, float reachMaxDownVelocityTime, MethodInfo* method)
	{
        auto& gm = GodMode::GetInstance();
		if ((gm.f_Enabled || gm.f_AltGodMode) && -velocity.y > 13)
		{
			float randAdd = (float)(std::rand() % 1000) / 1000;
			velocity.y = -8 - randAdd;
			reachMaxDownVelocityTime = 0;
		}
		// LOG_DEBUG("%s, %f", il2cppi_to_string(velocity).c_str(), reachMaxDownVelocityTime);
		CALL_ORIGIN(VCHumanoidMove_NotifyLandVelocity_Hook, __this, velocity, reachMaxDownVelocityTime, method);
	}

    // Analog function for disable attack damage (Thanks to Taiga74164)
    void GodMode::LCBaseCombat_FireBeingHitEvent_Hook(app::LCBaseCombat* __this, uint32_t attackeeRuntimeID, app::AttackResult* attackResult, MethodInfo* method)
    {        
        auto& gm = GodMode::GetInstance();
        auto& manager = game::EntityManager::instance();
        if (gm.f_AltGodMode && manager.avatar()->runtimeID() == attackeeRuntimeID)
            return;

        CALL_ORIGIN(LCBaseCombat_FireBeingHitEvent_Hook, __this, attackeeRuntimeID, attackResult, method);
    }

    // Environmental damage immunity (Thanks to RELOADED#7236 / GitHub: @34736384)
    bool GodMode::MoleMole_ActorAbilityPlugin_HanlderModifierThinkTimerUp_Hook(app::ActorAbilityPlugin* __this, float delay, app::Object* arg, MethodInfo* method)
    {
        if (GetInstance().NeedBlockHanlerModifierThinkTimeUp(arg))
            return false;

        return CALL_ORIGIN(MoleMole_ActorAbilityPlugin_HanlderModifierThinkTimerUp_Hook, __this, delay, arg, method);
    }

	bool GodMode::NeedBlockHanlerModifierThinkTimeUp(app::Object* arg)
	{
        if (!f_AltGodMode)
            return false;

		auto actorModifier = CastTo<app::MoleMole_ActorModifier>(arg, *app::MoleMole_ActorModifier__TypeInfo);
        if (actorModifier == nullptr)
            return false;

		static std::vector<std::string> modifierBlacklist
		{
			"BlackMud",
			"SERVER_ClimateAbility",
			"ElectricWater",
			"SeiraiThunder",
			"UNIQUE_Monster_",
			"Monster_Shougun"
		};
        
        std::string modifierName = il2cppi_to_string(actorModifier->fields._config->fields._modifierName);
		for (auto& forbiddenModifierName : modifierBlacklist)
			if (modifierName.find(forbiddenModifierName) != std::string::npos)
				return true;

        return false;
	}

	//  ____________________________________________________________________________________________________________
    // | Name                                                                   | Description                       |
    // |------------------------------------------------------------------------|-----------------------------------|
    // | SERVER_ClimateAbility_Cold_Area                                        | Sheer cold                        |
    // | SERVER_ClimateAbility_Cold_Lv1                                         | Sheer cold                        |
    // | SERVER_ClimateAbility_Cold_Lv2                                         | Sheer cold                        |
    // | SERVER_ClimateAbility_TsurumiMist_Area                                 | Electric debuff                   |
    // | SERVER_ClimateAbility_TatariRegion_Area                                | Electric debuff                   |
    // | SERVER_ClimateAbility_TatariRegion_Lv1                                 | Electric debuff                   |
    // | SERVER_ClimateAbility_TatariRegion_Lv2                                 | Electric debuff                   |
    // | SERVER_ClimateAbility_SeiraiStorm_Area                                 | Serai Island                      |
    // | SERVER_ClimateAbility_SeiraiStorm_Lv1                                  | Serai Island                      |
    // | SERVER_ClimateAbility_SeiraiStorm_Lv2                                  | Serai Island                      |
    // | SERVER_ClimateAbility_TsurumiMist_Area                                 | Tsurumi Island                    |
    // | ElectricWaterAreaModifier                                              | All electric water in inazuma     |
    // | BlackMudAreaBuff_Avatar                                                |                                   |
    // | BlackMudAreaBuff_Avatar02                                              |                                   |
    // | WaterAreaModifier                                                      |                                   |
    // | SeiraiThunder_Manager                                                  |                                   |
    // | UNIQUE_Monster_Shougun_Mitakenarukami_BurstAtk02_NotInShieldPredicated |                                   |
    // | Monster_Shougun_Mitakenarukami_BurstAtk02_NotInShieldAtk               |                                   |
    // |------------------------------------------------------------------------|-----------------------------------|
}