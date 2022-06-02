#include "pch-il2cpp.h"
#include "GodMode.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature 
{
    static bool Miscs_CheckTargetAttackable_Hook(app::BaseEntity* attacker, app::BaseEntity* target, MethodInfo* method);
    static void VCHumanoidMove_NotifyLandVelocity_Hook(app::VCHumanoidMove* __this, app::Vector3 velocity, float reachMaxDownVelocityTime, MethodInfo* method);

    GodMode::GodMode() : Feature(),
        NFEX(f_Enabled, "God mode", "m_GodMode", "Player", false, false)
    {
		// HookManager::install(app::MoleMole_LCBaseCombat_FireBeingHitEvent, LCBaseCombat_FireBeingHitEvent_Hook);
		HookManager::install(app::VCHumanoidMove_NotifyLandVelocity, VCHumanoidMove_NotifyLandVelocity_Hook);
		HookManager::install(app::Miscs_CheckTargetAttackable, Miscs_CheckTargetAttackable_Hook);
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
    }

    bool GodMode::NeedStatusDraw() const
{
        return f_Enabled;
    }

    void GodMode::DrawStatus() 
    {
        ImGui::Text("God Mode");
    }

    GodMode& GodMode::GetInstance()
    {
        static GodMode instance;
        return instance;
    }

	// Attack immunity (return false when target is avatar, that mean avatar entity isn't attackable)
	static bool Miscs_CheckTargetAttackable_Hook(app::BaseEntity* attacker, app::BaseEntity* target, MethodInfo* method)
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
	static void VCHumanoidMove_NotifyLandVelocity_Hook(app::VCHumanoidMove* __this, app::Vector3 velocity, float reachMaxDownVelocityTime, MethodInfo* method)
	{
        auto& gm = GodMode::GetInstance();
		if (gm.f_Enabled && -velocity.y > 13)
		{
			float randAdd = (float)(std::rand() % 1000) / 1000;
			velocity.y = -8 - randAdd;
			reachMaxDownVelocityTime = 0;
		}
		// LOG_DEBUG("%s, %f", il2cppi_to_string(velocity).c_str(), reachMaxDownVelocityTime);
		CALL_ORIGIN(VCHumanoidMove_NotifyLandVelocity_Hook, __this, velocity, reachMaxDownVelocityTime, method);
	}

    // Analog function for disable attack damage (Thanks to Taiga74164)
    //void LCBaseCombat_FireBeingHitEvent_Hook(app::LCBaseCombat* __this, uint32_t attackeeRuntimeID, app::AttackResult* attackResult, MethodInfo* method) 
    //{
    //    auto avatarEntity = GetAvatarEntity();
    //    if (avatarEntity != nullptr && Config::cfgGodModEnable.GetValue() && avatarEntity->fields._runtimeID_k__BackingField == attackeeRuntimeID)
    //        return;
    //
    //    return callOrigin(LCBaseCombat_FireBeingHitEvent_Hook, __this, attackeeRuntimeID, attackResult, method);
    //}
}

