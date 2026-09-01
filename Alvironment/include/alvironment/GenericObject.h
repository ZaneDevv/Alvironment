#pragma once

#include "data_types/numbers.h"
#include "alvironment/shaders/Shader.h"

/**
 * @brief Class for generic objects
 * @version 1.4
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class GenericObject
{
private:
	static const char* const DEFAULT_VERTEX_SHADER;
	static const char* const DEFAULT_FRAGMENT_SHADER;

protected:
	float* verticesToRender;
	float* vertices;
	u32_t* indices;

	u32_t verticesAmount = 0;
	u32_t indicesAmount = 0;

	u32_t vao;
	u32_t vbo;
	u32_t ebo;

	Shader* shader;

public:
	/**
	 * @brief Creates a brand new abstract object with the given vertices, indices and shaders
	 * @param Vertices' positions list
	 * @param Vertices amount
	 * @param Indices' list
	 * @param Indices amount
	 * @param Vertex shacer's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	GenericObject(float*, u32_t, u32_t*, u32_t, const char*, const char*);

	/**
	 * @brief Creates a brand new abstract object with the given vertices and indices
	 * @param Vertices' positions list
	 * @param Vertices amount
	 * @param Indices' list
	 * @param Indices amount
	 * @param Vertex shacer's code's path
	 * @param Fragment shader's code's path
	 * @version 1.2
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	GenericObject(float* vertices, u32_t verticesAmount, u32_t* indices, u32_t indicesAmount)
		: GenericObject(vertices, verticesAmount, indices, indicesAmount, GenericObject::DEFAULT_VERTEX_SHADER, GenericObject::DEFAULT_FRAGMENT_SHADER) {};

	/**
	 * @brief Removes the object and frees the memory
	 * @version 1.0
	 * @since 1.3
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	~GenericObject();

	/**
	 * @brief Renders the object
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	virtual void render() = 0;

	/**
	 * @brief Sets up the buffers of this object for the GPU
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	virtual void setUpBuffers() = 0;
};