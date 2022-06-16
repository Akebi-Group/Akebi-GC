#include "pch-il2cpp.h"
#include "Browser.h"

#include <helpers.h>
#include <cheat/events.h>
#include <misc/cpp/imgui_stdlib.h>

namespace cheat::feature
{
    app::GameObject* planeObject = nullptr;
    app::Component_1* BrowserComponents = nullptr;
    static std::string f_URL;

    Browser::Browser() : Feature(),
        NFEX(f_Enabled, "Browser", "Browser", "Visuals", false, false),
        toBeUpdate(), nextUpdate(0)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(Browser::OnGameUpdate);
    }

    const FeatureGUIInfo& Browser::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "Browser", "Visuals", false };
        return info;
    }

    void Browser::DrawMain()
    {
        ConfigWidget(f_Enabled, "Create in-game Browser");
        ImGui::InputText("URL", &f_URL);
    }

    bool Browser::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void Browser::DrawStatus()
    {
        ImGui::Text("Browser");
    }

    Browser& Browser::GetInstance()
    {
        static Browser instance;
        return instance;
    }

    void Browser::OnGameUpdate()
    {
        auto currentTime = util::GetCurrentTimeMillisec();
        if (currentTime < nextUpdate)
            return;

        if (f_Enabled) {
            auto entityRoot = app::GameObject_Find(string_to_il2cppi("EntityRoot/AvatarRoot/"), nullptr);
            if (!app::GameObject_get_active(entityRoot, nullptr))
                return;

            if (planeObject == nullptr) {
                auto PrimitiveType = app::PrimitiveType__Enum::Plane;
                planeObject = app::GameObject_CreatePrimitive(PrimitiveType, nullptr);

                app::Transform* planeObject_Transform = app::GameObject_get_transform(planeObject, nullptr);
                app::Quaternion planeObject_Transform_Quaternion = { 0.5, 0.5, -0.5, 0.5 };

                auto avatarPos = app::ActorUtils_GetAvatarPos(nullptr);
                auto relativePos = app::WorldShiftManager_GetRelativePosition(avatarPos, nullptr);
                app::Vector3 planeObject_Transform_Vector3 = { relativePos.x, relativePos.y + 3, relativePos.z };
                app::Vector3 planeObject_Transform_Scale = { 1, 1, 1 };

                app::Transform_set_localPosition(planeObject_Transform, planeObject_Transform_Vector3, nullptr);
                app::Transform_set_localScale(planeObject_Transform, planeObject_Transform_Scale, nullptr);
                app::Transform_set_localRotation(planeObject_Transform, planeObject_Transform_Quaternion, nullptr);
            }

            if (planeObject != nullptr) {
                if (BrowserComponents == nullptr) {
                    std::string custom_url = f_URL.length() < 2 || f_URL.c_str() == "" ? "https://www.google.com/" : f_URL.c_str();

                    BrowserComponents = app::GameObject_AddComponentInternal(planeObject, string_to_il2cppi("Browser"), nullptr);
                    reinterpret_cast<app::Browser*>(BrowserComponents)->fields._url = string_to_il2cppi(custom_url);
                    reinterpret_cast<app::Browser*>(BrowserComponents)->fields._width = 1920;
                    reinterpret_cast<app::Browser*>(BrowserComponents)->fields._height = 1080;
                    reinterpret_cast<app::Browser*>(BrowserComponents)->fields.forceNextRender = true;
                    reinterpret_cast<app::Browser*>(BrowserComponents)->fields._EnableInput_k__BackingField = true;
                }
            }
        }
        else {
            if (planeObject != nullptr && BrowserComponents != nullptr) {
                app::Object_1_DestroyImmediate_1(reinterpret_cast<app::Object_1*>(planeObject), nullptr);
                app::Object_1_DestroyImmediate_1(reinterpret_cast<app::Object_1*>(BrowserComponents), nullptr);
                planeObject = nullptr;
                BrowserComponents = nullptr;
            }
        }
        nextUpdate = currentTime + (int)f_DelayUpdate;
    }
}