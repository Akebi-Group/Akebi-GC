#include "pch-il2cpp.h"
#include "FreezeEnemies.h"

#include <helpers.h>

#include <cheat/events.h>
#include <cheat/game/EntityManager.h>
#include <cheat/game/filters.h>

namespace cheat::feature
{
    static bool change = false;

    FreezeEnemies::FreezeEnemies() : Feature(),
        NF(f_Enabled, "Freeze Enemies", "FreezeEnemies", false)
    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(FreezeEnemies::OnGameUpdate);
    }

    const FeatureGUIInfo& FreezeEnemies::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "", "World", false };
        return info;
    }

    void FreezeEnemies::DrawMain()
    {
        ConfigWidget(f_Enabled, "Freezes all enemies' animation speed.");
    }

    bool FreezeEnemies::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void FreezeEnemies::DrawStatus()
    {
        ImGui::Text("Freeze Enemies");
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
                change = false;
            }
            else
            {
                app::Rigidbody_set_constraints(rigidBody, app::RigidbodyConstraints__Enum::FreezeRotation, nullptr);
                if (!change)
                {
                    app::Animator_set_speed(animator, 1.f, nullptr);
                    change = true;
                }
            }
        }
    }
}

