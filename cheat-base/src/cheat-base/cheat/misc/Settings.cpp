#include <pch.h>
#include "Settings.h"

#include <cheat-base/render/gui-util.h>
#include <cheat-base/render/renderer.h>
#include <cheat-base/cheat/CheatManagerBase.h>

namespace cheat::feature 
{
    Settings::Settings() : Feature(),
		NF(f_MenuKey, u8"��ʾ���ײ˵���", "General", Hotkey(VK_F1)),
		NF(f_HotkeysEnabled, u8"�ȼ�����", "General", true),
		NF(f_FontSize, u8"�����С", "General", 16.0f),

		NF(f_StatusMove, u8"�ƶ�״̬����", "General::StatusWindows", true),
		NF(f_StatusShow, u8"��ʾ״̬����", "General::StatusWindows", true),
		
		NF(f_InfoMove,   u8"�ƶ���Ϣ����", "General::InfoWindows", true),
		NF(f_InfoShow, u8"��ʾ��Ϣ����", "General::InfoWindows", true),
		
		NF(f_FpsMove, u8"�ƶ�FPSָʾ��", "General::FPS", false),
		NF(f_FpsShow, u8"��ʾ�ƶ�FPSָʾ��", "General::FPS", true),

		NF(f_NotificationsShow, u8"��ʾ��ʾ", "General::notic", true),
		NF(f_NotificationsDelay, u8"��ʾ����", "General::֪ͨ", 500),
  
		NF(f_FileLogging, u8"�ļ���־", u8"ȫ��::��־", false),
		NF(f_ConsoleLogging, u8"����̨��־", u8"ȫ��::��־", true),

		NF(f_FastExitEnable, u8"�����˳�", u8"ȫ��::�����˳�", false),
		NF(f_HotkeyExit, u8"�ȼ�", u8"ȫ��::�����˳�", Hotkey(VK_F12))
		
    {
		renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
		f_HotkeyExit.value().PressedEvent += MY_METHOD_HANDLER(Settings::OnExitKeyPressed);
    }

    const FeatureGUIInfo& Settings::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", u8"����", false };
        return info;
    }

	void Settings::DrawMain()
	{

		ImGui::BeginGroupPanel(u8"ȫ��");
		{
			ConfigWidget(f_MenuKey, false,
				u8"�л����˵��ļ�λ�����ɿ�\n"\
				u8"��������������λ��������������ļ��в鿴");
			ConfigWidget(f_HotkeysEnabled, u8"�����ȼ�");
			if (ConfigWidget(f_FontSize, 1, 8, 64, u8"���׽���������С"))
			{
				f_FontSize = std::clamp(f_FontSize.value(), 8, 64);
				renderer::SetGlobalFontSize(static_cast<float>(f_FontSize));
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"��־");
		{
			bool consoleChanged = ConfigWidget(f_ConsoleLogging,
				u8"���ÿ���̨�Լ�¼��Ϣ�����Ľ���������������Ч��");
			if (consoleChanged && !f_ConsoleLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::ConsoleLogger);
			}

			bool fileLogging = ConfigWidget(f_FileLogging,
				u8"�����ļ���־��¼�����Ľ���������������Ч��.\n" \
				u8"����Ӧ�ó���Ŀ¼��Ϊ��־����һ���ļ��С�");
			if (fileLogging && !f_FileLogging)
			{
				Logger::SetLevel(Logger::Level::None, Logger::LoggerType::FileLogger);
			}
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"״̬����");
		{
			ConfigWidget(f_StatusShow);
			ConfigWidget(f_StatusMove, u8"�����ƶ� '״̬' ����.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"��Ϣ����");
		{
			ConfigWidget(f_InfoShow);
			ConfigWidget(f_InfoMove, u8"�����ƶ� '��Ϣ' ����.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"FPSָʾ��");
		{
			ConfigWidget(f_FpsShow);
			ConfigWidget(f_FpsMove, u8"�����ƶ� 'FPS ָʾ��' ����.");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"��ʾ��ʾ");
		{
			ConfigWidget(f_NotificationsShow, u8"�������½ǽ���ʾ֪ͨ");
			ConfigWidget(f_NotificationsDelay, 1,1,10000, u8"֪֮ͨ����ӳ٣����룩��");
		}
		ImGui::EndGroupPanel();

		ImGui::BeginGroupPanel(u8"�����˳�");
		{
			ConfigWidget(u8"����",
				f_FastExitEnable,
				u8"���ÿ����˳�.\n"
			);
			if (!f_FastExitEnable)
				ImGui::BeginDisabled();

			ConfigWidget(u8"��λ", f_HotkeyExit, true,
				u8"�����˳���Ϸ�ļ�");

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

