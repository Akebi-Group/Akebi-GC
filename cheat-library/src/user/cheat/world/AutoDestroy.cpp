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
        NF(f_Enabled,			u8"自动摧毁", "AutoDestroy", false),
		NF(f_DestroyOres, u8"摧毁矿石", "AutoDestroy", false),
		NF(f_DestroyShields, u8"摧毁盾牌", "AutoDestroy", false),
		NF(f_DestroyDoodads, u8"摧毁装饰品", "AutoDestroy", false),
        NF(f_Range, u8"距离", u8"自动摧毁", 10.0f)
    { 
		HookManager::install(app::MoleMole_LCAbilityElement_ReduceModifierDurability, LCAbilityElement_ReduceModifierDurability_Hook);
	}

    const FeatureGUIInfo& AutoDestroy::GetGUIInfo() const
    {
        static const FeatureGUIInfo info { u8"自动摧毁物品", u8"世界", true };
        return info;
    }

    void AutoDestroy::DrawMain()
    {
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"注意：此功能未在检测方面进行全面测试。\n"
			u8"不推荐用大号或氪号。");
		
		ConfigWidget(u8"启用", f_Enabled, u8"立即摧毁范围内的非生命物体。");
		ImGui::Indent();
		ConfigWidget(u8"矿石", f_DestroyOres, u8"矿石和其他，例如 电晶体、骨髓等");
		ConfigWidget(u8"盾牌", f_DestroyShields, u8"深渊法师/丘丘人/史莱姆盾");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"风险极大！");
		ConfigWidget(u8"装饰品", f_DestroyDoodads, u8"桶、盒、花瓶等");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"风险极大！");
		ImGui::Unindent();
		ConfigWidget(u8"距离 (m)", f_Range, 0.1f, 1.0f, 15.0f);
    }

    bool AutoDestroy::NeedStatusDraw() const
	{
        return f_Enabled;
    }

    void AutoDestroy::DrawStatus() 
    { 
		ImGui::Text(u8"销毁 [%.01fm%s%s%s%s]",
			f_Range.value(),
			f_DestroyOres || f_DestroyShields || f_DestroyDoodads ? "|" : "",
			f_DestroyOres ? "矿石" : "",
			f_DestroyShields ? "盾牌" : "",
			f_DestroyDoodads ? "装饰品" : "");
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

