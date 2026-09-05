#include "Vector2D.h"

#include <cmath>

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

const Vector2D Vector2D::zero(0, 0);
const Vector2D Vector2D::one(1, 1);

const Vector2D Vector2D::i(1, 0);
const Vector2D Vector2D::j(0, 1);

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Vector2D::Vector2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D()
{

}

// ------------------------------------------------------
// OPERATORS
// ------------------------------------------------------

Vector2D Vector2D::operator + (const Vector2D& v) const
{
	return Vector2D(this->x + v.x, this->y + v.y);
}

Vector2D Vector2D::operator - (const Vector2D& v) const
{
	return Vector2D(this->x - v.x, this->y - v.y);
}

Vector2D Vector2D::operator * (const double& scalar) const
{
	return Vector2D(this->x * scalar, this->y * scalar);
}

Vector2D Vector2D::operator / (const double& scalar) const
{
	return Vector2D(this->x / scalar, this->y / scalar);
}

Vector2D Vector2D::operator - () const
{
	return Vector2D(-this->x, -this->y);
}

bool Vector2D::operator == (const Vector2D& v) const
{
	return this->x == v.x && this->y == v.y;
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

double Vector2D::dot(const Vector2D& v, const Vector2D& w)
{
	return v.getX() * w.getX() + v.getY() * w.getY();
}

Vector2D Vector2D::hadamard(const Vector2D& v, const Vector2D& w)
{
	return Vector2D(v.getX() * w.getX(), v.getY() * w.getY());
}

Vector2D Vector2D::lerp(const Vector2D& v, const Vector2D& w, double alpha)
{
	return Vector2D(
		v.getX() * (1 - alpha) + w.getX() * alpha,
		v.getY() * (1 - alpha) + w.getY() * alpha
	);
}

double Vector2D::getMagnitude() const
{
	double result = 0;

	if (this->x != 0 || this->y != 0)
	{
		result = sqrt(Vector2D::dot(*this, *this));
	}

	return result;
}

double Vector2D::getX() const
{
	return this->x;
}

void Vector2D::setX(double x)
{
	this->x = x;
}

double Vector2D::getY() const
{
	return this->y;
}

void Vector2D::setY(double y)
{
	this->y = y;
}