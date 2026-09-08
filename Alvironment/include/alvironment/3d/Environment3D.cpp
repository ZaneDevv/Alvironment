#include "Environment3D.h"

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Environment3D::addObject(Object3D* object)
{
    object->setCamera(&this->camera);
    Environment::addObject(object);
}

void Environment3D::removeObject(Object3D* object)
{
    Environment::removeObject(object);
}