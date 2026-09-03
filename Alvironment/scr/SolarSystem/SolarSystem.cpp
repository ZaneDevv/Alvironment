#include "SolarSystem.h"

#include <cmath>

#include "alvironment/window/WindowProperties.h"

#include "math/constants.h"
#include "math/Vector2D.h"

#include "debug_helper/print.h"

void SolarSystem::initialize()
{
	WindowProperties properties(800, 1200, "Solar system", true);
	this->environment.emplace(&properties);

	this->planet = std::make_unique<Circle2D>();
	this->planet->setScale(Vector2D::one * 200);
	this->planet->setShaderProperty("color4", 0.3f, 0.3f, 0.7f, 1.0f);

	this->sun = std::make_unique<Circle2D>();
	this->sun->setScale(this->planet->getScale() * 2);
	this->sun->setShaderProperty("color4", 0.8f, 0.8f, 0.1f, 1.0f);

	this->moon = std::make_unique<Circle2D>();
	this->moon->setScale(this->planet->getScale() / 2);
	this->moon->setShaderProperty("color4", 0.4f, 0.4f, 0.5f, 1.0f);

	this->environment->addObject(this->sun.get());
	this->environment->addObject(this->planet.get());
	this->environment->addObject(this->moon.get());
}

void SolarSystem::update(double deltaTime)
{
	this->theta += deltaTime;
	this->alpha += deltaTime * 2;
	this->phi += deltaTime / 2;

	this->theta = fmod(this->theta, TAU);
	this->alpha = fmod(this->alpha, TAU);
	this->phi = fmod(this->phi, TAU);

	this->sun->setPosition(Vector2D(0, sin(phi) * 20));
	this->planet->setPosition(sun->getPosition() + Vector2D(cos(theta), sin(theta)) * 500);
	this->moon->setPosition(planet->getPosition() + Vector2D(cos(alpha), sin(alpha)) * 200);
}