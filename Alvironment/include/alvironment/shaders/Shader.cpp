#include "Shader.h"

#include <memory>
#include <fstream>
#include <GL/glew.h>

#include "data_types/numbers.h"
#include "debug_helper/print.h"

// ------------------------------------------------------
// CONSTRUCTORS
// ------------------------------------------------------

Shader::Shader(const char* vertexShaderCode, const char* fragmentShaderCode)
{
	this->program = glCreateProgram();

	std::string vertexCode = this->getShaderCodeFromFile(vertexShaderCode);
	std::string fragmentCode = this->getShaderCodeFromFile(fragmentShaderCode);

	u32_t vertexShader = this->compileShader(GL_VERTEX_SHADER, &vertexCode[0]);
	u32_t fragmentShader = this->compileShader(GL_FRAGMENT_SHADER, &fragmentCode[0]);

	glAttachShader(this->program, vertexShader);
	glAttachShader(this->program, fragmentShader);

	glLinkProgram(this->program);
	glValidateProgram(this->program);
}

// ------------------------------------------------------
// DESTRUCTORS
// ------------------------------------------------------

Shader::~Shader()
{
	glDeleteProgram(this->program);
}

// ------------------------------------------------------
// METHODS
// ------------------------------------------------------

std::string Shader::getShaderCodeFromFile(const char* codePath) const
{
	std::fstream stream(codePath);
	
	if (!stream.is_open())
	{
		WARNING_PRINT("The file could not be opened");
		return "";
	}

	std::stringstream buffer;
	buffer << stream.rdbuf();

	return buffer.str();
}

u32_t Shader::compileShader(u32_t type, const char* source) const
{
	u32_t id = glCreateShader(type);
	int result = 0;

	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)malloc(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		ERROR_PRINT((type == GL_VERTEX_SHADER ? "Vertex Shader" : "Fragment Shader") << " -> " << message);
		throw message;
	}

	return id;
}

u32_t Shader::getShaderId() const
{
	return this->program;
}