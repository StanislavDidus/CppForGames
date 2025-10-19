#include "Config.hpp"
#include "game.hpp"

#include <iostream>

int main()
{
	std::cout << "JumpHeight: " << JumpHeight << "\n";
	std::cout << "JumpDuration: " << JumpDuration << "\n";

	Update();

	return 0;
}