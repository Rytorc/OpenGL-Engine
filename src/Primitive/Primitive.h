#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Shader/Shader.h"
#include "../helpers/helpers.h"

class Primitive
{
    public:
        Primitive(
            Shader* shader,  
            float3 position = {0.0f, 0.0f, 0.0f}, 
            float3 rotation = {0.0f, 0.0f, 0.0f}, 
            float3 scale = {1.0f, 1.0f, 1.0f}
        );
        virtual void CreatePrimitive();
        virtual void Render();

    private:
        Shader* m_Shader;
        unsigned int m_VAO = 0;
        unsigned int m_VBO = 0;
        unsigned int m_EBO = 0;
        float3 m_Position = {0.0f, 0.0f, 0.0f};
        float3 m_Rotation = {0.0f, 0.0f, 0.0f};
        float3 m_Scale = {1.0f, 1.0f, 1.0f};
};

#endif