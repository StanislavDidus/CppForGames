#include <iostream>

int readNumber()
{
	int n;
	std::cin >> n;

	while (std::cin.fail())
	{
		std::cerr << "ERROR::Wrong data type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> n;
	}

	return n;
}

bool isPrime(int number)
{
	if (number <= 1) return false;
	//if (number == 2) return true;
	
	for (int i = 2; i * i <= number; i++)
	{
		if (i != number && number % i == 0) return false;
	}

	return true;
}

bool isPrimeOptimized(int number)
{
	if (number <= 1) return false;
	if (number <= 3) return true;

	if (number % 2 == 0 || number % 3 == 0) return false;

	for (int i = 5; i * i <= number; i += 6)
	{
		if (number % i == 0 || number % (i + 2) == 0) return false;
	}

	return true;
}

int main()
{
	//1
	/*std::cout << "Enter a natural number" << std::endl;

	int number = readNumber();

	if (isPrime(number))
	{
		std::cout << "<" << number << ">" << " is prime." << std::endl;
	}
	else
	{
		std::cout << "<" << number << ">" << " is not prime." << std::endl;
	}*/

	//2
	std::cout << "Enter min value" << std::endl;
	int min = readNumber();

	std::cout << "Enter max value" << std::endl;
	int max = readNumber();

	for (int i = min; i < max; ++i)
	{
		if (isPrimeOptimized(i))
		{
			std::cout << i << " ";
		}
	}

	return 0;
}