#include "pch-il2cpp.h"
#include "CustomTeleports.h"

#include <helpers.h>
#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include "MapTeleport.h"
#include <cheat/game/util.h>
#include <misc/cpp/imgui_stdlib.h>
#include <filesystem>
#include <fstream>
#include <regex>
#include <imgui_internal.h>
#include "shlwapi.h"
#pragma comment(lib, "shlwapi.lib")

namespace cheat::feature
{
	CustomTeleports::CustomTeleports() : Feature(),
		NF(f_DebugMode, "Debug Mode", "CustomTeleports", false), // Soon to be added
		NF(f_Enabled, "Custom Teleport", "CustomTeleports", false),
		NF(f_Next, "Teleport Next", "CustomTeleports", Hotkey(VK_OEM_6)),
		NF(f_Previous, "Teleport Previous", "CustomTeleports", Hotkey(VK_OEM_4))
	{
		f_Next.value().PressedEvent += MY_METHOD_HANDLER(CustomTeleports::OnNextKeyPressed);
		f_Previous.value().PressedEvent += MY_METHOD_HANDLER(CustomTeleports::OnPreviousKeyPressed);
	}
	const FeatureGUIInfo& CustomTeleports::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Custom Teleports", "Teleport", true };
		return info;
	}

	void CustomTeleports::DrawMain()
	{
		auto& entityManager = game::EntityManager::instance();
		auto& MapTeleport = MapTeleport::GetInstance();
		static std::string teleportName;
		static std::string search;
		app::Vector3 pos = app::ActorUtils_GetAvatarPos(nullptr);

		ImGui::InputText("Teleport name", &teleportName);
		if (ImGui::Button("Add Teleport"))
		{
			// check if name is valid and doesnt  contain special characters
			if (teleportName.find_first_of("\\/:*?\"<>|") != std::string::npos)
				return;

			// check if already added
			if (std::any_of(teleports.begin(), teleports.end(), [](const auto& pair)
				{ return pair.first == teleportName; }))
				return;

			selectedIndex = -1;
			teleports.push_back({ teleportName, pos });

			auto dir = std::filesystem::current_path();
			dir /= "teleports";
			if (!std::filesystem::exists(dir))
				std::filesystem::create_directory(dir);
			std::ofstream ofs(dir / (teleportName + ".json"));
			nlohmann::json j;
			j["name"] = teleportName;
			j["position"] = { pos.x, pos.y, pos.z };
			ofs << j;
			teleportName.clear();
		}
		ImGui::SameLine();
		if (ImGui::Button("Reload"))
		{
			selectedIndex = -1;
			auto dir = std::filesystem::current_path();
			dir /= "teleports";
			auto result = std::filesystem::directory_iterator(dir);
			teleports.clear();
			for (auto& file : result)
			{
				if (file.path().extension() != ".json")
					continue;

				std::string name = file.path().stem().string();
				if (file.is_directory())
					continue;

				std::ifstream ifs(file.path());
				nlohmann::json j;
				ifs >> j;
				teleports.push_back({ j["name"], {j["position"][0], j["position"][1], j["position"][2]} });
				LOG_INFO("Loaded teleport %s", name.c_str());
			}
		}
		ImGui::SameLine();
		// open directory
		if (ImGui::Button("Open Folder"))
		{
			auto dir = std::filesystem::current_path();
			dir /= "teleports";
			ShellExecuteA(NULL, "open", dir.string().c_str(), NULL, NULL, SW_SHOW);
		}
		ImGui::SameLine();
		static std::string jsonInput;
		if (ImGui::Button("Load from JSON"))
		{
			selectedIndex = -1;
			auto dir = std::filesystem::current_path();
			dir /= "teleports";
			LOG_INFO("Defined dir");
			if (!std::filesystem::exists(dir))
				std::filesystem::create_directory(dir);
			nlohmann::json j;
			try
			{
				j = nlohmann::json::parse(jsonInput);
			}
			catch (nlohmann::json::parse_error& e)
			{
				LOG_ERROR("Failed to parse JSON: %s", e.what());
				return;
			}
			LOG_INFO("Parsed JSON");
			std::string teleportName = j["name"];
			app::Vector3 pos = { j["position"][0], j["position"][1], j["position"][2] };
			teleports.push_back({ teleportName, pos });
			LOG_INFO("Loaded teleport %s", teleportName.c_str());
			std::ofstream ofs(dir / (teleportName + ".json"));
			ofs << jsonInput;
			jsonInput.clear();
		}
		ImGui::InputTextMultiline("JSON input", &jsonInput, ImVec2(0, 50), ImGuiInputTextFlags_AllowTabInput);

		ConfigWidget("Teleport Next", f_Next, true, "Press to teleport next of selected");
		ConfigWidget("Teleport Previous", f_Previous, true, "Press to teleport previous of selected");
		ConfigWidget("Enable",
			f_Enabled,
			"Enable teleport-through-list functionality\n" \
			"Usage:\n" \
			"1. Put Checkmark to the teleports you want to teleport using hotkey\n" \
			"2. Single click the teleport (with checkmark) to select where you want to start\n" \
			"3. You can now press Next or Previous Hotkey to Teleport through the Checklist\n" \
			"Initially it will teleport the player to the selection made\n" \
			"Note: Double click or click the arrow to open teleport details");
		ImGui::SameLine();
		if (ImGui::Button("Delete Checked"))
		{
			if (!teleports.empty()) {
				std::vector<std::string> teleportNames;
				// get all teleport names by index
				for (auto& i : checkedIndices) {
					teleportNames.push_back(teleports.at(i).first);
					if (selectedIndex == i) selectedIndex = -1;
				}

				for (auto& name : teleportNames) {
					auto dir = std::filesystem::current_path();
					dir /= "teleports";
					// delete file
					std::filesystem::remove(dir / (name + ".json"));
					// remove from list
					teleports.erase(std::remove_if(teleports.begin(), teleports.end(), [&name](const auto& pair)
						{ return pair.first == name; }), teleports.end());
				}
				checkedIndices.clear();
				UpdateIndexName();
			}

		}
		ImGui::SameLine();
		HelpMarker("Warning: This will delete the file from the directory and\nremove the teleport from the list. It will be lost forever.");

		if (ImGui::TreeNode("Teleports"))
		{

			// using natural sort instead of ascii sort
			std::sort(teleports.begin(), teleports.end(), [](const auto& a, const auto& b)
				{ return StrCmpLogicalW(std::wstring(a.first.begin(), a.first.end()).c_str(), std::wstring(b.first.begin(), b.first.end()).c_str()) < 0; });

			bool allSearchChecked = std::includes(checkedIndices.begin(), checkedIndices.end() ,searchIndices.begin(), searchIndices.end()) && !searchIndices.empty();
			bool allChecked = (checkedIndices.size() == teleports.size() && !teleports.empty()) || allSearchChecked;
			ImGui::Checkbox("All", &allChecked);
			if (ImGui::IsItemClicked()) {
				if (!teleports.empty()) {
					if (allChecked) {
						selectedIndex = -1;
						if (!searchIndices.empty()) {
							checkedIndices.erase(searchIndices.begin(), searchIndices.end());
						}
						else {
							checkedIndices.clear();
						}
					}
					else {
						if (!searchIndices.empty()) {
							checkedIndices.insert(searchIndices.begin(), searchIndices.end());
						}
						else {
							for (int i = 0; i < teleports.size(); i++)
								checkedIndices.insert(i);
						}
					}
					UpdateIndexName();
				}
			}
			ImGui::SameLine();
			ImGui::InputText("Search", &search);
			unsigned int index = 0;
			searchIndices.clear();
			for (const auto& [teleportName, position] : teleports)
			{
				// find without case sensitivity
				if (search.empty() || std::search(teleportName.begin(), teleportName.end(), search.begin(), search.end(), [](char a, char b)
					{ return std::tolower(a) == std::tolower(b); }) != teleportName.end())
				{
					// sets are sorted by default and does not allow duplicates
					// which works in favor here.
					if (!search.empty()) {
						searchIndices.insert(index);
					}

					bool checked = std::any_of(checkedIndices.begin(), checkedIndices.end(), [&index](const auto& i) { return i == index; });
					bool selected = index == selectedIndex;

					ImGui::Checkbox(("##Index" + std::to_string(index)).c_str(), &checked);
					if (ImGui::IsItemClicked(0)) {
						if (checked) {
							if (selected) selectedIndex = -1;
							checkedIndices.erase(index);
						}
						else {
							checkedIndices.insert(index);
						}
						UpdateIndexName();
					}
					ImGui::SameLine();
					if (ImGui::Button(("TP##Button" + std::to_string(index)).c_str()))
					{
						auto& mapTeleport = MapTeleport::GetInstance();
						mapTeleport.TeleportTo(position);
					}
					ImGui::SameLine();
					ImGui::PushStyleColor(ImGuiCol_Text, selected ? IM_COL32(40, 90, 175, 255) : IM_COL32(255, 255, 255, 255));
					ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
					if (selected) nodeFlags |= ImGuiTreeNodeFlags_Selected;
					bool node_open = ImGui::TreeNodeEx(teleportName.data(), nodeFlags);
					if (ImGui::IsItemClicked() && checked) {
						if (!selected) {
							selectedIndex = index;
							selectedByClick = true;
						}
						else {
							selectedIndex = -1;
							selectedByClick = false;
						}
						UpdateIndexName();
					}
					if (node_open)
					{
						ImGui::Text("Position: %.3f, %.3f, %.3f", position.x, position.y, position.z);
						ImGui::TreePop();
					}
					ImGui::PopStyleColor();
				}
				index++;
			}
			ImGui::TreePop();
		}
	}

	bool CustomTeleports::NeedStatusDraw() const
	{
		return f_Enabled;
	}

	void CustomTeleports::DrawStatus()
	{
		ImGui::Text("Custom Teleport\n[%s]", selectedIndexName);
	}

	void CustomTeleports::OnNextKeyPressed()
	{
		if (!f_Enabled || selectedIndex < 0)
			return;

		auto& mapTeleport = MapTeleport::GetInstance();
		app::Vector3 position;

		if (selectedByClick) {
			position = teleports.at(selectedIndex).second;
			selectedByClick = false;
		}
		else {
			std::vector list(checkedIndices.begin(), checkedIndices.end());
			if (selectedIndex == list.back())
				return;

			auto index = std::distance(list.begin(), std::find(list.begin(), list.end(), selectedIndex));
			position = teleports.at(list.at(index + 1)).second;
			selectedIndex = list.at(index + 1);
		}
		mapTeleport.TeleportTo(position);
		UpdateIndexName();
	}

	void CustomTeleports::OnPreviousKeyPressed()
	{
		if (!f_Enabled || selectedIndex < 0)
			return;

		auto& mapTeleport = MapTeleport::GetInstance();
		app::Vector3 position;

		if (selectedByClick) {
			position = teleports.at(selectedIndex).second;
			selectedByClick = false;
		}
		else {
			std::vector list(checkedIndices.begin(), checkedIndices.end());
			if (selectedIndex == list.front())
				return;

			auto index = std::distance(list.begin(), std::find(list.begin(), list.end(), selectedIndex));
			position = teleports.at(list.at(index - 1)).second;
			selectedIndex = list.at(index - 1);
		}
		mapTeleport.TeleportTo(position);
		UpdateIndexName();
	}

	void CustomTeleports::UpdateIndexName() {
		std::string name(selectedIndex == -1 || checkedIndices.empty() ? "" : teleports.at(selectedIndex).first);

		// abbreviate teleport names that are too long
		if (name.length() > 15) {
			std::string shortened;
			std::regex numsExp("[\\d]+");
			std::regex firstCharsExp("\\b[A-Za-z]");

			std::sregex_iterator wordItr(name.begin(), name.end(), firstCharsExp);
			while (wordItr != std::sregex_iterator()) {
				for (unsigned i = 0; i < wordItr->size(); i++) {
					shortened.append((*wordItr)[i]);
				}
				wordItr++;
			}

			std::sregex_iterator numItr(name.begin(), name.end(), numsExp);
			while (numItr != std::sregex_iterator()) {
				for (unsigned i = 0; i < numItr->size(); i++) {
					shortened.append(" ");
					shortened.append((*numItr)[i]);
				}
				numItr++;
			}
			name = shortened;
		}
		selectedIndexName = name;

	}

	CustomTeleports& CustomTeleports::GetInstance()
	{
		static CustomTeleports instance;
		return instance;
	}
}
