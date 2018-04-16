#pragma once

#include "ecsx/CompDenseStorage.h"
#include "ecsx/CompSparseStorage.h"

#include <guard/check.h>

namespace ecsx
{
namespace detail
{

template <typename T>
inline bool ComponentPool::HasComponent(Entity e) const
{
	return e.index >= 0 && e.index < m_masks.size() 
		&& m_masks[e.index][GetComponentTypeID<T>()];
}

template <typename T, typename... Args>
inline T& ComponentPool::AddComponent(Entity e, Args&&... args)
{
	GD_ASSERT(!HasComponent<T>(e), "has comp");

	auto idx = GetComponentTypeID<T>();

	m_masks.resize(std::max(e.index + 1, m_masks.size()));
	m_masks[e.index].set(idx);

	auto storage = m_storage[idx];
	T comp(std::forward<Args>(args)...);
	storage->PushBack(e.index, &comp);
	return *static_cast<T*>(storage->Get(e.index));
}

inline 
void ComponentPool::RemoveAllComponents(Entity e)
{
	m_masks[e.index].reset();

	for (auto& storage : m_storage) {
		storage->Erase(e.index);
	}
}

template <typename T>
inline T& ComponentPool::RemoveComponent(Entity e)
{
	auto idx = GetComponentTypeID<T>();
	m_masks[e.index].reset(idx);

	m_storage[idx]->Erase(e.index);
}

template <typename T>
T& ComponentPool::GetComponent(Entity e) const
{
	GD_ASSERT(HasComponent<T>(e), "no component");
	return *reinterpret_cast<T*>(m_storage[GetComponentTypeID<T>()]->Get(e.index));
}

template <typename T>
inline void ComponentPool::SetStorage(CompStorageType type)
{
	int idx = GetComponentTypeID<T>();
	if (m_storage[idx]) {
		delete m_storage[idx];
	}

	IComponentsStorage* storage = nullptr;
	switch (type)
	{
	case COMP_STORAGE_DENSE:
		storage = new CompDenseStorage<T>();
		break;
	case COMP_STORAGE_SPARSE:
		storage = new CompSparseStorage<T>();
		break;
	}
	m_storage[idx] = storage;
}

}
}