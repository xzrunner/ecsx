#pragma once

namespace ecsx
{
namespace detail
{

inline bool EntityPool::IsValid(Entity e) const
{
	if (e.u.index > m_versions.size()) {
		return false;
	} else {
		return e.u.version > 0 && e.u.version == m_versions[e.u.index];
	}
}

}
}