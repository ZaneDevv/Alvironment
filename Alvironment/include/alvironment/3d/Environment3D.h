#pragma once

#include "../Environment.h"

#include "./object/Object3D.h"
#include "./Camera.h"

/**
 * @brief Class for 2D worlds
 * @version 2.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
class Environment3D : public Environment
{
private:

	// ------------------------------------------------------
	// STATIC FIELDS
	// ------------------------------------------------------

	static const float CAMERA_SPEED;
	static const float CAMERA_ANGULAR_SPEED;

	// ------------------------------------------------------
	// ATTRIBUTES
	// ------------------------------------------------------

	double lastMouseX = 0;
	double lastMouseY = 0;

	bool wasStartingMouseLocationSet = false;
	bool freeCamera = false;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Moves the free camera
	 * @param Delta time
	 * @version 2.0
	 * @since 2.0
	 * @date 2026-09-08
	 * @author Álvaro Fernández Barrero
	 */
	void moveCamera(double);

protected:
	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Runs the internal update callback
	 * @param Delta time
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-08
	 * @author Álvaro Fernández Barrero
	 */
	virtual void runInternalUpdateCallback(double) override;

public:
	Camera camera;

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new 2D environment with the given parameters
	 * @param Window's properties
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	class Environment3D(WindowProperties* properties) : Environment(properties) {
		this->dimensions = 3;
	};

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Adds a new object to the environment
	 * @param Object to add
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-07
	 * @author Álvaro Fernández Barrero
	 */
	void addObject(Object3D*);

	/**
	 * @brief Removes the given object from the environment
	 * @param Object to remove
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-07
	 * @author Álvaro Fernández Barrero
	 */
	void removeObject(Object3D*);

	/**
	 * @brief Enables/disables the free camera
	 * @param True if the free camera is expected to be enable, false otherwise
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-08-08
	 * @author Álvaro Fernández Barrero
	 */
	void enableFreeCamera(bool);
};