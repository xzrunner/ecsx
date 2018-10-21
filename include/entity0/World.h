#pragma once

#include "entity0/EntityPool.h"
#include "entity0/ComponentPool.h"
#include "entity0/CompStorageType.h"
#include "entity0/Entity.h"

#include <boost/noncopyable.hpp>

#include <vector>

namespace e0
{

class World : boost::noncopyable
{
public:
	World() {}

	Entity CreateEntity();
	void DestroyEntity(Entity e);

	bool IsIdValid(Entity e) const {
		return m_id_pool.IsValid(e);
	}

	template <typename T>
	bool HasComponent(Entity e) const;

	template <typename T, typename... Args>
	T& AddComponent(Args&&... args);

	template <typename T>
	T& GetComponent(Entity e) const;

	template <typename T>
	void SetCompStorage(CompStorageType type);

//	void Clear();

private:
	detail::EntityPool m_id_pool;

	detail::ComponentPool m_comp_pool;

}; // World

}

#include "entity0/World.inl"