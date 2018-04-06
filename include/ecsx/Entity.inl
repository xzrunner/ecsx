#pragma once

namespace ecsx
{

inline bool Entity::IsValid() const 
{
	return m_world->IsIdValid(m_id);
}

template <typename T>
inline bool Entity::HasComponent() const
{
	return m_world->HasComponent<T>(m_id);
}

template <typename T, typename... Args>
inline T& Entity::AddComponent(Args&&... args)
{
	return m_world->AddComponent<T>(m_id, args...);
}

template <typename T>
T& Entity::GetComponent() const
{
	return m_world->GetComponent<T>(m_id);
}

}