#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature
{
	class TextureChanger : public Feature
	{
	public:		
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<config::Toggle<std::string>> f_HeadPath;
		config::Field<config::Toggle<std::string>> f_BodyPath;
		config::Field<config::Toggle<std::string>> f_DressPath;
		config::Field<bool> f_HideStatus;
		std::string ActiveHero = "NONE";
 		bool ApplyTexture;

		static TextureChanger& GetInstance();
		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;
		bool NeedStatusDraw() const override;
		void DrawStatus() override;
		bool CheckFile(const std::string& name);
	private:
		SafeQueue<uint32_t> toBeUpdate;
		SafeValue<int64_t> nextUpdate;
		int f_DelayUpdate = 15;

		void OnGameUpdate();
		TextureChanger();

	};
}