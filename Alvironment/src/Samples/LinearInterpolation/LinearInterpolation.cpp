#include "LinearInterpolation.h"

#include <cmath>

#include "alvironment/Key.h";

// Runs when the world sets up

void LinearInterpolation::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(500, 500, "Linear interpolator", true);
	this->environment.emplace(&properties);

	// Creating the basic objects

	this->start = std::make_unique<Circle2D>();
	this->start->setScale(Vector2D::one * this->circleRadius);
	this->start->setPosition(Vector2D(-150, -150));
	this->start->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	this->goal = std::make_unique<Circle2D>();
	this->goal->setScale(Vector2D::one * this->circleRadius);
	this->goal->setPosition(Vector2D(150, 150));
	this->goal->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	this->mover = std::make_unique<Circle2D>();
	this->mover->setScale(Vector2D::one * this->circleRadius);
	this->mover->setShaderProperty("color4", 0.9f, 0.2f, 0.1f, 1.0f);

	// Creating a segment that joins the start and goal cricles

	this->segment = std::make_unique<Rectangle2D>();
	this->segment->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	this->updateSegment();

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

	// Checking if cursor is selecting anything

	if (this->environment->isKeyPressed(Key::Space))
	{
		// Getting mouse's position

		double x = 0;
		double y = 0;

		this->environment->getMousePosition(x, y);
		//PRINT("Mouse's position: " << x << ", " << y);

		Vector2D cursorVector = Vector2D(x, y);

		// Checking the distance between cursor and circle

		Vector2D startToCursor = cursorVector - this->start->getPosition();
		Vector2D goalToCursor = cursorVector - this->goal->getPosition();

		double distanceToStartPoint = startToCursor.getMagnitude();
		double distanceToGoalPoint = goalToCursor.getMagnitude();

		// Checking if the cursor is over any circle

		bool isOverStartPoint = distanceToStartPoint <= this->start->getScale().getX();
		bool isOverGoalPoint = distanceToGoalPoint <= this->start->getScale().getY();

		// Getting the selected circle

		if (isOverStartPoint && isOverGoalPoint)
		{
			this->selected = distanceToStartPoint < distanceToGoalPoint ? this->start.get() : this->goal.get();
			this->offset = distanceToStartPoint < distanceToGoalPoint ? startToCursor : goalToCursor;
		}
		else if (isOverStartPoint)
		{
			if (this->selected != this->start.get())
			{
				this->selected = this->start.get();
				this->offset = startToCursor;
			}
		}
		else if (isOverGoalPoint)
		{
			if (this->selected != this->goal.get())
			{
				this->selected = this->goal.get();
				this->offset = goalToCursor;
			}
		}
		else
		{
			this->selected = nullptr;
			this->offset = Vector2D::zero;
		}

		// Update position of the selected circle if there is one

		if (this->selected != nullptr)
		{
			this->selected->setPosition(cursorVector - this->offset);

			// Updating the segment

			this->updateSegment();
		}
	}
	else
	{
		this->selected = nullptr;
		this->offset = Vector2D::zero;
	}

	// Computing the new circle's position and placing it there

	this->mover->setPosition(Vector2D(
		this->start->getPosition().getX() + (this->goal->getPosition().getX() - this->start->getPosition().getX()) * alpha,
		this->start->getPosition().getY() + (this->goal->getPosition().getY() - this->start->getPosition().getY()) * alpha
	));
}

void LinearInterpolation::updateSegment()
{
	Vector2D difference = this->goal->getPosition() - this->start->getPosition();

	this->segment->setPosition((this->start->getPosition() + this->goal->getPosition()) / 2);
	this->segment->setTheta(atan2(difference.getY(), difference.getX()));
	this->segment->setScale(Vector2D(difference.getMagnitude(), 10));
}