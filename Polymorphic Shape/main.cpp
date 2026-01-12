#include <iostream>
#include <string>
#include <memory>

constexpr float PI = 3.141592653f;

class Shape
{
public:
	virtual std::string getName() const = 0;
	virtual float getArea() const = 0;
	virtual float getPerimeter() const = 0;
};

class Circle : public Shape
{
public:
	Circle(float radius) : radius(radius) {}

	std::string getName() const override
	{
		return "Circle";
	}

	float getArea() const override
	{
		return PI * radius * radius;
	}

	float getPerimeter() const override
	{
		return 2.f * PI * radius;
	}

private:
	float radius = 0.f;
};

class Square : public Shape
{
public:
	Square(float length) : length(length) {}

	std::string getName() const override
	{
		return "Square";
	}

	float getArea() const override
	{
		return length * length;
	}

	float getPerimeter() const override
	{
		return length * 4.f;
	}

private:
	float length = 0.f;
};

class Rectangle : public Shape
{
public:
	Rectangle(float length, float width) : length(length), width(width) {}

	std::string getName() const override
	{
		return "Rectangle";
	}

	float getArea() const override
	{
		return length * width;
	}

	float getPerimeter() const override
	{
		return (length + width) * 2.f;
	}

private:
	float length = 0.f;
	float width = 0.f;
};

class Triangle : public Shape
{
public:
	Triangle(float base, float height) : base(base), height(height) {}

	std::string getName() const override
	{
		return "Triangle";
	}

	float getArea() const override
	{
		return base * height * 0.5f;
	}

	float getPerimeter() const override
	{
		float h = sqrt(base * base + height * height);
		return base + height + h;
	}

private:
	float base = 0.f;
	float height = 0.f;
};

float readFloat(const std::string& text)
{
	float value;
	std::cout << text;
	std::cin >> value;

	if (std::cin.fail())
	{
		std::cout << "ERROR::Wrong data type" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << text;
		std::cin >> value;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return value;
}

int main()
{
	std::unique_ptr<Shape> shapes[4];

	{
		float radius = readFloat("Enter the radis of a circle: ");
		std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
		shapes[0] = std::move(circle);
	}

	{
		float length = readFloat("Enter the length of one side of a square: ");
		std::unique_ptr<Square> square = std::make_unique<Square>(length);
		shapes[1] = std::move(square);
	}

	{
		float length = readFloat("Enter the length of one side of a rectangle: ");
		float width = readFloat("Enter the width of one side of a rectangle: ");
		std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>(length, width);
		shapes[2] = std::move(rectangle);
	}

	{
		float base = readFloat("Enter the base of a triangle: ");
		float height = readFloat("Enter the height of a triangle: ");
		std::unique_ptr<Triangle> triangle = std::make_unique<Triangle>(base, height);
		shapes[3] = std::move(triangle);
	}

	for (int i = 0; i < 4; i++)
	{
		auto& shape = shapes[i];
		std::cout << shape->getName() << std::endl;
		std::cout << shape->getArea() << std::endl;
		std::cout << shape->getPerimeter() << std::endl;
		std::cout << "----------" << std::endl;
	}


	return 0;
}