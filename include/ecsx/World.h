#pragma once

#include "ecsx/EntityIdPool.h"
#include "ecsx/ComponentPool.h"
#include "ecsx/CompStorageType.h"

#include <boost/noncopyable.hpp>

#include <vector>

namespace ecsx
{

class Entity;

class World : boost::noncopyable
{
public:
	World() {}

	Entity CreateEntity();

	bool IsIdValid(EntityId id) const {
		return m_id_pool.IsValid(id);
	}

	template <typename T>
	bool HasComponent(EntityId id) const;

	template <typename T, typename... Args>
	T& AddComponent(Args&&... args);

	template <typename T>
	T& GetComponent(EntityId id) const;

	template <typename T>
	void SetCompStorage(CompStorageType type);

//	void Clear();

private:
	detail::EntityIdPool m_id_pool;

	detail::ComponentPool m_comp_pool;
	
}; // World

}

#include "ecsx/World.inl"