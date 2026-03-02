#include "ApplicationError.hpp"
#include "DataBaseError.hpp"

#include <format>
#include <iostream>
#include <ostream>

#include <expected>

int divide(int numerator, int denominator)
{
	if (denominator == 0)
		throw std::invalid_argument("Cannot divide by zero");

	return numerator / denominator;
}

std::expected<int, std::string> divideExpected(int numerator, int denominator) try
{
	if (denominator == 0)
		throw std::invalid_argument("Cannot divide by zero");

	return numerator / denominator;
}
catch (const std::exception& e)
{
	return std::unexpected{ e.what() };
}

class Ratio
{
public:
	Ratio(int numerator, int denominator) try
		: numerator{numerator},
		denominator{denominator},
		value{divide(numerator, denominator)}
	{
		
	}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "An error occured: " << e.what() << std::endl;
			// The exception is automatically rethrown.
		}

	~Ratio() noexcept(false) // Override the implicit noexcept.
	try
	{
		throw std::exception("Exception during destruction.");
	}
	catch (const std::exception& e)
	{
		std::cerr << "An error occured during destruction: " << e.what() << std::endl;
	}

private:
	int numerator;
	int denominator;
	int value = 0;
};

template<typename ... Args>
void logError(std::format_string<Args...> fmt, Args&&... args)
{
	std::cerr << std::format(fmt, std::forward<Args>(args)...) << std::endl;
}

void logNestedException(const std::exception& e, int level = 0)
{
	logError("{:{}} Exception: {}", "", level * 4, e.what());
	try
	{
		std::rethrow_if_nested(e);
	}
	catch (const std::exception& e)
	{
		logNestedException(e, level + 1);
	}
}

int main()
{
	// 1. Custom exception hierarchy.
	{
		try
		{
			// Does some application specific thing...
			//throw ConnectionError("Could not connect to database.");
			throw DataBaseError("Database does not exist.");
			//throw "Error";
		}
		catch (const ConnectionError& e)
		{
			logError("{} Connection error: {}\n", e.getErrorCode(), e.what());
		}
		catch (const QueryError& e)
		{
			logError("{} Query error with query {}: {}\n", e.getErrorCode(), e.getQuery(), e.what());
		}
		/*catch (const ApplicationError& e)
		{
			logError("{} ApplicationError error: {}\n", e.getErrorCode(), e.what());
		}
		catch (const std::exception& e)
		{
			logError("An error occured: {}\n", e.what());
		}*/
		catch (...)
		{
			//logError("An unknown error occured.\n");
			try
			{
				std::throw_with_nested(ApplicationError("An unknown error occured."));
			}
			catch (ApplicationError& e)
			{
				logNestedException(e);
			}
		}
	}

	// Function-try block

	{
		try
		{
			int numerator = 1;
			int denominator = 1;
			Ratio r{ numerator, denominator };
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "An error occured: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "An error occured: " << e.what() << std::endl;
		}

		auto expectedResult = divideExpected(1, 0);
		if (expectedResult)
		{
			int value = *expectedResult;
		}
		else
		{
			std::cerr << "Unexpected result: " << expectedResult.error();
		}
	}

	return 0;
}
