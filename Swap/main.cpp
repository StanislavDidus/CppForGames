#include <iostream>

void swap(int& a, int& b)
{
	std::cout << "Swap values" << std::endl;

	int temporary = a;

	a = b;
	b = temporary;
}

int main()
{
	int a = 3;
	int b = 5;

	std::cout << "a: " << a << std::endl
		      << "b: " << b << std::endl;

	swap(a, b);

	std::cout << "a: " << a << std::endl
		<< "b: " << b << std::endl;

	

	return 0;
}