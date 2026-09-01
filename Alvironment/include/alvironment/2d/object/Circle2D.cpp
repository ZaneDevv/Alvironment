#include "Circle2D.h"

#include <cmath>
#include <memory>
#include <iostream>

#include "math/constants.h"

// ------------------------------------------------------
// DEFINING STATIC FIELDS
// ------------------------------------------------------

const double Circle2D::DEFAULT_SMOOTHNESS = ONE_DEGREE_IN_RADIANS;
const double Circle2D::MAXIMUM_SMOOTHNESS = RIGHT_ANGLE;
const double Circle2D::MINIMUM_SMOOTHNESS = ONE_DEGREE_IN_RADIANS;

// ------------------------------------------------------
// DEFINDING METHODS
// ------------------------------------------------------

Circle2D::~Circle2D()
{
	delete[] this->vertices;
	delete[] this->indices;
}

void Circle2D::adjustSmoothness(double& smoothness)
{
	smoothness = std::min(Circle2D::MAXIMUM_SMOOTHNESS, std::max(Circle2D::MINIMUM_SMOOTHNESS, smoothness));
}

float* Circle2D::computeVertices(double smoothness)
{
	Circle2D::adjustSmoothness(smoothness);

	u32_t perimeterVerticesAmount = (u32_t)(TAU / smoothness);
	u32_t verticesAmount = (perimeterVerticesAmount + 1) * 2;

	float* vertices = new float[verticesAmount];

	vertices[0] = 0.0f;
	vertices[1] = 0.0f;

	for (u32_t vertex = 0; vertex < perimeterVerticesAmount; ++vertex)
	{
		u32_t i = (1 + vertex) * 2;
		double alpha = vertex * smoothness;

		vertices[i] = cosf((float)alpha) * 0.5f;
		vertices[i + 1] = sinf((float)alpha) * 0.5f;
	}

	return vertices;
}

u32_t* Circle2D::computeIndices(double smoothness)
{
	Circle2D::adjustSmoothness(smoothness);

	u32_t perimeterVerticesAmount = (u32_t)(TAU / smoothness);
	u32_t indicesAmount = perimeterVerticesAmount * 3;

	u32_t* indices = new u32_t[indicesAmount];

	for (u32_t triangle = 0; triangle < perimeterVerticesAmount; ++triangle)
	{
		u32_t i = triangle * 3;

		indices[i] = 0;
		indices[i + 1] = triangle + 1;
		indices[i + 2] = ((triangle + 1) % perimeterVerticesAmount) + 1;
	}

	return indices;
}

u32_t Circle2D::computeVerticesAmount(double smoothness)
{
	Circle2D::adjustSmoothness(smoothness);
	return ((u32_t)(TAU / smoothness) + 1) * 2;
}

u32_t Circle2D::computeIndicesAmount(double smoothness)
{
	Circle2D::adjustSmoothness(smoothness);
	return (u32_t)(TAU / smoothness) * 3;
}

u32_t Circle2D::getVerticesAmount()
{
	return this->verticesAmount;
}

u32_t Circle2D::getIndicesAmount()
{
	return this->indicesAmount;
}