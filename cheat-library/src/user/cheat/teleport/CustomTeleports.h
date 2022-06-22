#pragma once

#include <il2cpp-appdata.h>

#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/Config.h>
#include <set>

namespace cheat::feature
{
    class CustomTeleports : public Feature
    {
    public:
        config::Field<config::Toggle<Hotkey>> f_DebugMode;
        config::Field<config::Toggle<Hotkey>> f_Enabled;
        config::Field<Hotkey> f_Next;
        config::Field<Hotkey> f_Previous;
        static CustomTeleports& GetInstance();
        const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

        virtual bool NeedStatusDraw() const override;
        void DrawStatus() override;

    private:
        std::vector<std::pair<std::string, app::Vector3>> teleports;
        std::set<unsigned int> checkedIndices;
        std::set<unsigned int> searchIndices;
        bool selectedByClick = false;
        int selectedIndex = -1;
        std::string selectedIndexName;
        CustomTeleports();
        void OnNextKeyPressed();
        void OnPreviousKeyPressed();
        void UpdateIndexName();
    };
}