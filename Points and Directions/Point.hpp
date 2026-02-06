#pragma once

#include <compare>

#include "Direction.hpp"

struct Point
{
	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	auto operator<=>(const Point& rhs) const = default;

	float x;
	float y;
};

template <typename Self>
auto&& Point::operator[](this Self&& self, size_t i)
{
	return i == 0 ? self.x : self.y;
}

inline Direction operator-(const Point& lhs, const Point& rhs)
{
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}

inline Point operator+(const Point& lhs, const Direction& rhs)
{
	return {lhs.x + rhs.x, lhs.y + rhs.y};
}

inline Point operator-(const Point& lhs, const Direction& rhs)
{
	return { lhs.x - rhs.x, lhs.y - rhs.y };
}
