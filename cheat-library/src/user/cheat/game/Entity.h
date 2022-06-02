#pragma once
#include <helpers.h>
namespace cheat::game
{
	class Entity
	{
	public:

		Entity(app::BaseEntity* rawEntity);

		std::string& name();

		app::BaseEntity* raw();
		uint32_t runtimeID();
		app::EntityType__Enum_1 type();

		app::Vector3 relativePosition();
		app::Vector3 absolutePosition();
		app::Vector2 levelPosition();

		float distance(const app::Vector3& point);
		float distance(const app::Vector2& levelPosition);
		float distance(Entity* entity);
		float distance(app::BaseEntity* rawEntity);

		bool isGadget();
		bool isChest();
		bool isAvatar();

		bool isLoaded();

		void setRelativePosition(const app::Vector3& value);
		void setAbsolutePosition(const app::Vector3& value);
		
		app::VCBaseMove* moveComponent();
		app::LCBaseCombat* combat();

		app::GameObject* gameObject();
		app::Rigidbody* rigidbody();
		
		app::Vector3 forward();
		app::Vector3 back();
		app::Vector3 right();
		app::Vector3 left();
		app::Vector3 up();
		app::Vector3 down();

		template<class T>
		T* plugin(void* pClass)
		{
			if (m_RawEntity == nullptr)
				return nullptr;

			SAFE_BEGIN();

			auto logicComponentsRaw = app::MoleMole_BaseEntity_GetAllLogicComponents(m_RawEntity, nullptr);
			auto logicComponents = TO_UNI_LIST(logicComponentsRaw, app::BaseComponent*);
			if (logicComponents == nullptr)
				return nullptr;

			for (auto& component : *logicComponents)
			{
				T* value = GetLCPlugin<T>(component, pClass);
				if (value != nullptr)
					return value;
			}
			return nullptr;

			SAFE_ERROR();
			return nullptr;
			SAFE_END();
		}

	private:

		app::BaseEntity* m_RawEntity;
		bool m_HasName;
		std::string m_Name;

		bool m_IsLoaded;

		template<class T>
		T* GetLCPlugin(app::BaseComponentPlugin* plugin, void* pClass)
		{
			return CastTo<T>(plugin, pClass);
		}

		template<class T>
		T* GetLCPlugin(app::BaseComponent* component, void* pClass)
		{
			if (component == nullptr || component->fields._pluginList == nullptr)
				return nullptr;

			auto componentList = TO_UNI_LIST(component->fields._pluginList, app::BaseComponentPlugin*);
			for (auto& plugin : *componentList)
			{
				T* value = GetLCPlugin<T>(plugin, pClass);
				if (value != nullptr)
					return value;
			}
			return nullptr;
		}
	};
}
