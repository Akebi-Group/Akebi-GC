#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <il2cpp-appdata.h>

namespace cheat::feature 
{

	class NoClip : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_NoAnimation;

		config::Field<float> f_Speed;
		config::Field<bool> f_CameraRelative;
		config::Field<config::Toggle<Hotkey>> f_VelocityMode;
		config::Field<config::Toggle<Hotkey>> f_FreeflightMode;

		config::Field<bool> f_AltSpeedEnabled;
		config::Field<float> f_AltSpeed;


		static NoClip& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();
		void OnMoveSync(uint32_t entityId, app::MotionInfo* syncInfo);
	private:
		NoClip();
	};
}

