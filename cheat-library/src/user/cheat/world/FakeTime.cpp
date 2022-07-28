#include "pch-il2cpp.h"
#include "FakeTime.h"
#include <cheat/events.h>


namespace cheat::feature
{
	//CNLouisLiu
	void* LevelTimeManager = NULL;
	FakeTime::FakeTime() : Feature(),
		NF(f_Enabled, "FakeTime", u8"启用", false),
		NF(f_TimeHour,  "FakeTime", u8"小时", 12),
		NF(f_TimeMinute, "FakeTime", u8"分钟", 0)
	{
		HookManager::install(app::LevelTimeManager_SetInternalTimeOfDay, LevelTimeManager_SetInternalTimeOfDay_Hook);

		events::GameUpdateEvent += MY_METHOD_HANDLER(FakeTime::OnGameUpdate);
	}
	FakeTime& FakeTime::GetInstance()
	{
		static FakeTime instance;
		return instance;
	}
	const FeatureGUIInfo& FakeTime::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ u8"锁定时间", u8"世界", true };
		return info;
	}
	void FakeTime::DrawMain()
	{
		ConfigWidget(u8"启用", f_Enabled, "保持游戏时间不变");
		ConfigWidget(u8"小时", f_TimeHour, 1, 0, 24);
		ConfigWidget(u8"分钟", f_TimeMinute, 1, 0, 60);
	}
	bool FakeTime::NeedStatusDraw() const
	{
		return f_Enabled;
	}
	void FakeTime::DrawStatus()
	{
		ImGui::Text(u8"锁定时间|%d:%d", f_TimeHour.value(), f_TimeMinute.value());
	}
	float FakeTime::ConversionTime() {

		float time = float(f_TimeHour);
		float timemin = f_TimeMinute / 60;
		return time + timemin;
	}
	void FakeTime::OnGameUpdate()
	{
		if (LevelTimeManager != NULL && f_Enabled) {
			auto& faketime = GetInstance();
			CALL_ORIGIN(LevelTimeManager_SetInternalTimeOfDay_Hook, LevelTimeManager, faketime.ConversionTime(), false, false, (MethodInfo*)0);
		}
	}
	void FakeTime::LevelTimeManager_SetInternalTimeOfDay_Hook(void* __this, float inHours, bool force, bool refreshEnviroTime, MethodInfo* method) {
		float Hours = inHours;
		auto& faketime = GetInstance();
		if (faketime.f_Enabled)
		{
			Hours = faketime.ConversionTime();
		}
		CALL_ORIGIN(LevelTimeManager_SetInternalTimeOfDay_Hook, __this, Hours, force, refreshEnviroTime, method);

	}

}