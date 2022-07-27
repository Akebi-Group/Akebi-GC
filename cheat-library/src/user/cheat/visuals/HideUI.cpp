#include "pch-il2cpp.h"
#include "HideUI.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    app::GameObject* ui_camera{};

    HideUI::HideUI() : Feature(),
        NFEX(f_Enabled, "Hide UI", "HideUI", "HideUI", false, false),
        NF(f_HideStatus, "Hide Status", "HideUI", false)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(HideUI::OnGameUpdate);
    }

    const FeatureGUIInfo& HideUI::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "HideUI", "Visuals", false };
        return info;
    }

    void HideUI::DrawMain()
    {
        ConfigWidget(f_Enabled, "Hide in-game UI.");
        if (f_Enabled)
        {
            ImGui::Indent();
            ConfigWidget("Hide Status", f_HideStatus, "Hide feature from status window");
            ImGui::Unindent();
        }
    }

    bool HideUI::NeedStatusDraw() const
    {
        return !f_HideStatus && f_Enabled;
    }

    void HideUI::DrawStatus()
    {
        ImGui::Text("HideUI");
    }

    HideUI& HideUI::GetInstance()
    {
        static HideUI instance;
        return instance;
    }

    void HideUI::OnGameUpdate()
    {
        if (f_Enabled)
        {
            if (ui_camera == nullptr)
                ui_camera = app::GameObject_Find(string_to_il2cppi("/UICamera"), nullptr);

            
            if (ui_camera)
                app::GameObject_SetActive(ui_camera, false, nullptr);
        }
        else
        {
            if (ui_camera)
                app::GameObject_SetActive(ui_camera, true, nullptr);
        }
    }
}