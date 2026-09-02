#include <iostream>

#include "alvironment/WorldSetUp.h"
#include "./world/World.h"

int main()
{
	World myWorld;
	setUp(myWorld);

	std::cin.get();
	return 0;
}