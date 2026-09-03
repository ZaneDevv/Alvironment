#pragma once

#include "alvironment/AbstractWorld.h"
#include "alvironment/2d/object/Circle2D.h"
#include "alvironment/2d/object/Rectangle2D.h"

#include "math/Vector2D.h"

class LinearInterpolation : public AbstractWorld
{
private:
	// Objects variables

	std::unique_ptr<Circle2D> start;
	std::unique_ptr<Circle2D> goal;
	std::unique_ptr<Circle2D> mover;

	std::unique_ptr<Rectangle2D> segment;

	Vector2D offset = Vector2D::zero;
	Circle2D* selected = nullptr;

	// Simulation's parameters

	float alpha = 0;
	float circleRadius = 50;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Updates the segment to connect the start and the goal circles
	 * @version 1.0
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void updateSegment();

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