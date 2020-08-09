#ifndef _ANIMAL_MANAGER_HPP_
#define _ANIMAL_MANAGER_HPP_

#include <string>
#include <iostream>
#include <cstdint>
#include <vector>

namespace Creature
{
	class Animal;

	class Animal_Manager
	{
	private:
		std::vector<Animal*> Animal_Vector;
	public:
		Animal_Manager();
		Animal_Manager(const Animal_Manager & Object);

		void Add_Animal(Animal & Object);
		void Show_Animal() const;

		Animal_Manager& operator=(const Animal_Manager& rhs);

		virtual ~Animal_Manager();
	};

}

#endif /* _ANIMAL_MANAGER_HPP_ */