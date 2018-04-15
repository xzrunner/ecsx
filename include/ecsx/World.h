#pragma once

#include "ecsx/EntityPool.h"
#include "ecsx/ComponentPool.h"
#include "ecsx/CompStorageType.h"
#include "ecsx/Entity.h"

#include <boost/noncopyable.hpp>

#include <vector>

namespace ecsx
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

#include "ecsx/World.inl"