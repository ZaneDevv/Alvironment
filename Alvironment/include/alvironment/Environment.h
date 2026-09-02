#pragma once

#include <memory>
#include <functional>

#include "./GenericObject.h"

#include "./window/Window.h"
#include "./window/WindowProperties.h"

using updateMethod = std::function<void(double)>;

/**
 * @brief Abstract class for the environments
 * @version 3.3
 * @date 2026-09-02
 * @author Álvaro Fernández Barrero
 */
class Environment
{
protected:
	std::vector<GenericObject*> objectsInEnvironment;

	std::unique_ptr<Window> window;

	u32_t lastWindowWidth;
	u32_t lastWindowHeight;

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
	 * @brief Computes the delta time for any frame
	 * @param Reference to where thr last time variable is placed
	 * @param Reference to where the variable for the delta time is placed
	 * @version 1.0
	 * @since 2.4
	 * @date 2026-09-02
	 * @author Álvaro Fernández Barrero
	 */
	void computeDeltaTime(double&, double&);

	/**
	 * @brief Renders all the listed objects
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-02
	 * @author Álvaro Fernández Barrero
	 */
	void renderObjects();

	/**
	 * @brief Updates the window's scale
	 * @version 1.0
	 * @since 2.2
	 * @date 2026-09-02
	 * @author Álvaro Fernández Barrero
	 */
	void updateProportionsOnWindowSize();
public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new environment with the given parameters
	 * @param Window's properties
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-02
	 * @author Álvaro Fernández Barrero
	 */
	Environment(WindowProperties*);

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Initializes the environment
	 * @param Method callback for every frame
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-02
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
	void addObject(GenericObject*);
};