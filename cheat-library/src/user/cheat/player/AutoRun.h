#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>


namespace cheat::feature
{
	class AutoRun : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<float> f_Speed;
		config::Field<bool> f_HideStatus;

		static AutoRun& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();

	private:
		AutoRun();
	};
}
