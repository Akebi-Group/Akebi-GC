#include "pch-il2cpp.h"
#include "ShowChestIndicator.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    static bool IndicatorPlugin_DoCheck(app::LCIndicatorPlugin* __this, MethodInfo* method);

    ChestIndicator::ChestIndicator() : Feature(),
        NFEX(f_Enabled, "Show Chest Indicator", "ChestIndicator", "ChestIndicator", false, false),
        NF(f_HideStatus, "Hide Status", "ChestIndicator", false)
    {
        HookManager::install(app::MoleMole_LCIndicatorPlugin_DoCheck, IndicatorPlugin_DoCheck);
    }

    const FeatureGUIInfo& ChestIndicator::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "ShowChest", "Visuals", false };
        return info;
    }

    void ChestIndicator::DrawMain()
    {
        ConfigWidget(f_Enabled, "Show chests, game mechanics.");
        if (f_Enabled)
        {
            ImGui::Indent();
            ConfigWidget("Hide Status", f_HideStatus, "Hide feature from status window");
            ImGui::Unindent();
        }
    }

    bool ChestIndicator::NeedStatusDraw() const
    {
        return !f_HideStatus && f_Enabled;
    }

    void ChestIndicator::DrawStatus()
    {
        ImGui::Text("Chest Indicator");
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