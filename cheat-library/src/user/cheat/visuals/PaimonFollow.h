#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature
{
	class PaimonFollow : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		static PaimonFollow& GetInstance();
		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	private:
		SafeQueue<uint32_t> toBeUpdate;
		SafeValue<int64_t> nextUpdate;
		int f_DelayUpdate = 100.f;

		void OnGameUpdate();
		PaimonFollow();
	};
}