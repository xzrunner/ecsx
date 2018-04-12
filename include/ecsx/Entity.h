#pragma once

#include "ecsx/Config.h"

namespace ecsx
{

struct Entity
{
	Entity() : id(0) {}

	bool operator == (const Entity& e) const {
		return id == e.id;
	}

	bool IsNull() const { return id == 0; }

	union
	{
		struct 
		{
			ID_TYPE index   : ECSX_ENTITY_ID_INDEX_BIT_COUNT;
			ID_TYPE version : ECSX_ENTITY_ID_VERSION_BIT_COUNT;
		};
		ID_TYPE id;
	};

}; // Entity

}