#include <iostream>
#include <bitset>
#include <cstdint>

template<typename T>
void readInput(T& value)
{
	std::cin >> value;

	while(std::cin.fail())
	{
		std::cerr << "ERROR: Wrong data type input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> value;
	}
}

int main()
{
	uint8_t value;

	{
		int temp = 0;
		std::cout << "Enter a number in range (0 - 255): ";
		readInput(temp);

		while (temp < 0 || temp > 255)
		{
			std::cerr << "ERROR: number is out of range" << std::endl;
			readInput(temp);
		}

		value = static_cast<uint8_t>(temp);
	}

	uint8_t bit_position;

	{
		int temp = 0;
		std::cout << "Enter a bit position in range (0 - 7): ";
		readInput(temp);

		while (temp < 0 || temp > 7)
		{
			std::cerr << "ERROR: number is out of range" << std::endl;
			readInput(temp);
		}

		bit_position = static_cast<uint8_t>(temp);
	}

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "Initial number: " << static_cast<int>(value) << std::endl;
	std::cout << "Initial bit position: " << static_cast<int>(bit_position) << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "Binary: " << std::bitset<8>(value) << std::endl;

	uint8_t number_of_set_bits = 0;

	for (int i = 0; i < 8; i++)
	{
		if (value >> i & 0b00000001)
		{
			number_of_set_bits++;
		}
	}

	std::cout << "----------------------------------------------" << std::endl;

	std::cout << "Bits that are set: " << static_cast<int>(number_of_set_bits) << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	bool is_bit_set = value >> bit_position & 0b00000001;

	if(is_bit_set)	std::cout << "Bit <" << static_cast<int>(bit_position) << "> is set: true" << std::endl;
	else std::cout << "Bit <" << static_cast<int>(bit_position) << "> is set: false" << std::endl;

	std::cout << "----------------------------------------------" << std::endl;

	{
		uint8_t v = value;
		uint8_t mask = 1 << bit_position;
		v = v | mask;

		std::cout << static_cast<int>(bit_position) << "th bit is set" << std::endl;
		std::cout << "New binary value: " << std::bitset<8>(v) << std::endl;
		std::cout << "New decimal value: " << static_cast<int>(v) << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		uint8_t v = value;
		uint8_t mask = ~(1 << bit_position);
		v = v & mask;

		std::cout << static_cast<int>(bit_position) << "th bit is cleared" << std::endl;
		std::cout << "New binary value: " << std::bitset<8>(v) << std::endl;
		std::cout << "New decimal value: " << static_cast<int>(v) << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		uint8_t v = value;
		uint8_t mask = 1 << bit_position;
		v = v ^ mask;

		std::cout << static_cast<int>(bit_position) << "th bit is inverted" << std::endl;
		std::cout << "New binary value: " << std::bitset<8>(v) << std::endl;
		std::cout << "New decimal value: " << static_cast<int>(v) << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		uint8_t v = value;
		v = v << bit_position;

		std::cout << "Number is left shifted by " << bit_position << std::endl;
		std::cout << "New binary value: " << std::bitset<8>(v) << std::endl;
		std::cout << "New decimal value: " << static_cast<int>(v) << std::endl;
	}

	std::cout << "----------------------------------------------" << std::endl;

	{
		uint8_t v = value;
		v = v >> bit_position;

		std::cout << "Number is right shifted by " << bit_position << std::endl;
		std::cout << "New binary value: " << std::bitset<8>(v) << std::endl;
		std::cout << "New decimal value: " << static_cast<int>(v) << std::endl;
	}

	return 0;
}