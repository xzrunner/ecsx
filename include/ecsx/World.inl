#pragma once

namespace ecsx
{

template <typename T>
inline bool World::HasComponent(Entity e) const
{
	static_assert(std::is_base_of<Component, T>::value,
		"T must inherit from Component");
	return m_comp_pool.HasComponent<T>(e);
}

template <typename T, typename... Args>
inline T& World::AddComponent(Args&&... args)
{
	static_assert(std::is_base_of<Component, T>::value,
		"T must inherit from Component");
	return m_comp_pool.AddComponent<T>(args...);
}

template <typename T>
T& World::GetComponent(Entity e) const
{
	static_assert(std::is_base_of<Component, T>::value,
		"T must inherit from Component");
	return m_comp_pool.GetComponent<T>(e);
}

template <typename T>
void World::SetCompStorage(CompStorageType type)
{
	static_assert(std::is_base_of<Component, T>::value,
		"T must inherit from Component");
	m_comp_pool.SetStorage<T>(type);
}

}