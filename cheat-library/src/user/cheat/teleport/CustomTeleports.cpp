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
		NF(f_Previous, "Teleport Previous", "CustomTeleports", Hotkey(VK_OEM_4)),
		dir(util::GetCurrentPath() / "teleports")
	{
		f_Next.value().PressedEvent += MY_METHOD_HANDLER(CustomTeleports::OnNext);
		f_Previous.value().PressedEvent += MY_METHOD_HANDLER(CustomTeleports::OnPrevious);
	}

	const FeatureGUIInfo& CustomTeleports::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "Teleport", true };
		return info;
	}

	void CustomTeleports::CheckFolder()
	{
		if (!std::filesystem::exists(dir))
			std::filesystem::create_directory(dir);
		else return;
	}

	bool CustomTeleports::ValidateTeleport(std::string name)
	{
		for (auto &Teleport : Teleports)
			if (Teleport.name == name)
				return false;
		if (name.find_first_of("\\/:*?\"<>|") != std::string::npos)
				return false;
		return true;
	}

	Teleport CustomTeleports::Teleport_(std::string name, app::Vector3 position, std::string description)
	{
		Teleport t(name, position, description);
		return t;
	}

	void CustomTeleports::SerializeTeleport(Teleport t)
	{
		Teleports.push_back(t);
		LOG_INFO("Teleport '%s' Loaded", t.name.c_str());
		CheckFolder();
		std::ofstream ofs(dir / (t.name + ".json"));
		nlohmann::json j;
		try
		{
			j["name"] = t.name;
			j["position"] = {t.position.x, t.position.y, t.position.z};
			j["description"] = t.description;
			ofs << j;
			ofs.close();
			LOG_INFO("Teleport '%s' Serialized.", t.name.c_str());
		} catch (std::exception e)
		{
			ofs.close();
			LOG_ERROR("Failed to serialize teleport: %s: %s", t.name.c_str(), e.what());
		}
	}

	Teleport CustomTeleports::SerializeFromJson(std::string json, bool fromfile)
	{
		nlohmann::json j;
		try { j = nlohmann::json::parse(json);}
		catch (nlohmann::json::parse_error &e)
		{
			LOG_ERROR("Invalid JSON Format");
			LOG_ERROR("Failed to parse JSON: %s", e.what());
		}
		std::string teleportName; 
		teleportName = j["name"];
		if (j["name"].is_null() && fromfile)
		{
			LOG_ERROR("No name found! Using File Name");
			teleportName = std::filesystem::path(json).stem().filename().string();
		}
		std::string description;
		if (j["description"].is_null()) description = "";
		else description = j["description"];
		return Teleport_(teleportName, {j["position"][0], j["position"][1], j["position"][2]}, description);
	}
	
	void CustomTeleports::ReloadTeleports()
	{
		auto result = std::filesystem::directory_iterator(dir);
		Teleports.clear();

		for (auto &file : result)
		{
			if (file.path().extension() == ".json")
			{
				std::ifstream ifs(file.path());
				std::string json;
				std::getline(ifs, json);
				SerializeTeleport(SerializeFromJson(json, true));
			}
		}
	}

	float PositionDistance(app::Vector3 a, app::Vector3 b)
	{
		return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
	}

	void CustomTeleports::OnTeleportKeyPressed(bool next)
	{
		if (!f_Enabled || selectedIndex < 0)
			return;

		auto &mapTeleport = MapTeleport::GetInstance();
		app::Vector3 position;

		if (selectedByClick)
		{
			position = Teleports.at(selectedIndex).position;
			selectedByClick = false;
		}
		else
		{
			std::vector list(checkedIndices.begin(), checkedIndices.end());
			if (selectedIndex == list.back() ? next : selectedIndex == list.front())
				return;
			auto index = std::distance(list.begin(), std::find(list.begin(), list.end(), selectedIndex));
			position = Teleports.at(list.at(index + (next ? 1 : -1))).position;
			selectedIndex = list.at(index + (next ? 1 : -1));
		}
		mapTeleport.TeleportTo(position);
		UpdateIndexName();
	}

	void CustomTeleports::OnPrevious()
	{
		OnTeleportKeyPressed(false);
	}
	void CustomTeleports::OnNext()
	{
		OnTeleportKeyPressed(true);
	}


	void CustomTeleports::UpdateIndexName()
	{
		std::string name(selectedIndex == -1 || checkedIndices.empty() ? "" : Teleports.at(selectedIndex).name);

		// abbreviate teleport names that are too long
		if (name.length() > 15)
		{
			std::string shortened;
			std::regex numsExp("[\\d]+");
			std::regex firstCharsExp("\\b[A-Za-z]");

			std::sregex_iterator wordItr(name.begin(), name.end(), firstCharsExp);
			while (wordItr != std::sregex_iterator())
			{
				for (unsigned i = 0; i < wordItr->size(); i++)
				{
					shortened.append((*wordItr)[i]);
				}
				wordItr++;
			}

			std::sregex_iterator numItr(name.begin(), name.end(), numsExp);
			while (numItr != std::sregex_iterator())
			{
				for (unsigned i = 0; i < numItr->size(); i++)
				{
					shortened.append(" ");
					shortened.append((*numItr)[i]);
				}
				numItr++;
			}
			name = shortened;
		}
		selectedIndexName = name;
	}

	void CustomTeleports::DrawMain()
	{
		if (ImGui::CollapsingHeader("Custom Teleports"))
		{
			// Buffers
			static std::string nameBuffer_;
			static std::string searchBuffer_;
			static std::string JSONBuffer_;
			static std::string descriptionBuffer_;

			ImGui::InputText("Name", &nameBuffer_);
			ImGui::InputText("Description", &descriptionBuffer_);
			if (ImGui::Button("Add Teleport"))
			{
				selectedIndex = -1;
				UpdateIndexName();
				SerializeTeleport(Teleport_(nameBuffer_, app::ActorUtils_GetAvatarPos(nullptr), descriptionBuffer_));
				nameBuffer_ = "";
				descriptionBuffer_ = "";
			}
			ImGui::SameLine();

			if (ImGui::Button("Reload"))
			{
				selectedIndex = -1;
				UpdateIndexName();
				checkedIndices.clear();
				ReloadTeleports();
			}

			ImGui::SameLine();
			if (ImGui::Button("Open Folder"))
			{
				CheckFolder();
				ShellExecuteA(NULL, "open", dir.string().c_str(), NULL, NULL, SW_SHOW);
			}

			ImGui::SameLine();
			if (ImGui::Button("Load from JSON"))
			{
				selectedIndex = -1;
				UpdateIndexName();
				SerializeTeleport(SerializeFromJson(JSONBuffer_, false));
				JSONBuffer_ = "";
			}
			ImGui::InputTextMultiline("JSON input", &JSONBuffer_, ImVec2(0, 50), ImGuiInputTextFlags_AllowTabInput);

			ConfigWidget("Teleport Next", f_Next, true, "Press to teleport next of selected");
			ConfigWidget("Teleport Previous", f_Previous, true, "Press to teleport previous of selected");
			ConfigWidget("Enable", f_Enabled,
				"Enable teleport-through-list functionality\n"
				"Usage:\n"
				"1. Put Checkmark to the teleports you want to teleport using hotkey\n"
				"2. Single click the teleport (with checkmark) to select where you want to start\n"
				"3. You can now press Next or Previous Hotkey to Teleport through the Checklist\n"
				"Initially it will teleport the player to the selection made\n"
				"Note: Double click or click the arrow to open teleport details");
			ImGui::SameLine();

			if (ImGui::Button("Delete Checked"))
			{
				if (!Teleports.empty())
				{
					if (checkedIndices.empty())
					{
						LOG_INFO("No teleports selected");
						return;
					}
					std::vector<std::string> teleportNames;
					for (auto& Teleport : Teleports)
						teleportNames.push_back(Teleport.name);
					for (auto& index : checkedIndices)
					{
						std::filesystem::remove(dir / (teleportNames[index] + ".json"));
						LOG_INFO("Deleted teleport %s", teleportNames[index].c_str());
					}
					checkedIndices.clear();
					UpdateIndexName();
					ReloadTeleports();
				}
				else { LOG_INFO("No teleports to delete"); }
			}
			ImGui::SameLine();
			HelpMarker("Warning: This will delete the file from the directory and\n \
		remove the teleport from the list. It will be lost forever.");

			if (ImGui::TreeNode("Teleports"))
			{
				std::sort(Teleports.begin(), Teleports.end(), [](const auto& a, const auto& b)
					{ return StrCmpLogicalW(std::wstring(a.name.begin(), a.name.end()).c_str(), std::wstring(b.name.begin(), b.name.end()).c_str()) < 0; });
				bool allChecked = checkedIndices.size() == Teleports.size() && !Teleports.empty();
				bool allSearchChecked = checkedIndices.size() == searchIndices.size() && !searchIndices.empty();
				ImGui::Checkbox("All", &allChecked);
				if (ImGui::IsItemClicked())
				{
					if (!Teleports.empty())
					{
						if (allChecked)
						{
							selectedIndex = -1;
							if (!searchIndices.empty())
								for (const auto& i : searchIndices)
									checkedIndices.erase(i);
							else
								checkedIndices.clear();
						}
						else if (!searchIndices.empty())
							checkedIndices.insert(searchIndices.begin(), searchIndices.end());
						else
							for (int i = 0; i < Teleports.size(); i++)
								checkedIndices.insert(i);
						UpdateIndexName();
					}
				}
				ImGui::SameLine();
				ImGui::InputText("Search", &searchBuffer_);
				unsigned int index = 0;
				searchIndices.clear();

				unsigned int maxNameLength = 0;
				for (auto& Teleport : Teleports)
					if (Teleport.name.length() > maxNameLength)
						maxNameLength = Teleport.name.length();
				ImGui::BeginTable("Teleports", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable | ImGuiTableFlags_NoSavedSettings);
				ImGui::TableSetupColumn("#", ImGuiTableColumnFlags_WidthFixed, 20);
				ImGui::TableSetupColumn("Commands", ImGuiTableColumnFlags_WidthFixed, 100);
				ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, maxNameLength * 8 + 10);
				ImGui::TableSetupColumn("Position");
				ImGui::TableHeadersRow();
				ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

				for (const auto& [name, position, description] : Teleports)
				{
					if (searchBuffer_.empty() || std::search(name.begin(), name.end(), searchBuffer_.begin(), searchBuffer_.end(), [](char a, char b)
						{ return std::tolower(a) == std::tolower(b); }) != name.end())
					{
						if (!searchBuffer_.empty())
							searchIndices.insert(index);
						bool checked = std::any_of(checkedIndices.begin(), checkedIndices.end(), [&index](const auto& i)
							{ return i == index; });
						bool selected = index == selectedIndex;

						ImGui::TableNextRow();
						ImGui::TableNextColumn();
						ImGui::Text("%d", index);
						ImGui::TableNextColumn();
						ImGui::Checkbox(("##Index" + std::to_string(index)).c_str(), &checked);
						if (ImGui::IsItemClicked(0))
						{
							if (checked)
							{
								if (selected)
									selectedIndex = -1;
								checkedIndices.erase(index);
							}
							else
								checkedIndices.insert(index);
							UpdateIndexName();
						}

						ImGui::SameLine();
						if (ImGui::Button(("TP##Button" + std::to_string(index)).c_str()))
						{
							auto& manager = game::EntityManager::instance();
							auto avatar = manager.avatar();
							if (avatar->moveComponent() == nullptr)
							{
								LOG_ERROR("Avatar has no move component, Is scene loaded?");
								return;
							}
							if (PositionDistance(position, app::ActorUtils_GetAvatarPos(nullptr)) > 60.0f)
								MapTeleport::GetInstance().TeleportTo(position);
							else
								manager.avatar()->setAbsolutePosition(position);
						}

						ImGui::SameLine();
						if (ImGui::Button(("Select##Button" + std::to_string(index)).c_str()))
						{
							selectedIndex = index;
							selectedByClick = true;
							UpdateIndexName();
						}
						ImGui::SameLine();
						ImGui::PushStyleColor(ImGuiCol_Text, selected ? IM_COL32(40, 90, 175, 255) : IM_COL32(255, 255, 255, 255));

						if (selected)
							nodeFlags |= ImGuiTreeNodeFlags_Selected;
						ImGui::PopStyleColor();
						ImGui::TableNextColumn();

						ImGui::Text("%s", name.c_str());
						if (ImGui::IsItemHovered())
						{
							ImGui::BeginTooltip();
							ImGui::Text("%s", description.c_str());
							ImGui::Text("Distance: %.2f", PositionDistance(position, app::ActorUtils_GetAvatarPos(nullptr)));
							ImGui::EndTooltip();
						}
						ImGui::TableNextColumn();
						ImGui::Text("%f, %f, %f", position.x, position.y, position.z);
					}
					index++;
				}
				ImGui::EndTable();
				ImGui::TreePop();
			}

			if (selectedIndex != -1)
				ImGui::Text("Selected: [%d] %s", selectedIndex, Teleports[selectedIndex].name.c_str());
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

	CustomTeleports &CustomTeleports::GetInstance()
	{
		static CustomTeleports instance;
		return instance;
	}
}
