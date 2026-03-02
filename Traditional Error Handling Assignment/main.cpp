#include <iostream>
#include <string>

struct Digit
{
	int digit;
	int position;
};

inline int parseInt(const char* str, int* result)
{
	size_t str_len = strlen(str);
	
	Digit* digits = new Digit[str_len];
	size_t digit_size = 0;

	bool negative = false;
	for (size_t i = 0; i < str_len; ++i)
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

		digits[digit_size] = Digit{static_cast<int>(current_letter - '0'), 0};

		for (size_t j = 0; j < digit_size; ++j)
		{
			digits[j].position++;
		}

		++digit_size; 
	}

	if (digit_size == 0)
	{
		errno = EINVAL;
		return -1;
	}

	int number = 0;
	for (size_t i = 0; i < digit_size; ++i)
	{
		// long so that temp does not overflow
		long temp = digits[i].digit * pow(10, digits[i].position);

		if (number > INT_MAX - temp)
		{
			errno = ERANGE;
			return -2;
		}
		number += temp;
	}

	*result = negative ? number * -1 : number;
	return 0;
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
