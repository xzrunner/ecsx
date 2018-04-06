#pragma once

#include "ecsx/IComponentsStorage.h"
#include "ecsx/Config.h"

namespace ecsx
{
namespace detail
{

template<typename T>
class CompDenseStorage : public IComponentsStorage
{
public:
	virtual void Add(const ID_TYPE& idx, void* data) override;
	virtual void* Get(const ID_TYPE& idx) override;
	//virtual void Add(const ID_TYPE& idx, T&& v) override;
	//virtual T* Get(const ID_TYPE& idx) override;
	virtual void Clear() override;

private:
	std::vector<T> m_buf;

}; // CompDenseStorage

}
}

#include "ecsx/CompDenseStorage.inl"