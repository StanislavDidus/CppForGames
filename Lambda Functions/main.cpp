#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 != 0; }), vec.end());

	//std::erase_if(vec, [](int num) { return num % 2 != 0; });

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "Value <" << i << "> is: " << vec[i] << std::endl;
	}

	return 0;
}