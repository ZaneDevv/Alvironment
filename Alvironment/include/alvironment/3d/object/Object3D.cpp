#include "Object3D.h"

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Object3D::updateVertices()
{
    for (int i = 0; i < this->verticesAmount; i += 3)
    {
        float x = this->vertices[i] * this->scale.getX();
        float y = this->vertices[i + 1] * this->scale.getY();
        float z = this->vertices[i + 2] * this->scale.getZ();

        Vector3D rotatedVertex = (this->rotation * Quaternion(0, x, y, z) * Quaternion::inverse(this->rotation)).getAxis();
        Vector3D newVertex = rotatedVertex + this->position;

        this->verticesToRender[i] = newVertex.getX();
        this->verticesToRender[i + 1] = newVertex.getY();
        this->verticesToRender[i + 2] = newVertex.getZ();
    }

    this->updateVbo();
}

Vector3D Object3D::getScale() const
{
    return this->scale;
}

void Object3D::setScale(const Vector3D& scale)
{
    this->scale = scale;
    this->updateVertices();
}

Vector3D Object3D::getPosition() const
{
    return this->position;
}

void Object3D::setPosition(const Vector3D& position)
{
    this->position = position;
    this->updateVertices();
}

Quaternion Object3D::getRotation() const
{
    return this->rotation;
}

void Object3D::setRotation(const Quaternion& rotation)
{
    this->rotation = rotation;
    this->updateVertices();
}