#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/game/Entity.h>
#include <cheat/game/filters.h>
#include <il2cpp-appdata.h>
#include <cheat-base/thread-safe.h>

namespace cheat::feature
{
	class VacuumLoot : public Feature
	{
	public:
		config::Field<config::Toggle<Hotkey>> f_Enabled;
		config::Field<float> f_Distance;
		config::Field<bool> f_HideStatus;
		config::Field<float> f_Radius;
		config::Field<float> f_MobDropRadius;
		config::Field<int> f_DelayTime;

		static VacuumLoot& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void OnGameUpdate();

	private:
		using FilterInfo = std::pair<config::Field<bool>, game::IEntityFilter*>;
		using Filters = std::vector<FilterInfo>;
		using Sections = std::map<std::string, Filters>;

		Sections m_Sections;
		SafeValue<int64_t> nextTime;

		const std::vector<game::IEntityFilter*> m_MobDropFilter = {
			& game::filters::featured::ItemDrops,
			& game::filters::equipment::Artifacts,
			& game::filters::equipment::Bow,
			& game::filters::equipment::Catalyst,
			& game::filters::equipment::Claymore,
			& game::filters::equipment::Pole,
			& game::filters::equipment::Sword
		};

		VacuumLoot();
		void DrawSection(const std::string& section, const Filters& filters);
		void InstallFilters();
		void AddFilter(const std::string& section, const std::string& name, game::IEntityFilter* filter);
		bool IsEntityForVac(cheat::game::Entity* entity);
	};
}
