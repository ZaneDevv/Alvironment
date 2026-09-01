#pragma once

#include <vector>
#include <memory>

#include "../WindowProperties.h"
#include "../Window.h"

#include "./object/Object2D.h"

typedef void(*updateMethod)();

/**
 * @brief Class for creating a new project's environment
 * @version 2.3
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class Environment2D
{
private:
	std::vector<Object2D*> objectsInEnvironment;
	std::unique_ptr<Window> window;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Checks if the conditions are right to keep going with the render loop
	 * @pre The window has to be created
	 * @exception The window was not created yet
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	inline bool shouldGoToNextRenerIteration();

	/**
	 * @brief Initializes the environment
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void renderObjects();

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new environment with the given parameters
	 * @param Window's properties
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Environment2D(WindowProperties*);

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Initializes the environment
	 * @param Update method to tun every iteration
	 * @version 2.4
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void initialize(updateMethod);

	/**
	 * @brief Adds a new objecto to the environment
	 * @param Object to add
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void addObject(Object2D*);
};