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
    u32_t shaderId = this->shader->getShaderId();
	glUseProgram(shaderId);

    int location = glGetUniformLocation(shaderId, "color4");
    glUniform4f(location, 0.85f, 0.2f, 0.2f, 1.0f);

    glBindVertexArray(this->vao);

	glDrawElements(GL_TRIANGLES, this->indicesAmount, GL_UNSIGNED_INT, nullptr);
}

void Object2D::updateVertices()
{
    for (int i = 0; i < this->verticesAmount; i += 2)
    {
        this->verticesToRender[i] = this->scale.getX() * (cosf(this->theta) * this->vertices[i] + sinf(this->theta) * this->vertices[i + 1]) + this->position.getX();
        this->verticesToRender[i + 1] = this->scale.getY() * (cosf(this->theta) * this->vertices[i + 1] - sinf(this->theta) * this->vertices[i]) + this->position.getY();

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
    this->updateVertices();
}

Vector2D Object2D::getScale()
{
    return this->scale;
}
    
void Object2D::setScale(Vector2D& scale)
{
    this->scale = scale;
    this->updateVertices();
}

void Object2D::setScale(Vector2D scale)
{
    this->scale = scale;
    this->updateVertices();
}

Vector2D Object2D::getPosition()
{
    return this->position;
}

void Object2D::setPosition(Vector2D& position)
{
    this->position = position;
    this->updateVertices();
}

void Object2D::setPosition(Vector2D position)
{
    this->position = position;
    this->updateVertices();
}