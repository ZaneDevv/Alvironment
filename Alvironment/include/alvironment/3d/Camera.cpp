#include "Camera.h"

#include "debug_helper/print.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Camera::Camera()
{
	SUCCESS_PRINT("Camera created successfully");
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

Vector3D Camera::getPosition() const
{
	return this->position;
}

void Camera::setPosition(const Vector3D& position)
{
	this->position = position;
}

double Camera::getFov() const
{
	return this->fov;
}

void Camera::setFov(double fov)
{
	this->fov = fov;
}