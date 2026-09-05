#pragma once

#include "data_types/numbers.h"
#include "graphics/Color4.h"
#include "alvironment/shaders/Shader.h"

class Environment;

/**
 * @brief Class for generic objects
 * @version 2.1
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
class GenericObject
{
private:
	static const char* const DEFAULT_VERTEX_SHADER;
	static const char* const DEFAULT_FRAGMENT_SHADER;

protected:
	u32_t halfWindowWidth = 1;
	u32_t halfWindowHeight = 1;
	float windowAspectRatio = 1.0f;

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

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

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

	// ------------------------------------------------------
	// DESTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Removes the object and frees the memory
	 * @version 1.0
	 * @since 1.3
	 * @date 2026-09-01
	 * @author Álvaro Fernández Barrero
	 */
	~GenericObject();

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

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

	/**
	 * @brief Updates the object's vertices according to the transformation evolved
	 * @version 1.0
	 * @since 1.4
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	virtual void updateVertices() = 0;

	/**
	 * @brief Updates the window's dimensions
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-02
	 * @author Álvaro Fernández Barrero
	 */
	void updateWindowDimensions(u32_t, u32_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Color to set
	 * @version 1.0
	 * @since 2.0
	 * @date 2026-09-04
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, const Color4&);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, int);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, int, int);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, int, int, int);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, int, int, int, int);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u8_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u8_t, u8_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u8_t, u8_t, u8_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u8_t, u8_t, u8_t, u8_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u16_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u16_t, u16_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u16_t, u16_t, u16_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u16_t, u16_t, u16_t, u16_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u32_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u32_t, u32_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u32_t, u32_t, u32_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u32_t, u32_t, u32_t, u32_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u64_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u64_t, u64_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u64_t, u64_t, u64_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, u64_t, u64_t, u64_t, u64_t);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, float);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, float, float);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, float, float, float);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, float, float, float, float);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, double);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, double, double);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, double, double, double);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, double, double, double, double);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Value to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, bool);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, bool, bool);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, bool, bool, bool);

	/**
	 * @brief Sets a shader's property
	 * @param The shader property's name
	 * @param Values to set
	 * @version 1.0
	 * @since 1.5
	 * @date 2026-09-03
	 * @author Álvaro Fernández Barrero
	 */
	void setShaderProperty(const char*, bool, bool, bool, bool);
};