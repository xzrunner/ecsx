#pragma once

#include "entity0/IComponentsStorage.h"
#include "entity0/Config.h"

#include <unordered_map>

namespace e0
{
namespace detail
{

template<typename T>
class CompSparseStorage : public IComponentsStorage
{
public:
	virtual void PushBack(const ID_TYPE& idx, void* data) override;
	virtual void Erase(const ID_TYPE& idx) override;
	virtual void* Get(const ID_TYPE& idx) override;
	//virtual void PushBack(const ID_TYPE& idx, T&& v) override;
	//virtual T* Get(const ID_TYPE& idx) override;
	virtual void Clear() override;

private:
	std::unordered_map<ID_TYPE, T> m_id2comp;

}; // CompSparseStorage

}
}

#include "entity0/CompSparseStorage.inl"