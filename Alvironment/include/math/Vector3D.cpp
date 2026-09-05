#include "Vector3D.h"

#include <cmath>

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

const Vector3D Vector3D::zero(0, 0, 0);
const Vector3D Vector3D::one(1, 1, 1);

const Vector3D Vector3D::i(1, 0, 0);
const Vector3D Vector3D::j(0, 1, 0);
const Vector3D Vector3D::k(0, 0, 1);

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D()
{

}

// ------------------------------------------------------
// OPERATORS
// ------------------------------------------------------

Vector3D Vector3D::operator + (const Vector3D& v) const
{
	return Vector3D(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector3D Vector3D::operator - (const Vector3D& v) const
{
	return Vector3D(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector3D Vector3D::operator * (const double& scalar) const
{
	return Vector3D(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3D Vector3D::operator / (const double& scalar) const
{
	return Vector3D(this->x / scalar, this->y / scalar, this->z / scalar);
}

bool Vector3D::operator == (const Vector3D& v) const
{
	return this->x == v.x && this->y == y && this->z == v.z;
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

double Vector3D::dot(const Vector3D& v, const Vector3D& w)
{
	return v.getX() * w.getX() + v.getY() * w.getY() + v.getZ() * w.getZ();;
}

Vector3D Vector3D::cross(const Vector3D& v, const Vector3D& w)
{
	return Vector3D(
		v.getY() * w.getZ() - w.getY() * v.getZ(),
		w.getZ() * v.getX() - v.getZ() * w.getX(),
		v.getX() * w.getY() - v.getY() * w.getX()
	);
}

Vector3D Vector3D::lerp(const Vector3D& v, const Vector3D& w, double alpha)
{
	return Vector3D(
		v.getX() * (1 - alpha) + w.getX() * alpha,
		v.getY() * (1 - alpha) + w.getY() * alpha,
		v.getZ() * (1 - alpha) + w.getZ() * alpha
	);
}

double Vector3D::getMagnitude() const
{
	double result = 0;

	if (this->x != 0 || this->y != 0)
	{
		result = sqrt(Vector3D::dot(*this, *this));
	}

	return result;
}

double Vector3D::getX() const
{
	return this->x;
}

void Vector3D::setX(double x)
{
	this->x = x;
}

double Vector3D::getY() const
{
	return this->y;
}

void Vector3D::setY(double y)
{
	this->y = y;
}

double Vector3D::getZ() const
{
	return this->z;
}

void Vector3D::setZ(double z)
{
	this->z = z;
}