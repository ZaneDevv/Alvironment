#include "Object2D.h"

#include <cmath>
#include "math/constants.h"

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Object2D::updateVertices()
{
    for (int i = 0; i < this->verticesAmount; i += 2)
    {
        float x = this->vertices[i] * this->scale.getX();
        float y = this->vertices[i + 1] * this->scale.getY();

        this->verticesToRender[i] = this->cosTheta * x - this->sinTheta * y + this->position.getX();
        this->verticesToRender[i + 1] = this->sinTheta * x + this->cosTheta * y + this->position.getY();

        this->verticesToRender[i] /= this->halfWindowWidth;
        this->verticesToRender[i + 1] /= this->halfWindowHeight;
    }

    this->updateVbo();
}

void Object2D::rotate(double alpha)
{
    this->setTheta(std::fmod(alpha + this->getTheta(), TAU));
}

double Object2D::getTheta() const
{
    return this->theta;
}

void Object2D::setTheta(double alpha)
{
    this->theta = std::fmod(alpha, TAU);

    this->cosTheta = cosf(theta);
    this->sinTheta = sinf(theta);

    this->updateVertices();
}

Vector2D Object2D::getScale() const
{
    return this->scale;
}
    
void Object2D::setScale(const Vector2D& scale)
{
    this->scale = scale;
    this->updateVertices();
}

Vector2D Object2D::getPosition() const
{
    return this->position;
}

void Object2D::setPosition(const Vector2D& position)
{
    this->position = position;
    this->updateVertices();
}