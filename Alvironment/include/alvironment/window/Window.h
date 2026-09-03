#pragma once

#include <vector>

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "data_types/numbers.h"
#include "../Key.h"

/**
 * @brief Class for creating a window easily using OpenGL
 * @version 2.3
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class Window
{
private:
	GLFWwindow* window;

	bool isRenderLoopPaused = false;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

public:

	u32_t width = 0;
	u32_t height = 0;

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
	 * @brief Checks if the window should close
	 * @return True if the window should close, false otherwise
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	bool shouldWindowClose();

	/**
	 * @brief Prepares the window to start rendering
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void prepareWindowForRendering();

	/**
	 * @brief Finishes the rendering tasks in screen
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void finishRendering();

	/**
	 * @brief Gets the window's dimensions
	 * @param Window's width
	 * @param Window's height
	 * @version 1.0
	 * @since 2.1
	 * @date 2026-09-02
	 * @author Álvaro Fernández Barrero
	 */
	void getDimensions(u32_t&, u32_t&);

	/**
	 * @brief Checks if the given key is being pressed
	 * @param Key to check
	 * @return True if the key is being pressed, false otherwise
	 * @version 1.0
	 * @since 2.2
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	bool isKeyPressed(Key);

	/**
	 * @brief Gets the mouse's position relative to the screen
	 * @param Mouse's position's x axis
	 * @param Mouse's position's y
	 * @version 1.0
	 * @since 3.3
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void getMousePosition(double&, double&);
};