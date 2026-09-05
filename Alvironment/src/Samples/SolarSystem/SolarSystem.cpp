#include "SolarSystem.h"

#include <cmath>

#include "alvironment/window/WindowProperties.h"

#include "math/constants.h"
#include "math/Vector2D.h"

#include "debug_helper/print.h"

// Runs when the world sets up

void SolarSystem::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(800, 1200, "Solar system", true);
	this->environment.emplace(&properties);

	// Creating the objects to show on screen

	this->planet = std::make_unique<Circle2D>();
	this->planet->setScale(Vector2D::one * 115);
	this->planet->setShaderProperty("color4", 0.3f, 0.3f, 0.7f, 1.0f);

	this->sun = std::make_unique<Circle2D>();
	this->sun->setScale(this->planet->getScale() * 2);
	this->sun->setShaderProperty("color4", 0.8f, 0.8f, 0.1f, 1.0f);

	this->moon = std::make_unique<Circle2D>();
	this->moon->setScale(this->planet->getScale() / 2);
	this->moon->setShaderProperty("color4", 0.4f, 0.4f, 0.5f, 1.0f);

	// Adding the created objects to the environment so that they can be rendered on screen

	this->environment->addObject(this->sun.get());
	this->environment->addObject(this->planet.get());
	this->environment->addObject(this->moon.get());
}

// Runs every frame after setting up the world

void SolarSystem::update(double deltaTime)
{
	// Increasing the angles

	this->theta += deltaTime;
	this->alpha += deltaTime * 2;
	this->phi += deltaTime / 2;

	// Limiting the angles to be within -tau and tau

	this->theta = fmod(this->theta, TAU);
	this->alpha = fmod(this->alpha, TAU);
	this->phi = fmod(this->phi, TAU);

	// Computing the sun, planet and moon's positions and placing them

	Vector2D sunPosition(0, sin(phi) * 20);
	Vector2D planetPosition = sun->getPosition() + Vector2D(cos(theta), sin(theta)) * 300;

	this->sun->setPosition(sunPosition);
	this->planet->setPosition(planetPosition);
	this->moon->setPosition(planetPosition + Vector2D(cos(alpha), sin(alpha)) * 150);
}