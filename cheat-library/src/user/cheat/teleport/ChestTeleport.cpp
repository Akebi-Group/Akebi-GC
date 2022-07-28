#include "pch-il2cpp.h"
#include "ChestTeleport.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/Chest.h>
#include <cheat/game/util.h>
#include <cheat/teleport/MapTeleport.h>

namespace cheat::feature 
{

    ChestTeleport::ChestTeleport() : ItemTeleportBase("ChestTeleport", u8"箱子"),
        NF(f_FilterChestLocked    , u8"锁定",       "ChestTeleport", true),
		NF(f_FilterChestInRock    , u8"岩石中的",      "ChestTeleport", true),
		NF(f_FilterChestFrozen    , u8"冷冻中的",       "ChestTeleport", true),
		NF(f_FilterChestBramble   , u8"荆棘中的",      "ChestTeleport", true),
		NF(f_FilterChestTrap      , u8"陷阱中的",         "ChestTeleport", true),

		NF(f_FilterChestCommon    , u8"普通",       "ChestTeleport", true),
		NF(f_FilterChestExquisite , u8"精美",    "ChestTeleport", true),
		NF(f_FilterChestPrecious  , u8"宝贵",     "ChestTeleport", true),
		NF(f_FilterChestLuxurious , u8"华丽",    "ChestTeleport", true),
		NF(f_FilterChestRemarkable, u8"卓越",   "ChestTeleport", true),

		NF(f_FilterChest          , u8"宝箱",       "ChestTeleport", true),
		NF(f_FilterInvestigates   , u8"调查", "ChestTeleport", false),
		NF(f_FilterBookPage       , u8"书页",   "ChestTeleport", false),
		NF(f_FilterBGM            , u8"BGMs",         "ChestTeleport", false),
		NF(f_FilterQuestInt       , u8"箱子搜索",  "ChestTeleport", false),
		NF(f_FilterFloraChest     , u8"植物宝箱",  "ChestTeleport", false),

		NF(f_FilterUnknown        , u8"未知", "ChestTeleport", true)
	{ }


    void cheat::feature::ChestTeleport::DrawFilterOptions()
    {
		ConfigWidget(f_ShowInfo, u8"在信息窗口显示最近的箱子的简短信息.");

		if (ImGui::TreeNode(u8"过滤器Filters"))
		{

			ImGui::Text(u8"类型过滤器");

			ConfigWidget(f_FilterChest, u8"启用宝箱检测和过滤器。");
			ConfigWidget(f_FilterInvestigates);
			ConfigWidget(f_FilterBookPage);
			ConfigWidget(f_FilterBGM);
			ConfigWidget(f_FilterQuestInt);
			ConfigWidget(f_FilterFloraChest);
			ConfigWidget(f_FilterUnknown, u8"启用对未知项目的检测。\n您可以在下面查看这些项目（如果存在）。");

			ImGui::Spacing();

			if (!f_FilterChest)
				ImGui::BeginDisabled();

			if (ImGui::BeginTable(u8"宝箱过滤器", 2, ImGuiTableFlags_NoBordersInBody))
			{
				ImGui::TableNextColumn();
				ImGui::Text(u8"稀有过滤器");

				ImGui::TableNextColumn();
				ImGui::Text(u8"状态过滤器");

				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestCommon);

				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestLocked);


				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestExquisite);

				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestInRock);


				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestPrecious);

				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestFrozen);


				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestLuxurious);

				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestBramble);


				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestRemarkable);

				ImGui::TableNextColumn();
				ConfigWidget(f_FilterChestTrap);

				ImGui::EndTable();
			}

			if (!f_FilterChest)
				ImGui::EndDisabled();

			ImGui::TreePop();
		}
    }

	const FeatureGUIInfo& ChestTeleport::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ u8"宝箱传送", u8"传送", true };
		return info;
	}

    ChestTeleport& ChestTeleport::GetInstance()
	{
		static ChestTeleport instance;
		return instance;
	}

	bool ChestTeleport::IsValid(game::Entity* entity) const
	{
		if (!entity->isChest())
			return false;

		auto chest = reinterpret_cast<game::Chest*>(entity);
		auto filterResult = FilterChest(chest);
		return filterResult == ChestTeleport::FilterStatus::Valid ||
			(filterResult == ChestTeleport::FilterStatus::Unknown && f_FilterUnknown);
	}

	cheat::feature::ChestTeleport::FilterStatus ChestTeleport::FilterChest(game::Chest* entity) const
	{
		auto itemType = entity->itemType();
		switch (itemType)
		{
		case game::Chest::ItemType::Chest:
		{
			if (!f_FilterChest)
				return FilterStatus::Invalid;
			
			auto chestRarity = entity->chestRarity();
			if (chestRarity == game::Chest::ChestRarity::Unknown)
				return FilterStatus::Unknown;
			
			bool rarityValid = (chestRarity == game::Chest::ChestRarity::Common && f_FilterChestCommon) ||
				(chestRarity == game::Chest::ChestRarity::Exquisite  && f_FilterChestExquisite) ||
				(chestRarity == game::Chest::ChestRarity::Precious   && f_FilterChestPrecious) ||
				(chestRarity == game::Chest::ChestRarity::Luxurious  && f_FilterChestLuxurious) ||
				(chestRarity == game::Chest::ChestRarity::Remarkable && f_FilterChestRemarkable);

			if (!rarityValid)
				return FilterStatus::Invalid;

			auto chestState = entity->chestState();
			if (chestState == game::Chest::ChestState::Invalid)
				return FilterStatus::Invalid;

			bool chestStateValid = chestState == game::Chest::ChestState::None ||
				(chestState == game::Chest::ChestState::Locked  && f_FilterChestLocked) ||
				(chestState == game::Chest::ChestState::InRock  && f_FilterChestInRock) ||
				(chestState == game::Chest::ChestState::Frozen  && f_FilterChestFrozen) ||
				(chestState == game::Chest::ChestState::Bramble && f_FilterChestBramble) ||
				(chestState == game::Chest::ChestState::Trap    && f_FilterChestTrap);

			if (!chestStateValid)
				return FilterStatus::Invalid;

			return FilterStatus::Valid;
		}
		case game::Chest::ItemType::Investigate:
			return f_FilterInvestigates ? FilterStatus::Valid : FilterStatus::Invalid;
		case game::Chest::ItemType::BookPage:
			return f_FilterBookPage ? FilterStatus::Valid : FilterStatus::Invalid;
		case game::Chest::ItemType::BGM:
			return f_FilterBGM ? FilterStatus::Valid : FilterStatus::Invalid;
		case game::Chest::ItemType::QuestInteract:
			return f_FilterQuestInt ? FilterStatus::Valid : FilterStatus::Invalid;
		case game::Chest::ItemType::Flora:
			return f_FilterFloraChest ? FilterStatus::Valid : FilterStatus::Invalid;
		case game::Chest::ItemType::None:
		default:
			return FilterStatus::Unknown;
		}

		return FilterStatus::Unknown;
	}

	void ChestTeleport::DrawItems()
	{
		DrawUnknowns();
		DrawChests();
	}

	bool ChestTeleport::NeedInfoDraw() const
	{
		return true;
	}

	void ChestTeleport::DrawInfo()
	{
		auto entity = game::FindNearestEntity(*this);
		auto chest = reinterpret_cast<game::Chest*>(entity);

		DrawEntityInfo(entity);
		if (entity == nullptr)
			return;
		ImGui::SameLine();

		ImGui::TextColored(chest->chestColor(), "%s", chest->minName().c_str());
	}

	void ChestTeleport::DrawChests()
	{	
		if (!ImGui::TreeNode(u8"物品"))
			return;

		auto& manager = game::EntityManager::instance();
		auto entities = manager.entities(*this);

		ImGui::BeginTable(u8"宝箱表", 2);
		for (auto& entity : entities)
		{
			ImGui::PushID(entity);
			auto chest = reinterpret_cast<game::Chest*>(entity);

			ImGui::TableNextColumn();
			if (chest->itemType() == game::Chest::ItemType::Chest)
			{
				ImGui::TextColored(chest->chestColor(), "%s [%s] [%s] at %0.3fm", 
					magic_enum::enum_name(chest->itemType()).data(),
					magic_enum::enum_name(chest->chestRarity()).data(),
					magic_enum::enum_name(chest->chestState()).data(),
					manager.avatar()->distance(entity));
			}
			else
			{
				ImGui::TextColored(chest->chestColor(), "%s at %0.3fm", magic_enum::enum_name(chest->itemType()).data(), 
					manager.avatar()->distance(entity));
			}

			ImGui::TableNextColumn();

			if (ImGui::Button(u8"传送"))
			{
				auto& mapTeleport = MapTeleport::GetInstance();
				mapTeleport.TeleportTo(chest->absolutePosition());
			}
			ImGui::PopID();
		}
		ImGui::EndTable();
		ImGui::TreePop();
	}

	static bool ChestUnknownFilter(game::Entity* entity)
	{
		if (!entity->isChest())
			return false;

		auto chest = reinterpret_cast<game::Chest*>(entity);
		auto& chestTp = ChestTeleport::GetInstance();
		return chestTp.FilterChest(chest) == ChestTeleport::FilterStatus::Unknown;
	}

	void ChestTeleport::DrawUnknowns()
	{
		auto& manager = game::EntityManager::instance();
		auto unknowns = manager.entities(ChestUnknownFilter);
		if (unknowns.empty())
			return;

		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"哇，你发现了未知的宝箱名称。 这意味着这种宝箱类型还没有过滤器。");
		TextURL(u8"请将此反馈到Github", "https://github.com/CallowBlack/genshin-cheat/issues/48", false, false);
		
		if (ImGui::Button(u8"复制"))
		{
			ImGui::LogToClipboard();

			ImGui::LogText(u8"未知名称:\n");
			
			for (auto& entity : unknowns)
				ImGui::LogText(u8"%s; 地点: %s; 场景: %u\n", entity->name().c_str(),
					il2cppi_to_string(entity->relativePosition()).c_str(), game::GetCurrentPlayerSceneID());
			
			ImGui::LogFinish();
		}

		if (!ImGui::TreeNode(u8"未知物品"))
			return;

		ImGui::BeginTable(u8"位置列表", 2);

		for (auto& entity : unknowns)
		{
			ImGui::PushID(entity);
			
			ImGui::TableNextColumn();
			ImGui::Text(u8"%s. 距离 %0.3f", entity->name().c_str(), manager.avatar()->distance(entity));
			
			ImGui::TableNextColumn();
			if (ImGui::Button(u8"传送"))
			{
				auto& mapTeleport = MapTeleport::GetInstance();
				mapTeleport.TeleportTo(entity->absolutePosition());
			}

			ImGui::PopID();
		}
		ImGui::EndTable();
		ImGui::TreePop();
	}



}

