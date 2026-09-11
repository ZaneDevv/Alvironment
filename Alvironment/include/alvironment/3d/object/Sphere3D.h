#pragma once

#include "./Object3D.h"

/**
 * @brief Class for creating 3D spheres
 * @version 1.2
 * @date 2026-09-10
 * @author Álvaro Fernández Barrero
 */
class Sphere3D : public Object3D
{
private:
	static constexpr u32_t verticesAmount = 1224;
	static constexpr u32_t indicesAmount = 672;

	static float vertices[Sphere3D::verticesAmount];
	static u32_t indices[Sphere3D::indicesAmount];

public:
	
	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a new sphere
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	Sphere3D(const char* vertexShader, const char* fragmentShader)
		: Object3D(Sphere3D::vertices, Sphere3D::verticesAmount, Sphere3D::indices, Sphere3D::indicesAmount, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a new sphere
	 * @param Texture's path
	 * @version 1.0
	 * @since 1.2
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	Sphere3D(const char* texture)
		: Object3D(Sphere3D::vertices, Sphere3D::verticesAmount, Sphere3D::indices, Sphere3D::indicesAmount, texture) {};

	/**
	 * @brief Creates a new sphere
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @param Texture's path
	 * @version 1.0
	 * @since 1.2
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	Sphere3D(const char* vertexShader, const char* fragmentShader, const char* texture)
		: Object3D(Sphere3D::vertices, Sphere3D::verticesAmount, Sphere3D::indices, Sphere3D::indicesAmount, vertexShader, fragmentShader, texture) {};

	/**
	 * @brief Creates a new sphere
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	Sphere3D() : Object3D(Sphere3D::vertices, Sphere3D::verticesAmount, Sphere3D::indices, Sphere3D::indicesAmount) {};
};