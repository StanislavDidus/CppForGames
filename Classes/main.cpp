#include <Player.hpp>
#include <iostream>

void printHitPoints(const Entity& entity)
{
	std::cout << "hitPoints: " << entity.getHitPoints() << std::endl;
}

int main()
{
	Player player{ 100 };
	player.draw(); // Draw the player on the screen

	Entity* e = &player;
	e->update(0.1f);
	e->draw();

	return 0;
}