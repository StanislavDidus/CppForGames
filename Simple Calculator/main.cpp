#include <iostream>
#include <vector>

int safeDivision(int& divident, int divisor)
{
	if (divisor == 0)
	{
		std::cout << "ERROR: division it not valid\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	else
	{
		divident /= divisor;
	}

	return 0;
}

int checkForWrongInput()
{
	if (std::cin.fail())
	{
		std::cout << "ERROR: wrong input\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	else
	{
		return 0;
	}
}

//Check for situation if user types: 10+ or 255/
int checkForNextNumber()
{
	if(std::cin.peek() == '\n')
	{
		std::cout << "ERROR: wrong input\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	return 0;
}

int checkForFutherMultiplicationOrDivisionSigns(int& value)
{
	while (std::cin.peek() != '\n' && std::cin.peek() != '+' && std::cin.peek() != '-')
	{
		char sign_ = ' ';
		int num_ = 0;

		std::cin >> sign_;
		if (checkForWrongInput() == 1) return 1;

		switch (sign_)
		{
		case '*':
			if (checkForNextNumber() == 1) return 1;

			std::cin >> num_;

			if (checkForWrongInput() == 1) return 1;

			value *= num_;
			break;
		case '/':
			if (checkForNextNumber() == 1) return 1;

			std::cin >> num_;

			if (checkForWrongInput() == 1) return 1;

			//If error occurs - return
			if (safeDivision(value, num_) == 1)
			{
				return 1;
			}

			break;
		}
	}

	return 0;
}

int calculator()
{
	std::vector<int> numbers;

	std::cout << "Enter your expression: ";

	bool isNextValueNegative = false;

	while (std::cin.peek() != '\n')
	{
		int value = 0;
		char sign = ' ';

		std::cin >> value;
		if (checkForWrongInput() == 1) return 1;

		//If end of expression then do not read sign
		if (std::cin.peek() != '\n')
		{
			std::cin >> sign;
			if (checkForWrongInput() == 1) return 1;
		}

		//If there was a '-' before a value then reverse it
		if (isNextValueNegative)
		{
			value *= -1;
			isNextValueNegative = false;
		}


		//Read sign after a number
		int temp = 0;
		switch (sign)
		{
		case '+':
			if (checkForNextNumber() == 1) return 1;
 			//If plus we do not do anything

			//Check for situations like: 10+
			break;
		case '-':
			if (checkForNextNumber() == 1) return 1;

			//If minus then the next number should be reversed
			isNextValueNegative = true;

			break;
		case '*':
			if (checkForNextNumber() == 1) return 1;

			//If '*' multiply by the next value
			std::cin >> temp;
			if (checkForWrongInput() == 1) return 1;

			value *= temp;

			//Check for further '*' and '/' signs
			if (checkForFutherMultiplicationOrDivisionSigns(value) == 1)
			{
				return 1;
			}

			break;
		case '/':
			if (checkForNextNumber() == 1) return 1;

			std::cin >> temp;

			if (checkForWrongInput() == 1) return 1;

			//If error occurs - return
			if (safeDivision(value, temp) == 1)
			{
				return 1;
			}

			if (checkForFutherMultiplicationOrDivisionSigns(value) == 1)
			{
				return 1;
			}

			break;
		}

		numbers.push_back(value);
	}

	//Sum up all the values in the vector
	int value = 0;
	for (auto& number : numbers)
	{
		value += number;
	}

	std::cout << "Result is: " << value << std::endl;

	return 0;
}

int main()
{
	//Call calculator until the operation succeed
	while(true)
	{
		if (calculator() == 0)
		{
			break;
		}
	} 

	/////////////////////////////////////////////////////////////////////////////

	/*int number1 = 0;
	int number2 = 0;
	char oper = ' ';
	int result = 0;

	std::cout << "Enter first number\n";
	std::cin >> number1;

	while (std::cin.fail())
	{
		std::cout << "ERROR1: not correct input type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> number1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter type of operation: '+', '-', '*', '/'" << std::endl;
	std::cin >> oper;

	while (std::cin.fail())
	{
		std::cout << "ERROR2: not correct input type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> oper;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter second number" << std::endl;
	std::cin >> number2;

	while (std::cin.fail())
	{
		std::cout << "ERROR3: not correct input type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> number2;
	}

	if (oper != '+' && oper != '-' && oper != '*' && oper != '/')
	{
		std::cout << "ERRRO4: invalid operator type" << std::endl;
		return 1;
	}

	if (oper == '/' && number2 == 0)
	{
		std::cout << "ERROR5: division by zero is not allowed" << std::endl;
		return 1;
	}

	switch (oper)
	{
	case '+':
		result = number1 + number2;
		break;
	case '-':
		result = number1 - number2;
		break;
	case '*':
		result = number1 * number2;
		break;
	case '/':
		result = number1 / number2;
		break;
	}

	std::cout << "Result: " << result << std::endl;*/

	return 0;
}