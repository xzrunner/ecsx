#pragma once

#include <boost/noncopyable.hpp>

namespace e0
{

using ComponentID = size_t;

namespace detail
{

inline size_t GetComponentID() noexcept
{
    static ComponentID id{ 0u };
    return id++;
}

}

template <typename T>
inline ComponentID GetComponentTypeID() noexcept
{
    static_assert(std::is_base_of<Component, T>::value,
        "T must inherit from Component");

    static ComponentID type_id{ detail::GetComponentID()};
    return type_id;
}

class Component
{
public:


}; // Component

}