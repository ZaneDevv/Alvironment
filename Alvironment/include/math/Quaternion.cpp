#include "Quaternion.h"

#include <cmath>
#include "math/constants.h"

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

const Quaternion Quaternion::identity = Quaternion(1, 0, 0, 0);
const Quaternion Quaternion::zero = Quaternion(0, 0, 0, 0);

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Quaternion::Quaternion()
{

}

Quaternion::Quaternion(double theta, const Vector3D& v)
{
	theta /= 2.0f;

	float cos = cosf(theta);
	float sin = sinf(theta);

	this->w = cos;
	this->x = sin * v.getX();
	this->y = sin * v.getY();
	this->z = sin * v.getZ();
}

// ------------------------------------------------------
// OPERATORS
// ------------------------------------------------------

Quaternion Quaternion::operator + (const Quaternion& q) const
{
	return Quaternion(this->w + q.w, this->x + q.x, this->y + q.y, this->z + q.z);
}

Quaternion Quaternion::operator - (const Quaternion& q) const
{
	return Quaternion(this->w - q.w, this->x - q.x, this->y - q.y, this->z - q.z);
}

Quaternion Quaternion::operator * (const Quaternion& q) const
{
	return Quaternion(
		this->w * q.w - this->x * q.x - this->y * q.y - this->z * q.z,
		this->w * q.x + this->x * q.w + this->y * q.z - this->z * q.y,
		this->w * q.y - this->x * q.z + this->y * q.w + this->z * q.x,
		this->w * q.z + this->x * q.y - this->y * q.x + this->z * q.w
	);
}

Quaternion Quaternion::operator * (double scalar) const
{
	return Quaternion(this->w * scalar, this->x * scalar, this->y * scalar, this->z * scalar);
}

Quaternion Quaternion::operator / (double scalar) const
{
	return Quaternion(this->w / scalar, this->x / scalar, this->y / scalar, this->z / scalar);
}

Quaternion Quaternion::operator - () const
{
	return Quaternion(-this->w, -this->x, -this->y, -this->z);
}

bool Quaternion::operator == (const Quaternion& q) const
{
	return abs(this->w - q.w) < EPSILON && abs(this->x - q.x) < EPSILON && abs(this->y - q.y) < EPSILON && abs(this->z - q.z) < EPSILON;
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

Quaternion Quaternion::normalize(const Quaternion& q)
{
	float magnitude = q.getMagnitude();

	return magnitude > 0 ? q / magnitude : q;
}

Quaternion Quaternion::conjugate(const Quaternion& q)
{
	return Quaternion(q.w, -q.x, -q.y, -q.z);
}

Quaternion Quaternion::inverse(const Quaternion& q)
{
	if (q == Quaternion::zero)
	{
		return Quaternion::zero;
	}

	Quaternion conjugate = Quaternion::conjugate(q);
	return conjugate / (q * conjugate).w;
}

Quaternion Quaternion::power(const Quaternion& q, double scalar)
{
	float magnitudeSquared = (q * Quaternion::conjugate(q)).w;

	if (magnitudeSquared == 0)
	{
		return Quaternion::zero;
	}

	float angle = q.getAngle();
	Vector3D axis = q.getAxis();

	float magnitudePowered = pow(magnitudeSquared, scalar / 2.0f);

	if (axis == Vector3D::zero)
	{
		return Quaternion(magnitudePowered, 0, 0, 0);
	}

	angle *= scalar;

	return Quaternion(angle, Vector3D::normalize(axis)) * magnitudePowered;
}

Quaternion Quaternion::slerp(const Quaternion& q0, const Quaternion& q1, double t)
{
	return Quaternion::power(q1 * Quaternion::inverse(q0), t) * q0;
}

float Quaternion::getMagnitude() const
{
	float magnitude = 0;

	if (this->w != 0 || this->x != 0 || this->y != 0 || this->z != 0)
	{
		float magnitudeSquared = ((*this) * Quaternion::conjugate(*this)).w;
		magnitude = sqrtf(magnitudeSquared);
	}

	return magnitude;
}

float Quaternion::getAngle() const
{
	float alpha = 0;

	if (*this != Quaternion::zero)
	{
		float magnitude = this->getMagnitude();
		float realComponent = this->w;

		if (magnitude != 1)
		{
			realComponent /= magnitude;
		}

		alpha = 2 * acos(realComponent);

	}

	return alpha;
}

Vector3D Quaternion::getAxis() const
{
	return Vector3D(this->x, this->y, this->z);
}