#include "Object3D.h"

#include <iostream>

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

bool Object3D::isVertexZWithinFrustrum(float z)
{
    return z >= this->camera->getNear() && z <= this->camera->getFar();
}

void Object3D::updateIndices()
{
    this->indices = nullptr;
    this->indicesAmount = 0;
    this->indicesToRenderVector.clear();

    for (int i = 0; i < this->actualIndicesAmount; i += 3)
    {
        u32_t vertexIndex0 = this->actualIndices[i];
        u32_t vertexIndex1 = this->actualIndices[i + 1];
        u32_t vertexIndex2 = this->actualIndices[i + 2];

        float depthVertex0 = this->depthVertices.at(vertexIndex0);
        float depthVertex1 = this->depthVertices.at(vertexIndex1);
        float depthVertex2 = this->depthVertices.at(vertexIndex2);

        float vertex0Z = depthVertex0 * this->verticesToRender[vertexIndex0 * 3 + 2];
        float vertex1Z = depthVertex1 * this->verticesToRender[vertexIndex1 * 3 + 2];
        float vertex2Z = depthVertex2 * this->verticesToRender[vertexIndex2 * 3 + 2];

        if (this->isVertexZWithinFrustrum(vertex0Z) && this->isVertexZWithinFrustrum(vertex1Z) && this->isVertexZWithinFrustrum(vertex2Z))
        {
            this->indicesToRenderVector.push_back(vertexIndex0);
            this->indicesToRenderVector.push_back(vertexIndex1);
            this->indicesToRenderVector.push_back(vertexIndex2);

            indicesAmount += 3;
        }
    }

    this->indices = this->indicesToRenderVector.data();
       this->depthVertices.clear();

    this->updateVbo();
}

void Object3D::updateVertices()
{
    if (camera != nullptr)
    {
        double cameraFarAndNear = this->camera->getFar() + this->camera->getNear();
        double differenceCamearaFarNear = this->camera->getFar() - this->camera->getNear();
        double cameraDoubleFarNear = 2 * this->camera->getFar() * this->camera->getNear();

        for (int i = 0; i < this->verticesAmount; i += 3)
        {
            float x = this->vertices[i] * this->scale.getX();
            float y = this->vertices[i + 1] * this->scale.getY();
            float z = this->vertices[i + 2] * this->scale.getZ();

            Vector3D rotatedVertex = (this->rotation * Quaternion(0, x, y, z) * Quaternion::inverse(this->rotation)).getAxis();
            Vector3D newVertex = rotatedVertex + this->position;

            newVertex = newVertex - this->camera->getPosition();
            newVertex = (Quaternion::inverse(this->camera->getRotation()) * Quaternion::createByWAndAxis(0, newVertex) * this->camera->getRotation()).getAxis();

            this->verticesToRender[i] = newVertex.getX() * this->camera->getProjectionScale() / (newVertex.getZ() * this->windowAspectRatio);
            this->verticesToRender[i + 1] = newVertex.getY() * this->camera->getProjectionScale() / newVertex.getZ();
            this->verticesToRender[i + 2] = (newVertex.getZ() * cameraFarAndNear / differenceCamearaFarNear - cameraDoubleFarNear / differenceCamearaFarNear) /  newVertex.getZ();

            this->depthVertices.push_back(newVertex.getZ());
        }

        this->updateEbo();
        this->updateIndices();
    }
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

void Object3D::setCamera(Camera* camera)
{
    this->camera = camera;
    this->updateVertices();
}