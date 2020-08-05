#include "Sheep.hpp"

Creature::Sheep::Sheep() :
	Animal()
{

}

Creature::Sheep::Sheep(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator) : Animal(name, pos_x, pos_y, breed, is_predator)
{

}

Creature::Sheep::Sheep(const Sheep& Object) :
	Animal(Object)
{

}

void Creature::Sheep::Move_Forwards()
{
	this->m_pos_x++;
}

void Creature::Sheep::Move_Backwards()
{
	this->m_pos_x--;
}

void Creature::Sheep::Move_Upwards()
{
	this->m_pos_y++;
}

void Creature::Sheep::Move_Downwards()
{
	this->m_pos_y--;
}

Creature::Sheep& Creature::Sheep::operator=(const Sheep& rhs)
{
	if (this != std::addressof(rhs))
	{
		Creature::Creature::operator=(rhs);
		Animal::operator=(dynamic_cast<const Animal&>(rhs));
		//add sheep statements
	}
	return *this;
}

Creature::Sheep::~Sheep()
{

}