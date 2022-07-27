#include "Texture.h"


Texture::Texture(const char* filepath)
     :m_ID(0), m_Width(0), m_Height(0), m_NrChannel(0), m_LocalBuffer(nullptr),  m_Filepath(filepath)
{
    stbi_set_flip_vertically_on_load(true);
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &m_ID);
    glBindTexture(GL_TEXTURE_2D, m_ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    m_LocalBuffer = stbi_load(m_Filepath, &m_Width, &m_Height,
        &m_NrChannel, 4);

    if (m_LocalBuffer)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA,
            GL_UNSIGNED_BYTE, m_LocalBuffer);
       glGenerateMipmap(GL_TEXTURE_2D);

       stbi_image_free(m_LocalBuffer);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }


    
    
}

void Texture::set_slot(unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_ID);
}

void Texture::use()
{
    glBindTexture(GL_TEXTURE_2D, m_ID);
}

