#include "pch-il2cpp.h"
#include "ShowChestIndicator.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    static bool IndicatorPlugin_DoCheck(app::LCIndicatorPlugin* __this, MethodInfo* method);

    ChestIndicator::ChestIndicator() : Feature(),
        NFEX(f_Enabled, u8"显示箱子指示器", "ChestIndicator", "Visuals", false, false)
    {
        HookManager::install(app::MoleMole_LCIndicatorPlugin_DoCheck, IndicatorPlugin_DoCheck);
    }

    const FeatureGUIInfo& ChestIndicator::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ u8"显示箱子", u8"界面", false };
        return info;
    }

    void ChestIndicator::DrawMain()
    {
        ConfigWidget(f_Enabled, u8"展示箱子，游戏机制。");
    }

    bool ChestIndicator::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void ChestIndicator::DrawStatus()
    {
        ImGui::Text(u8"箱子指示器");
    }

    ChestIndicator& ChestIndicator::GetInstance()
    {
        static ChestIndicator instance;
        return instance;
    }

    static bool IndicatorPlugin_DoCheck(app::LCIndicatorPlugin* __this, MethodInfo* method) {
        ChestIndicator& chestIndicator = ChestIndicator::GetInstance();
        if (chestIndicator.f_Enabled)
        {
            if (__this->fields._dataItem != nullptr)
            {
                // Base Chest not found, try improve
                app::MoleMole_LCIndicatorPlugin_ShowIcon(__this, nullptr);
            }
        }
        return CALL_ORIGIN(IndicatorPlugin_DoCheck, __this, method);
    }
}