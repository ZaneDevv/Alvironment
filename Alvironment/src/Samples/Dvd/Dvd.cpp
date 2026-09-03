#include "Dvd.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

#include "math/Vector2D.h"

// Runs when the world sets up

void Dvd::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(this->SCREEN_WIDTH, this->SCREEN_HEIGHT, "DVD", false);
	this->environment.emplace(&properties);

	// Creating the shape to show moving

	this->dvdCircle = std::make_unique<Circle2D>();
	this->dvdCircle->setScale(Vector2D(80, 150));
	this->dvdCircle->setShaderProperty("color4", 0.0f, 0.0f, 0.5f, 1.0f);

	// Computing the first direction to follow

	float theta = rand();
	this->direction = Vector2D(cosf(theta), sinf(theta));

	// Adding all the objects created to the environment so that they can be rendered on screen

	this->environment->addObject(this->dvdCircle.get());
}

// Runs every frame after setting up the world

void Dvd::update(double deltaTime)
{
	// Computing the new object's position and placing it there

	this->dvdCircle->setPosition(this->dvdCircle->getPosition() + this->direction * (deltaTime * this->SPEED));

	// Checking if the direction should change to keep the object on screen

	Vector2D newPosition = this->dvdCircle->getPosition();

	bool isOnTheLeft = newPosition.getX() - this->dvdCircle->getScale().getX() / 2.0f <= -this->SCREEN_WIDTH;
	bool isOnTheRight = newPosition.getX() + this->dvdCircle->getScale().getX() / 2.0f >= this->SCREEN_WIDTH;
	bool isOnTheBottom = newPosition.getY() - this->dvdCircle->getScale().getY() / 2.0f <= -this->SCREEN_HEIGHT;
	bool isOnTheTop = newPosition.getY() + this->dvdCircle->getScale().getY() / 2.0f >= this->SCREEN_HEIGHT;

	if (isOnTheLeft || isOnTheRight)
	{
		this->direction = Vector2D(-this->direction.getX(), this->direction.getY());
	}

	if (isOnTheBottom || isOnTheTop)
	{
		this->direction = Vector2D(this->direction.getX(), -this->direction.getY());
	}
}