#pragma once

#include "ecsx/IComponentsStorage.h"
#include "ecsx/Config.h"

#include <unordered_map>

namespace ecsx
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

#include "ecsx/CompSparseStorage.inl"