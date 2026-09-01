#pragma once

#include "./Object2D.h"
#include "data_types/numbers.h"

/**
 * @brief Class for creating 2D rectangles
 * @version 1.0
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
class Rectangle2D : public Object2D
{
private:
	static constexpr u32_t verticesAmount = 8;
	static constexpr u32_t indicesAmount = 6;

	static float vertices[Rectangle2D::verticesAmount];
	static u32_t indices[Rectangle2D::indicesAmount];

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 2D rectangle with the given shaders
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Rectangle2D(const char* vertexShader, const char* fragmentShader)
		: Object2D(Rectangle2D::vertices, Rectangle2D::verticesAmount, Rectangle2D::indices, Rectangle2D::indicesAmount, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a brand new 2D rectangle
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Rectangle2D() : Object2D(Rectangle2D::vertices, Rectangle2D::verticesAmount, Rectangle2D::indices, Rectangle2D::indicesAmount) {};
};