#pragma once

#include <cassert>
#include <cstring>

template<typename T>
struct Array
{
	Array(size_t size);
	~Array();

	// Copy semantics.
	Array(const Array& copy);
	Array& operator=(const Array& rhs);

	// Move semantics.
	Array(Array&& other) noexcept;
	Array& operator=(Array&& rhs) noexcept;

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	size_t getSize() const { return size; }
private:
	T* data = nullptr;
	size_t size = 0;
};

template<typename T>
inline Array<T>::Array(size_t size)
	: size{size}
{
	data = new T[size];
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] data;
}

template<typename T>
inline Array<T>::Array(const Array& copy)
	: size(copy.size)
{
	data = new T[size];
	std::memcpy(data, copy.data, size * sizeof(T));
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs) return *this;

	if (size != rhs.size)
	{
		delete[] data;
		size = rhs.size;
		data = new T[size];
	}
	std::memcpy(data, rhs.data, size * sizeof(T));

	return *this;
}

template<typename T>
inline Array<T>::Array(Array&& other) noexcept
	: size(other.size)
{
	data = other.data;

	other.data = nullptr;
	other.size = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& rhs) noexcept
{
	if (this == &rhs) return *this;

	size = rhs.size;
	data = rhs.data;

	rhs.data = nullptr;
	rhs.size = 0;

	return *this;
}


template<typename T>
template<typename Self>
auto&& Array<T>::operator[](this Self&& self, size_t i)
{
	assert(i < self.size);
	return self.data[i];

}