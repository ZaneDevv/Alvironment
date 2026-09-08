#include "Camera.h"

#include "debug_helper/print.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Camera::Camera()
{
	this->projectionScale = 1 / tan(this->fov / 2.0f);
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

Quaternion Camera::getRotation() const
{
	return this->rotation;
}

void Camera::setRotation(const Quaternion& rotation)
{
	this->rotation = rotation;
}

double Camera::getFov() const
{
	return this->fov;
}

double Camera::getProjectionScale() const
{
	return this->projectionScale;
}

void Camera::setFov(double fov)
{
	this->fov = fov;
	this->projectionScale = 1 / tan(this->fov / 2.0f);
}

double Camera::getNear() const
{
	return this->near;
}

void Camera::setNear(double near)
{
	this->near = near;
}

double Camera::getFar() const
{
	return this->far;
}

void Camera::setFar(double far)
{
	this->far = far;
}