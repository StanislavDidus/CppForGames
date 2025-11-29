#include <iostream>
#include <cstdint>
#include <bitset>

int main()
{
	int8_t a = 0b01010101;
	int8_t b = 0b11111111;
	uint8_t mask = 0b1;

	std::cout << "a: " << std::bitset<8>(a & mask) << std::endl;
	std::cout << "a ^ b: " << std::bitset<8>(a ^ b) << std::endl;

	return 0;
}