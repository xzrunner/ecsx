#pragma once

namespace ecsx
{
namespace detail
{

inline bool EntityIdPool::IsValid(EntityId id) const
{
	if (id.index > m_versions.size()) {
		return false;
	} else {
		return id.version > 0 && id.version == m_versions[id.index];
	}
}

}
}