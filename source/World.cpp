#include "ecsx/World.h"

namespace ecsx
{

Entity World::CreateEntity()
{
	return Entity(m_id_pool.Create());
}

}