#include <iostream>
#include <cassert>

#include <Vector.hpp>

int main()
{
	vec3f a{ 1,2, 3 };
	vec3f b{ 4, 5, 6 };
	
	vec3f c = a + b ;
	assert(c.x == 5.0f && c[1] == 7.0f);

	return 0;
}