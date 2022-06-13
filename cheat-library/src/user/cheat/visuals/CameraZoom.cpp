#include "pch-il2cpp.h"
#include "CameraZoom.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    static void SCameraModuleInitialize_SetWarningLocateRatio_Hook(app::SCameraModuleInitialize* __this, double deltaTime, app::CameraShareData* data, MethodInfo* method);

    CameraZoom::CameraZoom() : Feature(),
        NF(f_Enabled, "Camera Zoom", "Visuals::CameraZoom", false),
        NF(f_Zoom, "Zoom", "Visuals::CameraZoom", 200)
    {
        HookManager::install(app::MoleMole_SCameraModuleInitialize_SetWarningLocateRatio, SCameraModuleInitialize_SetWarningLocateRatio_Hook);
    }

    const FeatureGUIInfo& CameraZoom::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "CameraZoom", "Visuals", false };
        return info;
    }

    void CameraZoom::DrawMain()
    {
        ConfigWidget("", f_Enabled); ImGui::SameLine();
        ConfigWidget("Camera Zoom", f_Zoom, 0.01f, 1.0f, 500.0f, "Custom camera zooming.\n"
            "Specified value is multiplier for default zoom distance.\n"
			"For example:\n"
            "\t2.0 = 2.0 * defaultZoom"
        );
    }

    bool CameraZoom::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void CameraZoom::DrawStatus()
    {
        ImGui::Text("Camera zoom [%.1fx]", f_Zoom.value());
    }

    CameraZoom& CameraZoom::GetInstance()
    {
        static CameraZoom instance;
        return instance;
    } 

    void SCameraModuleInitialize_SetWarningLocateRatio_Hook(app::SCameraModuleInitialize* __this, double deltaTime, app::CameraShareData* data, MethodInfo* method)
    {
        CameraZoom& cameraZoom = CameraZoom::GetInstance();
        if (cameraZoom.f_Enabled)
        {
            data->currentWarningLocateRatio= static_cast<double>(cameraZoom.f_Zoom);
            //data->isRadiusSqueezing;
        }
        else
            data->currentWarningLocateRatio = 1.0;
        
        CALL_ORIGIN(SCameraModuleInitialize_SetWarningLocateRatio_Hook, __this, deltaTime, data, method);
    }
}

