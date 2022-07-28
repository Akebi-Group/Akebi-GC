#include "pch-il2cpp.h"
#include "ChestTeleport.h"

#include <helpers.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/Chest.h>
#include <cheat/game/util.h>
#include <cheat/teleport/MapTeleport.h>

namespace cheat::feature 
{

    ChestTeleport::ChestTeleport() : ItemTeleportBase("ChestTeleport", u8"����"),
        NF(f_FilterChestLocked    , u8"����",       "ChestTeleport", true),
		NF(f_FilterChestInRock    , u8"��ʯ�е�",      "ChestTeleport", true),
		NF(f_FilterChestFrozen    , u8"�䶳�е�",       "ChestTeleport", true),
		NF(f_FilterChestBramble   , u8"�����е�",      "ChestTeleport", true),
		NF(f_FilterChestTrap      , u8"�����е�",         "ChestTeleport", true),

		NF(f_FilterChestCommon    , u8"��ͨ",       "ChestTeleport", true),
		NF(f_FilterChestExquisite , u8"����",    "ChestTeleport", true),
		NF(f_FilterChestPrecious  , u8"����",     "ChestTeleport", true),
		NF(f_FilterChestLuxurious , u8"����",    "ChestTeleport", true),
		NF(f_FilterChestRemarkable, u8"׿Խ",   "ChestTeleport", true),

		NF(f_FilterChest          , u8"����",       "ChestTeleport", true),
		NF(f_FilterInvestigates   , u8"����", "ChestTeleport", false),
		NF(f_FilterBookPage       , u8"��ҳ",   "ChestTeleport", false),
		NF(f_FilterBGM            , u8"BGMs",         "ChestTeleport", false),
		NF(f_FilterQuestInt       , u8"��������",  "ChestTeleport", false),
		NF(f_FilterFloraChest     , u8"ֲ�ﱦ��",  "ChestTeleport", false),

		NF(f_FilterUnknown        , u8"δ֪", "ChestTeleport", true)
	{ }


    void cheat::feature::ChestTeleport::DrawFilterOptions()
    {
		ConfigWidget(f_ShowInfo, u8"����Ϣ������ʾ��������ӵļ����Ϣ.");

		if (ImGui::TreeNode(u8"������Filters"))
		{

			ImGui::Text(u8"���͹�����");

			ConfigWidget(f_FilterChest, u8"���ñ�����͹�������");
			ConfigWidget(f_FilterInvestigates);
			ConfigWidget(f_FilterBookPage);
			ConfigWidget(f_FilterBGM);
			ConfigWidget(f_FilterQuestInt);
			ConfigWidget(f_FilterFloraChest);
			ConfigWidget(f_FilterUnknown, u8"���ö�δ֪��Ŀ�ļ�⡣\n������������鿴��Щ��Ŀ��������ڣ���");

			ImGui::Spacing();

			if (!f_FilterChest)
				ImGui::BeginDisabled();

			if (ImGui::BeginTable(u8"���������", 2, ImGuiTableFlags_NoBordersInBody))
			{
				ImGui::TableNextColumn();
				ImGui::Text(u8"ϡ�й�����");

				ImGui::TableNextColumn();
				ImGui::Text(u8"״̬������");

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
		static const FeatureGUIInfo info{ u8"���䴫��", u8"����", true };
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
		if (!ImGui::TreeNode(u8"��Ʒ"))
			return;

		auto& manager = game::EntityManager::instance();
		auto entities = manager.entities(*this);

		ImGui::BeginTable(u8"�����", 2);
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

			if (ImGui::Button(u8"����"))
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

		ImGui::TextColored(ImColor(255, 165, 0, 255), u8"�ۣ��㷢����δ֪�ı������ơ� ����ζ�����ֱ������ͻ�û�й�������");
		TextURL(u8"�뽫�˷�����Github", "https://github.com/CallowBlack/genshin-cheat/issues/48", false, false);
		
		if (ImGui::Button(u8"����"))
		{
			ImGui::LogToClipboard();

			ImGui::LogText(u8"δ֪����:\n");
			
			for (auto& entity : unknowns)
				ImGui::LogText(u8"%s; �ص�: %s; ����: %u\n", entity->name().c_str(),
					il2cppi_to_string(entity->relativePosition()).c_str(), game::GetCurrentPlayerSceneID());
			
			ImGui::LogFinish();
		}

		if (!ImGui::TreeNode(u8"δ֪��Ʒ"))
			return;

		ImGui::BeginTable(u8"λ���б�", 2);

		for (auto& entity : unknowns)
		{
			ImGui::PushID(entity);
			
			ImGui::TableNextColumn();
			ImGui::Text(u8"%s. ���� %0.3f", entity->name().c_str(), manager.avatar()->distance(entity));
			
			ImGui::TableNextColumn();
			if (ImGui::Button(u8"����"))
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

