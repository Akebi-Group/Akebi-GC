#include "pch-il2cpp.h"
#include "MusicEvent.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{

    static void MusicGamePlayComponent_OnStart_Hook(app::MusicGamePlayComponent* __this, app::BeatMapData* beatMapData, app::MusicMetaInfo* musicMetaInfo, MethodInfo* method);
    static void MusicGamePlayComponent_OnMiss_Hook(app::MusicGamePlayComponent* __this, MethodInfo* method);
    static void MusicGamePlayComponent_set_combo_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method);
    static void MusicGamePlayComponent_set_score_Hook(app::MusicGamePlayComponent* __this, float value, MethodInfo* method);
    static void MusicGamePlayComponent_set_maxCombo_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method);
    static void MusicGamePlayComponent_set_perfectCnt_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method);
    static void MusicGamePlayComponent_set_greatCnt_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method);
    static void MusicGamePlayComponent_set_missCnt_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method);
    static void MusicGamePlayComponent_OnHit_Hook(app::MusicGamePlayComponent* __this, float score, MethodInfo* method);

    MusicEvent::MusicEvent() : Feature(),
        NF(f_Enabled, "Music Event", "MusicEvent", false)
    {
        //HookManager::install(app::MusicGamePlayComponent_OnStart, MusicGamePlayComponent_OnStart_Hook);
        HookManager::install(app::MusicGamePlayComponent_OnMiss, MusicGamePlayComponent_OnMiss_Hook);
        HookManager::install(app::MusicGamePlayComponent_set_combo, MusicGamePlayComponent_set_combo_Hook);
        HookManager::install(app::MusicGamePlayComponent_set_score, MusicGamePlayComponent_set_score_Hook);
        HookManager::install(app::MusicGamePlayComponent_set_maxCombo, MusicGamePlayComponent_set_maxCombo_Hook);
        HookManager::install(app::MusicGamePlayComponent_set_perfectCnt, MusicGamePlayComponent_set_perfectCnt_Hook);
        HookManager::install(app::MusicGamePlayComponent_set_greatCnt, MusicGamePlayComponent_set_greatCnt_Hook);
        HookManager::install(app::MusicGamePlayComponent_set_missCnt, MusicGamePlayComponent_set_missCnt_Hook);
        HookManager::install(app::MusicGamePlayComponent_OnHit, MusicGamePlayComponent_OnHit_Hook);
    }

    const FeatureGUIInfo& MusicEvent::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "World", false };
        return info;
    }

    void MusicEvent::DrawMain()
    {
        ConfigWidget(f_Enabled, "Enemies don't attack or use abilities against player. \n"
            "May not work with some enemies or enemy abilites.");
    }

    bool MusicEvent::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void MusicEvent::DrawStatus()
    {
        ImGui::Text("Music Event");
    }

    MusicEvent& MusicEvent::GetInstance()
    {
        static MusicEvent instance;
        return instance;
    }

    static void MusicGamePlayComponent_OnStart_Hook(app::MusicGamePlayComponent * __this, app::BeatMapData* beatMapData, app::MusicMetaInfo* musicMetaInfo, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            __this->fields._combo = 9999999;
            __this->fields._score_k__BackingField = 9999999;
            __this->fields._maxCombo_k__BackingField = 9999999;
            __this->fields._perfectCnt_k__BackingField = 9999999;
            __this->fields._greatCnt_k__BackingField = 9999999;
            __this->fields._missCnt_k__BackingField = 0;
        }
        CALL_ORIGIN(MusicGamePlayComponent_OnStart_Hook, __this, beatMapData, musicMetaInfo, method);
    }

    static void MusicGamePlayComponent_OnMiss_Hook(app::MusicGamePlayComponent* __this, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            return;
        }
        CALL_ORIGIN(MusicGamePlayComponent_OnMiss_Hook, __this, method);
    }

    static void MusicGamePlayComponent_set_combo_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            value = 999999999;
        }
        CALL_ORIGIN(MusicGamePlayComponent_set_combo_Hook, __this, value, method);
    }

    static void MusicGamePlayComponent_set_score_Hook(app::MusicGamePlayComponent* __this, float value, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            value = 999999999;
        }
        CALL_ORIGIN(MusicGamePlayComponent_set_score_Hook, __this, value, method);
    }
    static void MusicGamePlayComponent_set_maxCombo_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            value = 999999999;
        }
        CALL_ORIGIN(MusicGamePlayComponent_set_maxCombo_Hook, __this, value, method);
    }
    static void MusicGamePlayComponent_set_perfectCnt_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            value = 999999999;
        }
        CALL_ORIGIN(MusicGamePlayComponent_set_perfectCnt_Hook, __this, value, method);
    }
    static void MusicGamePlayComponent_set_greatCnt_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            value = 999999999;
        }
        CALL_ORIGIN(MusicGamePlayComponent_set_greatCnt_Hook, __this, value, method);
    }
    static void MusicGamePlayComponent_set_missCnt_Hook(app::MusicGamePlayComponent* __this, uint32_t value, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            value = 0;
        }
        CALL_ORIGIN(MusicGamePlayComponent_set_missCnt_Hook, __this, value, method);
    }
    static void MusicGamePlayComponent_OnHit_Hook(app::MusicGamePlayComponent* __this, float score, MethodInfo* method)
    {
        MusicEvent& MusicEvent = MusicEvent::GetInstance();
        if (MusicEvent.f_Enabled)
        {
            score = 999999999;
        }
        CALL_ORIGIN(MusicGamePlayComponent_OnHit_Hook, __this, score, method);
    }
}

