#include "Arkanoid.h"

#include <cmath>
#include <cstdlib>

#include "math/constants.h"

// Runs when the world sets up

void Arkanoid::initialize()
{
	// Creating the environment with the given window's parameters

	WindowProperties properties(1000, 600, "Arkanoid", false);
	this->environment.emplace(&properties);

	// Creating the player's box

	this->player = std::make_unique<Rectangle2D>();
	this->player->setScale(Vector2D(5, 100));
	this->player->setPosition(Vector2D(0, this->PLAYER_Y_COORDINATE));
	this->player->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	// Creating the ball

	this->ball = std::make_unique<Circle2D>();
	this->ball->setScale(Vector2D::one * 10);
	this->ball->setShaderProperty("color4", 0.9f, 0.9f, 0.9f, 1.0f);

	// Computing random starting direction

	srand(5);
	float theta = fmod(rand(), static_cast<double>(TAU));
	this->direction = Vector2D(cosf(theta), sinf(theta));

	// Adding all the objects created to the environment so that they can be rendered on screen

	this->environment->addObject(this->player.get());
	this->environment->addObject(this->ball.get());
}

// Runs every frame after setting up the world

void Arkanoid::update(double deltaTime)
{
	this->updatePlayerPosition(deltaTime);
	this->updateBallPosition(deltaTime);
}

void Arkanoid::updatePlayerPosition(double deltaTime)
{
	// Getting mouse's position

	double xCursorPosition = 0;
	double yCursorPosition = 0;
	this->environment->getMousePosition(xCursorPosition, yCursorPosition);

	// Limiting x position

	xCursorPosition = std::max(-this->MAX_PLAYER_X, std::min(xCursorPosition, this->MAX_PLAYER_X));

	// Computing player's position

	double previousPlayerPositionX = this->player->getPosition().getX();
	double alpha = deltaTime * this->PLAYER_X_SPEED;

	this->player->setPosition(Vector2D(
		previousPlayerPositionX + (xCursorPosition - previousPlayerPositionX) * alpha,
		this->PLAYER_Y_COORDINATE
	));
}

void Arkanoid::updateBallPosition(double deltaTime)
{
	// Computes and sets the new position moved in the direction

	this->ball->setPosition(this->ball->getPosition() + this->direction * (deltaTime * this->BALL_SPEED));

	// Checks if the ball hitted limit

	bool hasHittedVerticalLimit = this->ball->getPosition().getX() < -500 || this->ball->getPosition().getX() > 500;
	bool hasHittedHorizontalLimit = this->ball->getPosition().getY() < -300 || this->ball->getPosition().getY() > 300;

	if (hasHittedVerticalLimit)
	{
		this->direction = Vector2D(-this->direction.getX(), this->direction.getY());
	}

	if (hasHittedHorizontalLimit)
	{
		this->direction = Vector2D(this->direction.getX(), -this->direction.getY());
	}

	// Checks if the ball hitted the player

	bool aabbAxisX = this->player->getPosition().getX() - this->player->getScale().getY() < this->ball->getPosition().getX() - this->ball->getScale().getY();
	aabbAxisX &= this->player->getPosition().getX() + this->player->getScale().getY() > this->ball->getPosition().getX() + this->ball->getScale().getY();

	bool aabbAxisY = this->player->getPosition().getY() - this->player->getScale().getX() > this->ball->getPosition().getY() - this->ball->getScale().getX();
	aabbAxisY &= this->player->getPosition().getY() + this->player->getScale().getX() < this->ball->getPosition().getY() + this->ball->getScale().getX();

	// If the player hitted the ball and the ball was going down, the ball bounces

	if (aabbAxisX && aabbAxisY && this->direction.getY() < 0)
	{
		this->direction = Vector2D(this->direction.getX(), -this->direction.getY());
	}
}