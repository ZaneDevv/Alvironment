#include "SolarSystem.h"

#include <cmath>
#include "math/constants.h"

// Runs when the world sets up

void SolarSystem::initialize()
{
	// Creates properties for the window in the order: width, height, title, scalable
	WindowProperties properties(650, 650, "Solar system", true);

	// Creates the environment with the window properties. With this, once the methid initialize is fired, a window will be created automatically
	this->environment.emplace(&properties);

	// Creating objects

	this->sun = std::make_unique<Sphere3D>();
	this->sun->setShaderProperty("color4", Color4(0xFFF475FF));
	this->sun->setScale(Vector3D::one * 30);

	this->earth = std::make_unique<Sphere3D>();
	this->earth->setShaderProperty("color4", Color4(0x54AFEBFF));
	this->earth->setScale(Vector3D::one * 15);

	this->moon = std::make_unique<Sphere3D>();
	this->moon->setShaderProperty("color4", Color4(0x7A7A7AFF));
	this->moon->setScale(Vector3D::one * 6);

	// Increaing camera's far and near plane

	this->environment->camera.setNear(4);
	this->environment->camera.setFar(500);

	// Enable free camera movement

	this->environment->enableFreeCamera(true);

	// Including objects to environment

	this->environment->addObject(this->sun.get());
	this->environment->addObject(this->earth.get());
	this->environment->addObject(this->moon.get());
}

// Runs every frame after setting up the world

void SolarSystem::update(double deltaTime)
{
	// Incresing angles

	this->earthAlpha += deltaTime * this->EARTH_SPEED;
	this->moonAlpha += deltaTime * this->MOON_SPEED;

	// Limiting angles

	this->earthAlpha = fmod(this->earthAlpha, TAU);
	this->moonAlpha = fmod(this->moonAlpha, TAU);

	// Computing positions

	this->earth->setPosition(this->sun->getPosition() + Vector3D(cosf(this->earthAlpha), 0, sinf(this->earthAlpha)) * this->EARTH_RADIUS);
	this->moon->setPosition(this->earth->getPosition() + Vector3D(cosf(this->moonAlpha), 0, sinf(this->moonAlpha)) * this->MOON_RADIUS);
}