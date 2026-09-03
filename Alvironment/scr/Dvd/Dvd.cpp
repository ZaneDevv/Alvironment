#include "Dvd.h"

#include <cstdlib>
#include <cmath>
#include <iostream>

#include "math/Vector2D.h"

void Dvd::initialize()
{
	WindowProperties properties(this->SCREEN_WIDTH, this->SCREEN_HEIGHT, "DVD", false);
	this->environment.emplace(&properties);

	this->dvdCircle = std::make_unique<Circle2D>();
	this->dvdCircle->setScale(Vector2D(80, 150));

	float theta = rand();
	this->direction = Vector2D(cosf(theta), sinf(theta));

	this->environment->addObject(this->dvdCircle.get());
}

void Dvd::update(double deltaTime)
{
	this->dvdCircle->setPosition(this->dvdCircle->getPosition() + this->direction * (deltaTime * this->SPEED));

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