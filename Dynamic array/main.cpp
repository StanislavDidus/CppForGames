#include <iostream>

int main()
{
	int array_size;

	std::cout << "Enter the size of an array you wish: " << std::endl;
	while (true)
	{
		std::cin >> array_size;

		if(std::cin.fail())
		{
			std::cout << "ERROR: wrong data type" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (array_size >= 0 && array_size <= 10)
		{
			break;
		}
		else
		{
			std::cout << "ERROR: size of an array must be in a range of 0 and 10" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	int* array = new int[array_size];

	std::cout << "Enter the values of you array(one value per line)" << std::endl;
	for (int i = 0; i < array_size; i++)
	{
		std::cin >> array[i];

		while (std::cin.fail())
		{
			std::cout << "ERROR: wrong data type" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> array[i];
		}
	}

	int min = std::numeric_limits<int>::max();
	int max = -std::numeric_limits<int>::max();
	float average = 0.f;

	for (int i = 0; i < array_size; i++)
	{
		average += static_cast<float>(array[i]);
		if (array[i] < min) min = array[i];
		if (array[i] > max) max = array[i];
	}
	average /= static_cast<float>(array_size);

	std::cout << "Min value: " << min << std::endl;
	std::cout << "Max value: " << max << std::endl;
	std::cout << "Average value: " << average << std::endl;

	delete[] array;
	array = nullptr;

	return 0;
}