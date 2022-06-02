#include "pch-il2cpp.h"
#include "Entity.h"

#include <helpers.h>
#include "EntityManager.h"

namespace cheat::game
{

	Entity::Entity(app::BaseEntity* rawEntity) : m_RawEntity(rawEntity), m_Name({}), m_HasName(false)
	{
	}

	app::String* GetRawName(game::Entity* entity)
	{
		SAFE_BEGIN();
		return app::MoleMole_BaseEntity_ToStringRelease(entity->raw(), nullptr);
		SAFE_ERROR();
		return nullptr;
		SAFE_END();
	}
	std::string& Entity::name()
	{
		if (m_HasName || m_RawEntity == nullptr || !isLoaded())
			return m_Name;

		auto rawName = GetRawName(this);
		if (rawName == nullptr)
			return m_Name;

		auto name = il2cppi_to_string(rawName);
		m_Name = name;
		m_HasName = true;
		return m_Name;

	}

	app::BaseEntity* Entity::raw()
	{
		return m_RawEntity;
	}

	uint32_t Entity::runtimeID()
	{
		if (m_RawEntity == nullptr)
			return 0;

		return m_RawEntity->fields._runtimeID_k__BackingField;
	}

	app::EntityType__Enum_1 Entity::type()
	{
		if (m_RawEntity == nullptr)
			return app::EntityType__Enum_1::None;

		return m_RawEntity->fields.entityType;
	}

	app::Vector3 Entity::relativePosition()
	{
		if (m_RawEntity == nullptr)
			return {};

		return app::MoleMole_BaseEntity_GetRelativePosition(m_RawEntity, nullptr);
	}

	app::Vector3 Entity::absolutePosition()
	{
		if (m_RawEntity == nullptr)
			return {};

		return app::MoleMole_BaseEntity_GetAbsolutePosition(m_RawEntity, nullptr);
	}
	
	app::Vector2 Entity::levelPosition()
	{
		if (m_RawEntity == nullptr)
			return {};

		return app::Miscs_GenLevelPos_1(absolutePosition(), nullptr);
	}

	float Entity::distance(Entity* entity)
	{
		if (entity == nullptr)
			return 10000;

		return distance(entity->relativePosition());
	}

	float Entity::distance(app::BaseEntity* rawEntity)
	{
		if (rawEntity == nullptr)
			return 10000;

		auto point = app::MoleMole_BaseEntity_GetRelativePosition(rawEntity, nullptr);
		return distance(point);
	}

	float Entity::distance(const app::Vector3& point)
	{
		if (m_RawEntity == nullptr)
			return 10000;

		auto dist = app::Vector3_Distance(relativePosition(), point, nullptr);
		return dist;
	}

	float Entity::distance(const app::Vector2& levelPoint)
	{
		if (m_RawEntity == nullptr)
			return 10000;

		return app::Vector2_Distance(levelPosition(), levelPoint, nullptr);
	}

	bool Entity::isGadget()
	{
		if (m_RawEntity == nullptr)
			return false;

		return m_RawEntity->fields.entityType == app::EntityType__Enum_1::Gadget ||
			m_RawEntity->fields.entityType == app::EntityType__Enum_1::Bullet ||
			m_RawEntity->fields.entityType == app::EntityType__Enum_1::Field;
	}

	bool Entity::isChest()
	{
		if (m_RawEntity == nullptr)
			return false;

		return m_RawEntity->fields.entityType == app::EntityType__Enum_1::Chest;
	}

	bool Entity::isAvatar()
	{
		if (m_RawEntity == nullptr)
			return false;

		auto avatar = EntityManager::instance().avatar();
		if (avatar->raw() == nullptr)
			return false;

		return avatar->raw() == m_RawEntity;
	}

	void Entity::setRelativePosition(const app::Vector3& value)
	{
		if (m_RawEntity == nullptr)
			return;

		app::MoleMole_BaseEntity_SetRelativePosition(m_RawEntity, value, true, nullptr);
	}

	void Entity::setAbsolutePosition(const app::Vector3& value)
	{
		if (m_RawEntity == nullptr)
			return;

		app::MoleMole_BaseEntity_SetAbsolutePosition(m_RawEntity, value, true, nullptr);
	}

	bool Entity::isLoaded()
	{
		if (m_RawEntity == nullptr || !app::MoleMole_BaseEntity_IsActive(m_RawEntity, nullptr))
			return false;

		m_IsLoaded = m_IsLoaded || app::MoleMole_BaseEntity_get_rootGameObject(m_RawEntity, nullptr);
		return m_IsLoaded;
	}

	app::VCBaseMove* Entity::moveComponent()
	{
		if (!isLoaded())
			return nullptr;

		SAFE_BEGIN();
		return app::MoleMole_BaseEntity_GetMoveComponent_1(m_RawEntity, *app::MoleMole_BaseEntity_GetMoveComponent_1__MethodInfo);
		SAFE_ERROR();
		return nullptr;
		SAFE_END();
	}

	app::LCBaseCombat* Entity::combat()
	{
		if (!isLoaded())
			return nullptr;
		
		SAFE_BEGIN();
		return app::MoleMole_BaseEntity_GetLogicCombatComponent_1(m_RawEntity, *app::MoleMole_BaseEntity_GetLogicCombatComponent_1__MethodInfo);
		SAFE_ERROR();
		return nullptr;
		SAFE_END();
	}

	app::Rigidbody* Entity::rigidbody()
	{
		if (!isLoaded())
			return nullptr;

		SAFE_BEGIN();
		return app::MoleMole_BaseEntity_GetRigidbody(m_RawEntity, nullptr);
		SAFE_ERROR();
		return nullptr;
		SAFE_END();
	}

	app::GameObject* Entity::gameObject()
	{
		if (!isLoaded())
			return nullptr;

		SAFE_BEGIN();
		return app::MoleMole_BaseEntity_get_gameObject(m_RawEntity, nullptr);
		SAFE_ERROR();
		return nullptr;
		SAFE_END();
	}

	app::Vector3 Entity::forward()
	{
		if (m_RawEntity == nullptr)
			return {};

		return app::MoleMole_BaseEntity_GetForward(m_RawEntity, nullptr);
	}

	app::Vector3 Entity::back()
	{
		return -forward();
	}

	app::Vector3 Entity::right()
	{
		if (m_RawEntity == nullptr)
			return {};

		return app::MoleMole_BaseEntity_GetRight(m_RawEntity, nullptr);
	}

	app::Vector3 Entity::left()
	{
		return -right();
	}

	app::Vector3 Entity::up()
	{
		if (m_RawEntity == nullptr)
			return {};

		return app::MoleMole_BaseEntity_GetUp(m_RawEntity, nullptr);
	}

	app::Vector3 Entity::down()
	{
		return -up();
	}

}
