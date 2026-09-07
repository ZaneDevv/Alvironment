#pragma once

#include "math/constants.h"
#include "math/Vector3D.h"

/**
 * @brief Class for 3D cameras
 * @version 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class Camera
{
private:
	Vector3D position = Vector3D::zero;

	double fov = PI;

public:
	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------
	
	Camera();

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Gets the camera's position
	 * @return Camera's position
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D getPosition() const;

	/**
	 * @brief Sets the camera's position
	 * @param The new camera's position
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setPosition(const Vector3D&);

	/**
	 * @brief Gets the camera's FOV
	 * @return Camera's FOV
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	double getFov() const;

	/**
	 * @brief Sets the camera's FOV
	 * @param The new camera's FOV
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setFov(double);
};