#include <iostream>

decltype(auto) max(const auto& a, const auto& b)
{
	return a > b ? a : b;
}

void swap(auto& a, auto& b)
{
	auto temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main()
{
	{
		int a = 5;
		int b = 10;

		int c = max(a, b);
	}

	{
		int a = 5;
		double b = 10.0;

		auto c = max(a, b);
	}

	{
		int a  = 5;
		int b = 10;

		swap(a, b);

		std::cout << a << ", " << b << std::endl;
	}

	return 0;
}