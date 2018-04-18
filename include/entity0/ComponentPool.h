#pragma once

#include "entity0/Entity.h"
#include "entity0/Component.h"
#include "entity0/CompStorageType.h"

#include <boost/noncopyable.hpp>

#include <bitset>
#include <vector>
#include <array>

namespace e0
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
	T& RemoveComponent(Entity e);

	void RemoveAllComponents(Entity e);

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

#include "entity0/ComponentPool.inl"