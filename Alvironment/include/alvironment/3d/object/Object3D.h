#pragma once

#include "alvironment/GenericObject.h"

#include "math/Vector3D.h"
#include "math/Quaternion.h"

/**
 * @brief Class for creating 3D objects
 * @version 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class Object3D : public GenericObject
{
private:
	Vector3D scale = Vector3D::one;
	Vector3D position = Vector3D::zero;
	Quaternion rotation = Quaternion::identity;

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 3D object with the given vertices, indices and shaders
	 * @param Vertices' positions list
	 * @param Indices' list
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Object3D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount, const char* vertexShader, const char* fragmentShader)
		: GenericObject(3, vertices, verticesAmount, indices, indicesAmount, vertexShader, fragmentShader) {};

	/**
	 * @brief Creates a brand new 3D object with the given vertices, indices and shaders
	 * @param Vertices' positions list
	 * @param Indices' list
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Object3D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount) : GenericObject(3, vertices, verticesAmount, indices, indicesAmount) {
		this->dimensions = 3;
	};

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Updates the object's vertices according to the transformation evolved
	 * @version 2.6
	 * @since 1.4
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	void updateVertices() override;

	/**
	 * @brief Gets the scale of the object
	 * @return The object's scale
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D getScale() const;

	/**
	 * @brief Sets the scale of the object
	 * @param The new object's scale
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setScale(const Vector3D&);

	/**
	 * @brief Gets the position of the object
	 * @return The object's position
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D getPosition() const;

	/**
	 * @brief Sets the position of the object
	 * @param The new object's position
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setPosition(const Vector3D&);

	/**
	 * @brief Gets the rotation of the object
	 * @return The object's rotation
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion getRotation() const;

	/**
	 * @brief Sets the rotation of the object
	 * @param The new object's rotation
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setRotation(const Quaternion&);
};