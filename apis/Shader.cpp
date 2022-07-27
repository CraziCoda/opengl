#include "Shader.h"
#include <iostream>


Shader::Shader()
{
	m_RendererID = glCreateProgram();
}

Shader::~Shader()
{
}

void Shader::Bind()
{
	glLinkProgram(m_RendererID);
	glUseProgram(m_RendererID);
}

void Shader::Unbind()
{

}

void Shader::compileShader(std::string filepath, GLuint type)
{
	std::ifstream file(filepath);
	std::string line;
	std::stringstream ss;

	while (std::getline(file, line)) 
	{
		ss << line << std::endl;
	}

	int success;
	char infoLog[512];




	std::string s_source = ss.str();
	const char* source = s_source.c_str();
	unsigned int shader;
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	glGetShaderiv(m_RendererID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_RendererID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
			infoLog << std::endl;
	};

	glAttachShader(m_RendererID, shader);

	glDeleteShader(shader);
}

void Shader::setInt(const char* uniform, int value)
{
	glUniform1i(glGetUniformLocation(m_RendererID, uniform), value);
}

void Shader::setMat4(const char* uniform, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(m_RendererID, uniform), 1, GL_FALSE, glm::value_ptr(value));
}

