#pragma once

#include "alvironment/2d/World2D.h"

class MyWorld : public World2D
{
public:
	/**
	 * @brief Initializes the world
	 */
	void initialize() override;

	/**
	 * @brief Updates the world. This method will be fired every frame
	 * @param Time difference (delta time) between the last frame and the currect one
	 */
	void update(double) override;
};