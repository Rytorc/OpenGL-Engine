#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader 
{
    public:
        Shader();
        unsigned int *GetShaderProgram();

    private:
        unsigned int m_shaderProgram;
};

#endif