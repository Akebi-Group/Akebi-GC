#include <pch.h>
#include "Settings.h"

#include <cheat-base/render/gui-util.h>
#include <cheat-base/render/renderer.h>
#include <cheat-base/cheat/CheatManagerBase.h>

namespace cheat::feature 
{
    Settings::Settings() : Feature(),
		NF(f_MenuKey, u8"显示作弊菜单键", "General", Hotkey(VK_F1)),
		NF(f_HotkeysEnabled, u8"热键启用", "General", true),
		NF(f_FontSize, u8"字体大小", "General", 16.0f),

		NF(f_StatusMove, u8"移动状态窗口", "General::StatusWindows", true),
		NF(f_StatusShow, u8"显示状态窗口", "General::StatusWindows", true),
		
		NF(f_InfoMove,   u8"移动信息窗口", "General::InfoWindows", true),
		NF(f_InfoShow, u8"显示信息窗口", "General::InfoWindows", true),
		
		NF(f_FpsMove, u8"移动FPS指示器", "General::FPS", false),
		NF(f_FpsShow, u8"显示移动FPS指示器", "General::FPS", true),

		NF(f_NotificationsShow, u8"显示提示", "General::notic", true),
		NF(f_NotificationsDelay, u8"提示周期", "General::通知", 500),
  
		NF(f_FileLogging, u8"文件日志", u8"全局::日志", false),
		NF(f_ConsoleLogging, u8"控制台日志", u8"全局::日志", true),

		NF(f_FastExitEnable, u8"快速退出", u8"全局::快速退出", false),
		NF(f_HotkeyExit, u8"热键", u8"全局::快速退出", Hotkey(VK_F12))
		
    {
		renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
		f_HotkeyExit.value().PressedEvent += MY_METHOD_HANDLER(Settings::OnExitKeyPressed);
    }

    const FeatureGUIInfo& Settings::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", u8"设置", false };
        return info;
    }

	void Settings::DrawMain()
	{

		ImGui::BeginGroupPanel(u8"全局");
		{
			ConfigWidget(f_MenuKey, false,
				u8"切换主菜单的键位，不可空\n"\
				u8"如果你忘了这个键位，你可以在配置文件中查看");
			ConfigWidget(f_HotkeysEnabled, u8"启用热键");
			if (ConfigWidget(f_FontSize, 1, 8, 64, u8"作弊界面的字体大小"))
			{
				f_FontSize = std::clamp(f_FontSize.value(), 8, 64);
				renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"日志");
		{
			bool consoleChanged = ConfigWidget(f_ConsoleLogging,
				u8"启用控制台以记录信息（更改将在重新启动后生效）");
			if (consoleChanged && !f_ConsoleLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::ConsoleLogger);
			}

			bool fileLogging = ConfigWidget(f_FileLogging,
				u8"启用文件日志记录（更改将在重新启动后生效）.\n" \
				u8"将在应用程序目录中为日志创建一个文件夹。");
			if (fileLogging && !f_FileLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::FileLogger);
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"状态窗口");
		{
			ConfigWidget(f_StatusShow);
			ConfigWidget(f_StatusMove, u8"允许移动 '状态' 窗口.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"信息窗口");
		{
			ConfigWidget(f_InfoShow);
			ConfigWidget(f_InfoMove, u8"允许移动 '信息' 窗口.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"FPS指示器");
		{
			ConfigWidget(f_FpsShow);
			ConfigWidget(f_FpsMove, u8"允许移动 'FPS 指示器' 窗口.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"显示提示");
		{
			ConfigWidget(f_NotificationsShow, u8"窗口右下角将显示通知");
			ConfigWidget(f_NotificationsDelay, 1,1,10000, u8"通知之间的延迟（毫秒）。");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"快速退出");
		{
			ConfigWidget(u8"启用",
				f_FastExitEnable,
				u8"启用快速退出.\n"
			);
			if (!f_FastExitEnable)
				ImGui::BeginDisabled();

			ConfigWidget(u8"键位", f_HotkeyExit, true,
				u8"快速退出游戏的键");

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

