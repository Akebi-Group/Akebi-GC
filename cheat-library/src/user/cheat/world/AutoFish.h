#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

	class AutoFish : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<int> f_DelayBeforeCatch;
		config::Field<bool> f_AutoRecastRod;
		config::Field<int> f_DelayBeforeRecast;
		config::Field<bool> f_HideStatus;

		static AutoFish& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

	private:
		AutoFish();

		std::mutex m_BattleFinishTimestampMutex;
		uint64_t m_BattleFinishTimestamp;

		std::mutex m_RecastTimestampMutex;
		uint64_t m_RecastTimestamp;

		struct RodCastData
		{
			bool exist;

			void* fishingModule;
			uint32_t baitId;
			uint32_t rodId;
			app::Vector3 pos;
			uint32_t rodEntityId;
		};

		RodCastData m_LastCastData;

		void OnGameUpdate();

		// Hooks
		static void FishingModule_OnFishBattleEndRsp_Hook(void* __this, app::FishBattleEndRsp* rsp, MethodInfo* method);
		static void FishingModule_OnExitFishingRsp_Hook(void* __this, void* rsp, MethodInfo* method);
		static void FishingModule_RequestFishCastRod_Hook(void* __this, uint32_t baitId, uint32_t rodId, app::Vector3 pos, uint32_t rodEntityId, MethodInfo* method);
		static void FishingModule_onFishChosenNotify_Hook(void* __this, void* notify, MethodInfo* method);
		static void FishingModule_OnFishBiteRsp_Hook(void* __this, app::FishBiteRsp* rsp, MethodInfo* method);
		static void FishingModule_OnFishBattleBeginRsp_Hook(void* __this, app::FishBattleBeginRsp* rsp, MethodInfo* method);
	};
}
