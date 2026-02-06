#include "Int.hpp"

Int::Int(int i) : i{i}
{

}

Int& Int::operator=(int i)
{
	this->i = i;

	return *this;
}

Int::operator int() const
{
	return i;
}
