#include <iostream>
#include <cassert>

#include <Array.hpp>
#include <numeric>

int main()
{
	//Default constructor
	{
		Array<float> vector;

		assert(vector.size() == 0 && vector.capacity() == 8);
	}

	//Parameterized constructor
	{
		Array<float> vector{ 25, 100.f };
		assert(vector.size() == 25);
		for (size_t i = 0; i < 25; ++i)
		{
			assert(vector.data()[i] == 100.f);
		}
	}

	//Copy constructor
	{
		Array<float> vector{ 10,10.f };
		Array<float> vector2{ vector };

		for (size_t i = 0; i < vector.size(); ++i)
		{
			assert(vector[i] == vector2[i]);
		}
	}

	//Move constructor
	{
		Array<float> vector{ 5, 7.f };
		Array<float> vector2{ std::move(vector) };
		
		assert(vector2.size() == 5 && vector.empty());
	}

	//Copy assignment
	{
		Array<float> vector{ 3, 5.f };
		Array<float> vector2 = vector;

		for (size_t i = 0; i < vector.size(); ++i)
		{
			assert(vector[i] == vector2[i]);
		}
	}

	//Move assignment
	{
		Array<float> vector{ 3, 5.f };
		Array<float> vector2 = std::move(vector);

		assert(vector2[0] == 5.f && vector.empty()); 
	}

	// Iterator
	{
		Array<float> vector{ 3, 10.f };
		auto it = vector.begin();
		assert(*it == 10.0f);

		vector[1] = 15.0f;
		++it;
		assert(*it == 15.0f);

		--it;
		assert(*it == 10.0f);

		vector[2] = 20.0f;
		it = vector.end();
		--it;
		assert(*it == 20.0f);

		for (const auto& number : vector)
		{
			std::cout << number << std::endl;
		}

		/*for (auto iter = vector.begin(); iter != vector.end(); ++iter)
		{
			std::cout << *iter << std::endl;
		}*/

		float sum = std::accumulate(vector.begin(), vector.end(), 0.f);
		std::cout << "Sum is: " << sum << std::endl;
	}

	return 0;
}
