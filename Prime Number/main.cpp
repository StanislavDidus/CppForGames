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
	
	for (int i = 2; i < number; i++)
	{
		if (i != number && number % i == 0) return false;
	}

	return true;
}

int main()
{
	std::cout << "Enter a natural number" << std::endl;

	int number = readNumber();

	if (isPrime(number))
	{
		std::cout << "<" << number << ">" << " is prime." << std::endl;
	}
	else
	{
		std::cout << "<" << number << ">" << " is not prime." << std::endl;
	}

	return 0;
}