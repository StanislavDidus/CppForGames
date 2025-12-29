#include <iostream>
#include <vector>

template <typename T>
T readValue()
{
	T value;
	std::cin >> value;

	while (std::cin.fail())
	{
		std::cerr << "ERROR::Wrong type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> value;
	}

	return value;
}

template <typename T>
T max(const std::vector<T>& arr)
{
	T max = std::numeric_limits<T>::min();
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

template <typename T>
T min(const std::vector<T>& arr)
{
	T min = std::numeric_limits<T>::max();
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

template <typename T>
T sum(const std::vector<T>& arr)
{
	T sum = static_cast<T>(0);
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}

	return sum;
}

template <typename T>
T mean(const std::vector<T>& arr)
{
	return sum(arr) / arr.size();
}

template <typename T>
T var(const std::vector<T>& arr)
{
	const T& mean_ = mean(arr);
	T sq_sum = static_cast<T>(0);
	for (int i = 0; i < arr.size(); i++)
	{
		T deviation = arr[i] - mean_;
		T sq_deviation = deviation * deviation;
		sq_sum += sq_deviation;
	}

	return sq_sum / (arr.size() - 1);
}

template <typename T>
T stdDev(const std::vector<T>& arr)
{
	const T& var_ = var(arr);
	return sqrt(var_);
}

template <typename T>
void sort(std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		bool swapped = false;

		for (int j = 0; j < arr.size() - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) return;
	}
}

int main()
{
	{
		std::vector<int> arr{ 0,15,100,14,-15,0,5,101 };
		sort(arr);
		for (int i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << std::endl;
		}
	}

	std::cout << "Array was sorted." << std::endl;

	std::cout << "Enter the size of an array: ";
	int n = readValue<int>();
	while (n <= 0)
	{
		std::cerr << "ERROR::Value must be greater than 0" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		n = readValue<int>();
	}

	std::vector<float> arr;
	arr.reserve(n);

	for (int i = 0; i < n; i++)
	{
		std::cout << "\nType the <" << i << "> element of the array: ";
		//I use ignore() here because otherwise if I for example type the size of array to be 10.0 then 0 goes here 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		float value = readValue<float>();
		arr.push_back(value);
	}

	std::cout << "\nMax: " << max(arr) << std::endl;
	std::cout << "Min: " << min(arr) << std::endl;
	std::cout << "Sum: " << sum(arr) << std::endl;
	std::cout << "Mean: " << mean(arr) << std::endl;
	std::cout << "Variance: " << var(arr) << std::endl;
	std::cout << "Standard deviation: " << stdDev(arr) << std::endl;

	return 0;
}