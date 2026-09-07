#include "SpinningCube.h"

// Runs when the world sets up

void SpinningCube::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(500, 500, "Spinning cube", true);
	this->environment.emplace(&properties);
}

// Runs every frame after setting up the world

void SpinningCube::update(double deltaTime)
{

}