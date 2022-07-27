#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/game/Entity.h>
#include <cheat/game/filters.h>
#include <il2cpp-appdata.h>

namespace cheat::feature 
{

	class MobVacuum : public Feature
    {
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<bool> f_HideStatus;

		config::Field<config::Toggle<Hotkey>> f_IncludeMonsters;
		config::Field<bool> f_MonsterCommon;
		config::Field<bool> f_MonsterElites;
		config::Field<bool> f_MonsterBosses;

		config::Field<config::Toggle<Hotkey>> f_IncludeAnimals;
		config::Field<bool> f_AnimalDrop;
		config::Field<bool> f_AnimalPickUp;
		config::Field<bool> f_AnimalNPC;

		config::Field<float> f_Speed;
		config::Field<float> f_Radius;
		config::Field<float> f_Distance;
		config::Field<bool> f_OnlyTarget;
		config::Field<bool> f_Instantly;

		static MobVacuum& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;
	
		void OnGameUpdate();
	private:
		
		std::vector<game::IEntityFilter*> m_Filters;
		MobVacuum();

		void UpdateFilters();

		bool IsEntityForVac(cheat::game::Entity* entity);
		void OnMoveSync(uint32_t entityId, app::MotionInfo* syncInfo);
		app::Vector3 CalcMobVacTargetPos();
	};
}

