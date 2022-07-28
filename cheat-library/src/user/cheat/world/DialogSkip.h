#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature
{

	class DialogSkip : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<Hotkey>> f_AutoSelectDialog;
		config::Field<config::Toggle<Hotkey>> f_ExcludeImportant;
		config::Field<config::Toggle<Hotkey>> f_FastDialog;
		config::Field<config::Toggle<Hotkey>> f_CutsceneUSM;
		config::Field<float> f_TimeSpeedup;
		config::Field<bool> f_GameSpeedEnabled;
		config::Field<Hotkey> f_GameSpeedKey;
		config::Field<float> f_GameSpeedVal;

		static DialogSkip& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();
		void OnCutScenePageUpdate(app::InLevelCutScenePageContext* context);

	private:
		DialogSkip();
	};
}

