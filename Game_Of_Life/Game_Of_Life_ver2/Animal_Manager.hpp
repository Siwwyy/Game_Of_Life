#ifndef _ANIMAL_MANAGER_HPP_
#define _ANIMAL_MANAGER_HPP_

#include <vector>

namespace Creature
{
	class Animal;	//forward declaration for preventing to include whole file

	class Animal_Manager
	{
	private:
		std::vector<Animal*> Animal_Vector;
	public:
		Animal_Manager();
		Animal_Manager(const Animal_Manager & Object);

		void Add_Animal(Animal & Object);
		void Add_Animal(Animal * const Object);
		void Remove_Animal(Animal * const Object);
		void Remove_Animal(Animal & Object);
		void Show_Animal() const;
		void Run_Simulation();

		Animal_Manager& operator=(const Animal_Manager& rhs);

		virtual ~Animal_Manager();
	};

}

#endif /* _ANIMAL_MANAGER_HPP_ */