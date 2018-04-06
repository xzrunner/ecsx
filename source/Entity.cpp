#include "ecsx/Entity.h"
#include "ecsx/World.h"

namespace ecsx
{

Entity::Entity(World* world, EntityId id)
	: m_world(world)
	, m_id(id)
{
}

Entity::Entity(const Entity& e)
	: m_world(e.m_world)
	, m_id(e.m_id)
{
}

Entity& Entity::operator = (const Entity& e)
{
	m_world = e.m_world;
	m_id = e.m_id;
	return *this;
}

}