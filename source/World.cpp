#include "ecsx/World.h"
#include "ecsx/Entity.h"

namespace ecsx
{

Entity World::CreateEntity()
{
	return Entity(this, m_id_pool.Create());
}

}