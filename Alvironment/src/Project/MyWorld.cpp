#include "MyWorld.h"

// This method is fired automatically once the world is set up

void MyWorld::initialize()
{
	// Creates properties for the window in the order: width, height, title, scalable
	WindowProperties properties(500, 500, "My World", true);

	// Creates the environment with the window properties. With this, once the methid initialize is fired, a window will be created automatically
	this->environment.emplace(&properties);

	// Write here the rest of the code, create the scenario. Bear in mind that every object created should be then stored in environment with the
	// environment's method addObject
}

// This method is fired once per frame and gives you the time it took to change the last frame for the new one

void MyWorld::update(double deltaTime)
{
	// Write here the code to run every frame
}