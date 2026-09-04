#pragma once

#include "alvironment/AbstractWorld.h"

#include "alvironment/2d/object/Rectangle2D.h"
#include "alvironment/2d/object/Circle2D.h"

class Arkanoid : public AbstractWorld
{
private:
	// Simulation's parameters

	const double PLAYER_Y_COORDINATE = -250;
	const double MAX_PLAYER_X = 400;

	const double PLAYER_X_SPEED = 10;
	const double BALL_SPEED = 350;

	// Math

	Vector2D direction = Vector2D::j;

	// Objects

	std::unique_ptr<Rectangle2D> player;
	std::unique_ptr<Circle2D> ball;

	std::vector<std::unique_ptr<Rectangle2D>> enemies;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Updates player's position
	 * @param Delta time
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void updatePlayerPosition(double);

	/**
	 * @brief Updates ball's position
	 * @param Delta time
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void updateBallPosition(double);

	/**
	 * @brief Checks if the ball is hitting the given rectangle
	 * @param Rectangle evolved in the possible collision
	 * @return True if the ball is hitting the rectangle, false otherwise
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	bool isBallHittingRectangle(Rectangle2D&);

public:
	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Initializes the world
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void initialize() override;

	/**
	 * @brief Updates the world. This method will be fired every frame
	 * @param Time difference (delta time) between the last frame and the currect one
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void update(double) override;
};