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
#include <helpers.h>
#include <imgui_internal.h>

namespace cheat::feature
{
    CustomTeleports::CustomTeleports() : Feature(),
     NF(f_DebugMode, "Debug Mode", "CustomTeleports", false) // Soon to be added
    { }
    const FeatureGUIInfo &CustomTeleports::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{"Custom Teleports", "Teleport", true};
        return info;
    }

    void CustomTeleports::DrawMain()
    {
        auto &entityManager = game::EntityManager::instance();
        auto &MapTeleport = MapTeleport::GetInstance();
        static std::string teleportName;
        ImGui::InputText("Teleport name", &teleportName);
        static std::vector<std::pair<std::string, app::Vector3>> teleports;
        app::Vector3 pos = app::ActorUtils_GetAvatarPos(nullptr);
        if (ImGui::Button("Add teleport"))
        {
            // check if already added
            bool found = false;
            for (const auto &[name, pos] : teleports)
            {
                if (name == teleportName)
                {
                    found = true;
                    break;
                }
            }
            // check if name is valid and doesnt  contain special characters
            if (teleportName.find_first_of("\\/:*?\"<>|") != std::string::npos)
            {
                return;
            }

            teleports.push_back({teleportName, pos});

            auto dir = std::filesystem::current_path();
            dir /= "teleports";
            if (!std::filesystem::exists(dir))
                std::filesystem::create_directory(dir);
            std::ofstream ofs(dir / (teleportName + ".json"));
            nlohmann::json j;
            j["name"] = teleportName;
            j["position"] = {pos.x, pos.y, pos.z};
            ofs << j;
            teleportName.clear();
        }
        ImGui::SameLine();
        if (ImGui::Button("Reload"))
        {
            auto dir = std::filesystem::current_path();
            dir /= "teleports";
            auto result = std::filesystem::directory_iterator(dir);
            teleports.clear();
            for (auto &file : result)
            {

                if (file.path().extension() != ".json")
                    continue;

                std::string name = file.path().stem().string();
                if (file.is_directory())
                    continue;

                std::ifstream ifs(file.path());
                nlohmann::json j;
                ifs >> j;
                teleports.push_back({j["name"], {j["position"][0], j["position"][1], j["position"][2]}});
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

        static std::string jsonInput;
        ImGui::InputTextMultiline("JSON input", &jsonInput, ImVec2(0, 50), ImGuiInputTextFlags_AllowTabInput);

        if (ImGui::Button("Load from JSON"))
        {
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
            catch (nlohmann::json::parse_error &e)
            {
                LOG_ERROR("Failed to parse JSON: %s", e.what());
                return;
            }
            LOG_INFO("Parsed JSON");
            std::string teleportName = j["name"];
            app::Vector3 pos = {j["position"][0], j["position"][1], j["position"][2]};
            teleports.push_back({teleportName, pos});
            LOG_INFO("Loaded teleport %s", teleportName.c_str());
            std::ofstream ofs(dir / (teleportName + ".json"));
            ofs << jsonInput;
            jsonInput.clear();
        }

        if (ImGui::TreeNode("Teleports"))
        {
            std::string search;
            ImGui::InputText("Search", &search);
            for (const auto &[teleportName, position] : teleports)
            {
                // find without case sensitivity
                if (search.empty() || std::search(teleportName.begin(), teleportName.end(), search.begin(), search.end(), [](char a, char b)
                                                  { return std::tolower(a) == std::tolower(b); }) != teleportName.end())
                {
                    if (ImGui::TreeNode(teleportName.data()))
                    {
                        ImGui::Text("Position: %.3f, %.3f, %.3f", position.x, position.y, position.z);
                        if (ImGui::Button("Teleport"))
                        {
                            auto &mapTeleport = MapTeleport::GetInstance();
                            mapTeleport.TeleportTo(position);
                        }
                        ImGui::SameLine();
                        if (ImGui::Button("Remove"))
                        {
                            auto dir = std::filesystem::current_path();
                            dir /= "teleports";
                            // delete file
                            std::filesystem::remove(dir / (teleportName + ".json"));
                            auto it = std::find_if(teleports.begin(), teleports.end(), [&teleportName](const auto &pair)
                                                   { return pair.first == teleportName; });
                            if (it != teleports.end())
                                teleports.erase(it);
                        }
                        ImGui::SameLine();
                        HelpMarker("Warning: Removing a teleport will remove the file from the directory. It will be lost forever.");
                        ImGui::TreePop();
                    }
                }
            }
            ImGui::TreePop();
        }
    }

    CustomTeleports& CustomTeleports::GetInstance()
    {
        static CustomTeleports instance;
        return instance;
    }
}
