#pragma once

#include <vector>
#include <memory>

#include "../WindowProperties.h"
#include "../Window.h"

#include "./object/Object2D.h"

/**
 * @brief Class for creating a new project's environment
 * @version 1.0
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class Environment2D
{
private:
	std::vector<Object2D*> objectsInEnvironment;
	std::unique_ptr<Window> window;

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
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void initialize();

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