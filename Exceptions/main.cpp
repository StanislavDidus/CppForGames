#include <iostream>
#include <stdexcept>

class MyException : public std::exception
{
public:
	MyException() = default;

	MyException(const char* msg) : std::exception(msg)
	{}
};

int divide(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Cannot divide 0.");
	}

	return numerator / denominator;
}

int main()
{
	// 1. Standard exception syntax
	{
		int numerator = 1;
		int denominator = 0;
		try
		{
			int result = divide(numerator, denominator);
			
			std::cout << numerator << "/" << denominator << " = " << result << std::endl;
		} 
		catch (const MyException& e)
		{
			std::cerr << "Invalid argument: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Invalid argument: " << e.what() << std::endl;
		}
		// All exception
		catch (...)
		{
			std::cerr << "Unknown error: " << std::endl;
		}
		
	}
		
	return 0;
}
