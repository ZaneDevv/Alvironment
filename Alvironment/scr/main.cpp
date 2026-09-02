#include <iostream>

#include "alvironment/WorldSetUp.h"
#include "./world/World.h"


int main()
{
	World world;
	setUp(world);

	std::cin.get();
	return 0;
}