#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>

struct Value
{
	float number = 0.f;
	char sign = ' ';


	bool isSign = false; //false - number; true - sign
};

constexpr bool isOperator(char c) noexcept
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

constexpr bool isNumber(char c) noexcept
{
	return c >= '0' && c <= '9';
}

constexpr bool isLetter(char c) noexcept
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//The Shunting Yard Algorithm https://mathcenter.oxford.emory.edu/site/cs171/shuntingYardAlgorithm/
int main()
{
	std::map<char, int> precedence
	{
		{'-', 1 },
		{'+', 1 },
		{'/', 2 },
		{'*', 2 },
		{'%', 2 },
		{'^', 4},
		{'&', 3} //Negation operator
	};

	std::string expression;

	std::cout << "Enter your expression: " << std::endl;

	std::getline(std::cin, expression);

	//Check each operand and operator individually

	std::vector<Value> end_vector;
	std::stack<char> sign_stack;

	Value last_value;

	for (int i = 0; i < expression.length(); i++)
	{
		float number = 0.f;
		char sign = ' ';

		//If letter - return error
		if (isLetter(expression[i]))
		{
			std::cout << "ERROR: wrong syntax\n";
			return 1;
		}

		//If the incoming symbols is an operand, print it..
		if (isNumber(expression[i]))
		{
			std::string num = "";
			bool floatingPoint = false;

			int nextSymbol = i;
			do
			{
				// '.' is encountered more that 1 time - display error
				if (floatingPoint && expression[nextSymbol] == '.')
				{
					std::cout << "ERROR: wrong syntax\n";
					return 1;
				}
				if (expression[nextSymbol] == '.')
				{
					floatingPoint = true;
				}

				num += expression[nextSymbol];
				nextSymbol++;
			} while (nextSymbol < expression.length() && (isNumber(expression[nextSymbol]) || expression[nextSymbol] == '.'));

			number = std::stof(num);

			Value v;
			v.number = number;
			end_vector.push_back(v);

			i = nextSymbol - 1;
			continue;
		}
		//Check for unary -
		else if (expression[i] == '-' && (i == 0 || isOperator(expression[i - 1]) || expression[i - 1] == '('))
		{
			sign_stack.push('&');
		}
		//Skip unecessary + operators
		else if (expression[i] == '+' && (i == 0 || isOperator(expression[i - 1]) || expression[i - 1] == '('))
		{
			continue;
		}
		else
		{ 
			//Value is not a number
			
			sign = expression[i];
			Value v;
			v.sign = sign;
			v.isSign = true;
			//last_value = v;

			//If the incoming symbol is a left parenthesis, push it on the stack.
			if (sign == '(')
			{
				sign_stack.push(sign);
			}
			//If the incoming symbol is a right parenthesis: discard the right parenthesis,
			// pop and print the stack symbols until you see a left parenthesis. 
			// Pop the left parenthesis and discard it.
			else if (sign == ')')
			{
				//Check if left paranthese is on the stack
				while (!sign_stack.empty() && sign_stack.top() != '(')
				{
					char symbol = sign_stack.top();
					sign_stack.pop();

					Value v;
					v.sign = symbol;
					v.isSign = true;
					end_vector.push_back(v);
				}

				//Pop the left paranthese
				if (!sign_stack.empty() && sign_stack.top() == '(') sign_stack.pop();
			}
			//If an operator
			else if (isOperator(sign))
			{
				//If the incoming symbol is an operator and the stack is empty or contains a left parenthesis on top,
				// push the incoming operator onto the stack.
				if (sign_stack.empty() || sign_stack.top() == '(')
				{
					sign_stack.push(sign);
				}
				//If the incoming symbol is an operator and has either higher precedence than the operator on the top of the stack,
				// or has the same precedence as the operator on the top of the stack and is right associative,
				// or if the stack is empty, or if the top of the stack is "(" (a floor) -- push it on the stack.
				else if (precedence[sign] > precedence[sign_stack.top()])
				{
					sign_stack.push(sign);
				}
				//If the incoming symbol is an operator and has either lower precedence than the operator on the top of the stack,
				// or has the same precedence as the operator on the top of the stack and is left associative-- continue to pop the stack until this is not true.Then,
				// push the incoming operator.
				else if (precedence[sign] <= precedence[sign_stack.top()])
				{
					while (!sign_stack.empty() && precedence[sign] <= precedence[sign_stack.top()])
					{
						char symbol = sign_stack.top();
						sign_stack.pop();

						Value v;
						v.sign = symbol;
						v.isSign = true;
						end_vector.push_back(v);

					
					}

					sign_stack.push(sign);
				}
			}
			//If not any of the given operators return error
			else
			{
				std::cout << "ERROR: wrong syntax\n";
				return 1;
			}
		}
	}
	//Add all operators that are left to the end_vector
	while (!sign_stack.empty())
	{
		if (sign_stack.top() == '(') { sign_stack.pop(); continue; }

		char sign = sign_stack.top();
		sign_stack.pop();

		Value v;
		v.sign = sign;
		v.isSign = true;
		end_vector.push_back(v);
	}

	std::stack<Value> result_stack;
	for (auto it = end_vector.begin(); it != end_vector.end(); ++it)
	{
		Value v = *it;

		if (v.isSign && v.sign != '&')
		{
			float v1 = result_stack.top().number;
			result_stack.pop();
			float v2 = result_stack.top().number;
			result_stack.pop();

			float result = 0.f;
		
			switch (v.sign)
			{
			case '+':
				result = v2 + v1;
				break;
			case '-':
				result = v2 - v1;
				break;
			case '*':
				result = v2 * v1;
				break;
			case '/':
				if (v1 == 0)
				{
					std::cout << "ERROR: division by 0 is not possible\n";
					return 1;
				}
				result = v2 / v1;
				break;
			case '%':
				if (v1 == 0)
				{
					std::cout << "ERROR: modulo of 0 is not possible\n";
					return 1;
				}
				result = std::fmodf(v2, v1);
				break;
			case '^':
				result = std::pow(v2, v1);
				break;
			}

			Value res;
			res.number = result;
			result_stack.push(res);

			
		}
		else if (v.sign == '&')
		{
			float v1 = result_stack.top().number;
			result_stack.pop();

			Value result;
			result.number =  v1 * -1.f;
			result_stack.push(result);
		}
		else
		{
			result_stack.push(v);
		}
		
	}

	std::cout << "RPN: ";
	for (const auto& n : end_vector)
	{
		if (!n.isSign)
		{
			std::cout << n.number;
		}
		else
		{
			std::cout << n.sign;
		}
		std::cout << " ";
	}

	std::cout << std::endl << "Result is: " << result_stack.top().number << std::endl;

	//Might look a bit messy but I tried to fix most of the bugs with unary - and +

	return 0;
}