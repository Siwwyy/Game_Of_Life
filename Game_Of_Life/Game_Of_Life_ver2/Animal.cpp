#include "Animal.hpp"

Creature::Animal::Animal() :
	Creature::Creature(),
	m_is_predator(true)
{

}

Creature::Animal::Animal(const std::string& name, const int32_t pos_x, const int32_t pos_y, const bool is_predator) :
	Creature::Creature(name, pos_x, pos_y),
	m_is_predator(is_predator)
{

}

Creature::Animal::Animal(const Animal& Object) :
	Creature::Creature(Object),
	m_is_predator(Object.m_is_predator)
{

}

void Creature::Animal::Set_Is_Predator(const bool is_predator)
{
	this->m_is_predator = is_predator;
}

void Creature::Animal::Move_Forwards()
{
	this->m_pos_x++;
}

void Creature::Animal::Move_Backwards()
{
	this->m_pos_x--;
}

void Creature::Animal::Move_Upwards()
{
	this->m_pos_y++;
}

void Creature::Animal::Move_Downwards()
{
	this->m_pos_y--;
}

void Creature::Animal::Print() const
{
	Creature::Print();
	std::cout << "Predator: " << std::boolalpha << this->m_is_predator << '\n';
}

Creature::Animal& Creature::Animal::operator=(const Animal& rhs)
{
	if (this != std::addressof(rhs))
	{
		Creature::Creature::operator=(rhs);
		this->m_is_predator = rhs.m_is_predator;
	}
	return *this;
}

bool Creature::Animal::operator==(const Animal& rhs)
{
	if (this->m_is_predator == rhs.m_is_predator)
	{
		return true;
	}
	return false;
}

const bool Creature::Animal::Get_Is_Predator() const
{
	return this->m_is_predator;
}