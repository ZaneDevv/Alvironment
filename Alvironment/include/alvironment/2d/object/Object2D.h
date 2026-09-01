#pragma once

#include "alvironment/GenericObject.h"

/**
 * @brief Class for creating 2D objects
 * @version 2.1
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class Object2D : public GenericObject
{
private:
	double theta = 0;

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 2D object with the given vertices, indices and shaders
	 * @param Vertices' positions list
	 * @param Indices' list
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Object2D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount, const char* vertexShader, const char* fragmentShader)
		: GenericObject(vertices, verticesAmount, indices, indicesAmount, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a brand new 2D object with the given vertices, indices and shaders
	 * @param Vertices' positions list
	 * @param Indices' list
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Object2D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount) : GenericObject(vertices, verticesAmount, indices, indicesAmount) {};

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Renders the object
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void render() override;

	/**
	 * @brief Sets up the buffers of this object for the GPU
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void setUpBuffers() override;

	/**
	 * @brief Rotates the object by the given angle
	 * @param The angle in radians to rotate the object
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void rotate(double);

	/**
	 * @brief Gets the rotation angle of the object in radians
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	double getTheta();

	/**
	 * @brief Sets the rotation angle of the object
	 * @param The new rotation angle in radians
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void setTheta(double);
};