#include "Environment3D.h"

#include <iostream>

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

const float Environment3D::CAMERA_SPEED = 50.0f;
const float Environment3D::CAMERA_ANGULAR_SPEED = 0.6f;

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Environment3D::runInternalUpdateCallback(double deltaTime)
{
    this->moveCamera(deltaTime);
}

void Environment3D::moveCamera(double deltaTime)
{
    bool hasCameraMoved = false;

    if (this->isKeyPressed(Key::MOUSE_RIGHT_BUTTON))
    {
        double newX = 0;
        double newY = 0;
        this->getMousePosition(newX, newY);

        if (!this->wasStartingMouseLocationSet)
        {
            this->lastMouseX = newX;
            this->lastMouseY = newY;

            this->wasStartingMouseLocationSet = true;
        }

        double differenceX = newX - this->lastMouseX;
        double differenceY = newY - this->lastMouseY;

        if (differenceX != 0 || differenceY != 0)
        {
            Vector3D axis = Vector3D::normalize(Vector3D(-differenceY, differenceX, 0));
            double theta = abs(deltaTime * (differenceX + differenceY) * Environment3D::CAMERA_ANGULAR_SPEED);

            this->camera.setRotation(this->camera.getRotation() * Quaternion(theta, axis));

            this->lastMouseX = newX;
            this->lastMouseY = newY;

            hasCameraMoved = true;
        }
    }
    else
    {
        this->wasStartingMouseLocationSet = false;
    }

    Vector3D direction(
        this->isKeyPressed(Key::D) ? 1 : this->isKeyPressed(Key::A) ? -1 : 0,
        this->isKeyPressed(Key::E) ? 1 : this->isKeyPressed(Key::Q) ? -1 : 0,
        this->isKeyPressed(Key::W) ? 1 : this->isKeyPressed(Key::S) ? -1 : 0
    );

    if (direction != Vector3D::zero)
    {
        direction = (this->camera.getRotation() * Quaternion::createByWAndAxis(0, direction) * Quaternion::inverse(this->camera.getRotation())).getAxis();

        this->camera.setPosition(this->camera.getPosition() + Vector3D::normalize(direction) * (deltaTime * Environment3D::CAMERA_SPEED));
        hasCameraMoved = true;
    }

    if (hasCameraMoved)
    {
        for (GenericObject* object : this->objectsInEnvironment)
        {
            object->updateVertices();
        }
    }
}

void Environment3D::addObject(Object3D* object)
{
    object->setCamera(&this->camera);
    Environment::addObject(object);
}

void Environment3D::removeObject(Object3D* object)
{
    Environment::removeObject(object);
}

void Environment3D::enableFreeCamera(bool enable)
{
    this->freeCamera = enable;
}