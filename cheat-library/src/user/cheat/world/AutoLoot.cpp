#include "pch-il2cpp.h"
#include "AutoLoot.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/filters.h>
#include <cheat/game/Chest.h>

namespace cheat::feature 
{
	static void LCSelectPickup_AddInteeBtnByID_Hook(void* __this, app::BaseEntity* entity, MethodInfo* method);
	static bool LCSelectPickup_IsInPosition_Hook(void* __this, app::BaseEntity* entity, MethodInfo* method);
	static bool LCSelectPickup_IsOutPosition_Hook(void* __this, app::BaseEntity* entity, MethodInfo* method);

    AutoLoot::AutoLoot() : Feature(),
        NF(f_AutoPickup,     u8"自动拾取掉落物",               "AutoLoot", false),
		NF(f_AutoTreasure,   u8"自动开宝箱",             "AutoLoot", false),
		NF(f_UseCustomRange, u8"使用自定义拾取距离",         "AutoLoot", false),
		NF(f_PickupFilter, u8"拾取物筛选器",					"AutoLoot", false),
		NF(f_PickupFilter_Animals, u8"动物筛选器",			"AutoLoot", true),
		NF(f_PickupFilter_DropItems, u8"掉落物筛选器",		"AutoLoot", true),
		NF(f_PickupFilter_Resources, u8"资源筛选器",		"AutoLoot", true),
		NF(f_Chest, u8"箱子",							"AutoLoot", false),
		NF(f_Leyline, u8"地脉之花",						"AutoLoot", false),
		NF(f_Investigate, u8"搜索",					"AutoLoot", false),
		NF(f_QuestInteract, u8"任务交互",					"AutoLoot", false),
        NF(f_Others, u8"其他宝箱",					"AutoLoot", false),
		NF(f_DelayTime, u8"拾取周期 (ms)",				"AutoLoot", 150),
        NF(f_CustomRange, u8"拾取范围",                    "AutoLoot", 5.0f),
		toBeLootedItems(), nextLootTime(0)
    {
		// Auto loot
		HookManager::install(app::MoleMole_LCSelectPickup_AddInteeBtnByID, LCSelectPickup_AddInteeBtnByID_Hook);
		HookManager::install(app::MoleMole_LCSelectPickup_IsInPosition, LCSelectPickup_IsInPosition_Hook);
		HookManager::install(app::MoleMole_LCSelectPickup_IsOutPosition, LCSelectPickup_IsOutPosition_Hook);

		events::GameUpdateEvent += MY_METHOD_HANDLER(AutoLoot::OnGameUpdate);
	}

    const FeatureGUIInfo& AutoLoot::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ u8"自动掠夺", u8"世界", true };
        return info;
    }

    void AutoLoot::DrawMain()
    {
		if (ImGui::BeginTable(u8"自动掠夺", 2, ImGuiTableFlags_NoBordersInBody))
		{
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);

			ImGui::BeginGroupPanel(u8"自动拾取");
			{
				ConfigWidget(u8"启用", f_AutoPickup, u8"自动拾取掉落的物品.\n" \
					u8"注意：在自定义范围和低延迟时间下使用此选项非常危险。\n" \
					u8"滥用肯定会被封禁\n\n" \
					u8"如果使用自定义范围，请确保首先打开它。");
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 165, 0, 255), u8"使用必读!");
			}
			ImGui::EndGroupPanel();
			
			ImGui::BeginGroupPanel(u8"自定义拾取范围");
			{
				ConfigWidget(u8"启用", f_UseCustomRange, u8"启用自定义拾取范围。\n" \
					u8"不建议使用高值，因为它很容易被服务器检测到。\n\n" \
					u8"如果与自动拾取/自动宝藏一起使用，请最后打开此选项。");
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 165, 0, 255), u8"使用必读!");
				ImGui::SetNextItemWidth(100.0f);
				ConfigWidget(u8"距离 (米)", f_CustomRange, 0.1f, 0.5f, 40.0f, u8"将拾取/打开范围修改为此值（以米为单位）。");
			}
			ImGui::EndGroupPanel();
			
			ImGui::BeginGroupPanel(u8"拾取速度");
			{
				ImGui::SetNextItemWidth(100.0f);
				ConfigWidget(u8"拾取周期 (毫秒)", f_DelayTime, 1, 0, 1000, u8"战利品/打开操作之间的延迟（以毫秒为单位）。\n" \
					u8"低于 200 毫秒的值是不安全的。\n如果没有开启自动功能，则不使用。");
			}
			ImGui::EndGroupPanel();
			
			ImGui::TableSetColumnIndex(1);
			ImGui::BeginGroupPanel(u8"自动宝箱");
			{
				ConfigWidget(u8"启用", f_AutoTreasure, u8"自动打开宝箱和其他宝藏。\n" \
					u8"注意：将其与自定义范围和低延迟时间一起使用是非常危险的。\n" \
					u8"滥用肯定会被封禁。\n\n" \
					u8"如果使用自定义范围，请确保首先打开它。");
				ImGui::SameLine();
				ImGui::TextColored(ImColor(255, 165, 0, 255), u8"使用必读!");
				ImGui::Indent();
				ConfigWidget(u8"箱子", f_Chest, u8"普通的、珍贵的、豪华的等等。");
				ConfigWidget(u8"地脉之花", f_Leyline, u8"摩拉/经验, 世界/战利品 boss等.");
				ConfigWidget(u8"搜索", f_Investigate, u8"标记为调查/搜索等。");
				ConfigWidget(u8"任务互动", f_QuestInteract, u8"有效的任务交互点。");
				ConfigWidget(u8"其他", f_Others, u8"书页、自旋晶体等");
				ImGui::Unindent();
			}
			ImGui::EndGroupPanel();
			ImGui::EndTable();
		}
			
    	ImGui::BeginGroupPanel(u8"拾取筛选器");
	    {
			ConfigWidget(u8"启用", f_PickupFilter, u8"启用掉落物过滤器。\n");
			ConfigWidget(u8"动物", f_PickupFilter_Animals, u8"鱼，蜥蜴，青蛙，飞行动物。"); ImGui::SameLine();
			ConfigWidget(u8"掉落物", f_PickupFilter_DropItems, u8"材料，矿物，人工制品。."); ImGui::SameLine();
			ConfigWidget(u8"资源", f_PickupFilter_Resources, u8"除了动物和掉落物品（植物、书籍等）之外的所有东西。");
	    }
    	ImGui::EndGroupPanel();
    }

    bool AutoLoot::NeedStatusDraw() const
	{
        return f_AutoPickup || f_AutoTreasure || f_UseCustomRange || f_PickupFilter;
    }

    void AutoLoot::DrawStatus() 
    {
		ImGui::Text(u8"自动掠取\n[%s%s%s%s%s]",
			f_AutoPickup ? "AP" : "",
			f_AutoTreasure ? fmt::format("{}AT", f_AutoPickup ? "|" : "").c_str() : "",
			f_UseCustomRange ? fmt::format("{}CR{:.1f}m", f_AutoPickup || f_AutoTreasure ? "|" : "", f_CustomRange.value()).c_str() : "",
			f_PickupFilter ? fmt::format("{}PF", f_AutoPickup || f_AutoTreasure || f_UseCustomRange ? "|" : "").c_str() : "",
			f_AutoPickup || f_AutoTreasure ? fmt::format("|{}ms", f_DelayTime.value()).c_str() : ""
		);
    }

    AutoLoot& AutoLoot::GetInstance()
    {
        static AutoLoot instance;
        return instance;
    }

	bool AutoLoot::OnCreateButton(app::BaseEntity* entity)
	{
		if (!f_AutoPickup)
			return false;

		auto itemModule = GET_SINGLETON(MoleMole_ItemModule);
		if (itemModule == nullptr)
			return false;
    	
		auto entityId = entity->fields._runtimeID_k__BackingField;
		if (f_DelayTime == 0)
		{
			app::MoleMole_ItemModule_PickItem(itemModule, entityId, nullptr);
			return true;
		}

		toBeLootedItems.push(entityId);
		return false;
	}

	void AutoLoot::OnGameUpdate()
	{
		auto currentTime = util::GetCurrentTimeMillisec();
		if (currentTime < nextLootTime)
			return;

		auto entityManager = GET_SINGLETON(MoleMole_EntityManager);
		if (entityManager == nullptr)
			return;

		// RyujinZX#6666
		if (f_AutoTreasure) 
		{
			auto& manager = game::EntityManager::instance();
			for (auto& entity : manager.entities(game::filters::combined::Chests)) 
			{
				float range = f_UseCustomRange ? f_CustomRange : 3.5f;
				if (manager.avatar()->distance(entity) >= range)
					continue;

				auto chest = reinterpret_cast<game::Chest*>(entity);
				auto chestType = chest->itemType();

				if (!f_Investigate && chestType == game::Chest::ItemType::Investigate)
					continue;

				if (!f_QuestInteract && chestType == game::Chest::ItemType::QuestInteract)
					continue;

				if (!f_Others && (
					chestType == game::Chest::ItemType::BGM ||
					chestType == game::Chest::ItemType::BookPage
					))
					continue;

				if (!f_Leyline && chestType == game::Chest::ItemType::Flora)
					continue;

				if (chestType == game::Chest::ItemType::Chest)
				{
					if (!f_Chest)
						continue;
					auto ChestState = chest->chestState();
					if (ChestState != game::Chest::ChestState::None)
						continue;
				}

				uint32_t entityId = entity->runtimeID();
				toBeLootedItems.push(entityId);
			}
		}

		auto entityId = toBeLootedItems.pop();
		if (!entityId)
			return;

		auto itemModule = GET_SINGLETON(MoleMole_ItemModule);
		if (itemModule == nullptr)
			return;

		auto entity = app::MoleMole_EntityManager_GetValidEntity(entityManager, *entityId, nullptr);
		if (entity == nullptr)
			return;

		app::MoleMole_ItemModule_PickItem(itemModule, *entityId, nullptr);
		nextLootTime = currentTime + (int)f_DelayTime;
	}

	void AutoLoot::OnCheckIsInPosition(bool& result, app::BaseEntity* entity)
	{
		if (f_AutoPickup || f_UseCustomRange) {
			float pickupRange = f_UseCustomRange ? f_CustomRange : 3.5f;
			if (f_PickupFilter)
			{
				if (!f_PickupFilter_Animals && entity->fields.entityType == app::EntityType__Enum_1::EnvAnimal ||
					!f_PickupFilter_DropItems && entity->fields.entityType == app::EntityType__Enum_1::DropItem ||
					!f_PickupFilter_Resources && entity->fields.entityType == app::EntityType__Enum_1::GatherObject)
				{
					result = false;
					return;
				}
			}
			
			auto& manager = game::EntityManager::instance();
			result = manager.avatar()->distance(entity) < pickupRange;
		}
	}

	static void LCSelectPickup_AddInteeBtnByID_Hook(void* __this, app::BaseEntity* entity, MethodInfo* method)
	{
		AutoLoot& autoLoot = AutoLoot::GetInstance();
		bool canceled = autoLoot.OnCreateButton(entity);
		if (!canceled)
			CALL_ORIGIN(LCSelectPickup_AddInteeBtnByID_Hook, __this, entity, method);
	}

	static bool LCSelectPickup_IsInPosition_Hook(void* __this, app::BaseEntity* entity, MethodInfo* method)
	{
		bool result = CALL_ORIGIN(LCSelectPickup_IsInPosition_Hook, __this, entity, method);

		AutoLoot& autoLoot = AutoLoot::GetInstance();
		autoLoot.OnCheckIsInPosition(result, entity);

		return result;
	}

	static bool LCSelectPickup_IsOutPosition_Hook(void* __this, app::BaseEntity* entity, MethodInfo* method)
	{
		bool result = CALL_ORIGIN(LCSelectPickup_IsOutPosition_Hook, __this, entity, method);

		AutoLoot& autoLoot = AutoLoot::GetInstance();
		autoLoot.OnCheckIsInPosition(result, entity);

		return result;
	}
}

