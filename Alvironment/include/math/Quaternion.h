#pragma once

#include "./Vector3D.h"


/**
 * @brief Struct for quaternions
 * @version 1.0
 * @date 2026-09-07
 * @author Álvaro Fernández Barrero
 */
struct Quaternion
{
private:
	double w = 0;
	double x = 0;
	double y = 0;
	double z = 0;

public:
	static const Quaternion identity;
	static const Quaternion zero;

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a null quaternion
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion();

	/**
	 * @brief Creates a quaternion with the given numbers
	 * @param Quaternion's w axis
	 * @param Quaternion's x axis
	 * @param Quaternion's y axis
	 * @param Quaternion's z axis
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion(double w, double x, double y, double z) : w(w), x(x), y(y), z(z) {};

	/**
	 * @brief Creates a quaternion with the given angle and axis
	 * @param Quaternion's angle
	 * @param Quaternion's axis
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion(double, const Vector3D&);

	/**
	 * @brief Copies the given quaternion
	 * @param Quaternion to copy
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Quaternion(const Quaternion&) = default;

	// ------------------------------------------------------
	// OPERATORS
	// ------------------------------------------------------

	Quaternion operator + (const Quaternion&) const;
	Quaternion operator - (const Quaternion&) const;
	Quaternion operator * (const Quaternion&) const;
	Quaternion operator * (double) const;
	Quaternion operator / (double) const;
	Quaternion operator - () const;
	bool operator == (const Quaternion&) const;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Normalizes the given quaternion
	 * @param Quaternion to normalize
	 * @return Quaternion normalized
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	static Quaternion normalize(const Quaternion&);

	/**
	 * @brief Gets the conjugate of the given quaternion
	 * @param Quaternion to get the conjugate from
	 * @return Quaternion conjugated
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	static Quaternion conjugate(const Quaternion&);

	/**
	 * @brief Gets the inverse of the given quaternion
	 * @param Quaternion to get the inverse from
	 * @return Quaternion's inverse
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	static Quaternion inverse(const Quaternion&);

	/**
	 * @brief Powers the given quaternion to the given scalar
	 * @param Quaternion to power
	 * @param Scalar raised
	 * @return Quaternion powered by the scalar
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	static Quaternion power(const Quaternion&, double);

	/**
	 * @brief Interpolates spherically between the first and the second quaternion given the alpha parameter
	 * @param Quaternion to start
	 * @param Quaternion to end
	 * @param Alpha parameter
	 * @return Quaternion interpolated between the first one and the second one
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	static Quaternion slerp(const Quaternion&, const Quaternion&, double);

	/**
	 * @brief Gets the quaternion's magnitude
	 * @return Quaternion's magnitude
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	float getMagnitude() const;

	/**
	 * @brief Gets the quaternion's angle
	 * @return Quaternion's angles
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	float getAngle() const;

	/**
	 * @brief Gets the quaternion's axis
	 * @return Quaternion's axis
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-07
	 * @author Álvaro Fernández Barrero
	 */
	Vector3D getAxis() const;
};