#include "Object2D.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "math/constants.h"
#include "debug_helper/print.h"
#include "data_types/numbers.h"

#include "alvironment/shaders/Shader.h"

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void Object2D::setUpBuffers()
{
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->verticesAmount * sizeof(float), this->verticesToRender, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indicesAmount * sizeof(u32_t), this->indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glBindVertexArray(0);
}

void Object2D::render()
{
	glUseProgram(this->shader->getShaderId());
    glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES, this->indicesAmount, GL_UNSIGNED_INT, nullptr);
}

void Object2D::updateVertices()
{
    for (int i = 0; i < this->verticesAmount; i += 2)
    {
        float x = this->vertices[i] * this->scale.getX();
        float y = this->vertices[i + 1] * this->scale.getY();

        this->verticesToRender[i] = this->cosTheta * x - this->sinTheta * y + this->position.getX();
        this->verticesToRender[i + 1] = this->sinTheta * x + this->cosTheta * y + this->position.getY();

        this->verticesToRender[i] /= this->windowWidth * this->windowAspectRatio;
        this->verticesToRender[i + 1] /= this->windowWidth;
    }

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->verticesAmount * sizeof(float), this->verticesToRender, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Object2D::rotate(double alpha)
{
    this->setTheta(std::fmod(alpha + this->getTheta(), TAU));
}

double Object2D::getTheta()
{
    return this->theta;
}

void Object2D::setTheta(double alpha)
{
    this->theta = std::fmod(alpha, TAU);

    this->cosTheta = cosf(theta);
    this->sinTheta = sinf(theta);

    this->updateVertices();

    DEBUG_PRINT("Theta changed to " << this->theta);
}

Vector2D Object2D::getScale()
{
    return this->scale;
}
    
void Object2D::setScale(Vector2D& scale)
{
    this->scale = scale;
    this->updateVertices();

    DEBUG_PRINT("Scale changed to (" << scale.getX() << ", " << scale.getY() << ")");
}

void Object2D::setScale(Vector2D scale)
{
    this->scale = scale;
    this->updateVertices();

    DEBUG_PRINT("Scale changed to (" << scale.getX() << ", " << scale.getY() << ")");
}

Vector2D Object2D::getPosition()
{
    return this->position;
}

void Object2D::setPosition(Vector2D& position)
{
    this->position = position;
    this->updateVertices();

    DEBUG_PRINT("Position changed to (" << position.getX() << ", " << position.getY() << ")");
}

void Object2D::setPosition(Vector2D position)
{
    this->position = position;
    this->updateVertices();

    DEBUG_PRINT("Position changed to (" << position.getX() << ", " << position.getY() << ")");
}