#include <Entity.hpp>

#include <iostream>

Entity::Entity(int hitPoints)
	: hitPoints(hitPoints)
{
	std::cout << "Entity::Entity(" << this->hitPoints << ")" << std::endl;
}

Entity::~Entity()
{
	std::cout << "Entity::~Entity()" << hitPoints << std::endl;
}

Entity::Entity(const Entity& other)
{
	this->hitPoints = other.hitPoints;

	std::cout << "Entity::Entity(const Entity& other)" << std::endl;
}

void Entity::draw() const
{
	std::cout << "Entity::draw()" << std::endl;
}