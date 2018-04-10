#pragma once

#include "ecsx/Entity.h"

#include <boost/noncopyable.hpp>

#include <vector>

namespace ecsx
{
namespace detail
{

class EntityPool : boost::noncopyable
{
public:
	EntityPool();

	Entity Create();

	bool IsValid(Entity e) const;

private:
	ID_TYPE m_next_id;

	std::vector<Entity> m_freelist;

	std::vector<ID_VERSION_TYPE> m_versions;

}; // EntityPool

}
}

#include "ecsx/EntityPool.inl"