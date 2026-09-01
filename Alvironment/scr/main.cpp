#include <iostream>

#include "alvironment/WindowProperties.h"
#include "alvironment/2d/Environment2D.h"
#include "alvironment/2d/object/Rectangle2D.h"
#include "alvironment/2d/object/Triangle2D.h"
#include "alvironment/2d/object/Circle2D.h"

#include "data_types/numbers.h"

#include "math/constants.h"
#include "math/Vector2D.h"


int main()
{
	WindowProperties properties(500, 500, "Test", false);
	Environment2D environment(&properties);

	Rectangle2D shape;
	environment.addObject(&shape);

	environment.initialize([]() {});
	
	std::cin.get();
	return 0;
}