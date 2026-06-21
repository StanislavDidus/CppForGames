#include <iostream>
#include <string>
#include <cerrno>
#include <cmath>
#include <climits>

int parseInt(const char* str, int* result)
{
	int length = strlen(str);

	bool negate = false;
	bool was_sign = false; // If value is true then the next sign encountered will stop the parser
	bool digit_encountered = false;

	int value = 0;

	for (int i = 0; i < length; ++i)
	{
		const char current_letter = str[i];

		if (current_letter == ' ' ||
			current_letter == '\t' ||
			current_letter == '\n' ||
			current_letter == '\r') continue;

		// Stop if encountered more than one sign
		if ((current_letter == '-' || current_letter == '+') && was_sign)
		{
			errno = EINVAL;
			return -1;
		}

		if (current_letter == '-' && !was_sign)
		{
			negate = true;
			was_sign = true;
			continue;
		}
		else if (current_letter == '+' && !was_sign)
		{
			was_sign = true;
			continue;
		}

		if (!(current_letter >= '0' && current_letter <= '9'))
		{
			// Stop parsing when non-digit character is encountered
			if (digit_encountered)
				break;
			// If no digit was encountered yet return Invalid argument error
			else
			{
				errno = EINVAL;
				return -1;
				
			}
		}

		int digit = current_letter - '0';
		digit_encountered = true;

		// Check for overflow and underflow
		if (negate)
		{
			if (value < (INT_MIN + digit) / 10)
			{
				errno = ERANGE;
				return -2;
			}
			value = value * 10 - digit;
		}
		else
		{
			if (value > (INT_MAX - digit) / 10)
			{
				errno = ERANGE;
				return -2;
			}
			value = value * 10 + digit;
		}
	}
	
	*result = value;
	return 0;
}

bool tryParseInt(const char* str, int& result)
{
	int res = 0;
	int out = parseInt(str, &res);
	
	if (out == 0)
	{
		result = res;
		return true;
	}
	else
	{
		return false;
	}
}

void printResult(const std::string& str)
{
	int result = 0;
	bool out = tryParseInt(str.c_str(), result);
	
	if(out)
		std::cout << result << std::endl;
	else
	{
		if (errno == EINVAL)
		{
			std::cout << "Invalid argument." << std::endl;
		}
		else if (errno == ERANGE)
		{
			std::cout << "Overflow or underflow." << std::endl;
		}
	}
}

int main()
{
	printResult("42");
	printResult("+42");
	printResult(" -42");
	printResult("3.14159");
	printResult("10 thousand");
	printResult("Ten thousand");
	printResult("2147483647");
	printResult("-2147483648");
	printResult("2147483648");
	printResult("-2147483649");
	return 0;
}