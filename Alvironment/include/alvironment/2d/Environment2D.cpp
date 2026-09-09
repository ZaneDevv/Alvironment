#include "Environment2D.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Environment2D::Environment2D(WindowProperties* properties) : Environment(properties)
{
	this->dimensions = 2;
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Environment2D::addObject(Object2D* object)
{
    Environment::addObject(object);
}

void Environment2D::removeObject(Object2D* object)
{
    Environment::removeObject(object);
}