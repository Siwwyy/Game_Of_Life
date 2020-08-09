#include "Animal_Manager.hpp"
#include "Animal.hpp"

Creature::Animal_Manager::Animal_Manager() :
	Animal_Vector()
{

}

Creature::Animal_Manager::Animal_Manager(const Animal_Manager& Object) :
	Animal_Vector(Object.Animal_Vector)
{

}

void Creature::Animal_Manager::Add_Animal(Animal& Object)
{
	Animal_Vector.emplace_back(&Object);
}

void Creature::Animal_Manager::Add_Animal(Animal* const Object)
{
	Animal_Vector.emplace_back(Object);
}

void Creature::Animal_Manager::Remove_Animal(Animal* const Object)
{
	if (this->Animal_Vector.size() > 0)
	{
		std::vector<Animal*>::iterator it_vec = std::find(this->Animal_Vector.begin(), this->Animal_Vector.end(), Object);

		if (it_vec != this->Animal_Vector.end())
		{
			this->Animal_Vector.erase(it_vec);
		}
	}
}

void Creature::Animal_Manager::Remove_Animal(Animal& Object)
{
	if (this->Animal_Vector.size() > 0)
	{
		std::vector<Animal*>::iterator it_vec = std::find(this->Animal_Vector.begin(), this->Animal_Vector.end(), &Object);

		if (it_vec != this->Animal_Vector.end())
		{
			this->Animal_Vector.erase(it_vec);
		}
	}
}

void Creature::Animal_Manager::Show_Animal() const
{
	for (Animal* const My_Animal : this->Animal_Vector)
	{
		My_Animal->Print();
	}
}

void Creature::Animal_Manager::Run_Simulation()
{
	Animal* Temporary{};
	Animal* Temporary_2{};
	for (std::size_t i = 0; i < 10; ++i)
	{
		if (i == 3)
		{
			Temporary = new Animal("Ted", 0, 0, false);
			Temporary_2 = Temporary;
		}
		else
		{
			Temporary = new Animal("Ted", 0, 0, true);
		}
		Add_Animal(Temporary);	//two overloaded functions, for passing by reference or at this case by pointer
		Temporary = nullptr;
	}

	Show_Animal();
	Remove_Animal(Temporary_2);
	std::cout << '\n';
	std::cout << '\n';
	Show_Animal();
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
	for (auto animal_ptr : this->Animal_Vector)
	{
		delete animal_ptr;
	}
	this->Animal_Vector.clear();
}