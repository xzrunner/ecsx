#pragma once

namespace ecsx
{
namespace detail
{

inline bool EntityPool::IsValid(Entity e) const
{
	if (e.index > m_versions.size()) {
		return false;
	} else {
		return e.version > 0 && e.version == m_versions[e.index];
	}
}

}
}