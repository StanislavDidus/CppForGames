#include <cassert>
#include <iostream>

#include "Point.hpp"

int main()
{
	Point p1{1.0f,1.0f};
	Point p2{ 2.0f,3.0f };
	Direction d{ 5.0f, 5.0f };
	Direction d1{ 0.f, 2.0f };

	// Point +/- Direction
	{
		Point temp = p1 + d;
		assert(temp.x == 6.0f && temp.y == 6.0f);

		Point temp1 = p1 - d;
		assert(temp1.x == -4.0f && temp1.y == -4.0f);
	}

	// Point - Point
	{
		Direction temp = p2 - p1;
		assert(temp.x == 1.0f && temp.y == 2.0f);
	}

	// Direction +/- Direction
	{
		Direction temp = d + d1;
		assert(temp.x == 5.0f && temp.y == 7.0f);

		Direction temp1 = d - d1;
		assert(temp1.x == 5.0f && temp1.y == 3.0f);
	}

	// Direction * float
	{
		Direction temp = 2.0f * d;
		assert(temp.x == 10.0f && temp.y == 10.0f);
	}
	
	return 0;
}
