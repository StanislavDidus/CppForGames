#include <iostream>

template<typename T, size_t N>
class Array
{
public:
	Array() = default;

	size_t size() const
	{
		return std::size(arr);
	}
private:
	T arr[N];
};

template<size_t N>
class Array<bool, N>
{
public:
	Array()
	{
		std::cout << "boolean array was generated" << std::endl;
	}

	size_t size() const
	{
		return std::size(arr);
	}
private:
	bool arr[N];
};	

using ivec2 = Array<int, 2>;
using vec2 = Array<float, 2>;
using vec3 = Array<float, 3>;

int main()
{
	Array<int, 3> arr;
	std::cout << arr.size() << std::endl;

	vec2 vec;

	return 0;
}