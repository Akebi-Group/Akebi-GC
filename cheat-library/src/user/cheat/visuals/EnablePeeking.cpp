#include "pch-il2cpp.h"
#include "EnablePeeking.h"

#include <helpers.h>

namespace cheat::feature
{
    static void MoleMole_VCBaseSetDitherValue_set_ManagerDitherAlphaValue_Hook(app::MoleMole_VCBaseSetDitherValue* __this, float value, MethodInfo* method);

    EnablePeeking::EnablePeeking() : Feature(),
        NF(f_Enabled, "Enable Peeking", "Visuals::EnablePeeking", false),
        NF(f_HideStatus, "Hide Status", "Visuals::EnablePeeking", false)
    {
        HookManager::install(app::MoleMole_VCBaseSetDitherValue_set_ManagerDitherAlphaValue, MoleMole_VCBaseSetDitherValue_set_ManagerDitherAlphaValue_Hook);
    }

    const FeatureGUIInfo& EnablePeeking::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "EnablePeeking", "Visuals", false };
        return info;
    }

    void EnablePeeking::DrawMain()
    {
        ConfigWidget(f_Enabled, ";)");
        if (f_Enabled)
        {
            ImGui::Indent();
            ConfigWidget("Hide Status", f_HideStatus, "Hide feature from status window");
            ImGui::Unindent();
        }
    }

    bool EnablePeeking::NeedStatusDraw() const
    {
        return !f_HideStatus && f_Enabled;
    }

    void EnablePeeking::DrawStatus()
    {
        ImGui::Text("Enable Peeking");
    }

    EnablePeeking& EnablePeeking::GetInstance()
    {
        static EnablePeeking instance;
        return instance;
    }

    static void MoleMole_VCBaseSetDitherValue_set_ManagerDitherAlphaValue_Hook(app::MoleMole_VCBaseSetDitherValue* __this, float value, MethodInfo* method)
    {
        EnablePeeking& EnablePeeking = EnablePeeking::GetInstance();
        if (EnablePeeking.f_Enabled)
            value = 1;

        CALL_ORIGIN(MoleMole_VCBaseSetDitherValue_set_ManagerDitherAlphaValue_Hook, __this, value, method);
    }
}

