#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/game/Entity.h>
#include <cheat/game/filters.h>
#include <cheat-base/thread-safe.h>
#include <il2cpp-appdata.h>


namespace cheat::feature
{

	class AutoSeelie : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<bool> f_ElectroSeelie;

		static AutoSeelie& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();
	private:
		AutoSeelie();
		SafeValue<int64_t> nextTime;
		bool IsEntityForVac(cheat::game::Entity* entity);
	};
}
