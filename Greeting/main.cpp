#include <iostream>
#include <string>
#include <limits>

int main()
{
	std::string name;
	int age;

	std::cout << "What is your name?" << std::endl;
	std::cin >> name;

	std::cout << "How old are you?" << std::endl;
	std::cin >> age;

	while (std::cin.fail())
	{
		std::cout << "ERROR: not correct input type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> age;
	}

	//Advanced

	if (age < 25)
	{
		std::cout << "Hello " << name << ","
			<< " you are only " << age << " years old" << std::endl;
	}
	else if (age > 25 && age < 50)
	{
		std::cout << "Hello " << name << ","
			<< " you are already " << age << " years old" << std::endl;
	}
	else if (age > 50)
	{
		std::cout << "Hello " << name << "." << std::endl
			<< "You are a very wise for your age." << std::endl;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return 0;
}