#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{

	class AutoCook : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_FastProficiency;

		config::Field<int> f_CountField;
		config::Field<int> f_QualityField;
		config::Field<bool> f_HideStatus;

		int CookFoodMaxNum; // Maximum quantity at a time
		int CookCount; 

		static AutoCook& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

	private:
		
		AutoCook();
	};
}

