#include <iostream>

unsigned int readNumber()
{
	int n;
	std::cin >> n;

	while (std::cin.fail() || n < 0)
	{
		std::cerr << "ERROR::Wrong data type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> n;
	}

	return static_cast<unsigned int>(n);
}

unsigned int factorial(unsigned int value)
{
	if (value == 0) return 1;
	
	return value * factorial(value - 1);
}

uint64_t factorialOptimized(uint32_t value)
{
	uint64_t result = 1;

	while (value > 0)
	{
		result *= value;
		--value;
	}

	return result;
}

int fib(int value)
{
	if (value == 0) return 0;
	if (value == 1) return 1;

	return fib(value - 1) + fib(value - 2);
}

int main()
{
	//std::cout << "Enter the number" << std::endl;
	//unsigned int number = readNumber();
	//std::cout << "Factorial of <" << number << "> is " << factorialOptimized(number) << std::endl;

	unsigned int number = readNumber();
	std::cout << "Fib: " << fib(number) << std::endl;

	return 0;
}