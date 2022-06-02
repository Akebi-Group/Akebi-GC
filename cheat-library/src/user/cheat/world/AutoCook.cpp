#include "pch-il2cpp.h"
#include "AutoCook.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    static void PlayerModule_RequestPlayerCook(app::MoleMole_PlayerModule* __this, uint32_t recipeId, uint32_t avatarId, uint32_t qteQuality, uint32_t count, MethodInfo* method); 
    static void PlayerModule_OnPlayerCookRsp(app::MoleMole_PlayerModule* __this, app::PlayerCookRsp* rsp, MethodInfo* method);

    static void CookingQtePageContext_UpdateProficiency(app::CookingQtePageContext* __this, MethodInfo* method);
    static void CookingQtePageContext_SetProficiencyInfo(app::CookingQtePageContext* __this, MethodInfo* method);
    static uint32_t CookRecipeExcelConfig_get_maxProficiency(app::CookRecipeExcelConfig* __this, MethodInfo* method);

    AutoCook::AutoCook() : Feature(),
        NF(f_Enabled, "Auto Cooking", "AutoCook", false),
        NF(f_Count, "Count Item", "AutoCook", 1),
        NF(f_Quality, "Quality", "AutoCook", 1)
    {
        HookManager::install(app::MoleMole_PlayerModule_RequestPlayerCook, PlayerModule_RequestPlayerCook);
        HookManager::install(app::MoleMole_PlayerModule_OnPlayerCookRsp, PlayerModule_OnPlayerCookRsp); 
        HookManager::install(app::MoleMole_CookingQtePageContext_UpdateProficiency, CookingQtePageContext_UpdateProficiency);
        HookManager::install(app::CookRecipeExcelConfig_get_maxProficiency, CookRecipeExcelConfig_get_maxProficiency);
    }

    const FeatureGUIInfo& AutoCook::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "AutoCook", "World", true };
        return info;
    }

    void AutoCook::DrawMain()
    {
        ConfigWidget(f_Enabled, "Automatic cooking.");
        ConfigWidget("Count Item", f_Count, 1, 1, 100,
            "How much to cook at a time.\n" \
            "(If the recipe is not fully explored, set it to 1.)");
        ConfigWidget("Quality Cooking", f_Quality, 1, 1, 3, "Quality of the cook.");
    }

    bool AutoCook::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void AutoCook::DrawStatus()
    {
        ImGui::Text("Auto Cook");
    }

    AutoCook& AutoCook::GetInstance()
    {
        static AutoCook instance;
        return instance;
    }

    // Auto Cooking | RyujinZX#6666

    static void PlayerModule_RequestPlayerCook(app::MoleMole_PlayerModule* __this, uint32_t recipeId, uint32_t avatarId, uint32_t qteQuality, uint32_t count, MethodInfo* method)
    {
        AutoCook& autoCook = AutoCook::GetInstance();
        if (autoCook.f_Enabled)
        {
            qteQuality = autoCook.f_Quality;
            count = autoCook.f_Count;
        }

        return CALL_ORIGIN(PlayerModule_RequestPlayerCook, __this, recipeId, avatarId, qteQuality, count, method);
    }

    static void PlayerModule_OnPlayerCookRsp(app::MoleMole_PlayerModule* __this, app::PlayerCookRsp* rsp, MethodInfo* method) { 
        AutoCook& autoCook = AutoCook::GetInstance();
        if (autoCook.f_Enabled)
        {
            rsp->fields.qteQuality_ = autoCook.f_Quality;
            rsp->fields.cookCount_ = autoCook.f_Count;

            // Unlock Quick Cooking, It will reset after a restart, so it is better to study the recipe in full at once.
            if (rsp->fields.recipeData_ != nullptr)
                rsp->fields.recipeData_->fields.proficiency_ = autoCook.CookCount;  
        }

        return CALL_ORIGIN(PlayerModule_OnPlayerCookRsp, __this, rsp, method);
    }

    static void CookingQtePageContext_UpdateProficiency(app::CookingQtePageContext* __this, MethodInfo* method) {
        AutoCook& autoCook = AutoCook::GetInstance();
        if (autoCook.f_Enabled)
        {
            __this->fields._pageMono->fields._qteTime = 0;
            __this->fields._pageMono->fields._autoQteTime = 0;
        }

        return CALL_ORIGIN(CookingQtePageContext_UpdateProficiency, __this, method);
    }

    static uint32_t CookRecipeExcelConfig_get_maxProficiency(app::CookRecipeExcelConfig* __this, MethodInfo* method) {
        AutoCook& autoCook = AutoCook::GetInstance();
        if (autoCook.f_Enabled)
        {
            uint32_t maxCount = app::MoleMole_SimpleSafeUInt32_get_Value(__this->fields.maxProficiencyRawNum, nullptr);
            autoCook.CookCount = maxCount;
        }
        return CALL_ORIGIN(CookRecipeExcelConfig_get_maxProficiency, __this, method);
    }   
}