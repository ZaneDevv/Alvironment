#include "GenericObject.h"

#include "./Environment.h"

// ------------------------------------------------------
// STATIC FIELDS
// ------------------------------------------------------

const char* const GenericObject::DEFAULT_VERTEX_SHADER = "include/alvironment/shaders/common_shaders/Basic.vsha";
const char* const GenericObject::DEFAULT_FRAGMENT_SHADER = "include/alvironment/shaders/common_shaders/Basic.fsha";

// ------------------------------------------------------
// CONSTRUCTORS
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

// ------------------------------------------------------
// DESTRUCTORS
// ------------------------------------------------------

GenericObject::~GenericObject()
{
	delete[] this->verticesToRender;
	delete this->shader;
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

void GenericObject::updateWindowDimensions(u32_t width, u32_t height)
{
	this->halfWindowWidth = width / 2.0f;
	this->halfWindowHeight = height / 2.0f;

	this->windowAspectRatio = static_cast<float>(width) / static_cast<float>(height);

	this->updateVertices();
}

void GenericObject::setShaderProperty(const char* shaderProperty, Color4& color)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4f(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}


void GenericObject::setShaderProperty(const char* shaderProperty, int value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value);
}

void GenericObject::setShaderProperty(const char* shaderProperty, int value1, int value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2);
}

void GenericObject::setShaderProperty(const char* shaderProperty, int value1, int value2, int value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3);
}

void GenericObject::setShaderProperty(const char* shaderProperty, int value1, int value2, int value3, int value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3, value4);
}

void GenericObject::setShaderProperty(const char* shaderProperty, u8_t value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u8_t value1, u8_t value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u8_t value1, u8_t value2, u8_t value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2), static_cast<GLuint>(value3));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u8_t value1, u8_t value2, u8_t value3, u8_t value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2), static_cast<GLuint>(value3), static_cast<GLuint>(value4));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u16_t value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u16_t value1, u16_t value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u16_t value1, u16_t value2, u16_t value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2), static_cast<GLuint>(value3));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u16_t value1, u16_t value2, u16_t value3, u16_t value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2), static_cast<GLuint>(value3), static_cast<GLuint>(value4));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u32_t value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value);
}

void GenericObject::setShaderProperty(const char* shaderProperty, u32_t value1, u32_t value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2);
}

void GenericObject::setShaderProperty(const char* shaderProperty, u32_t value1, u32_t value2, u32_t value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3);
}

void GenericObject::setShaderProperty(const char* shaderProperty, u32_t value1, u32_t value2, u32_t value3, u32_t value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3, value4);
}

void GenericObject::setShaderProperty(const char* shaderProperty, u64_t value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u64_t value1, u64_t value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u64_t value1, u64_t value2, u64_t value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2), static_cast<GLuint>(value3));
}

void GenericObject::setShaderProperty(const char* shaderProperty, u64_t value1, u64_t value2, u64_t value3, u64_t value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4ui(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLuint>(value1), static_cast<GLuint>(value2), static_cast<GLuint>(value3), static_cast<GLuint>(value4));
}

void GenericObject::setShaderProperty(const char* shaderProperty, float value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1f(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value);
}

void GenericObject::setShaderProperty(const char* shaderProperty, float value1, float value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2f(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2);
}

void GenericObject::setShaderProperty(const char* shaderProperty, float value1, float value2, float value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3f(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3);
}

void GenericObject::setShaderProperty(const char* shaderProperty, float value1, float value2, float value3, float value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4f(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3, value4);
}

void GenericObject::setShaderProperty(const char* shaderProperty, double value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1d(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value);
}

void GenericObject::setShaderProperty(const char* shaderProperty, double value1, double value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2d(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2);
}

void GenericObject::setShaderProperty(const char* shaderProperty, double value1, double value2, double value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3d(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3);
}

void GenericObject::setShaderProperty(const char* shaderProperty, double value1, double value2, double value3, double value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4d(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), value1, value2, value3, value4);
}

void GenericObject::setShaderProperty(const char* shaderProperty, bool value)
{
	glUseProgram(this->shader->getShaderId());
	glUniform1i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLint>(value));
}

void GenericObject::setShaderProperty(const char* shaderProperty, bool value1, bool value2)
{
	glUseProgram(this->shader->getShaderId());
	glUniform2i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLint>(value1), static_cast<GLint>(value2));
}

void GenericObject::setShaderProperty(const char* shaderProperty, bool value1, bool value2, bool value3)
{
	glUseProgram(this->shader->getShaderId());
	glUniform3i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLint>(value1), static_cast<GLint>(value2), static_cast<GLint>(value3));
}

void GenericObject::setShaderProperty(const char* shaderProperty, bool value1, bool value2, bool value3, bool value4)
{
	glUseProgram(this->shader->getShaderId());
	glUniform4i(glGetUniformLocation(this->shader->getShaderId(), shaderProperty), static_cast<GLint>(value1), static_cast<GLint>(value2), static_cast<GLint>(value3), static_cast<GLint>(value4));
}