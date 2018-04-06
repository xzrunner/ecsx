#pragma once

#include "ecsx/EntityId.h"
#include "ecsx/World.h"

#include <boost/noncopyable.hpp>

namespace ecsx
{

class World;

class Entity : boost::noncopyable
{
public:
	Entity(World* world, EntityId id);
	Entity(const Entity& e);
	Entity& operator = (const Entity& e);

	bool IsValid() const;

	template <typename T>
	bool HasComponent() const;

	template <typename T, typename... Args>
	T& AddComponent(Args&&... args);

	template <typename T>
	T& GetComponent() const;

private:
	World* m_world;

	EntityId m_id;

}; // Entity

}

#include "ecsx/Entity.inl"