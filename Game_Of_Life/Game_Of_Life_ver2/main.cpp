#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cstdint>


#include "Animal_Manager.hpp"
#include "Animal.hpp"

int main(int argc, char* argv[])
{
	using Creature::Animal_Manager;
	using Creature::Animal;

	Animal_Manager Obj;
	Animal* Temp{};
	Animal* Temp2{};

	//for (std::size_t i = 0; i < 10; ++i)
	//{
	//	if (i == 3)
	//	{
	//		Temp = new Animal("Ted", 0, 0, false);
	//		Temp2 = Temp;
	//	}
	//	else
	//	{
	//		Temp = new Animal("Ted", 0, 0, true);
	//	}
	//	Obj.Add_Animal(*Temp);
	//	Temp = nullptr;
	//}

	//Obj.Show_Animal();
	//Obj.Remove_Animal(*Temp2);
	//std::cout << '\n';
	//std::cout << '\n';
	//std::cout << '\n';
	//Obj.Show_Animal();

	for (std::size_t i = 0; i < 10; ++i)
	{
		if (i == 3)
		{
			Temp = new Animal("Ted", 0, 0, false);
			Temp2 = Temp;
		}
		else
		{
			Temp = new Animal("Ted", 0, 0, true);
		}
		Obj.Add_Animal(Temp);
		Temp = nullptr;
	}

	Obj.Show_Animal();
	Obj.Remove_Animal(Temp2);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	Obj.Show_Animal();

	system("pause");
	return EXIT_SUCCESS;
}