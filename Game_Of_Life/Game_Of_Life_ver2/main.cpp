#include <windows.h>


#include "Animal_Manager.hpp"

int main(int argc, char* argv[])
{
	using Creature::Animal_Manager;

	Animal_Manager Obj;
	Obj.Run_Simulation();

	system("pause");
	return EXIT_SUCCESS;
}