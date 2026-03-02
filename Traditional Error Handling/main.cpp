#include <iostream>
#include <string>
#include <stdexcept>
#include <expected>

enum class ReturnCode
{
	SUCCESS,
	INVALID_ARGUMENT,
	OUT_OF_RANGE,
};

bool tryParseInt( const std::string& str, int& value)
{
	try
	{
		value = std::stoi(str);
	}
	catch (const std::invalid_argument& e)
	{
		return false;
	}
	catch (const std::out_of_range& e)
	{
		return false;
	}

	return true;
}

ReturnCode parseInt(const std::string& str, int& value)
{
	try
	{
		value = std::stoi(str);
	}
	catch (const std::invalid_argument& e)
	{
		return ReturnCode::INVALID_ARGUMENT;
	}
	catch (const std::out_of_range& e)
	{
		return ReturnCode::OUT_OF_RANGE;
	}

	return ReturnCode::SUCCESS;
}

std::expected<int, ReturnCode> parseIntExpected(const std::string& str)
{
	try
	{
		int result = std::stoi(str);
		return result;
	}
	catch (const std::invalid_argument& e)
	{
		return std::unexpected{ ReturnCode::INVALID_ARGUMENT };
	}
	catch (const std::out_of_range& e)
	{
		return std::unexpected{ ReturnCode::OUT_OF_RANGE };
	}
}

using ErrorHandler = void(*)(ReturnCode code);

void parseIntWithHandler(const std::string& str, int& value, ErrorHandler handler = nullptr)
{
	try
	{
		value = std::stoi(str);
	}
	catch (const std::invalid_argument& e)
	{
		if (handler)
			handler(ReturnCode::INVALID_ARGUMENT);
	}
	catch (const std::out_of_range& e)
	{
		if (handler)
			handler(ReturnCode::OUT_OF_RANGE);
	}
}

void handleError(ReturnCode code)
{
	switch (code)
	{
	case ReturnCode::INVALID_ARGUMENT:
		std::cerr << "Invalid argument." << std::endl;
		break;
	case ReturnCode::OUT_OF_RANGE:
		std::cerr << "Out of range." << std::endl;
		break;
	default:
		std::cerr << "Unknown error" << std::endl;
	}
}

int main()
{
	// 1. Error return values.	
	{
		int value;
		if (tryParseInt("42", value))
		{
			std::cout << "Success!" << std::endl;
		}
		else
		{
			std::cerr << "Failed!" << std::endl;
		}

		ReturnCode ret = parseInt("2147483648", value);
		if (ret == ReturnCode::SUCCESS)
		{
			std::cout << "Success!" << std::endl;
		}
		else
		{
			switch (ret)
			{
			case ReturnCode::INVALID_ARGUMENT:
				std::cerr << "Invalid argument." << std::endl;
				break;
			case ReturnCode::OUT_OF_RANGE:
				std::cerr << "Out of range." << std::endl;
				break;
			default:
				std::cerr << "Unknown error" << std::endl;
			}
		}

		// Using C++23 std::expected
		auto result = parseIntExpected("2147483648");
		if (result)
		{
			int value = *result;
			std::cout << "Success!" << std::endl;
		}
		else
		{
			switch (result.error())
			{
			case ReturnCode::INVALID_ARGUMENT:
				std::cerr << "Invalid argument." << std::endl;
				break;
			case ReturnCode::OUT_OF_RANGE:
				std::cerr << "Out of range." << std::endl;
				break;
			default:
				std::cerr << "Unknown error" << std::endl;
			}
		}
	}

	// 2. Error handlers.
	{
		int value;
		parseIntWithHandler("two", value, &handleError);
	}

	return 0;
}
