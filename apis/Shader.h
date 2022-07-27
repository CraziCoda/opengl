#pragma once
#include "glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
private:
	unsigned int m_RendererID;
	
public:
	Shader();
	~Shader();

	void Bind();
	void Unbind();

	void compileShader(std::string filepath, GLuint type);

	void setInt(const char* uniform, int value);
	void setMat4(const char* uniform, glm::mat4 value);
};