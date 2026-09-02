#pragma once

#include <optional>

#include "./Environment.h"
#include "./WorldSetUp.h"

/**
 * @brief Class for the worlds
 * @version 1.0
 * @date 2026-09-02
 * @author Álvaro Fernández Barrero
 */
class AbstractWorld
{
	friend void setUp(AbstractWorld& world);

protected:
	std::optional<Environment> environment;

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
	virtual void initialize() = 0;

	/**
	 * @brief Updates the world. This method will be fired every frame
	 * @param Time difference (delta time) between the last frame and the currect one
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	virtual void update(double) = 0;
};