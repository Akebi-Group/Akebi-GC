#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <cheat/esp/ESPItem.h>
#include <cheat/game/IEntityFilter.h>
#include <cheat/game/CacheFilterExecutor.h>

namespace cheat::feature 
{

	class ESP : public Feature
    {
	public:
		enum class DrawMode
		{
			None,
			Rectangle,
			Box
		};

		enum class DrawTracerMode
		{
			None,
			Line,
			OffscreenArrows
		};

		config::Field<config::Toggle<Hotkey>> f_Enabled;
    
		config::Field<config::Enum<DrawMode>> f_DrawBoxMode;
		config::Field<config::Enum<DrawTracerMode>> f_DrawTracerMode;
		config::Field<bool> f_Fill;
		config::Field<float> f_FillTransparency;

		config::Field<bool> f_DrawDistance;
		config::Field<bool> f_DrawName;
		config::Field<float> f_ArrowRadius;
		config::Field<float> f_OutlineThickness;
		config::Field<float> f_TracerSize;
		config::Field<bool> f_MiddleScreenTracer;

		config::Field<int> f_FontSize;
		config::Field<bool> f_FontOutline;
		config::Field<float> f_FontOutlineSize;

		config::Field<config::Toggle<ImColor>> f_GlobalFontColor;
		ImColor m_FontContrastColor;
		config::Field<config::Toggle<ImColor>> f_GlobalBoxColor;
		config::Field<config::Toggle<ImColor>> f_GlobalRectColor;
		config::Field<config::Toggle<ImColor>> f_GlobalLineColor;

		config::Field<float> f_MinSize;
		config::Field<float> f_Range;

		std::string m_Search;

		static ESP& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		virtual bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void DrawExternal() override;

	private:
		using FilterInfo = std::pair<config::Field<esp::ESPItem>, game::IEntityFilter*>;
		using Filters = std::vector<FilterInfo>;
		using Sections = std::map<std::string, Filters>;

		Sections m_Sections;
		game::CacheFilterExecutor m_FilterExecutor;

		void InstallFilters();
		void AddFilter(const std::string& section, const std::string& name, game::IEntityFilter* filter);
		
		void DrawSection(const std::string& section, const Filters& filters);
		void DrawFilterField(const config::Field<esp::ESPItem>& field);

		void OnKeyUp(short key, bool& cancelled);

		ESP();
	};
}

