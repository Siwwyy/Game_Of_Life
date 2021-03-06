#include "Creature.hpp"

void Creature::Creature::Set_Name(const std::string& name)
{
	this->m_name = name;
}

void Creature::Creature::Set_Pos_X(int32_t pos_x)
{
	this->m_pos_x = pos_x;
}

void Creature::Creature::Set_Pos_Y(int32_t pos_y)
{
	this->m_pos_y = pos_y;
}

const std::string& Creature::Creature::Get_Name() const
{
	return this->m_name;
}

int32_t Creature::Creature::Get_Pos_X() const
{
	return this->m_pos_x;
}

int32_t Creature::Creature::Get_Pos_Y() const
{
	return this->m_pos_y;
}

Creature::Creature::Creature() :
	m_name("empty"),
	m_pos_x(0),
	m_pos_y(0)
{

}

Creature::Creature::Creature(const std::string& name) :
	m_name(name),
	m_pos_x(0),
	m_pos_y(0)
{

}

Creature::Creature::Creature(const std::string& name, int32_t pos_x, int32_t pos_y) :
	m_name(name),
	m_pos_x(pos_x),
	m_pos_y(pos_y)
{

}

Creature::Creature::Creature(const Creature& Object) :
	m_name(Object.m_name),
	m_pos_x(Object.m_pos_x),
	m_pos_y(Object.m_pos_y)
{

}

void Creature::Creature::Print() const
{
	std::cout << "=============\n";
	std::cout << this->m_name << '\n';
	std::cout << "=============\n";
	std::cout << this->m_pos_x << '\n';
	std::cout << this->m_pos_y << '\n';
}

Creature::Creature& Creature::Creature::operator=(const Creature& rhs)
{
	if (this != std::addressof(rhs))
	{
		this->m_name = rhs.m_name;
		this->m_pos_x = rhs.m_pos_x;
		this->m_pos_y = rhs.m_pos_y;
	}
	return *this;
}