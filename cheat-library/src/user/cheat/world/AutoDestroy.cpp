#include "pch-il2cpp.h"
#include "AutoDestroy.h"

#include <helpers.h>
#include <algorithm>

#include <cheat/events.h>
#include <cheat/game/SimpleFilter.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/filters.h>

namespace cheat::feature 
{
	static void LCAbilityElement_ReduceModifierDurability_Hook(app::LCAbilityElement* __this, int32_t modifierDurabilityIndex, float reduceDurability, app::Nullable_1_Single_ deltaTime, MethodInfo* method);

    AutoDestroy::AutoDestroy() : Feature(),
        NF(f_Enabled,			"Auto Destroy",			"AutoDestroy", false),
		NF(f_DestroyOres,		"Destroy Ores",			"AutoDestroy", false),
		NF(f_DestroyShields,	"Destroy Shields",		"AutoDestroy", false),
		NF(f_DestroyDoodads,	"Destroy Doodads",		"AutoDestroy", false),
        NF(f_Range,				"Range",				"AutoDestroy", 10.0f)
    { 
		HookManager::install(app::MoleMole_LCAbilityElement_ReduceModifierDurability, LCAbilityElement_ReduceModifierDurability_Hook);
	}

    const FeatureGUIInfo& AutoDestroy::GetGUIInfo() const
    {
        static const FeatureGUIInfo info { "Auto Destroy Objects", "World", true };
        return info;
    }

    void AutoDestroy::DrawMain()
    {
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Note. This feature is not fully tested detection-wise.\n"
			"Not recommended for main accounts or used with high values.");
		
		ConfigWidget("Enabled", f_Enabled, "Instantly destroys non-living objects within range.");
		ImGui::Indent();
		ConfigWidget("Ores", f_DestroyOres, "Ores and variants, e.g. electro crystals, marrows, etc.");
		ConfigWidget("Shields", f_DestroyShields, "Abyss mage/churl/slime shields.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Extremely risky!");
		ConfigWidget("Doodads", f_DestroyDoodads, "Barrels, boxes, vases, etc.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Extremely risky!");
		ImGui::Unindent();
		ConfigWidget("Range (m)", f_Range, 0.1f, 1.0f, 15.0f);
    }

    bool AutoDestroy::NeedStatusDraw() const
	{
        return f_Enabled;
    }

    void AutoDestroy::DrawStatus() 
    { 
		ImGui::Text("Destroy [%.01fm%s%s%s%s]",
			f_Range.value(),
			f_DestroyOres || f_DestroyShields || f_DestroyDoodads ? "|" : "",
			f_DestroyOres ? "O" : "",
			f_DestroyShields ? "S" : "",
			f_DestroyDoodads ? "D" : "");
    }

    AutoDestroy& AutoDestroy::GetInstance()
    {
        static AutoDestroy instance;
        return instance;
    }

	// Thanks to @RyujinZX
	// Every ore has ability element component
	// Durability of ability element is a ore health
	// Every tick ability element check reducing durability, for ore in calm state `reduceDurability` equals 0, means HP don't change
	// We need just change this value to current durability or above to destroy ore
	// This function also can work with some types of shields (TODO: improve killaura with this function)
	static void LCAbilityElement_ReduceModifierDurability_Hook(app::LCAbilityElement* __this, int32_t modifierDurabilityIndex, float reduceDurability, app::Nullable_1_Single_ deltaTime, MethodInfo* method)
	{
		auto& manager = game::EntityManager::instance();
		auto& autoDestroy = AutoDestroy::GetInstance();
		auto entity = __this->fields._._._entity;
		if (autoDestroy.f_Enabled && 
			autoDestroy.f_Range > manager.avatar()->distance(entity) &&
			(
				(autoDestroy.f_DestroyOres && game::filters::combined::Ores.IsValid(manager.entity(entity))) || 
				(autoDestroy.f_DestroyDoodads && game::filters::combined::Doodads.IsValid(manager.entity(entity))) ||
				(autoDestroy.f_DestroyShields && !game::filters::combined::MonsterBosses.IsValid(manager.entity(entity)) && (
												   game::filters::combined::MonsterShielded.IsValid(manager.entity(entity)) ||      // For shields attached to monsters, e.g. abyss mage shields.
												   game::filters::combined::MonsterEquips.IsValid(manager.entity(entity))    // For shields/weapons equipped by monsters, e.g. rock shield.
												 ))
			)
		)
		{
			// This value always above any ore durability
			reduceDurability = 1000;
		}
		CALL_ORIGIN(LCAbilityElement_ReduceModifierDurability_Hook, __this, modifierDurabilityIndex, reduceDurability, deltaTime, method);
	}

}

