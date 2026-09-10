#include "Object3D.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Object3D::Object3D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount, const char* vertexShader, const char* fragmentShader, const char* texture)
    : GenericObject(3, vertices, verticesAmount, indices, indicesAmount, vertexShader, fragmentShader, texture)
{
    this->setUpIndicesList();
};

Object3D::Object3D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount, const char* texture)
    : GenericObject(3, vertices, verticesAmount, indices, indicesAmount, texture)
{
    this->setUpIndicesList();
};

Object3D::Object3D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount, const char* vertexShader, const char* fragmentShader)
    : GenericObject(3, vertices, verticesAmount, indices, indicesAmount, vertexShader, fragmentShader)
{
    this->setUpIndicesList();
};

Object3D::Object3D(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount)
    : GenericObject(3, vertices, verticesAmount, indices, indicesAmount)
{
    this->setUpIndicesList();
};

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

inline void Object3D::setUpIndicesList()
{
    this->actualIndices = indices;
    this->actualIndicesAmount = indicesAmount;

    std::copy(indices, indices + indicesAmount, this->actualIndices);
}

bool Object3D::isVertexZWithinFrustrum(float z) const
{
    return z >= this->camera->getNear() && z <= this->camera->getFar();
}

inline bool Object3D::shouldRenderTriangleByBackFaceCulling(const u32_t& index0, const u32_t& index1, const u32_t& index2) const
{
    double crossVerticesZTerm1 = this->verticesToRender[index1 * 5] - this->verticesToRender[index0 * 5];
    double crossVerticesZTerm2 = this->verticesToRender[index2 * 5 + 1] - this->verticesToRender[index0 * 5 + 1];
    double crossVerticesZTerm3 = this->verticesToRender[index1 * 5 + 1] - this->verticesToRender[index0 * 5 + 1];
    double crossVerticesZTerm4 = this->verticesToRender[index2 * 5] - this->verticesToRender[index0 * 5];

    double crossVerticesZ = crossVerticesZTerm1 * crossVerticesZTerm2 - crossVerticesZTerm3 * crossVerticesZTerm4;

    return crossVerticesZ >= 0;
}

void Object3D::updateIndices()
{
    this->indicesAmount = 0;
    this->indicesToRenderVector.clear();

    for (int i = 0; i < this->actualIndicesAmount; i += 3)
    {
        u32_t triangleIndex0 = this->actualIndices[i];
        u32_t triangleIndex1 = this->actualIndices[i + 1];
        u32_t triangleIndex2 = this->actualIndices[i + 2];

        if (this->shouldRenderTriangleByBackFaceCulling(triangleIndex0, triangleIndex1, triangleIndex2))
        {
            double depthVertex0 = this->depthVertices.at(triangleIndex0);
            double depthVertex1 = this->depthVertices.at(triangleIndex1);
            double depthVertex2 = this->depthVertices.at(triangleIndex2);

            if (this->isVertexZWithinFrustrum(depthVertex0) || this->isVertexZWithinFrustrum(depthVertex1) || this->isVertexZWithinFrustrum(depthVertex2))
            {
                this->indicesToRenderVector.push_back(triangleIndex0);
                this->indicesToRenderVector.push_back(triangleIndex1);
                this->indicesToRenderVector.push_back(triangleIndex2);

                indicesAmount += 3;
            }
        }
    }

    this->indices = nullptr;
    this->indices = this->indicesToRenderVector.data();
    this->depthVertices.clear();

    this->updateEbo();
}

void Object3D::updateVertices()
{
    if (camera != nullptr)
    {
        double cameraFarAndNear = this->camera->getFar() + this->camera->getNear();
        double differenceCamearaFarNear = this->camera->getFar() - this->camera->getNear();
        double cameraDoubleFarNear = 2 * this->camera->getFar() * this->camera->getNear();

        for (int i = 0; i < this->verticesAmount; i += 5)
        {
            double x = this->vertices[i] * this->scale.getX();
            double y = this->vertices[i + 1] * this->scale.getY();
            double z = this->vertices[i + 2] * this->scale.getZ();

            Vector3D rotatedVertex = (this->rotation * Quaternion(0, x, y, z) * Quaternion::inverse(this->rotation)).getAxis();
            Vector3D newVertex = rotatedVertex + this->position;

            newVertex = newVertex - this->camera->getPosition();
            newVertex = (Quaternion::inverse(this->camera->getRotation()) * Quaternion::createByWAndAxis(0, newVertex) * this->camera->getRotation()).getAxis();

            this->verticesToRender[i] = newVertex.getX() * this->camera->getProjectionScale() / (newVertex.getZ() * this->windowAspectRatio);
            this->verticesToRender[i + 1] = newVertex.getY() * this->camera->getProjectionScale() / newVertex.getZ();
            this->verticesToRender[i + 2] = (newVertex.getZ() * cameraFarAndNear / differenceCamearaFarNear - cameraDoubleFarNear / differenceCamearaFarNear) /  newVertex.getZ();

            this->depthVertices.push_back(newVertex.getZ());
        }

        this->updateVbo();
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