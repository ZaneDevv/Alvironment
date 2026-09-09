#pragma once

#include <cmath>

#include "math/constants.h"
#include "math/Vector3D.h"
#include "math/Quaternion.h"

/**
 * @brief Class for 3D cameras
 * @version 1.2
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class Camera
{
private:
	Vector3D position = Vector3D::zero;
	Quaternion rotation = Quaternion::identity;

	double fov = RIGHT_ANGLE;
	float projectionScale = 0;

	double far = 100;
	double near = 0;

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
	 * @brief Gets the camera's position
	 * @return Camera's position
	 * @version 1.0
	 * @since 1.1
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion getRotation() const;

	/**
	 * @brief Sets the camera's rotation
	 * @param The new camera's rotation
	 * @version 1.0
	 * @since 1.1
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setRotation(const Quaternion&);

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
	 * @brief Gets the tangent of the camera's FOV
	 * @return The tangent of the camera's FOV
	 * @version 1.0
	 * @since 1.1
	 * @date 2026-09-08
	 * @author Álvaro Fernández Barrero
	 */
	double getProjectionScale() const;

	/**
	 * @brief Sets the camera's FOV
	 * @param The new camera's FOV
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setFov(double);

	/**
	 * @brief Gets the camera's ner plane
	 * @return Camera's near plane
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	double getNear() const;

	/**
	 * @brief Sets the camera's near plane
	 * @param The new camera's near plane
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setNear(double);

	/**
	 * @brief Gets the camera's far plane
	 * @return Camera's far plane
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	double getFar() const;

	/**
	 * @brief Sets the camera's far plane
	 * @param The new camera's far plane
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	void setFar(double);
};