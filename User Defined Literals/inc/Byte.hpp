#pragma once
#include <cstdint>
#include <compare>

class Byte
{
public:
	explicit Byte(uint64_t bytes = 0ull) : bytes{bytes} {}

	auto operator<=>(const Byte& rhs) const = default;

	//Getters
	// Bits
	uint64_t b() const
	{
		return bytes * 8;
	}

	// Bytes
	uint64_t B() const
	{
		return bytes;
	}

	// Kilobits
	long double Kb() const
	{
		return bytes * 0.008;
	}

	// Kilobytes
	long double KB() const
	{
		return bytes * 0.001;
	}

	// Megabits
	long double Mb() const
	{
		return bytes * 8.0 * std::pow(10,-6);
	}

	//Megabytes
	long double MB() const
	{
		return bytes * std::pow(10, -6);
	}


private:
	uint64_t bytes = 0ull;
};

inline Byte operator""_b(uint64_t b)
{
	return Byte{ static_cast<uint64_t>(std::ceil(b / 8.0)) };
}

inline Byte operator""_B(uint64_t B)
{
	return Byte{ B };
}

inline Byte operator""_Kb(uint64_t Kb)
{
	return Byte{ static_cast<uint64_t>(Kb / 0.008) };
}

inline Byte operator""_KB(uint64_t KB)
{
	return Byte{ static_cast<uint64_t>(KB / 0.001) };
}

inline Byte operator""_Mb(uint64_t Mb)
{
	long double divisor = 8.0 * std::pow(10, -6);
	return Byte{ static_cast<uint64_t>(Mb / divisor) };
}

inline Byte operator""_MB(uint64_t MB)
{
	long double divisor = std::pow(10, -6);
	return Byte{ static_cast<uint64_t>(MB / divisor) };
}