#include "pch-il2cpp.h"
#include "NoCD.h"

#include <helpers.h>
#include <fmt/chrono.h>

namespace cheat::feature 
{
	static bool HumanoidMoveFSM_CheckSprintCooldown_Hook(void* __this, MethodInfo* method);
	static bool LCAvatarCombat_IsEnergyMax_Hook(void* __this, MethodInfo* method);
	static bool LCAvatarCombat_OnSkillStart(app::LCAvatarCombat* __this, uint32_t skillID, float cdMultipler, MethodInfo* method);
	static bool LCAvatarCombat_IsSkillInCD_1(app::LCAvatarCombat* __this, app::LCAvatarCombat_LCAvatarCombat_SkillInfo* skillInfo, MethodInfo* method);

	static void ActorAbilityPlugin_AddDynamicFloatWithRange_Hook(void* __this, app::String* key, float value, float minValue, float maxValue,
		bool forceDoAtRemote, MethodInfo* method);
	 
	static std::list<std::string> abilityLog;

    NoCD::NoCD() : Feature(),
        NF(f_AbilityReduce, u8"减少技能/元素爆发冷却",  "NoCD", false),
		NF(f_TimerReduce, u8"减少计数",        "NoCD", 1.f),
		NF(f_UtimateMaxEnergy, u8"元素爆发满能量",             "NoCD", false),
        NF(f_Sprint, u8"取消冲刺冷却",           "NoCD", false),
		NF(f_InstantBow, u8"无限蓄力弓",                  "NoCD", false)
    {
		HookManager::install(app::MoleMole_LCAvatarCombat_IsEnergyMax, LCAvatarCombat_IsEnergyMax_Hook);
		HookManager::install(app::MoleMole_LCAvatarCombat_IsSkillInCD_1, LCAvatarCombat_IsSkillInCD_1);

		HookManager::install(app::MoleMole_HumanoidMoveFSM_CheckSprintCooldown, HumanoidMoveFSM_CheckSprintCooldown_Hook);
		HookManager::install(app::MoleMole_ActorAbilityPlugin_AddDynamicFloatWithRange, ActorAbilityPlugin_AddDynamicFloatWithRange_Hook);
    }

    const FeatureGUIInfo& NoCD::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ u8"冷却效果", u8"玩家", true };
        return info;
    }

    void NoCD::DrawMain()
    {
		ConfigWidget(u8"满元素爆发能量", f_UtimateMaxEnergy,
			u8"消除元素爆发的能量需求。\n" \
			u8"（元素爆发指示可能看起来不充满，但仍然可用。）");

		ConfigWidget(u8"## 减少冷却", f_AbilityReduce); ImGui::SameLine();
		ConfigWidget(u8"减少技能/爆发冷却时间", f_TimerReduce, 1.f, 1.f, 6.0f,
			u8"减少元素技能和爆发的冷却时间。\n"\
			u8"1.0-无CD，2.0及更高-增加计时器值。");

    	ConfigWidget(f_Sprint, u8"消除冲刺之间的延迟。");

    	ConfigWidget(u8"无限蓄力弓", f_InstantBow, u8"禁用弓箭蓄力冷却\n" \
			u8"菲谢尔的已知无效。");

    	if (f_InstantBow) {
			ImGui::Text(u8"如果此功能无效");
			TextURL(u8"请点击这里去Github进行反馈", "https://github.com/Akebi-Group/Akebi-GC/issues/281", false, false);
			if (ImGui::TreeNode(u8"能力日志 [调试]"))
			{
				if (ImGui::Button(u8"复制"))
				{
					ImGui::LogToClipboard();

					ImGui::LogText(u8"能力日志:\n");

					for (auto& logEntry : abilityLog)
						ImGui::LogText("%s\n", logEntry.c_str());

					ImGui::LogFinish();
				}

				for (std::string& logEntry : abilityLog)
					ImGui::Text(logEntry.c_str());

				ImGui::TreePop();
			}
		}
    }

    bool NoCD::NeedStatusDraw() const
{
        return f_InstantBow || f_AbilityReduce || f_Sprint ;
    }

    void NoCD::DrawStatus() 
    {
		  ImGui::Text(u8"冷却\n[%s%s%s%s%s]",
			f_AbilityReduce ? fmt::format(u8"减少 x{:.1f}", f_TimerReduce.value()).c_str() : "",
			f_AbilityReduce && (f_InstantBow || f_Sprint) ? "|" : "",
			f_InstantBow ? u8"弓" : "",
			f_InstantBow && f_Sprint ? "|" : "",
			f_Sprint ? u8"冲刺" : "");
    }

    NoCD& NoCD::GetInstance()
    {
        static NoCD instance;
        return instance;
    }

	static bool LCAvatarCombat_IsEnergyMax_Hook(void* __this, MethodInfo* method)
	{
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_UtimateMaxEnergy)
			return true;

		return CALL_ORIGIN(LCAvatarCombat_IsEnergyMax_Hook, __this, method);
	}

	// Multipler CoolDown Timer Old | RyujinZX#6666
	static bool LCAvatarCombat_OnSkillStart(app::LCAvatarCombat* __this, uint32_t skillID, float cdMultipler, MethodInfo* method) {
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_AbilityReduce)
		{
			if (__this->fields._targetFixTimer->fields._._timer_k__BackingField > 0) {
				cdMultipler = noCD.f_TimerReduce / 3;
			}
			else {
				cdMultipler = noCD.f_TimerReduce / 1;
			}
		}		
		return CALL_ORIGIN(LCAvatarCombat_OnSkillStart, __this, skillID, cdMultipler, method);
	}

	// Timer Speed Up / CoolDown Reduce New | RyujinZX#6666
	static bool LCAvatarCombat_IsSkillInCD_1(app::LCAvatarCombat* __this, app::LCAvatarCombat_LCAvatarCombat_SkillInfo* skillInfo, MethodInfo* method) {
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_AbilityReduce)
		{
			auto cdTimer = app::MoleMole_SafeFloat_get_Value(skillInfo->fields.cdTimer, nullptr); // Timer start value in the game

			if (cdTimer > noCD.f_TimerReduce)
			{
				struct app::SafeFloat MyValueProtect = app::MoleMole_SafeFloat_set_Value(noCD.f_TimerReduce - 1.0f, nullptr); // Subtract -1 from the current timer value
				skillInfo->fields.cdTimer = MyValueProtect; 
			}
		}
		return CALL_ORIGIN(LCAvatarCombat_IsSkillInCD_1, __this, skillInfo, method);
	}

	// Check sprint cooldown, we just return true if sprint no cooldown enabled.
	static bool HumanoidMoveFSM_CheckSprintCooldown_Hook(void* __this, MethodInfo* method)
	{
		NoCD& noCD = NoCD::GetInstance();
		if (noCD.f_Sprint)
			return true;

		return CALL_ORIGIN(HumanoidMoveFSM_CheckSprintCooldown_Hook, __this, method);
	}

	// This function raise when abilities, whose has charge, is charging, like a bow.
	// value - increase value
	// min and max - bounds of charge.
	// So, to charge make full charge m_Instantly, just replace value to maxValue.
	static void ActorAbilityPlugin_AddDynamicFloatWithRange_Hook(void* __this, app::String* key, float value, float minValue, float maxValue,
		bool forceDoAtRemote, MethodInfo* method)
	{
		std::time_t t = std::time(nullptr);
		auto logEntry = fmt::format("{:%H:%M:%S} | Key: {} value {}.", fmt::localtime(t), il2cppi_to_string(key), value);
		abilityLog.push_front(logEntry);
		if (abilityLog.size() > 50)
			abilityLog.pop_back();

		NoCD& noCD = NoCD::GetInstance();
		// This function is calling not only for bows, so if don't put key filter it cause various game mechanic bugs.
		// For now only "_Enchanted_Time" found for bow charging, maybe there are more. Need to continue research.
		if (noCD.f_InstantBow && il2cppi_to_string(key) == "_Enchanted_Time")
			value = maxValue;
		CALL_ORIGIN(ActorAbilityPlugin_AddDynamicFloatWithRange_Hook, __this, key, value, minValue, maxValue, forceDoAtRemote, method);
	}
}

