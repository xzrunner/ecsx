#pragma once

#include "ecsx/EntityId.h"

#include <boost/noncopyable.hpp>

#include <vector>

namespace ecsx
{
namespace detail
{

class EntityIdPool : boost::noncopyable
{
public:
	EntityIdPool();

	EntityId Create();

	bool IsValid(EntityId id) const;

private:
	ID_TYPE m_next_id;

	std::vector<EntityId> m_freelist;

	std::vector<ID_VERSION_TYPE> m_versions;

}; // EntityIdPool

}
}

#include "ecsx/EntityIdPool.inl"