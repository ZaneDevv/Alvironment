#include "Vector2D.h"

#include <cmath>

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

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

double Vector2D::dot(Vector2D& v, Vector2D& w)
{
	return v.getX() * w.getX() + v.getY() * w.getY();
}

double Vector2D::getMagnitude()
{
	double result = 0;

	if (this->x != 0 || this->y != 0)
	{
		result = sqrt(Vector2D::dot(*this, *this));
	}

	return result;
}

double Vector2D::getX()
{
	return this->x;
}

void Vector2D::setX(double x)
{
	this->x = x;
}

double Vector2D::getY()
{
	return this->y;
}

void Vector2D::setY(double y)
{
	this->y = y;
}