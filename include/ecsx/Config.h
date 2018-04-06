#pragma once

#include <cstdint>
#include <cstddef>

#define ECSX_32_BIT_ENTITY_IDS

#ifdef ECSX_32_BIT_ENTITY_IDS
typedef std::uint32_t ID_TYPE;
typedef std::uint16_t ID_VERSION_TYPE;
#	define ECSX_ENTITY_ID_INDEX_BIT_COUNT   20
#	define ECSX_ENTITY_ID_VERSION_BIT_COUNT 12
#else
typedef std::uint64_t ID_TYPE;
typedef std::uint32_t ID_VERSION_TYPE;
#	define ECSX_ENTITY_ID_INDEX_BIT_COUNT   48
#	define ECSX_ENTITY_ID_VERSION_BIT_COUNT 16
#endif // ECSX_32_BIT_ENTITY_IDS

namespace ecsx
{

constexpr const std::size_t MAX_COMPONENTS = 64;

}