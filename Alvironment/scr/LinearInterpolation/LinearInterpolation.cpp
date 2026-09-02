#include "LinearInterpolation.h"

#include <cmath>

void LinearInterpolation::initialize()
{
	WindowProperties properties(400, 400, "Linear interpolator", false);
	this->environment.emplace(&properties);

	this->start = std::make_unique<Circle2D>();
	this->start->setScale(Vector2D(0.2f, 0.2f));
	this->start->setPosition(Vector2D(-0.8f, -0.8f));

	this->goal = std::make_unique<Circle2D>();
	this->goal->setScale(Vector2D(0.2f, 0.2f));
	this->goal->setPosition(Vector2D(0.8f, 0.8f));

	this->mover = std::make_unique<Circle2D>();
	this->mover->setScale(Vector2D(0.2f, 0.2f));

	this->environment->addObject(this->start.get());
	this->environment->addObject(this->goal.get());
	this->environment->addObject(this->mover.get());
}

void LinearInterpolation::update(double deltaTime)
{
	alpha += deltaTime;
	alpha = fmod(alpha, 1);

	this->mover->setPosition(Vector2D(
		this->start->getPosition().getX() + (this->goal->getPosition().getX() - this->start->getPosition().getX()) * alpha,
		this->start->getPosition().getY() + (this->goal->getPosition().getY() - this->start->getPosition().getY()) * alpha
	));
}