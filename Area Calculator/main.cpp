#include <iostream>

const float PI = 3.141592653f;

template<typename T>
T read()
{
	T c;
	std::cin >> c;

	while (std::cin.fail())
	{
		std::cerr << "ERROR::Wrong input." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> c;
	}

	return c;
}

bool isShape(char s)
{
	return (s >= '1' && s <= '4') || s == 'C' || s == 'S' || s == 'R' || s == 'T';
}

int main()
{
	std::cout << "Choose a shape: Circle(C), Square(S), Rectangle(R), Triangle(T)" << std::endl;

	char shape;
	shape = read<char>();
	while (!isShape(shape))
	{
		std::cerr << "ERROR:: Wrong input." << std::endl;
		shape = read<char>();
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (shape)
	{
	case '1':
	case 'C':
	{
		std::cout << "What is the radius of your circle?" << std::endl;
		float r;
		r = read<float>();
		float circumference = 2.f * PI * r;
		float area = PI * r * r;
		std::cout << "Circumference is: " << circumference << std::endl;
		std::cout << "Area is: " << area << std::endl;
		break;
	}
	case '2':
	case 'S':
	{
		std::cout << "What is the length of the side in your square?" << std::endl;
		float l;
		l = read<float>();
		float perimeter = l * 4.f;
		float area = l * l;
		std::cout << "Perimeter is: " << perimeter << std::endl;
		std::cout << "Area is: " << area << std::endl;
		break;
	}
		break;
	case '3':
	case 'R':
	{
		std::cout << "What is the height of your rectangle?" << std::endl;
		float h;
		h = read<float>();

		std::cout << "What is the width of your rectangle?" << std::endl;
		float w;
		w = read<float>();

		float perimeter = (w + h) * 2.f;
		float area = w * h;
		std::cout << "Perimeter is: " << perimeter << std::endl;
		std::cout << "Area is: " << area << std::endl;
		break;
	}
		break;
	case '4':
	case 'T':
	{
		std::cout << "What is the length of a base in your triangle?" << std::endl;
		float b;
		b = read<float>();

		std::cout << "What is the length of the height in your triangle?" << std::endl;
		float h;
		h = read<float>();

		float perimeter = (b + h + sqrt(b * b + h * h));
		float area = b * h * 0.5f;
		std::cout << "Perimeter of a right triangle is: " << perimeter << std::endl;
		std::cout << "Area is: " << area << std::endl;
		break;
	}
	}

	return 0;
}