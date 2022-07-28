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
        NF(f_Enabled,			u8"攻击倍数", "RapidFire", false),
		NF(f_MultiHit, u8"多次攻击", "RapidFire", false),
        NF(f_Multiplier, u8"伤害倍数", "RapidFire", 2),
        NF(f_OnePunch, u8"一拳超人模式", "RapidFire", false),
		NF(f_Randomize, u8"随机倍数", "RapidFire", false),
		NF(f_minMultiplier, u8"最小倍数", "RapidFire", 1),
		NF(f_maxMultiplier, u8"最大倍数", "RapidFire", 3),
		NF(f_MultiTarget, u8"多目标", "RapidFire", false),
		NF(f_MultiTargetRadius, u8"多目标范围", "RapidFire", 20.0f)
    {
		HookManager::install(app::MoleMole_LCBaseCombat_DoHitEntity, LCBaseCombat_DoHitEntity_Hook);
    }

    const FeatureGUIInfo& RapidFire::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ u8"攻击效果", u8"玩家", true };
        return info;
    }

    void RapidFire::DrawMain()
    {
		ConfigWidget(u8"启用", f_Enabled, u8"启用多倍攻击，需要设置一个模式");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"选择一个或所有功能启用.");

		ConfigWidget(u8"多倍伤害", f_MultiHit, u8"启用多倍伤害.\n" \
			u8"乘以你的攻击次数.\n" \
			u8"这没有经过很好的测试，可以通过反作弊检测到.\n" \
			u8"不建议大号使用或氪号使用.\n" \
			u8"某些多命中攻击的已知问题，例如魈的E、凌华的CA等。");

		ImGui::Indent();

		ConfigWidget(u8"一拳超人模式", f_OnePunch, u8"根据敌人的生命计算杀死敌人需要多少次攻击\n" \
			u8"并使用它来相应地设置乘数.\n" \
			u8"可能更安全，但乘数计算可能不准确.");

		ConfigWidget(u8"随机倍数", f_Randomize, u8"在最小和最大倍数之间随机伤害倍数");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"这将覆盖一拳超人模式！");

		if (!f_OnePunch) {
			if (!f_Randomize)
			{
				ConfigWidget(u8"倍数", f_Multiplier, 1, 2, 1000, u8"攻击倍数");
			}
			else
			{
				ConfigWidget(u8"最小攻击倍数", f_minMultiplier, 1, 2, 1000, u8"攻击计数最小乘数");
				ConfigWidget(u8"最大攻击倍数", f_maxMultiplier, 1, 2, 1000, u8"攻击计数最大乘数");
			}
		}

		ImGui::Unindent();

		ConfigWidget(u8"多目标", f_MultiTarget, u8"在指定的目标半径内启用多目标攻击。\n" \
			u8"将根据设置命中初始目标周围的所有有效目标。\n" \
			u8"伤害数字只会出现在初始目标上，但所有有效目标都已伤害。\n" \
			u8"如果禁用了multi-hit，并且单个目标上仍有多个数字，请检查调试部分中的实体管理器，以查看是否存在不可见的实体。\n" \
			u8"如果与多次命中一起使用，这可能会导致游戏不同步和快速封禁。"
		);
	
		ImGui::Indent();
		ConfigWidget(u8"距离 (米)", f_MultiTargetRadius, 0.1f, 5.0f, 50.0f, u8"检查有效目标的半径。");
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
				ImGui::Text(u8"随机倍数伤害[%d|%d]", f_minMultiplier.value(), f_maxMultiplier.value());
			else if (f_OnePunch)
				ImGui::Text(u8"一拳超人模式");
			else
				ImGui::Text(u8"多倍伤害 [%d]", f_Multiplier.value());
		}
		if (f_MultiTarget)
			ImGui::Text(u8"多目标模式 [%.01fm]", f_MultiTargetRadius.value());
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

	bool IsValidByFilter(game::Entity* entity)
	{
		if (game::filters::combined::OrganicTargets.IsValid(entity) ||
			game::filters::combined::Ores.IsValid(entity) ||
			game::filters::puzzle::Geogranum.IsValid(entity) ||
			game::filters::puzzle::LargeRockPile.IsValid(entity) ||
			game::filters::puzzle::SmallRockPile.IsValid(entity))
			return true;
		return false;
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
		if (!IsValidByFilter(originalTarget))
			return CALL_ORIGIN(LCBaseCombat_DoHitEntity_Hook, __this, targetID, attackResult, ignoreCheckCanBeHitInMP, method);

		std::vector<cheat::game::Entity*> validEntities;
		validEntities.push_back(originalTarget);

		if (rapidFire.f_MultiTarget)
		{
			auto filteredEntities = manager.entities();
			for (const auto& entity : filteredEntities) {
				auto distance = originalTarget->distance(entity);

				if (entity->runtimeID() == manager.avatar()->runtimeID())
					continue;

				if (entity->runtimeID() == targetID)
					continue;

				if (distance > rapidFire.f_MultiTargetRadius)
					continue;

				if (!IsValidByFilter(entity))
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

