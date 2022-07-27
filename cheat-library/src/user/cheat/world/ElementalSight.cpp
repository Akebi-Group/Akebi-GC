#include "pch-il2cpp.h"
#include "ElementalSight.h"

#include <helpers.h>

namespace cheat::feature
{
    static void LevelSceneElementViewPlugin_Tick_Hook(app::LevelSceneElementViewPlugin* __this, float inDeltaTime, MethodInfo* method);

    ElementalSight::ElementalSight() : Feature(),
        NF(f_Enabled, "Permanent Elemental Sight", "ElementalSight", false),
        NF(f_HideStatus, "Hide Status", "ElementalSight", false)
    {
        HookManager::install(app::MoleMole_LevelSceneElementViewPlugin_Tick, LevelSceneElementViewPlugin_Tick_Hook);
    }

    const FeatureGUIInfo& ElementalSight::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "World", false };
        return info;
    }

    void ElementalSight::DrawMain()
    {
        ConfigWidget("Permanent Elemental Sight", f_Enabled, "Elemental sight is kept on even when moving.\n"
                     "To turn off, toggle off and use Elemental Sight again.");
        if (f_Enabled)
        {
            ImGui::Indent();
            ConfigWidget("Hide Status", f_HideStatus, "Hide feature from status window");
            ImGui::Unindent();
        }
    }

    bool ElementalSight::NeedStatusDraw() const
    {
        return !f_HideStatus && f_Enabled;
    }

    void ElementalSight::DrawStatus()
    {
        ImGui::Text("Perma Elemental Sight");
    }

    ElementalSight& ElementalSight::GetInstance()
    {
        static ElementalSight instance;
        return instance;
    }

    static void LevelSceneElementViewPlugin_Tick_Hook(app::LevelSceneElementViewPlugin* __this, float inDeltaTime, MethodInfo* method)
    {
        ElementalSight& ElementalSight = ElementalSight::GetInstance();
        if (ElementalSight.f_Enabled)
            __this->fields._triggerElementView = true;
        CALL_ORIGIN(LevelSceneElementViewPlugin_Tick_Hook, __this, inDeltaTime, method);
    }
}

