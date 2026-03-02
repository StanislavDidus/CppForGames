#include <iostream>
#include <string>

inline int parseInt(const char* str, int* result)
{
	std::string number{};
	bool negative = false;
	for (size_t i = 0; i < std::strlen(str); ++i)
	{
		char current_letter = str[i];

		if (current_letter == ',' ||
			current_letter == '\t' ||
			current_letter == '\n' ||
			current_letter == '\r' ||
			current_letter == '+')
			continue;

		if (current_letter == '-')
		{
			negative = !negative;
			continue;
		}

		if (current_letter < '0' || current_letter > '9')
		{
			break;
		}

		number += current_letter;
	}

	// Check for Invalid Input
	if (number.empty())
	{
		errno = EINVAL;
		return -1;
	}
	else
	{
		// Check for integer overflow or underflow
		try
		{
			// Store the result in temp so that only valid value is assigned
			int temp = static_cast<int>(strtol(number.c_str(), nullptr, 10));
			
			if (errno == ERANGE)
				throw std::out_of_range("Integer overflow.");


			*result = temp;
			if (negative) *result *= -1;
			return 0;
		}	
		catch (const std::out_of_range& e)
		{
			return -2;
		}
	}
}

inline bool tryParseInt(const char* str, int& result)
{
	bool output = parseInt(str, &result);

	return output == 0;
}

inline void testString(const std::string& str)
{
	int number = 0;
	int result = parseInt(str.c_str(), &number);

	int number1 = 0;
	bool result1 = tryParseInt(str.c_str(), number1);

	std::cout << "------------------" << std::endl;
	std::cout << "Success: " << result1 << std::endl;
	std::cout << "Input: " << str << std::endl;
	std::cout << "Output: " << number << std::endl;

	if (!result1)
	{
		if (result == -1)
		{
			std::cout << "Invalid argument error." << std::endl;
		}
		else if (result == -2)
		{
			std::cout << "Overflow or underflow error." << std::endl;
		}
	}
}

int main()
{
	testString("42");
	testString("+42");
	testString("-42");
	testString("3.14159");
	testString("10 thousand");
	testString("Ten thousand");
	testString("2147483647");
	testString("-2147483647");
	testString("-2147483648");
	testString("2147483648");
	testString("-2147483649");

	return 0;
}
