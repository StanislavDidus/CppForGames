#pragma once

#include "VectorBase.hpp"

#include <cassert>

//Primary template
template<typename T, size_t N>
struct Vector : VectorBase<T, N>
{
	using base = VectorBase<T, N>;

	Vector<T, N> operator+(const Vector<T, N>& rhs) const;

	//T& operator[](size_t i);
	//const T& operator[](size_t i) const;

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);
};

template<>
struct Vector<float, 2>
{
	Vector operator+(const Vector& rhs) const;

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	float data[2];
};

inline Vector<float, 2> Vector<float, 2>::operator+(const Vector<float, 2>& rhs) const
{
	Vector<float, 2> result;

	result.data[0] = this->data[0] + rhs.data[0];
	result.data[1] = this->data[1] + rhs.data[1];

	return result;
}

template<typename T, size_t N>	
inline Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& rhs) const
{
	Vector<T, N> result;

	for (size_t i = 0; i < N; i++)
	{
		result.data[i] = base::data[i] + rhs.data[i];
	}

	return result;
}

//template<typename T, size_t N>
//T& Vector<T, N>::operator[](size_t i)
//{
//	assert(i < N);
//	return data[i];
//}
//
//template<typename T, size_t N>
//const T& Vector<T, N>::operator[](size_t i) const
//{
//	assert(i < N);
//	return data[i];
//}

template<typename Self>
auto&& Vector<float, 2>::operator[](this Self&& self, size_t i)
{
	assert(i < 2);
	return self.data[i];
}

template<typename T, size_t N>
template<typename Self>
auto&& Vector<T, N>::operator[](this Self&& self, size_t i)
{
	assert(i < N);
	return self.data[i];
}

using vec2f = Vector<float, 2>;
using vec3f = Vector<float, 3>;

extern template struct Vector<float, 2>;
extern template struct Vector<float, 3>;