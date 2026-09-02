#pragma once

#include "alvironment/AbstractWorld.h"

#include "alvironment/window/WindowProperties.h"
#include "alvironment/Environment.h"

#include "alvironment/2d/object/Object2D.h"
#include "alvironment/2d/object/Rectangle2D.h"
#include "alvironment/2d/object/Triangle2D.h"
#include "alvironment/2d/object/Circle2D.h"


class World : public AbstractWorld
{
private:
	std::unique_ptr<Object2D> shape;

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