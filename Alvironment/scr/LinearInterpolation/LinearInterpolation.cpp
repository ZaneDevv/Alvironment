#include "LinearInterpolation.h"

#include <cmath>

void LinearInterpolation::initialize()
{
	WindowProperties properties(500, 500, "Linear interpolator", true);
	this->environment.emplace(&properties);

	this->start = std::make_unique<Circle2D>();
	this->start->setScale(Vector2D::one * this->circleRadius);
	this->start->setPosition(Vector2D(-350, -350));

	this->goal = std::make_unique<Circle2D>();
	this->goal->setScale(Vector2D::one * this->circleRadius);
	this->goal->setPosition(Vector2D(350, 350));

	this->mover = std::make_unique<Circle2D>();
	this->mover->setScale(Vector2D::one * this->circleRadius);

	Vector2D difference = this->goal->getPosition() - this->start->getPosition();

	this->segment = std::make_unique<Rectangle2D>();
	this->segment->setTheta(atan2(difference.getY(), difference.getX()));
	this->segment->setScale(Vector2D(difference.getMagnitude(), 10));

	this->environment->addObject(this->start.get());
	this->environment->addObject(this->goal.get());
	this->environment->addObject(this->mover.get());
	this->environment->addObject(this->segment.get());
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