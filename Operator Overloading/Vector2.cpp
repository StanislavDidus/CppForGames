#include <cassert>
#include <Vector2.hpp>

Vector2::Vector2(const float x)
	: x{ x }
	, y{ x }
{

}

Vector2::Vector2(const float x, const float y)
	: x{ x }
	, y{ y }
{

}

/*Vector2 operator+(const Vector2& lhs, const Vector2 rhs)
{
	return { lhs.x + rhs.x, lhs.y + rhs.y };
}*/

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

Vector2 Vector2::operator-() const
{
	return { -x, -y };
}

Vector2 Vector2::operator+() const
{
	return { x, y };
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
	if (this == &rhs) return *this;

	x = rhs.x;
	y = rhs.y;

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vector2& Vector2::operator++()
{
	x += 1.0f;
	y += 1.0f;
	return *this;
}

Vector2 Vector2::operator++(int)
{
	Vector2 temp = *this;
	
	++(*this);

	return temp;

}

Vector2& Vector2::operator--()
{
	x -= 1.0f;
	y -= 1.0f;

	return *this;
}

Vector2 Vector2::operator--(int)
{
	Vector2 temp = *this;

	--(*this);

	return temp;
}

Vector2 Vector2::operator*(float rhs) const
{
	return { x * rhs, y * rhs };
}

/*bool Vector2::operator<(const Vector2& rhs) const
{ 
	return x < rhs.x || x == rhs.x && y < rhs.y;
}

bool Vector2::operator>(const Vector2& rhs) const
{
	return rhs < *this;
}

bool Vector2::operator<=(const Vector2& rhs) const
{
	return !(*this > rhs);
}

bool Vector2::operator>=(const Vector2& rhs) const
{
	return !(*this < rhs);
}*/

bool Vector2::operator==(const Vector2& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

bool Vector2::operator!=(const Vector2& rhs) const
{
	return !(*this == rhs);
}

/*float& Vector2::operator[](size_t i)
{
	assert(i < 2);
	return i == 0 ? x : y;
}

float Vector2::operator[](size_t i) const
{
	assert(i < 2);
	return i == 0 ? x : y;
}*/


Vector2 operator*(float lhs, const Vector2& rhs)
{
	return { lhs * rhs.x, lhs * rhs.y };
}
