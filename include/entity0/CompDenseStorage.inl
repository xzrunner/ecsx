#pragma once

namespace e0
{
namespace detail
{

template<typename T>
void CompDenseStorage<T>::PushBack(const ID_TYPE& idx, void* data)
{
	if (idx >= m_buf.size()) {
		m_buf.resize(idx + 1);
	}
	memcpy(&m_buf[idx], data, sizeof(T));
}

template<typename T>
void CompDenseStorage<T>::Erase(const ID_TYPE& idx)
{
	// todo
}

template<typename T>
void* CompDenseStorage<T>::Get(const ID_TYPE& idx)
{
	if (idx >= 0 && idx < m_buf.size()) {
		return &m_buf[idx];
	} else {
		return nullptr;
	}
}

//template<typename T>
//void CompDenseStorage<T>::PushBack(const ID_TYPE& idx, T&& v)
//{
//	if (idx >= m_buf.size()) {
//		m_buf.resize(idx + 1);
//	}
//	m_buf[idx] = std::move(v);
//}
//
//template<typename T>
//T* CompDenseStorage<T>::Get(const ID_TYPE& idx)
//{
//	if (idx >= 0 && idx < m_buf.size()) {
//		return &m_buf[idx];
//	} else {
//		return nullptr;
//	}
//}

template<typename T>
void CompDenseStorage<T>::Clear()
{
	m_buf.clear();
}

}
}