#pragma once

#include <sstream>

#include "data_types/numbers.h"

/**
 * @brief Class for creating shaders
 * @version 1.0
 * @date 2026-08-31
 * @author Álvaro Fernández Barrero
 */
struct Shader
{
private:
	u32_t program;

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Compiles the given shader code
	 * @param Shader type we need to compile: either vertex or fragment shader
	 * @param Shader's code
	 * @exception The shader could not be compiled
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	u32_t compileShader(u32_t, const char*) const;

	/**
	 * @brief Gets the shader code inside the given file
	 * @param Shader's file's path
	 * @exception The file could not be opened
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	std::string getShaderCodeFromFile(const char*) const;

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a brand new shader with the vertex a fragment shader codes
	 * @param Vertex shader's code's path
	 * @param Fragment shader's code's path
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	Shader(const char*, const char*);

	// ------------------------------------------------------
	// DESTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Removes the shader and frees the memory
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	~Shader();

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Gets the shader's id
	 * @return Shader's id
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-08-31
	 * @author Álvaro Fernández Barrero
	 */
	u32_t getShaderId() const;
};