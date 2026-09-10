#pragma once

#include "alvironment/3d/World3D.h"
#include "alvironment/3d/object/Sphere3D.h"

class SolarSystem : public World3D
{
private:

	// Mathematical parameters

	const float EARTH_RADIUS = 70;
	const float MOON_RADIUS = 40;

	const float EARTH_SPEED = 0.735f;
	const float MOON_SPEED = 1.673f;

	float earthAlpha = 0;
	float moonAlpha = 0;

	// Objects

	std::unique_ptr<Sphere3D> sun;
	std::unique_ptr<Sphere3D> earth;
	std::unique_ptr<Sphere3D> moon;

public:

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Initializes the world
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	void initialize() override;

	/**
	 * @brief Updates the world. This method will be fired every frame
	 * @param Time difference (delta time) between the last frame and the currect one
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-10
	 * @author Álvaro Fernández Barrero
	 */
	void update(double) override;
};