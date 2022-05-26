#include "pch-il2cpp.h"
#include "Hotkeys.h"

#include <helpers.h>
#include <misc/cpp/imgui_stdlib.h>

namespace cheat::feature 
{
    Hotkeys::Hotkeys() : Feature() { }

    const FeatureGUIInfo& Hotkeys::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "Hotkeys", false };
        return info;
    }

    void Hotkeys::DrawMain()
    {
        static std::string searchBuffer;
        ImGui::InputText("Search", &searchBuffer);

        ImGui::BeginChild("Hotkeys");
        
        std::unordered_map<std::string, std::vector<config::Field<config::Toggle<Hotkey>>*>> sections;

        for (auto& field : config::GetFields<config::Toggle<Hotkey>>())
        {
            if (!searchBuffer.empty())
            {
                auto name = field.friendName();
                auto it = std::search(
                    name.begin(), name.end(),
                    searchBuffer.begin(), searchBuffer.end(),
                    [](char ch1, char ch2) { return std::tolower(ch1) == std::tolower(ch2); }
                );
                if (it == name.end())
                    continue;
            }

            sections[field.section()].push_back(&field);
        }

        std::vector<config::Field<config::Toggle<Hotkey>>*> singleLineSections;
        std::vector<std::vector<config::Field<config::Toggle<Hotkey>>*>*> multiLineSections;
        for (auto& [section, fields] : sections)
        {
            if (fields.size() == 1)
                singleLineSections.push_back(fields[0]);
            else
                multiLineSections.push_back(&fields);
        }

        for (auto& field : singleLineSections)
        {
            ConfigWidget(*field, nullptr, true);
        }

        for (auto& fields : multiLineSections)
        {
	        if (ImGui::BeginGroupPanel((*fields)[0]->section().c_str(), true))
	        {
		        for (auto& field : *fields)
		        {
                    ConfigWidget(*field, nullptr, true);
		        }
	        }
            ImGui::EndGroupPanel();
        }

        ImGui::EndChild();
    }

    Hotkeys& Hotkeys::GetInstance()
    {
        static Hotkeys instance;
        return instance;
    }
}

