#include "World.h"

#include "alvironment/window/WindowProperties.h"

#include "math/constants.h"
#include "math/Vector2D.h"

#include "debug_helper/print.h"

void World::initialize()
{
	WindowProperties properties(500, 500, "Test", false);
	this->environment.emplace(&properties);

	this->shape = std::make_unique<Triangle2D>();
	this->shape.get()->rotate(ONE_DEGREE_IN_RADIANS * 16);

	this->environment.value().addObject(this->shape.get());
}

void World::update(double deltaTime)
{
	this->shape.get()->rotate(ONE_DEGREE_IN_RADIANS * deltaTime * 100);
}