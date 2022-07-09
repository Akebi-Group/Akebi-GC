#pragma once
#include <cheat-base/cheat/Feature.h>
#include <cheat-base/config/config.h>

#include <il2cpp-appdata.h>

namespace cheat::feature
{
    class FallControl : public Feature
    {
    public:
        config::Field<config::Toggle<Hotkey>> f_Enabled;
        config::Field<float> f_Speed;

        static FallControl& GetInstance();

        // Inherited via Feature
        virtual const FeatureGUIInfo& GetGUIInfo() const override;
        virtual void DrawMain() override;

        virtual bool NeedStatusDraw() const override;
        void DrawStatus() override;

        void OnGameUpdate();
        void OnMoveSync(uint32_t entityId, app::MotionInfo* syncInfo);

    private:
        FallControl();

        static bool isFalling;
    };
}
