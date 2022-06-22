#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature
{
	class ProfileChanger : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<std::string>> f_UID;
		config::Field<config::Toggle<std::string>> f_NickName;
		config::Field<config::Toggle<std::string>> f_Level;
		config::Field<config::Toggle<Hotkey>> f_Exp;
		config::Field<int> f_CurExp;
		config::Field<int> f_MaxExp;
		config::Field<config::Toggle<Hotkey>> f_ExpBar;
		config::Field<float> f_ExpBarValue;
		config::Field<config::Toggle<std::string>> f_WorldLevel;

		config::Field<config::Toggle<std::string>> f_Avatar; // Avatar png size 256x256
		config::Field<config::Toggle<std::string>> f_Card; // Card Name png size 840x400

		static ProfileChanger& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		bool CheckFile(const std::string& name);

	private:
		SafeQueue<uint32_t> toBeUpdate;
		SafeValue<int64_t> nextUpdate;
		int f_DelayUpdate = 100;
	
		void OnGameUpdate();
		ProfileChanger();
		
	};
}