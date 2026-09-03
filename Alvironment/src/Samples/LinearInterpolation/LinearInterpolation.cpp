#include "LinearInterpolation.h"

#include <cmath>

// Runs when the world sets up

void LinearInterpolation::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(500, 500, "Linear interpolator", true);
	this->environment.emplace(&properties);

	// Creating the basic objects

	this->start = std::make_unique<Circle2D>();
	this->start->setScale(Vector2D::one * this->circleRadius);
	this->start->setPosition(Vector2D(-350, -350));
	this->start->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	this->goal = std::make_unique<Circle2D>();
	this->goal->setScale(Vector2D::one * this->circleRadius);
	this->goal->setPosition(Vector2D(350, 350));
	this->goal->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	this->mover = std::make_unique<Circle2D>();
	this->mover->setScale(Vector2D::one * this->circleRadius);
	this->mover->setShaderProperty("color4", 0.9f, 0.2f, 0.1f, 1.0f);

	// Creating a segment that joins the start and goal cricles

	Vector2D difference = this->goal->getPosition() - this->start->getPosition();

	this->segment = std::make_unique<Rectangle2D>();
	this->segment->setTheta(atan2(difference.getY(), difference.getX()));
	this->segment->setScale(Vector2D(difference.getMagnitude(), 10));
	this->segment->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	// Adding all the objects created to the environment so that they can be rendered on screen

	this->environment->addObject(this->segment.get());
	this->environment->addObject(this->start.get());
	this->environment->addObject(this->goal.get());
	this->environment->addObject(this->mover.get());
}

// Runs every frame after setting up the world

void LinearInterpolation::update(double deltaTime)
{
	// Increasing alpha

	alpha += deltaTime;
	alpha = fmod(alpha, 1);

	// Computing the new circle's position and placing it there

	this->mover->setPosition(Vector2D(
		this->start->getPosition().getX() + (this->goal->getPosition().getX() - this->start->getPosition().getX()) * alpha,
		this->start->getPosition().getY() + (this->goal->getPosition().getY() - this->start->getPosition().getY()) * alpha
	));
}