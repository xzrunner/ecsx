#pragma once

#include "entity0/Config.h"

namespace e0
{
namespace detail
{

class IComponentsStorage
{
public:
	virtual void PushBack(const ID_TYPE& idx, void* data) = 0;
	virtual void Erase(const ID_TYPE& idx) = 0;
	virtual void* Get(const ID_TYPE& idx) = 0;
	virtual void Clear() = 0;

}; // IComponentsStorage

}
}