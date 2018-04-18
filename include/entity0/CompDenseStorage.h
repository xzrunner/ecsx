#pragma once

#include "entity0/IComponentsStorage.h"
#include "entity0/Config.h"

namespace e0
{
namespace detail
{

template<typename T>
class CompDenseStorage : public IComponentsStorage
{
public:
	virtual void PushBack(const ID_TYPE& idx, void* data) override;
	virtual void Erase(const ID_TYPE& idx) override;
	virtual void* Get(const ID_TYPE& idx) override;
	//virtual void PushBack(const ID_TYPE& idx, T&& v) override;
	//virtual T* Get(const ID_TYPE& idx) override;
	virtual void Clear() override;

private:
	std::vector<T> m_buf;

}; // CompDenseStorage

}
}

#include "entity0/CompDenseStorage.inl"