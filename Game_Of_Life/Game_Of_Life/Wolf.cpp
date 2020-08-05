#include "Wolf.hpp"

Creature::Wolf::Wolf() :
	Animal()
{

}

Creature::Wolf::Wolf(const std::string& name, const int32_t pos_x, const int32_t pos_y, const std::string& breed, const bool is_predator) : Animal(name, pos_x, pos_y, breed, is_predator)
{

}

Creature::Wolf::Wolf(const Wolf& Object):
	Animal(Object)
{

}

void Creature::Wolf::Move_Forwards()
{
	this->m_pos_x++;
}

void Creature::Wolf::Move_Backwards()
{
	this->m_pos_x--;
}

void Creature::Wolf::Move_Upwards()
{
	this->m_pos_y++;
}

void Creature::Wolf::Move_Downwards()
{
	this->m_pos_y--;
}

Creature::Wolf& Creature::Wolf::operator=(const Wolf& rhs)
{
	if (this != std::addressof(rhs))
	{
		Creature::Creature::operator=(rhs);
		Animal::operator=(dynamic_cast<const Animal&>(rhs));
		//add wolf statements
	}
	return *this;
}

Creature::Wolf::~Wolf()
{

}