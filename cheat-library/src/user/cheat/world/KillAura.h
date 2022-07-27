#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class KillAura : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_DamageMode;
		config::Field<config::Toggle<Hotkey>> f_InstantDeathMode;
		config::Field<bool> f_HideStatus;
		config::Field<bool> f_OnlyTargeted;
		config::Field<float> f_Range;
		config::Field<int> f_AttackDelay;
		config::Field<int> f_RepeatDelay;

		static KillAura& GetInstance();

		void OnGameUpdate();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	
	private:
		KillAura();
	};
}

