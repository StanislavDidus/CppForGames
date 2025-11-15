//#include <iostream>
//#include <vector>
//
//int safeDivision(float& divident, float divisor)
//{
//	if (divisor == 0.f)
//	{
//		std::cout << "ERROR: division it not valid\n";
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		return 1;
//	}
//	else
//	{
//		divident /= divisor;
//	}
//
//	return 0;
//}
//
//int safeModulo(float& divident, float divisor)
//{
//	if (divisor == 0)
//	{
//		std::cout << "ERROR: modulo of 0 it not valid\n";
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		return 1;
//	}
//	else
//	{
//		divident = std::fmodf(divident, divisor);
//	}
//	return 0;
//}
//
//int checkForWrongInput()
//{
//	if (std::cin.fail())
//	{
//		std::cout << "ERROR: wrong input\n";
//		std::cin.clear();
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
////Check for situation if user types: 10+ or 255/
//int checkForNextNumber()
//{
//	if (std::cin.peek() == '\n')
//	{
//		std::cout << "ERROR: wrong input\n";
//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		return 1;
//	}
//	return 0;
//}
//
//int checkForFutherMultiplicationOrDivisionSigns(float& value)
//{
//	while (std::cin.peek() != '\n' && std::cin.peek() != '+' && std::cin.peek() != '-')
//	{
//		char sign_ = ' ';
//		float num_ = 0.f;
//
//		std::cin >> sign_;
//		if (checkForWrongInput() == 1) return 1;
//
//		switch (sign_)
//		{
//		case '*':
//			if (checkForNextNumber() == 1) return 1;
//
//			std::cin >> num_;
//
//			if (checkForWrongInput() == 1) return 1;
//
//			value *= num_;
//			break;
//		case '/':
//			if (checkForNextNumber() == 1) return 1;
//
//			std::cin >> num_;
//
//			if (checkForWrongInput() == 1) return 1;
//
//			//If error occurs - return
//			if (safeDivision(value, num_) == 1)
//			{
//				return 1;
//			}
//
//			break;
//		case '%':
//			if (checkForNextNumber() == 1) return 1;
//
//			std::cin >> num_;
//
//			if (checkForWrongInput() == 1) return 1;
//
//			if (safeModulo(value, num_) == 1)
//			{
//				return 1;
//			}
//
//			break;
//		case '^':
//			if (checkForNextNumber() == 1) return 1;
//
//			//If '*' multiply by the next value
//			std::cin >> num_;
//			if (checkForWrongInput() == 1) return 1;
//
//			value = std::pow(value, num_);
//
//			break;
//		}
//	}
//
//	return 0;
//}
//
//int calculator()
//{
//	std::vector<float> numbers;
//
//	std::cout << "Enter your expression: ";
//
//	bool isNextValueNegative = false;
//
//	while (std::cin.peek() != '\n')
//	{
//		float value = 0.f;
//		char sign = ' ';
//
//		std::cin >> value;
//		if (checkForWrongInput() == 1) return 1;
//
//		//If end of expression then do not read sign
//		if (std::cin.peek() != '\n')
//		{
//			std::cin >> sign;
//			if (checkForWrongInput() == 1) return 1;
//		}
//
//		//If there was a '-' before a value then reverse it
//		if (isNextValueNegative)
//		{
//			value *= -1.f;
//			isNextValueNegative = false;
//		}
//
//
//		//Read sign after a number
//		float temp = 0;
//		switch (sign)
//		{
//		case '+':
//			if (checkForNextNumber() == 1) return 1;
//			//If plus we do not do anything
//
//			//Check for situations like: 10+
//			break;
//		case '-':
//			if (checkForNextNumber() == 1) return 1;
//
//			//If minus then the next number should be reversed
//			isNextValueNegative = true;
//
//			break;
//		case '*':
//			if (checkForNextNumber() == 1) return 1;
//
//			//If '*' multiply by the next value
//			std::cin >> temp;
//			if (checkForWrongInput() == 1) return 1;
//
//			value *= temp;
//
//			//Check for further '*' and '/' signs
//			if (checkForFutherMultiplicationOrDivisionSigns(value) == 1)
//			{
//				return 1;
//			}
//
//			break;
//		case '/':
//			if (checkForNextNumber() == 1) return 1;
//
//			std::cin >> temp;
//
//			if (checkForWrongInput() == 1) return 1;
//
//			//If error occurs - return
//			if (safeDivision(value, temp) == 1)
//			{
//				return 1;
//			}
//
//			if (checkForFutherMultiplicationOrDivisionSigns(value) == 1)
//			{
//				return 1;
//			}
//
//			break;
//		case '%':
//
//			if (checkForNextNumber() == 1) return 1;
//
//			//If '*' multiply by the next value
//			std::cin >> temp;
//			if (checkForWrongInput() == 1) return 1;
//
//			if (safeModulo(value, temp) == 1)
//			{
//				return 1;
//			}
//
//			if (checkForFutherMultiplicationOrDivisionSigns(value) == 1)
//			{
//				return 1;
//			}
//
//			break;
//		case '^':
//			if (checkForNextNumber() == 1) return 1;
//
//			//If '*' multiply by the next value
//			std::cin >> temp;
//			if (checkForWrongInput() == 1) return 1;
//
//			value = std::pow(value, temp);
//
//			if (checkForFutherMultiplicationOrDivisionSigns(value) == 1)
//			{
//				return 1;
//			}
//
//			break;
//		}
//
//
//		numbers.push_back(value);
//	}
//
//	//Sum up all the values in the vector
//	float value = 0;
//	for (auto& number : numbers)
//	{
//		value += number;
//	}
//
//	std::cout << "Result is: " << value << std::endl;
//
//	return 0;
//}
//
//int main()
//{
//	//Call calculator until the operation succeed
//	while (true)
//	{
//		if (calculator() == 0)
//		{
//			break;
//		}
//	}
//
//	return 0;
//}