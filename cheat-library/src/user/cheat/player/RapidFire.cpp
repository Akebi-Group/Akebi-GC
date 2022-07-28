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
        NF(f_Enabled,			u8"��������", "RapidFire", false),
		NF(f_MultiHit, u8"��ι���", "RapidFire", false),
        NF(f_Multiplier, u8"�˺�����", "RapidFire", 2),
        NF(f_OnePunch, u8"һȭ����ģʽ", "RapidFire", false),
		NF(f_Randomize, u8"�������", "RapidFire", false),
		NF(f_minMultiplier, u8"��С����", "RapidFire", 1),
		NF(f_maxMultiplier, u8"�����", "RapidFire", 3),
		NF(f_MultiTarget, u8"��Ŀ��", "RapidFire", false),
		NF(f_MultiTargetRadius, u8"��Ŀ�귶Χ", "RapidFire", 20.0f)
    {
		HookManager::install(app::MoleMole_LCBaseCombat_DoHitEntity, LCBaseCombat_DoHitEntity_Hook);
    }

    const FeatureGUIInfo& RapidFire::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ u8"����Ч��", u8"���", true };
        return info;
    }

    void RapidFire::DrawMain()
    {
		ConfigWidget(u8"����", f_Enabled, u8"���ö౶��������Ҫ����һ��ģʽ");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"ѡ��һ�������й�������.");

		ConfigWidget(u8"�౶�˺�", f_MultiHit, u8"���ö౶�˺�.\n" \
			u8"������Ĺ�������.\n" \
			u8"��û�о����ܺõĲ��ԣ�����ͨ�������׼�⵽.\n" \
			u8"��������ʹ�û�봺�ʹ��.\n" \
			u8"ĳЩ�����й�������֪���⣬�����̵�E���軪��CA�ȡ�");

		ImGui::Indent();

		ConfigWidget(u8"һȭ����ģʽ", f_OnePunch, u8"���ݵ��˵���������ɱ��������Ҫ���ٴι���\n" \
			u8"��ʹ��������Ӧ�����ó���.\n" \
			u8"���ܸ���ȫ��������������ܲ�׼ȷ.");

		ConfigWidget(u8"�������", f_Randomize, u8"����С�������֮������˺�����");
		ImGui::SameLine();
		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"�⽫����һȭ����ģʽ��");

		if (!f_OnePunch) {
			if (!f_Randomize)
			{
				ConfigWidget(u8"����", f_Multiplier, 1, 2, 1000, u8"��������");
			}
			else
			{
				ConfigWidget(u8"��С��������", f_minMultiplier, 1, 2, 1000, u8"����������С����");
				ConfigWidget(u8"��󹥻�����", f_maxMultiplier, 1, 2, 1000, u8"��������������");
			}
		}

		ImGui::Unindent();

		ConfigWidget(u8"��Ŀ��", f_MultiTarget, u8"��ָ����Ŀ��뾶�����ö�Ŀ�깥����\n" \
			u8"�������������г�ʼĿ����Χ��������ЧĿ�ꡣ\n" \
			u8"�˺�����ֻ������ڳ�ʼĿ���ϣ���������ЧĿ�궼���˺���\n" \
			u8"���������multi-hit�����ҵ���Ŀ�������ж�����֣�������Բ����е�ʵ����������Բ鿴�Ƿ���ڲ��ɼ���ʵ�塣\n" \
			u8"�����������һ��ʹ�ã�����ܻᵼ����Ϸ��ͬ���Ϳ��ٷ����"
		);
	
		ImGui::Indent();
		ConfigWidget(u8"���� (��)", f_MultiTargetRadius, 0.1f, 5.0f, 50.0f, u8"�����ЧĿ��İ뾶��");
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
				ImGui::Text(u8"��������˺�[%d|%d]", f_minMultiplier.value(), f_maxMultiplier.value());
			else if (f_OnePunch)
				ImGui::Text(u8"һȭ����ģʽ");
			else
				ImGui::Text(u8"�౶�˺� [%d]", f_Multiplier.value());
		}
		if (f_MultiTarget)
			ImGui::Text(u8"��Ŀ��ģʽ [%.01fm]", f_MultiTargetRadius.value());
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

