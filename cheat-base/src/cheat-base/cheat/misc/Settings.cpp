#include <pch.h>
#include "Settings.h"

#include <cheat-base/render/gui-util.h>
#include <cheat-base/render/renderer.h>
#include <cheat-base/cheat/CheatManagerBase.h>

namespace cheat::feature 
{
    Settings::Settings() : Feature(),
		NF(f_MenuKey, "Show Cheat Menu Key", "General", Hotkey(VK_F1)),
		NF(f_HotkeysEnabled, "Hotkeys Enabled", "General", true),
		NF(f_FontSize, "Font size", "General", 16.0f),

		NF(f_StatusMove, "Move Status Window", "General::StatusWindow", true),
		NF(f_StatusShow, "Show Status Window", "General::StatusWindow", true),
		
		NF(f_InfoMove,   "Move Info Window", "General::InfoWindow", true),
		NF(f_InfoShow,   "Show Info Window", "General::InfoWindow", true),
		
		NF(f_FpsMove, "Move FPS Indicator", "General::FPS", false),
		NF(f_FpsShow, "Show FPS Indicator", "General::FPS", true),

		NF(f_NotificationsShow, "Show Notifications", "General::Notify", true), 
		NF(f_NotificationsDelay, "Notifications Delay", "General::Notify", 500),
  
		NF(f_FileLogging,    "File Logging",    "General::Logging", false),
		NF(f_ConsoleLogging, "Console Logging", "General::Logging", true),

		NF(f_FastExitEnable, "Fast Exit", "General::FastExit", false),
		NF(f_HotkeyExit, "Hotkeys", "General::FastExit", Hotkey(VK_F12))
		
    {
		renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
		f_HotkeyExit.value().PressedEvent += MY_METHOD_HANDLER(Settings::OnExitKeyPressed);
    }

    const FeatureGUIInfo& Settings::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "Settings", false };
        return info;
    }

	void Settings::DrawMain()
	{

		ImGui::BeginGroupPanel("General");
		{
			ConfigWidget(f_MenuKey, false,
				"Key to toggle main menu visibility. Cannot be empty.\n"\
				"If you forget this key, you can see or set it in your config file.");
			ConfigWidget(f_HotkeysEnabled, "Enable hotkeys.");
			if (ConfigWidget(f_FontSize, 1, 8, 64, "Font size for cheat interface."))
			{
				f_FontSize = std::clamp(f_FontSize.value(), 8, 64);
				renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Logging");
		{
			bool consoleChanged = ConfigWidget(f_ConsoleLogging,
				"Enable console for logging information (changes will take effect after relaunch)");
			if (consoleChanged && !f_ConsoleLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::ConsoleLogger);
			}

			bool fileLogging = ConfigWidget(f_FileLogging,
				"Enable file logging (changes will take effect after relaunch).\n" \
				"A folder in the app directory will be created for logs.");
			if (fileLogging && !f_FileLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::FileLogger);
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Status Window");
		{
			ConfigWidget(f_StatusShow);
			ConfigWidget(f_StatusMove, "Allow moving of 'Status' window.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Info Window");
		{
			ConfigWidget(f_InfoShow);
			ConfigWidget(f_InfoMove, "Allow moving of 'Info' window.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("FPS indicator");
		{
			ConfigWidget(f_FpsShow);
			ConfigWidget(f_FpsMove, "Allow moving of 'FPS Indicator' window.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Show Notifications");
		{
			ConfigWidget(f_NotificationsShow, "Notifications on the bottom-right corner of the window will be displayed.");
			ConfigWidget(f_NotificationsDelay, 1,1,10000, "Delay in milliseconds between notifications.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel("Fast Exit");
		{
			ConfigWidget("Enabled",
				f_FastExitEnable,
				"Enable Fast Exit.\n" 
			);
			if (!f_FastExitEnable)
				ImGui::BeginDisabled();

			ConfigWidget("Key", f_HotkeyExit, true,
				"Key to exit the game.");

			if (!f_FastExitEnable)
				ImGui::EndDisabled();
		}
		ImGui::EndGroupPanel();
	}

    Settings& Settings::GetInstance()
    {
        static Settings instance;
        return instance;
    }

	void Settings::OnExitKeyPressed()
	{
		if (!f_FastExitEnable || CheatManagerBase::IsMenuShowed())
			return;

		ExitProcess(0);
	}
}

