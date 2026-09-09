#include "Texture.h"

#include <glad/gl.h>

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Texture::Texture(const char* path) : path(path)
{
	stbi_set_flip_vertically_on_load(1);
	this->textureBuffer = stbi_load(path, &this->width, &this->height, &this->bitsPerPixel, 4);

	glGenTextures(1, &this->textureId);
	glBindTexture(GL_TEXTURE_2D, this->textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->textureBuffer);
	
	glBindTexture(GL_TEXTURE_2D, 0);

	if (this->textureBuffer)
	{
		stbi_image_free(this->textureBuffer);
	}
}

// ------------------------------------------------------
// DESTRUCTORS
// ------------------------------------------------------

Texture::~Texture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

u32_t Texture::getId()
{
	return this->textureId;
}