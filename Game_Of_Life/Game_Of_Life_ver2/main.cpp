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
	Obj.Run_Simulation();

	system("pause");
	return EXIT_SUCCESS;
}