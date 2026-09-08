#pragma once

#include "alvironment/3d/World3D.h"
#include "alvironment/3d/object/Cube3D.h"

class SpinningCube : public World3D
{
private:

	// Objects

	std::unique_ptr<Cube3D> cube;

	// Mathematical

	Vector3D rotationAxis = Vector3D::normalize(Vector3D(1, 1, 0));
	double theta = 0;

public:

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Initializes the world
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void initialize() override;

	/**
	 * @brief Updates the world. This method will be fired every frame
	 * @param Time difference (delta time) between the last frame and the currect one
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void update(double) override;
};