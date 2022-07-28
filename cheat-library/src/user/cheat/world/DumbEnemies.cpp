#include "pch-il2cpp.h"
#include "DumbEnemies.h"

#include <helpers.h>

namespace cheat::feature 
{
    static void VCMonsterAIController_TryDoSkill_Hook(void* __this, uint32_t skillID, MethodInfo* method);

    DumbEnemies::DumbEnemies() : Feature(),
        NF(f_Enabled, u8"敌人变傻", "DumbEnemies", false)
    {
		HookManager::install(app::MoleMole_VCMonsterAIController_TryDoSkill, VCMonsterAIController_TryDoSkill_Hook);
    }

    const FeatureGUIInfo& DumbEnemies::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", u8"世界", false };
        return info;
    }

    void DumbEnemies::DrawMain()
    {
        ConfigWidget(f_Enabled, u8"敌人不会攻击或对玩家使用技能。 \n"
            u8"可能不适用于某些敌人或敌人的能力。");
    }

    bool DumbEnemies::NeedStatusDraw() const
{
        return f_Enabled;
    }

    void DumbEnemies::DrawStatus() 
    { 
        ImGui::Text(u8"敌人变傻");
    }

    DumbEnemies& DumbEnemies::GetInstance()
    {
        static DumbEnemies instance;
        return instance;
    }

	// Raised when monster trying to do skill. Attack also is skill.
    // We just block if dumb mob enabled, so mob will not attack player.
	static void VCMonsterAIController_TryDoSkill_Hook(void* __this, uint32_t skillID, MethodInfo* method)
	{
        DumbEnemies& dumbEnemies = DumbEnemies::GetInstance();
		if (dumbEnemies.f_Enabled)
			return;
		CALL_ORIGIN(VCMonsterAIController_TryDoSkill_Hook, __this, skillID, method);
	}
}

