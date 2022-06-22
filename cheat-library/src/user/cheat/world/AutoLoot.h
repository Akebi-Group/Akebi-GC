#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature 
{

	class AutoLoot : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_AutoPickup;
		config::Field<config::Toggle<Hotkey>> f_AutoTreasure;
		config::Field<config::Toggle<Hotkey>> f_UseCustomRange;
		config::Field<config::Toggle<Hotkey>> f_PickupFilter;

		config::Field<int> f_DelayTime;
		config::Field<float> f_CustomRange;

		config::Field<bool> f_Chest;
		config::Field<bool> f_Leyline;
		config::Field<bool> f_Investigate;
		config::Field<bool> f_QuestInteract;
		config::Field<bool> f_Others;
		
		config::Field<bool> f_PickupFilter_Animals;
		config::Field<bool> f_PickupFilter_DropItems;
		config::Field<bool> f_PickupFilter_Resources;

		static AutoLoot& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		bool OnCreateButton(app::BaseEntity* entity);
		void OnGameUpdate();
		void OnCheckIsInPosition(bool& result, app::BaseEntity* entity);
	
	private:
		
		SafeQueue<uint32_t> toBeLootedItems;
		SafeValue<int64_t> nextLootTime;
		AutoLoot();
	};
}

