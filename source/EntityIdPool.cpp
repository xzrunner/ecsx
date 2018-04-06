#include "ecsx/EntityIdPool.h"

namespace ecsx
{
namespace detail
{

EntityIdPool::EntityIdPool()
	: m_next_id(0)
{
}

EntityId EntityIdPool::Create()
{
	EntityId id;
	if (m_freelist.empty())
	{
		id.index = m_next_id++;
		id.version = 1;
		m_versions.push_back(id.version);
	}
	else
	{
		id = m_freelist.back();
		m_freelist.pop_back();
	}
	return id;
}

}
}