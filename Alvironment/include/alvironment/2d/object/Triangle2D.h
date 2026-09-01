#pragma once

#include "./Object2D.h"
#include "data_types/numbers.h"

/**
 * @brief Class for creating 2D triangles
 * @version 1.0
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
class Triangle2D : public Object2D
{
private:
	static constexpr u32_t verticesAmount = 6;
	static constexpr u32_t indicesAmount = 3;

	static float vertices[Triangle2D::verticesAmount];
	static u32_t indices[Triangle2D::indicesAmount];

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
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Triangle2D(const char* vertexShader, const char* fragmentShader)
		: Object2D(Triangle2D::vertices, Triangle2D::verticesAmount, Triangle2D::indices, Triangle2D::indicesAmount, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a brand new 2D rectangle
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Triangle2D() : Object2D(Triangle2D::vertices, Triangle2D::verticesAmount, Triangle2D::indices, Triangle2D::indicesAmount) {};
};