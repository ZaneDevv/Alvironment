#pragma once

#include "alvironment/AbstractWorld.h"

class MyWorld : public AbstractWorld
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