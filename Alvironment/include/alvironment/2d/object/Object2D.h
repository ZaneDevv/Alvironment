#pragma once

#include "alvironment/GenericObject.h"
#include "math/Vector2D.h"

/**
 * @brief Class for creating 2D objects
 * @version 4.2
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class Object2D : public GenericObject
{
private:
	double theta = 0;

	float cosTheta = 0;
	float sinTheta = 1;

	float scaleX = 0;
	float scaleY = 0;

	Vector2D scale = Vector2D::one;
	Vector2D position = Vector2D::zero;

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
	 * @brief Updates the object's vertices according to the transformation evolved
	 * @version 2.6
	 * @since 1.4
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void updateVertices() override;

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
	 * @return Object's rotation in radians
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	double getTheta() const;

	/**
	 * @brief Sets the rotation angle of the object
	 * @param The new rotation angle in radians
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void setTheta(double);

	/**
	 * @brief Gets the scale of the object
	 * @return The object's scale
	 * @version 1.0
	 * @since 3.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Vector2D getScale() const;

	/**
	 * @brief Sets the scale of the object
	 * @param The new object's scale
	 * @version 1.0
	 * @since 3.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void setScale(const Vector2D&);

	/**
	 * @brief Gets the position of the object
	 * @return The object's position
	 * @version 1.0
	 * @since 3.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Vector2D getPosition() const;

	/**
	 * @brief Sets the position of the object
	 * @param The new object's position
	 * @version 1.0
	 * @since 3.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void setPosition(const Vector2D&);
};