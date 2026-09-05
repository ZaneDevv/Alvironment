#pragma once

/**
 * @brief Struct for 3D vectors
 * @version 1.3
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
struct Vector3D
{
private:
	double x = 0;
	double y = 0;
	double z = 0;

public:
	static const Vector3D zero;
	static const Vector3D one;

	static const Vector3D i;
	static const Vector3D j;
	static const Vector3D k;

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
	Vector3D operator - () const;
	bool operator == (const Vector3D&) const;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Computes the dot product between the two given vectors
	 * @param The first vector v to compute the dot product
	 * @param The second vector w to compute the dot product
	 * @version 1.0
	 * @since 1.1
	 * @date 2026-09-05
	 * @author Álvaro Fernández Barrero
	 */
	static double dot(const Vector3D&, const Vector3D&);

	/**
	 * @brief Computes the cross product between the two given vectors
	 * @param The first vector v to compute the cross product
	 * @param The second vector w to compute the cross product
	 * @version 1.1
	 * @since 1.0
	 * @date 2026-09-05
	 * @author Álvaro Fernández Barrero
	 */
	static Vector3D cross(const Vector3D&, const Vector3D&);

	/**
	 * @brief Computes the haramard product between the two given vectors
	 * @param The first vector v to compute the haramard product
	 * @param The second vector w to compute the haramard product
	 * @version 1.0
	 * @since 1.2
	 * @date 2026-09-05
	 * @author Álvaro Fernández Barrero
	 */
	static Vector3D hadamard(const Vector3D&, const Vector3D&);

	/**
	 * @brief Computes a linar interpolation between the two given vectors
	 * @param The first vector v to compute the linear interpolation
	 * @param The second vector w to compute the linear interpolation
	 * @param Alpha parameter for the linear interpolation
	 * @version 1.1
	 * @since 1.0
	 * @date 2026-09-05
	 * @author Álvaro Fernández Barrero
	 */
	static Vector3D lerp(const Vector3D&, const Vector3D&, double);

	/**
	 * @brief Computes the norm of the vector
	 * @return The vector's norm
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	double getMagnitude() const;

	/**
	 * @brief Gets the X component of the vector
	 * @return The vector's X component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	double getX() const;

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
	double getY() const;

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
	double getZ() const;

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