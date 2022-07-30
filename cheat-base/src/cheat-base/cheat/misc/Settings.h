#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class Settings : public Feature
    {
	public:
		config::Field<Hotkey> f_MenuKey;
		config::Field<bool> f_HotkeysEnabled;
		config::Field<int> f_FontSize;
		config::Field<bool> f_ShowStyleEditor;

		config::Field<bool> f_StatusMove;
		config::Field<bool> f_StatusShow;

		config::Field<bool> f_InfoMove;
		config::Field<bool> f_InfoShow;
		
		config::Field<bool> f_FpsShow;
		config::Field<bool> f_FpsMove;
    
		config::Field<bool> f_NotificationsShow;
		config::Field<int> f_NotificationsDelay;

		config::Field<bool> f_ConsoleLogging;
		config::Field<bool> f_FileLogging;

		config::Field<bool> f_FastExitEnable;
		config::Field<Hotkey> f_HotkeyExit;

		static Settings& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
	
	private:

		void OnExitKeyPressed();
		Settings();
	};
}

