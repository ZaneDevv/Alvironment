#pragma once

#include <vector>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "data_types/numbers.h"
#include "./GenericObject.h"

/**
 * @brief Class for creating a window easily using OpenGL
 * @version 1.0
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class Window
{
private:
	GLFWwindow* window;

	bool isRenderLoopPaused = false;

	std::vector<GenericObject*> elementsToRender;

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

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new window with the given parameters
	 * @param Window's width
	 * @param Window's height
	 * @param Window's title
	 * @param True if the window can be resized, false otherwise
	 * @pre GLFW should have been initialized successfully already
	 * @exception The window could not be created
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Window(u16_t, u16_t, const char*, bool);

	// ------------------------------------------------------
	// DESTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Frees the window instance's memory
	 * @pre The window should have been created
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	~Window();

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Initializes the render loop
	 * @pre The window has to be created
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void startRenderLoop();

	/**
	 * @brief Pauses the render loop
	 * @pre The window has to be created
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void pauseRenderLoop();

	/**
	 * @brief Adds a new element to be rendered on screen
	 * @param The element to render on screen
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void addElementToRender(GenericObject*);

	/**
	 * @brief Removes the given element to be rendered on screen
	 * @param The element to quite from rendering on screen
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void removeElementToRender(GenericObject*);
};