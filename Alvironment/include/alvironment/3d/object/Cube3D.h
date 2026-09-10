#pragma once

#include "./Object3D.h"

/**
 * @brief Class for creating 3D cubes
 * @version 1.2
 * @date 2026-09-09
 * @author Álvaro Fernández Barrero
 */
class Cube3D : public Object3D
{
private:
	static constexpr u32_t verticesAmount = 120;
	static constexpr u32_t indicesAmount = 36;

	static float vertices[Cube3D::verticesAmount];
	static u32_t indices[Cube3D::indicesAmount];

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a new cube
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Cube3D(const char* vertexShader, const char* fragmentShader)
		: Object3D(Cube3D::vertices, Cube3D::verticesAmount, Cube3D::indices, Cube3D::indicesAmount, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a new cube
	 * @param Texture's path
	 * @version 1.0
	 * @since 1.2
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Cube3D(const char* texture)
		: Object3D(Cube3D::vertices, Cube3D::verticesAmount, Cube3D::indices, Cube3D::indicesAmount, texture) {};

	/**
	 * @brief Creates a new cube
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @param Texture's path
	 * @version 1.0
	 * @since 1.2
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Cube3D(const char* vertexShader, const char* fragmentShader, const char* texture)
		: Object3D(Cube3D::vertices, Cube3D::verticesAmount, Cube3D::indices, Cube3D::indicesAmount, vertexShader, fragmentShader, texture) {};

	/**
	 * @brief Creates a new cube
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Cube3D() : Object3D(Cube3D::vertices, Cube3D::verticesAmount, Cube3D::indices, Cube3D::indicesAmount) {};
};