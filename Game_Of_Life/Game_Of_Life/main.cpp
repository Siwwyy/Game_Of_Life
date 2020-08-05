#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cstdint>


#include "Logic.hpp"

int main(int argc, char* argv[])
{
	using Engine::Logic;

	Logic Obj(30, 10);
	Obj.Run_Game();

	system("pause");
	return EXIT_SUCCESS;
}