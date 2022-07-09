#include "pch-il2cpp.h"
#include "FallControl.h"

#include <cheat/events.h>
#include <cheat/game/EntityManager.h>

namespace cheat::feature
{
    bool FallControl::isFalling = false;

    FallControl::FallControl() : Feature(),
        NF(f_Enabled, "Fall Control", "FallControl", false),
        NF(f_Speed, "Speed", "FallControl", 1.0f)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(FallControl::OnGameUpdate);
        events::MoveSyncEvent += MY_METHOD_HANDLER(FallControl::OnMoveSync);
    }

    const FeatureGUIInfo& cheat::feature::FallControl::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "Fall-Control", "Player", true };
        return info;
    }

    void cheat::feature::FallControl::DrawMain()
    {
        ConfigWidget("Enabled", f_Enabled, "Enables fall control");
        ConfigWidget("Speed", f_Speed, 0.1f, 5.0f, 10.0f, "Movement speed when using fall control");
    }

    bool cheat::feature::FallControl::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void cheat::feature::FallControl::DrawStatus()
    {
        ImGui::Text("Fall Control [%.1f]", f_Speed.value());
    }

    FallControl& cheat::feature::FallControl::GetInstance()
    {
        static FallControl instance;
        return instance;
    }

    // Fall control update function
    // Detects and moves avatar when movement keys are pressed.
    void FallControl::OnGameUpdate()
    {
        if (!f_Enabled || !isFalling)
            return;

        auto& manager = game::EntityManager::instance();
        const auto avatarEntity = manager.avatar();

        app::Vector3 direction = {};
        if (Hotkey('W').IsPressed())
            direction = direction + avatarEntity->forward();
        if (Hotkey('S').IsPressed())
            direction = direction + avatarEntity->back();
        if (Hotkey('D').IsPressed())
            direction = direction + avatarEntity->right();
        if (Hotkey('A').IsPressed())
            direction = direction + avatarEntity->left();
        if (IsVectorZero(direction))
            return;

        auto rigidBody = avatarEntity->rigidbody();
        if (rigidBody == nullptr)
            return;

        // // Alternative, using set_velocity. Does not work while falling?
        // const float speed = f_Speed.value();
        // const auto currentVelocity = app::Rigidbody_get_velocity(rigidBody, nullptr);
        // const auto desiredvelocity = currentVelocity + direction * speed;
        // LOG_DEBUG("Current velocity: [%.1f,%.1f,%.1f]", desiredvelocity.x, desiredvelocity.y, desiredvelocity.z);
        // app::Rigidbody_set_velocity(rigidBody, desiredvelocity, nullptr);

        const app::Vector3 prevPos = avatarEntity->relativePosition();
        const auto currentVelocity = app::Rigidbody_get_velocity(rigidBody, nullptr);
        const float speed = f_Speed.value();
        const float deltaTime = app::Time_get_deltaTime(nullptr);
        const app::Vector3 newPos = prevPos + (currentVelocity + direction * speed) * deltaTime;
        // const auto debugvel = (currentVelocity + direction * speed);
        // LOG_DEBUG("PrevPos: [%.1f,%.1f,%.1f]", prevPos.x, prevPos.y, prevPos.z);
        // LOG_DEBUG("delta time: %f", deltaTime);
        // LOG_DEBUG("currentVelocity: [%.1f,%.1f,%.1f]", currentVelocity.x, currentVelocity.y, currentVelocity.z);
        // LOG_DEBUG("direction: [%.1f,%.1f,%.1f]", direction.x, direction.y, direction.z);
        // LOG_DEBUG("(currentVelocity + direction * speed): [%.1f,%.1f,%.1f]\n", debugvel.x, debugvel.y, debugvel.z);
        avatarEntity->setRelativePosition(newPos);
    }

    // Detects when player is falling and enables the FallControl cheat
    void FallControl::OnMoveSync(uint32_t entityId, app::MotionInfo* syncInfo)
    {
        if (!f_Enabled) {
            // Edgecase for when you turn off cheat while falling
            isFalling = false;
            return;
        }

        const auto motionState = syncInfo->fields.motionState;
        switch (motionState)
        {
            // These states tell us we are falling
        case app::MotionState__Enum::MotionDrop:
            isFalling = true;
            return;
            
            // State that doesn't tell us anything
        case app::MotionState__Enum::MotionStandby:
        case app::MotionState__Enum::MotionNotify:
            return;

            // We are not falling
        default:
            isFalling = false;
            break;
        }
    }
}
