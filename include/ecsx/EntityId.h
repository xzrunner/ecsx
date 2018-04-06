#pragma once

#include "ecsx/Config.h"

namespace ecsx
{

struct EntityId
{
	EntityId() : index(0), version(0) {}

	ID_TYPE index   : ECSX_ENTITY_ID_INDEX_BIT_COUNT;
	ID_TYPE version : ECSX_ENTITY_ID_VERSION_BIT_COUNT;

}; // EntityId

}