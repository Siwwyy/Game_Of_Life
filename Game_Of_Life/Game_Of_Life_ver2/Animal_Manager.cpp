#include "Animal_Manager.hpp"
#include "Animal.hpp"

Creature::Animal_Manager::Animal_Manager():
	Animal_Vector()
{

}

Creature::Animal_Manager::Animal_Manager(const Animal_Manager& Object):
	Animal_Vector(Object.Animal_Vector)
{

}

void Creature::Animal_Manager::Add_Animal(Animal& Object)
{
	Animal_Vector.emplace_back(&Object);
}

void Creature::Animal_Manager::Remove_Animal(Animal& Object)
{
	std::vector<Animal*>::iterator it_vec = std::find(this->Animal_Vector.begin(), this->Animal_Vector.end(), &Object);

	if (it_vec != this->Animal_Vector.end())
	{
		this->Animal_Vector.erase(it_vec);
	}
}

void Creature::Animal_Manager::Show_Animal() const
{
	for (Animal* const My_Animal: this->Animal_Vector)
	{
		My_Animal->Print();
	}
}

Creature::Animal_Manager& Creature::Animal_Manager::operator=(const Animal_Manager& rhs)
{
	if (this != std::addressof(rhs))
	{
		this->Animal_Vector = rhs.Animal_Vector;
	}
	return *this;
}

Creature::Animal_Manager::~Animal_Manager()
{
	this->Animal_Vector.clear();
}