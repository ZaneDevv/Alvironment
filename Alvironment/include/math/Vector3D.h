#pragma once

/**
 * @brief Class for 3D vectors
 * @version 1.0
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
class Vector3D
{
private:
	double x = 0;
	double y = 0;
	double z = 0;

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a new 3D vector
	 * @param First vector's component
	 * @param Second vector's component
	 * @param Third vector's component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D(double, double, double);

	/**
	 * @brief Creates a new 3D vector (0, 0, 0)
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D();

	/**
	 * @brief Copies the given vector
	 * @param Vector to copy
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D(const Vector3D&) = default;

	// ------------------------------------------------------
	// OPERATORS
	// ------------------------------------------------------

	Vector3D operator + (const Vector3D&) const;
	Vector3D operator - (const Vector3D&) const;
	Vector3D operator * (const double&) const;
	Vector3D operator / (const double&) const;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Computes the dot product between the two given vectors
	 * @param The first vector v to compute the dot product
	 * @param The second vector w to compute the dot product
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	static double dot(Vector3D&, Vector3D&);

	/**
	 * @brief Computes the norm of the vector
	 * @return The vector's norm
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	double getMagnitude();

	/**
	 * @brief Gets the X component of the vector
	 * @return The vector's X component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	double getX();

	/**
	 * @brief Sets the X component of the vector
	 * @param The new X component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void setX(double);

	/**
	 * @brief Gets the Y component of the vector
	 * @return The vector's Y component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	double getY();

	/**
	 * @brief Sets the Y component of the vector
	 * @param The new Y component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void setY(double);

	/**
	 * @brief Gets the Z component of the vector
	 * @return The vector's Z component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	double getZ();

	/**
	 * @brief Sets the Z component of the vector
	 * @param The new Z component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	void setZ(double);
};