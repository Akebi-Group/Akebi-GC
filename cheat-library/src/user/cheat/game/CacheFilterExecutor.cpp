#include "pch-il2cpp.h"
#include "CacheFilterExecutor.h"

#include "EntityManager.h"

namespace cheat::game
{

	CacheFilterExecutor::CacheFilterExecutor(uint32_t lifeTime) : m_LifeTime(lifeTime)
	{
		EntityManager& manager = EntityManager::instance();
		manager.entityDestroyEvent += MY_METHOD_HANDLER(CacheFilterExecutor::OnEntityDestroy);
	}

	bool CacheFilterExecutor::ApplyFilter(Entity* entity, IEntityFilter* filter)
	{
		std::lock_guard<std::mutex> lock(m_CacheLock);

		if (m_Cache.count(entity) == 0)
			m_Cache[entity] = {};

		auto& entityFilters = m_Cache[entity];
		if (entityFilters.count(filter) == 0)
			entityFilters[filter] = { false, 0 };

		auto& entry = entityFilters[filter];
		auto timestamp = app::MoleMole_TimeUtil_get_NowTimeStamp(nullptr);
		if (entry.second + m_LifeTime > timestamp)
			return entry.first;

		bool result = filter->IsValid(entity);
		entry = { result, timestamp + m_LifeTime };
		return result;
	}

	void CacheFilterExecutor::OnEntityDestroy(Entity* entity)
	{
		std::lock_guard<std::mutex> lock(m_CacheLock);

		if (m_Cache.count(entity) > 0)
			m_Cache.erase(entity);
	}

}