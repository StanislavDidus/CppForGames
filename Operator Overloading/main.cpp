#include <cassert>
#include <iostream>

#include <Vector2.hpp>
#include "Int.hpp"

void printInt(int i)
{
	std::cout << i << std::endl;
}

int main()
{
	Vector2 a{ 1,2 };
	Vector2 b{ 3,4 };

	Vector2 c = a + b;
	assert(c.x == 4.0f && c.y == 6.0f);

	Vector2 d = -a;
	assert(d.x == -1.0f && d.y == -2.0f);

	c += a;
	assert(c.x == 5.f && c.y == 8.f);

	Vector2 e = c--;
	assert(e.x == 5.0f && e.y == 8.f);
	assert (c.x == 4.0f && c.y == 7.0f);

	assert(c[0] == 4.0f && c[1] == 7.0f);

	Vector2 f = a;
	assert(f == a);
	assert(f != c);
	assert(f < b);
	assert(b > a);

	Int i { 1 };
	int j = static_cast<int>(i);
	printInt(static_cast<int>(i));

	i = 10;

	return 0;
}
