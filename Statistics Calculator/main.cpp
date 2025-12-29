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

int main()
{
	/*std::vector<float> arr;

	for (float i = 0.f; i < 10.f; i += 1.f)
	{
		arr.push_back(i);
	}

	std::cout << max(arr) << std::endl;
	std::cout << min(arr) << std::endl;
	std::cout << sum(arr) << std::endl;
	std::cout << mean(arr) << std::endl;
	std::cout << var(arr) << std::endl;
	std::cout << stdDev(arr) << std::endl;*/

	int n = readValue<int>();

	while (n <= 0)
	{
		std::cerr << "ERROR::Wrong type" << std::endl;
		n = readValue<int>();
	}

	std::cout << n << std::endl;

	std::vector<float> arr(n);

	return 0;
}