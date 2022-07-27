#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class AutoTreeFarm : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> m_Enabled;
		config::Field<int> m_AttackDelay;
		config::Field<int> m_RepeatDelay;
		config::Field<int> m_AttackPerTree;
		config::Field<float> m_Range;
		config::Field<bool> m_HideStatus;

		static AutoTreeFarm& GetInstance();

		void OnGameUpdate();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	
	private:
		AutoTreeFarm();
	};
}

