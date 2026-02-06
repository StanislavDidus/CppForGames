#pragma once

#include <compare>

struct Direction
{
	Direction operator+(const Direction& rhs) const;
	Direction operator-(const Direction& rhs) const;

	Direction operator*(float rhs) const;

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	auto operator<=>(const Direction& rhs) const = default;

	float x;
	float y;
};

template <typename Self>
auto&& Direction::operator[](this Self&& self, size_t i)
{
	return i == 0 ? self.x : self.y;
}


inline Direction operator*(float lhs, const Direction& rhs);

inline Direction Direction::operator+(const Direction& rhs) const
{
	return { x + rhs.x, y + rhs.y };	
}

inline Direction Direction::operator-(const Direction& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

inline Direction Direction::operator*(float rhs) const
{
	return { x * rhs, y * rhs };
}

inline Direction operator*(float lhs, const Direction& rhs)
{
	return rhs * lhs;
}
