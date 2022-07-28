#include "pch-il2cpp.h"
#include "FreezeEnemies.h"

#include <helpers.h>

#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/filters.h>

namespace cheat::feature
{

    FreezeEnemies::FreezeEnemies() : Feature(),
        NF(f_Enabled, u8"冻结敌人", "FreezeEnemies", false)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(FreezeEnemies::OnGameUpdate);
    }

    const FeatureGUIInfo& FreezeEnemies::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", u8"世界", false };
        return info;
    }

    void FreezeEnemies::DrawMain()
    {
        ConfigWidget(f_Enabled, u8"冻结所有敌人的移动");
    }

    bool FreezeEnemies::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void FreezeEnemies::DrawStatus()
    {
        ImGui::Text(u8"冻结敌人");
    }

    FreezeEnemies& FreezeEnemies::GetInstance()
    {
        static FreezeEnemies instance;
        return instance;
    }

    // Taiga#5555: There's probably be a better way of implementing this. But for now, this is just what I came up with.
    void FreezeEnemies::OnGameUpdate()
    {
        auto& manager = game::EntityManager::instance();

        for (const auto& monster : manager.entities(game::filters::combined::Monsters))
        {
            auto animator = monster->animator();
            auto rigidBody = monster->rigidbody();
            if (animator == nullptr && rigidBody == nullptr)
                return;

            if (f_Enabled)
            {
                //auto constraints = app::Rigidbody_get_constraints(rigidBody, nullptr);
                //LOG_DEBUG("%s", magic_enum::enum_name(constraints).data());
                app::Rigidbody_set_constraints(rigidBody, app::RigidbodyConstraints__Enum::FreezeAll, nullptr);
                app::Animator_set_speed(animator, 0.f, nullptr);
            }
            else
            {
                app::Rigidbody_set_constraints(rigidBody, app::RigidbodyConstraints__Enum::FreezeRotation, nullptr);
                app::Animator_set_speed(animator, 1.f, nullptr);
            }
        }
    }
}

