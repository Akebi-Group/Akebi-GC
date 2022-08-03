#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature
{

	class AnimationChanger : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<std::string> f_Animation;
		config::Field<Hotkey> f_ApplyKey;
		config::Field<Hotkey> f_ResetKey;

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
		static AnimationChanger& GetInstance();
		void OnGameUpdate();

	private:
		SafeQueue<uint32_t> toBeUpdate;
		SafeValue<int64_t> nextUpdate;
		int f_DelayUpdate = 500;
		AnimationChanger();
	};
}

