#pragma once

#include "data_types/numbers.h"

/**
 * @brief Struct to store all the window's properties
 * @version 1.0
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
struct WindowProperties
{
public:
	u16_t width = 0;
	u16_t height = 0;

	const char* title = "Title";

	bool resizeable = false;

	/**
	 * @brief Creates a new set of properties for a window
	 * @param Window's width
	 * @param Window's height
	 * @param Window's title
	 * @param True if the window can be resized, false otherwise
	 * @version 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	WindowProperties(u16_t, u16_t, const char*, bool);
};