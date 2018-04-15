#pragma once

namespace ecsx
{
namespace detail
{

template<typename T>
void CompSparseStorage<T>::PushBack(const ID_TYPE& idx, void* data)
{
	m_id2comp.insert(std::make_pair(idx, *static_cast<T*>(data)));
}

template<typename T>
void CompSparseStorage<T>::Erase(const ID_TYPE& idx)
{
	m_id2comp.erase(idx);
}

template<typename T>
void* CompSparseStorage<T>::Get(const ID_TYPE& idx)
{
	auto itr = m_id2comp.find(idx);
	return itr == m_id2comp.end() ? nullptr : &itr->second;
}

template<typename T>
void CompSparseStorage<T>::Clear()
{
	m_id2comp.clear();
}

}
}