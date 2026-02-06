#pragma once

class Int
{
public:
	explicit Int(int i);
	~Int() = default;

	Int& operator=(int i);

	//Conversion operator.
	explicit operator int() const;
private:
	int i = 0;
};