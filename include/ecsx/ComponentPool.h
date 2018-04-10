#pragma once

#include "ecsx/Entity.h"
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
	bool HasComponent(Entity e) const;

	template <typename T, typename... Args>
	T& AddComponent(Entity e, Args&&... args);

	template <typename T>
	T& GetComponent(Entity e) const;

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