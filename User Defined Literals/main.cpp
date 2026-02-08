#include <cassert>
#include <iostream>

#include "Byte.hpp"

int main()
{
	assert(1_b == Byte{ 1 });
	assert(9_b == Byte{ 2 });
	assert(1_B == Byte{ 1 });
	assert(2_B == Byte{ 2 });
	assert(1_Kb == Byte{ 125 });
	assert(1_KB == Byte{ 1000 });
	assert(1_Mb == Byte{ 125000 });
	assert(1_MB == Byte{ 1000000 });

	return 0;
}
