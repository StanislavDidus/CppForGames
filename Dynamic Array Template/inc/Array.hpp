#pragma once

template<typename T>
class Array
{
public:
	Array() : m_capacity(8)
	{
		m_data = new T[m_capacity];
	}

	Array(size_t size, const T& value = T()) : m_size(size), m_capacity(size)
	{
		m_data = new T[size];

		for (size_t i = 0; i < size; ++i)
		{
			m_data[i] = value;
		}
	}

	~Array()
	{
		delete[] m_data;
	}

	//Copy Semantics
	Array(const Array& copy);
	Array& operator=(const Array& rhs);

	//Move Semantics
	Array(Array&& other) noexcept;
	Array& operator=(Array&& rhs) noexcept;

	//Subscript operator
	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	void reserve(size_t new_capacity)
	{
		T* new_data = new T[new_capacity];
	
		for (size_t i = 0; i < m_size; ++i)
		{
			new_data[i] = std::move(m_data[i]);
		}

		delete[] m_data;
		m_data = new_data;
		m_capacity = new_capacity;
	}

	void add(const T& value)
	{
		if (m_size >= m_capacity) reserve(m_capacity * 2);

		m_data[m_size] = value;
		m_size++;
	}

	bool empty() const
	{
		return m_size == 0;
	}

	size_t size() const
	{
		return m_size;
	}

	size_t capacity() const
	{
		return m_capacity;
	}

	template<typename Self>
	auto&& data(this Self&& self);

private:
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;
};

template<typename T>
Array<T>::Array(const Array& copy) : m_size(copy.m_size), m_capacity(copy.m_capacity)
{
	m_data = new T[m_size];
	std::memcpy(m_data, copy.m_data, m_size * sizeof(T));
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this == &rhs) return *this;

	if (m_size != rhs.m_size)
	{
		delete[] m_data;
		m_size = rhs.m_size;
		m_capacity = rhs.m_capacity;
		m_data = new T[m_size];
	}
	std::memcpy(m_data, rhs.m_data, m_size * sizeof(T));

	return *this;
}

template<typename T>
Array<T>::Array(Array&& other) noexcept : m_size(other.m_size), m_capacity(other.m_capacity)
{
	m_data = other.m_data;

	other.m_size = 0;
	other.m_data = nullptr;
	other.m_capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs) noexcept
{
	if (this == &rhs) return *this;

	//Delete original data
	delete[] m_data;

	m_data = rhs.m_data;
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;

	rhs.m_data = nullptr;
	rhs.m_size = 0;
	rhs.m_capacity = 0;

	return *this;
}

template<typename T>
template<typename Self>
auto&& Array<T>::operator[](this Self&& self, size_t i)
{
	assert(i < self.m_size);
	return self.m_data[i];

}

template<typename T>
template<typename Self>
auto&& Array<T>::data(this Self&& self)
{
	return self.m_data;
}