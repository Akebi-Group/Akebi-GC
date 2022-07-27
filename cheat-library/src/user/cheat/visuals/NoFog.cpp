#include "pch-il2cpp.h"
#include "NoFog.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    static bool _prevEnabledState = false;
    NoFog::NoFog() : Feature(),
        NFEX(f_Enabled, "No Fog", "NoFog", "NoFog", false, false),
        NF(f_HideStatus, "Hide Status", "NoFog", false)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(NoFog::OnGameUpdate);
    }

    const FeatureGUIInfo& NoFog::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "NoFog", "Visuals", false };
        return info;
    }

    void NoFog::DrawMain()
    {
        ConfigWidget(f_Enabled, "Removes the fog.");
        if (f_Enabled)
        {
            ImGui::Indent();
            ConfigWidget("Hide Status", f_HideStatus, "Hide feature from status window");
            ImGui::Unindent();
        }
    }

    bool NoFog::NeedStatusDraw() const
    {
        return !f_HideStatus && f_Enabled;
    }

    void NoFog::DrawStatus()
    {
        ImGui::Text("NoFog");
    }

    NoFog& NoFog::GetInstance()
    {
        static NoFog instance;
        return instance;
    }

    void NoFog::OnGameUpdate()
    {
		if (_prevEnabledState != f_Enabled)
		{
			app::RenderSettings_set_fog(!f_Enabled, nullptr);
			_prevEnabledState = f_Enabled;
		}
    }
}

