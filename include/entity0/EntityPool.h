#pragma once

#include "entity0/Entity.h"

#include <boost/noncopyable.hpp>

#include <vector>

namespace e0
{
namespace detail
{

class EntityPool : boost::noncopyable
{
public:
	EntityPool();

	Entity Create();
	void Destroy(Entity e);

	bool IsValid(Entity e) const;

private:
	ID_TYPE m_next_id;

	std::vector<Entity> m_freelist;

	std::vector<ID_VERSION_TYPE> m_versions;

}; // EntityPool

}
}

#include "entity0/EntityPool.inl"