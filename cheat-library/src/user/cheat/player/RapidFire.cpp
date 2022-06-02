#include "pch-il2cpp.h"
#include "RapidFire.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/util.h>
#include <cheat/game/filters.h>

namespace cheat::feature 
{
	static void LCBaseCombat_DoHitEntity_Hook(app::LCBaseCombat* __this, uint32_t targetID, app::AttackResult* attackResult,
		bool ignoreCheckCanBeHitInMP, MethodInfo* method);

    RapidFire::RapidFire() : Feature(),
        NF(f_Enabled,			"Attack Multiplier",	"RapidFire", false),
		NF(f_MultiHit,			"Multi-hit",			"RapidFire", false),
        NF(f_Multiplier,		"Hit Multiplier",		"RapidFire", 2),
        NF(f_OnePunch,			"One Punch Mode",		"RapidFire", false),
		NF(f_Randomize,			"Randomize",			"RapidFire", false),
		NF(f_minMultiplier,		"Min Multiplier",		"RapidFire", 1),
		NF(f_maxMultiplier,		"Max Multiplier",		"RapidFire", 3),
		NF(f_MultiTarget,		"Multi-target",			"RapidFire", false),
		NF(f_MultiTargetRadius, "Multi-target Radius",	"RapidFire", 20.0f)
    {
		HookManager::install(app::MoleMole_LCBaseCombat_DoHitEntity, LCBaseCombat_DoHitEntity_Hook);
    }

    const FeatureGUIInfo& RapidFire::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "Attack Effects", "Player", true };
        return info;
    }

    void RapidFire::DrawMain()
    {
		ConfigWidget("Enabled", f_Enabled, "Enables attack multipliers. Need to choose a mode to work.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "Choose any or both modes below.");

		ConfigWidget("Multi-hit Mode", f_MultiHit, "Enables multi-hit.\n" \
            "Multiplies your attack count.\n" \
            "This is not well tested, and can be detected by anticheat.\n" \
            "Not recommended to be used with main accounts or used with high values.\n" \
			"Known issues with certain multi-hit attacks, e.g. Xiao E, Ayaka CA, etc.");

		ImGui::Indent();

		ConfigWidget("One-Punch Mode", f_OnePunch, "Calculate how many attacks needed to kill an enemy based on their HP\n" \
			"and uses that to set the multiplier accordingly.\n" \
			"May be safer, but multiplier calculation may not be on-point.");

		ConfigWidget("Randomize Multiplier", f_Randomize, "Randomize multiplier between min and max multiplier.");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), "This will override One-Punch Mode!");

		if (!f_OnePunch) {
			if (!f_Randomize)
			{
				ConfigWidget("Multiplier", f_Multiplier, 1, 2, 1000, "Attack count multiplier.");
			}
			else
			{
				ConfigWidget("Min Multiplier", f_minMultiplier, 1, 2, 1000, "Attack count minimum multiplier.");
				ConfigWidget("Max Multiplier", f_maxMultiplier, 1, 2, 1000, "Attack count maximum multiplier.");
			}
		}

		ImGui::Unindent();

		ConfigWidget("Multi-target", f_MultiTarget, "Enables multi-target attacks within specified radius of target.\n" \
			"All valid targets around initial target will be hit based on setting.\n" \
			"Damage numbers will only appear on initial target but all valid targets are damaged.\n" \
			"If multi-hit is off and there are still multiple numbers on a single target, check the Entity Manager in the Debug section to see if there are invisible entities.\n" \
			"This can cause EXTREME lag and quick bans if used with multi-hit. You are warned."
		);
	
		ImGui::Indent();
		ConfigWidget("Radius (m)", f_MultiTargetRadius, 0.1f, 5.0f, 50.0f, "Radius to check for valid targets.");
		ImGui::Unindent();
    }

    bool RapidFire::NeedStatusDraw() const
{
        return f_Enabled && (f_MultiHit || f_MultiTarget);
    }

    void RapidFire::DrawStatus() 
    {
		if (f_MultiHit) 
		{
			if (f_Randomize)
				ImGui::Text("Multi-Hit Random[%d|%d]", f_minMultiplier.value(), f_maxMultiplier.value());
			else if (f_OnePunch)
				ImGui::Text("Multi-Hit [OnePunch]");
			else
				ImGui::Text("Multi-Hit [%d]", f_Multiplier.value());
		}
		if (f_MultiTarget)
			ImGui::Text("Multi-Target [%.01fm]", f_MultiTargetRadius.value());
    }

    RapidFire& RapidFire::GetInstance()
    {
        static RapidFire instance;
        return instance;
    }


	int RapidFire::CalcCountToKill(float attackDamage, uint32_t targetID)
	{
		if (attackDamage == 0)
			return f_Multiplier;
		
		auto& manager = game::EntityManager::instance();
		auto targetEntity = manager.entity(targetID);
		if (targetEntity == nullptr)
			return f_Multiplier;

		auto baseCombat = targetEntity->combat();
		if (baseCombat == nullptr)
			return f_Multiplier;

		auto safeHP = baseCombat->fields._combatProperty_k__BackingField->fields.HP;
		auto HP = app::MoleMole_SafeFloat_get_Value(safeHP, nullptr);
		int attackCount = (int)ceil(HP / attackDamage);
		return std::clamp(attackCount, 1, 200);
	}

	int RapidFire::GetAttackCount(app::LCBaseCombat* combat, uint32_t targetID, app::AttackResult* attackResult)
	{
		if (!f_MultiHit)
			return 1;

		auto& manager = game::EntityManager::instance();
		auto targetEntity = manager.entity(targetID);
		auto baseCombat = targetEntity->combat();
		if (baseCombat == nullptr)
			return 1;

		int countOfAttacks = f_Multiplier;
		if (f_OnePunch)
		{
			app::MoleMole_Formula_CalcAttackResult(combat->fields._combatProperty_k__BackingField,
				baseCombat->fields._combatProperty_k__BackingField,
				attackResult, manager.avatar()->raw(), targetEntity->raw(), nullptr);
			countOfAttacks = CalcCountToKill(attackResult->fields.damage, targetID);
		}
		if (f_Randomize)
		{
			countOfAttacks = rand() % (f_maxMultiplier.value() - f_minMultiplier.value()) + f_minMultiplier.value();
			return countOfAttacks;
		}

		return countOfAttacks;
	}

	bool IsAvatarOwner(game::Entity entity)
	{
		auto& manager = game::EntityManager::instance();
		auto avatarID = manager.avatar()->runtimeID();

		while (entity.isGadget())
		{
			game::Entity temp = entity;
			entity = game::Entity(app::MoleMole_GadgetEntity_GetOwnerEntity(reinterpret_cast<app::GadgetEntity*>(entity.raw()), nullptr));
			if (entity.runtimeID() == avatarID)
				return true;
		} 

		return false;
		
	}

	bool IsAttackByAvatar(game::Entity& attacker)
	{
		if (attacker.raw() == nullptr)
			return false;

		auto& manager = game::EntityManager::instance();
		auto avatarID = manager.avatar()->runtimeID();
		auto attackerID = attacker.runtimeID();

		return attackerID == avatarID || IsAvatarOwner(attacker);
	}

	// Raises when any entity do hit event.
	// Just recall attack few times (regulating by combatProp)
	// It's not tested well, so, I think, anticheat can detect it.
	static void LCBaseCombat_DoHitEntity_Hook(app::LCBaseCombat* __this, uint32_t targetID, app::AttackResult* attackResult,
		bool ignoreCheckCanBeHitInMP, MethodInfo* method)
	{
		auto attacker = game::Entity(__this->fields._._._entity);
		RapidFire& rapidFire = RapidFire::GetInstance();
		if (!IsAttackByAvatar(attacker) || !rapidFire.f_Enabled)
			return CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, targetID, attackResult, ignoreCheckCanBeHitInMP, method);

		auto& manager = game::EntityManager::instance();
		auto originalTarget = manager.entity(targetID);
		if (!game::filters::combined::OrganicTargets.IsValid(originalTarget))
			return CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, targetID, attackResult, ignoreCheckCanBeHitInMP, method);

		std::vector<cheat::game::Entity*> validEntities;
		validEntities.push_back(originalTarget);
		
		if (rapidFire.f_MultiTarget)
		{
			auto filteredEntities = manager.entities(game::filters::combined::Monsters);
			for (const auto& entity : filteredEntities) {
				auto distance = originalTarget->distance(entity);

				if (entity->runtimeID() == targetID)
					continue;

				if (distance > rapidFire.f_MultiTargetRadius)
					continue;

				validEntities.push_back(entity);
			}
		}

		for (const auto& entity : validEntities) {
			if (rapidFire.f_MultiHit) {
				int attackCount = rapidFire.GetAttackCount(__this, entity->runtimeID(), attackResult);
				for (int i = 0; i < attackCount; i++)
					CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, entity->runtimeID(), attackResult, ignoreCheckCanBeHitInMP, method);
			} else CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, entity->runtimeID(), attackResult, ignoreCheckCanBeHitInMP, method);
		}
	}
}

