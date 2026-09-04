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

	// Defining colors

	Color4 white(0xD0D0D0FF);
	Color4 enemyColor(0xE02525FF);

	// Creating the player's box

	this->player = std::make_unique<Rectangle2D>();
	this->player->setScale(Vector2D(5, 100));
	this->player->setPosition(Vector2D(0, this->PLAYER_Y_COORDINATE));
	this->player->setShaderProperty("color4", white);

	// Creating the ball

	this->ball = std::make_unique<Circle2D>();
	this->ball->setScale(Vector2D::one * 10);
	this->ball->setShaderProperty("color4", white);

	// Creating enemies

	for (int i = -460; i <= 460; i += 200)
	{
		for (int j = 120; j <= 250; j += 25)
		{
			std::unique_ptr<Rectangle2D> enemy = std::make_unique<Rectangle2D>();
			enemy->setPosition(Vector2D(i + 50, j));
			enemy->setScale(Vector2D(15, 150));
			enemy->setShaderProperty("color4", enemyColor);

			this->enemies.push_back(std::move(enemy));
		}
	}

	// Computing random starting direction

	srand(5);
	float theta = fmod(rand(), static_cast<double>(TAU));
	this->direction = Vector2D(cosf(theta), sinf(theta));

	// Adding all the objects created to the environment so that they can be rendered on screen

	this->environment->addObject(this->player.get());
	this->environment->addObject(this->ball.get());
	
	for (const std::unique_ptr<Rectangle2D>& enemy : this->enemies)
	{
		this->environment->addObject(enemy.get());
	}
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

	// If the player hitted the ball and the ball was going down, the ball bounces

	if (this->isBallHittingRectangle(*this->player) && this->direction.getY() < 0)
	{
		this->direction = Vector2D(this->direction.getX(), -this->direction.getY());
	}

	// If the ball hitted a enemy, the direction must change and the enemy should be removed

	std::vector<std::unique_ptr<Rectangle2D>>::iterator iterator = this->enemies.begin();

	while (iterator != this->enemies.end())
	{
		if (this->isBallHittingRectangle(**iterator))
		{
			this->direction = Vector2D(this->direction.getX(), -this->direction.getY());

			this->environment->removeObject(iterator->get());
			iterator = this->enemies.erase(iterator);
		}
		else
		{
			++iterator;
		}
	}
}

bool Arkanoid::isBallHittingRectangle(Rectangle2D& rectangle)
{
	bool aabbAxisX = rectangle.getPosition().getX() - rectangle.getScale().getY() < this->ball->getPosition().getX() - this->ball->getScale().getY();
	aabbAxisX &= rectangle.getPosition().getX() + rectangle.getScale().getY() > this->ball->getPosition().getX() + this->ball->getScale().getY();

	bool aabbAxisY = rectangle.getPosition().getY() - rectangle.getScale().getX() < this->ball->getPosition().getY() - this->ball->getScale().getX();
	aabbAxisY &= rectangle.getPosition().getY() + rectangle.getScale().getX() > this->ball->getPosition().getY() + this->ball->getScale().getX();

	return aabbAxisX && aabbAxisY;
}