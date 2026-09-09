#pragma once

#include "stb/stb_image.h"
#include "data_types/numbers.h"

/**
 * @brief Class for creating textures
 * @version 1.0
 * @date 2026-09-09
 * @author Álvaro Fernández Barrero
 */
struct Texture
{
private:
	u32_t textureId = 0;
	u8_t* textureBuffer = nullptr;

	int width = 0;
	int height = 0;
	int bitsPerPixel = 0;

	const char* path;

public:

	// ------------------------------------------------------
	// CONSTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Creates a new texture given image's path
	 * @param Image's path for the texture
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-09
	 * @author Álvaro Fernández Barrero
	 */
	Texture(const char*);

	// ------------------------------------------------------
	// DESTRUCTORS
	// ------------------------------------------------------

	/**
	 * @brief Removes the texture created
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-09
	 * @author Álvaro Fernández Barrero
	 */
	~Texture();

	// ------------------------------------------------------
	// METHODS
	// ------------------------------------------------------

	/**
	 * @brief Gets this texture's id
	 * @version 1.0
	 * @since 1.0
	 * @date 2026-09-09
	 * @author Álvaro Fernández Barrero
	 */
	u32_t getId();
};