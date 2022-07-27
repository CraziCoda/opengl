#pragma once
#include "glad/glad.h"
#include "stb_image/stb_image.h"
#include <iostream>

class Texture {
private:
	unsigned int m_ID;
	int m_Width, m_Height, m_NrChannel;
	unsigned char* m_LocalBuffer;
	const char* m_Filepath;
public:
	Texture(const char* filepath);
	~Texture();

	void use();
	void set_parameter_i(GLuint pname, GLuint param);
	void set_slot(unsigned int slot);
};