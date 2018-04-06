#pragma once

#include "ecsx/Config.h"
#include "ecsx/EntityId.h"
#include "ecsx/Component.h"
#include "ecsx/CompStorageType.h"

#include <boost/noncopyable.hpp>

#include <bitset>
#include <vector>
#include <array>

namespace ecsx
{
namespace detail
{

class IComponentsStorage;

class ComponentPool : boost::noncopyable
{
public:
	ComponentPool();

	template <typename T>
	bool HasComponent(EntityId id) const;

	template <typename T, typename... Args>
	T& AddComponent(EntityId id, Args&&... args);

	template <typename T>
	T& GetComponent(EntityId id) const;

	template <typename T>
	void SetStorage(CompStorageType type);

private:
	typedef std::bitset<MAX_COMPONENTS> ComponentMask;
	std::vector<ComponentMask> m_masks;

	std::array<IComponentsStorage*, MAX_COMPONENTS> m_storage{};

}; // ComponentPool

}
}

#include "ecsx/ComponentPool.inl"