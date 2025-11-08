#include <iostream>

int main()
{
	double d = 42.99;
	float f = static_cast<float>(d);
	int i = static_cast<int>(f);
	char c = static_cast<char>(i);
	bool b = static_cast<bool>(c);

	std::cout << "Double: " << d << "\n"
		      << "Float: "  << f << "\n"
		      << "Int:"     << i << "\n"
		      << "Char: "   << c << "\n"
		      << "Bool: "   << b << "\n";

	std::cout << static_cast<int>('!') << "\n";
	auto v = '!' + 15;

	char five_char = '9';
	int five_int = static_cast<int>(five_char) - 48;

	std::cout << five_int << "\n";

	return 0;	
}