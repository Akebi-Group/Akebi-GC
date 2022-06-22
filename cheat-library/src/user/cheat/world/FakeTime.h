#pragma once
namespace cheat::feature
{

	class FakeTime : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<int> f_TimeHour;
		config::Field<int> f_TimeMinute;

		static FakeTime& GetInstance();
		void OnGameUpdate();
		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	private:
		static void LevelTimeManager_SetInternalTimeOfDay_Hook(void* __this, float inHours, bool force, bool refreshEnviroTime, MethodInfo* method);
		float ConversionTime();
		FakeTime();
	};
}