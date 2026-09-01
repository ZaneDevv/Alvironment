#pragma once

/**
 * @brief Class for 2D vectors
 * @version 1.0
 * @date 2026-09-01
 * @author Álvaro Fernández Barrero
 */
class Vector2D
{
private:
	double x = 0;
	double y = 0;

public:
	static const Vector2D zero;
	static const Vector2D one;

	static const Vector2D i;
	static const Vector2D j;

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a new 2D vector
	 * @param First vector's component
	 * @param Second vector's component
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Vector2D(double, double);

	/**
	 * @brief Creates a new 2D vector (0, 0)
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Vector2D();

	/**
	 * @brief Copies the given vector
	 * @param Vector to copy
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	Vector2D(const Vector2D&) = default;

	// ------------------------------------------------------
	// OPERATORS
	// ------------------------------------------------------

	Vector2D operator + (const Vector2D&) const;
	Vector2D operator - (const Vector2D&) const;
	Vector2D operator * (const double&) const;
	Vector2D operator / (const double&) const;

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
	static double dot(Vector2D&, Vector2D&);

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
};