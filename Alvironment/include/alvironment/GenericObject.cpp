#include "GenericObject.h"

// ------------------------------------------------------
// DEFINING STATIC FIELDS
// ------------------------------------------------------

const char* const GenericObject::DEFAULT_VERTEX_SHADER = "include/alvironment/shaders/common_shaders/Basic.vsha";
const char* const GenericObject::DEFAULT_FRAGMENT_SHADER = "include/alvironment/shaders/common_shaders/Basic.fsha";

// ------------------------------------------------------
// DEFINDING METHODS
// ------------------------------------------------------

GenericObject::GenericObject(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount, const char* vertexShader, const char* fragmentShader)
{
	this->vertices = vertices;
	this->indices = indices;

	this->verticesAmount = verticesAmount;
	this->indicesAmount = indicesAmount;

	this->shader = new Shader(vertexShader, fragmentShader);

	this->verticesToRender = new float[verticesAmount];
	std::copy(vertices, vertices + verticesAmount, this->verticesToRender);
}

GenericObject::~GenericObject()
{
	delete[] this->verticesToRender;
	delete this->shader;
}