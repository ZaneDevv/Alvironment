#pragma once

#include "../Environment.h"
#include "./object/Object2D.h"

/**
 * @brief Class for 2D environments
 * @version 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class Environment2D : public Environment
{
public:
	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 2D environment with the given parameters
	 * @param Window's properties
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Environment2D(WindowProperties* properties) : Environment(properties) {
		this->dimensions = 2;
	};

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Adds a new object to the environment
	 * @param Object to add
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-07
	 * @author Álvaro Fernández Barrero
	 */
	void addObject(Object2D*);

	/**
	 * @brief Removes the given object from the environment
	 * @param Object to remove
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-07
	 * @author Álvaro Fernández Barrero
	 */
	void removeObject(Object2D*);
};