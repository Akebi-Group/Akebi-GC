#include "pch-il2cpp.h"
#include "GenshinCM.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/util.h>

#define ACTIVE_COLOR ImColor(0.13f, 0.8f, 0.08f)

cheat::GenshinCM& cheat::GenshinCM::instance()
{
	static GenshinCM instance;
	return instance;
}

void cheat::GenshinCM::CursorSetVisibility(bool visibility)
{
	app::Cursor_set_visible(visibility, nullptr);
	app::Cursor_set_lockState(visibility ? app::CursorLockMode__Enum::None : app::CursorLockMode__Enum::Locked, nullptr);
}

bool cheat::GenshinCM::CursorGetVisibility()
{
	return app::Cursor_get_visible(nullptr);
}

cheat::GenshinCM::GenshinCM() :
	NFEX(f_AccConfig, "Account Config", "data", "General::Multi-Account", internal::AccountConfig(), true),
	NFS(f_ShowType,   "Name show type",         "General::Multi-Account", ShowType::Pseudo)
{
	events::AccountChangedEvent += MY_METHOD_HANDLER(cheat::GenshinCM::OnAccountChanged);
}


bool cheat::GenshinCM::IsAccountAttached(uint32_t userID, const std::string& profileName)
{
	auto& profiles = f_AccConfig.value().id2Profiles;
	return profiles.count(userID) > 0 && profiles[m_CurrentAccount.userID] == profileName;
}

std::string cheat::GenshinCM::GetAccountDisplayName(uint32_t uid)
{
	switch (f_ShowType.value())
	{
	case ShowType::Nickname:
		return uid == m_CurrentAccount.userID ? m_CurrentAccount.nickName : f_AccConfig.value().accounts[uid].nickName;
	case ShowType::UserID:
		return std::to_string(uid == m_CurrentAccount.userID ? m_CurrentAccount.userID : uid);
	case ShowType::Pseudo:
	default:
	{
		auto& pseudos = f_AccConfig.value().pseudos;
		return pseudos.count(uid) == 0 ? m_CurrentAccount.nickName : pseudos[uid];
	}
		break;
	}
}

void cheat::GenshinCM::DetachAccount(uint32_t uid, const std::string& profileName)
{
	auto& accConfig = f_AccConfig.value();
	accConfig.id2Profiles.erase(uid);
	accConfig.accounts.erase(uid);
	accConfig.profiles2id[profileName].erase(uid);

	f_AccConfig.FireChanged();
}

void cheat::GenshinCM::AttachAccount(uint32_t uid, const std::string& profileName)
{
	auto& accConfig = f_AccConfig.value();

	if (accConfig.id2Profiles.count(uid) > 0)
	{
		auto prevProfile = accConfig.id2Profiles[uid];
		accConfig.profiles2id[prevProfile].erase(uid);
	}

	accConfig.id2Profiles[uid] = profileName;
	accConfig.accounts[uid] = m_CurrentAccount;
	accConfig.profiles2id[profileName].insert(uid);

	if (accConfig.pseudos.count(uid) == 0)
		accConfig.pseudos[uid] = m_CurrentAccount.nickName;

	f_AccConfig.FireChanged();
}

void cheat::GenshinCM::DrawProfileEntryActivities(const std::string& profileName)
{
	CheatManagerBase::DrawProfileEntryActivities(profileName);

	ImGui::SameLine();

	if (m_CurrentAccount.userID == 0)
		ImGui::BeginDisabled();

	auto& profiles = f_AccConfig.value().id2Profiles;
	bool isAccountAttached = IsAccountAttached(m_CurrentAccount.userID, profileName);
	if (ImGui::SmallButton(isAccountAttached ? "-" : "+"))
	{
		if (isAccountAttached)
			DetachAccount(m_CurrentAccount.userID, profileName);
		else
			AttachAccount(m_CurrentAccount.userID, profileName);
	}

	if (ImGui::IsItemHovered())
		ImGui::SetTooltip(isAccountAttached ? "Dettach" : "Attach");

	if (m_CurrentAccount.userID == 0)
		ImGui::EndDisabled();

	ImGui::SameLine();

	if (ImGui::SmallButton("Acl"))
		ImGui::OpenPopup("Account list");
	if (ImGui::IsItemHovered())
		ImGui::SetTooltip("Account list");

	if (ImGui::BeginPopup("Account list", ImGuiWindowFlags_AlwaysAutoResize))
	{
		DrawAccountsList(profileName);
		ImGui::EndPopup();
	}
}

void cheat::GenshinCM::DrawProfileEntry(const std::string& profileName)
{
	CheatManagerBase::DrawProfileEntry(profileName);
	ImGui::TableNextColumn();

	auto& profileIds = f_AccConfig.value().profiles2id;
	auto accountCount = profileIds.count(profileName) > 0 ? profileIds[profileName].size() : 0;
	if (accountCount == 0)
	{
		ImGui::Text("No accounts.");
		return;
	}

	ImColor textColor = IsAccountAttached(m_CurrentAccount.userID, profileName) ? ACTIVE_COLOR : ImColor(ImGui::GetColorU32(ImGuiCol_Text));
	ImGui::TextColored(textColor, "%d account%s", accountCount, accountCount > 1 ? "s" : "");
}

void cheat::GenshinCM::DrawProfileTableHeader()
{
	CheatManagerBase::DrawProfileTableHeader();
	ImGui::TableSetupColumn("Accounts");
}

int cheat::GenshinCM::GetProfileTableColumnCount()
{
	return CheatManagerBase::GetProfileTableColumnCount() + 1;
}

void cheat::GenshinCM::DrawAccountsList(const std::string& profileName)
{
	static ImGuiTableFlags flags =
		ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable
		| ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_NoBordersInBody
		| ImGuiTableFlags_ScrollY;
	if (ImGui::BeginTable("Accounts", 2, flags,
		ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 10), 0.0f))
	{
		ImGui::TableSetupColumn("Name");
		ImGui::TableSetupColumn("Actions");
		ImGui::TableSetupScrollFreeze(0, 1);
		ImGui::TableHeadersRow();

		// Perform copying due to we can change values
		auto userIDs = f_AccConfig.value().profiles2id[profileName];
		for (auto& userID : userIDs)
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			ImGui::PushID(userID);

			std::string name = GetAccountDisplayName(userID);
			ImColor nameColor = m_CurrentAccount.userID == userID ? ACTIVE_COLOR : ImColor(ImGui::GetColorU32(ImGuiCol_Text));
			ImGui::TextColored(nameColor, name.c_str());

			ImGui::TableNextColumn();

			if (ImGui::Button("Remove"))
				DetachAccount(userID, profileName);

			ImGui::SameLine();

			DrawPseudoRename(userID);

			ImGui::PopID();
		}

		ImGui::EndTable();
	}
}

void cheat::GenshinCM::DrawProfileLine()
{
	CheatManagerBase::DrawProfileLine();

	if (m_CurrentAccount.userID == 0)
		return;

	auto& currentProfile = config::CurrentProfileName();
	std::string name = GetAccountDisplayName(m_CurrentAccount.userID);

	constexpr float buttonWidth = 75.0f;
	auto innerSpacing = ImGui::GetStyle().ItemInnerSpacing.x;
	auto textWidth = CalcWidth(name);
	auto width = textWidth + innerSpacing + buttonWidth;

	auto position = max(ImGui::GetCursorPosX() + innerSpacing + 130.0f, ImGui::GetContentRegionAvail().x - width + 20.0f);

	ImGui::SameLine(position);

	bool accountAttached = IsAccountAttached(m_CurrentAccount.userID, currentProfile);

	ImColor textColor = accountAttached ? ACTIVE_COLOR : ImColor(ImGui::GetColorU32(ImGuiCol_Text));
	ImGui::TextColored(textColor, name.c_str()); ImGui::SameLine();

	if (ImGui::Button(accountAttached ? "Deattach" : "Attach", ImVec2(buttonWidth, 0.0f)))
	{
		if (accountAttached)
			DetachAccount(m_CurrentAccount.userID, currentProfile);
		else
			AttachAccount(m_CurrentAccount.userID, currentProfile);
	}
}

void cheat::GenshinCM::DrawProfileConfiguration()
{
	ConfigWidget(f_ShowType, "Set accounts' name showing type.");
	auto& pseudos = f_AccConfig.value().pseudos;
	if (pseudos.count(m_CurrentAccount.userID) > 0)
	{
		ImGui::Text("Pseudo: %s", pseudos[m_CurrentAccount.userID].c_str()); ImGui::SameLine();
		DrawPseudoRename(m_CurrentAccount.userID);
	}
	
	CheatManagerBase::DrawProfileConfiguration();
}


void cheat::GenshinCM::DrawPseudoRename(uint32_t userID)
{
	auto& pseudo = f_AccConfig.value().pseudos[userID];
	if (ImGui::Button("Rename (Pseudo)"))
		ImGui::OpenRenamePopup(pseudo);

	if (ImGui::DrawRenamePopup(pseudo))
		f_AccConfig.FireChanged();
}

void cheat::GenshinCM::OnAccountChanged(uint32_t userID)
{
	auto accountData = game::GetAccountData();
	if (accountData == nullptr)
	{
		m_CurrentAccount.userID = 0;
		return;
	}

	m_CurrentAccount.nickName = il2cppi_to_string(accountData->fields.nickName);
	m_CurrentAccount.userID = accountData->fields.userId;

	auto& profiles = f_AccConfig.value().id2Profiles;
	if (profiles.count(m_CurrentAccount.userID) == 0)
		return;

	config::ChangeProfile(profiles[m_CurrentAccount.userID]);

	auto& settings = feature::Settings::GetInstance();

	ImGuiToast toast(ImGuiToastType_Info, settings.f_NotificationsDelay.value(), "Account was updated.\nConfig profile was changed.");
	toast.set_title("Config multi-account");
	ImGui::InsertNotification(toast);
}