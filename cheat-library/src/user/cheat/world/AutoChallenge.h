#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

namespace cheat::feature 
{

    class AutoChallenge : public Feature
    {
    public:
        config::Field<config::Toggle<Hotkey>> f_Enabled;
        config::Field<int> f_Delay;
        config::Field<float> f_Range;

        static AutoChallenge& GetInstance();

        void OnGameUpdate();

        const FeatureGUIInfo& GetGUIInfo() const override;
        void DrawMain() override;

        virtual bool NeedStatusDraw() const override;
        void DrawStatus() override;

    private:
        AutoChallenge();
    };
}

