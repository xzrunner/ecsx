#include "entity0/World.h"

namespace e0
{

Entity World::CreateEntity()
{
	return Entity(m_id_pool.Create());
}

void World::DestroyEntity(Entity e)
{
	if (!e.IsNull()) {
		m_id_pool.Destroy(e);
		m_comp_pool.RemoveAllComponents(e);
	}
}

}