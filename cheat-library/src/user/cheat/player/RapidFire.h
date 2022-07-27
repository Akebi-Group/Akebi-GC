#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <il2cpp-appdata.h>

namespace cheat::feature 
{

	class RapidFire : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_MultiHit;
		config::Field<int> f_Multiplier;
		config::Field<bool> f_OnePunch;
		config::Field<config::Toggle<Hotkey>> f_Randomize;
		config::Field<int> f_minMultiplier;
		config::Field<int> f_maxMultiplier;
		config::Field<config::Toggle<Hotkey>> f_MultiTarget;
		config::Field<float> f_MultiTargetRadius;
		config::Field<bool> f_HideStatus;

		static RapidFire& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	
		int GetAttackCount(app::LCBaseCombat* combat, uint32_t targetID, app::AttackResult* attackResult);
	private:
		RapidFire();
		int CalcCountToKill(float attackDamage, uint32_t targetID);
	};
}

