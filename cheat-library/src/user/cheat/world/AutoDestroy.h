#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class AutoDestroy : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_DestroyOres;
		config::Field<config::Toggle<Hotkey>> f_DestroyShields;
		config::Field<config::Toggle<Hotkey>> f_DestroyDoodads;
		config::Field<float> f_Range;
		config::Field<bool> f_HideStatus;

		static AutoDestroy& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	
	private:
		AutoDestroy();
	};
}

