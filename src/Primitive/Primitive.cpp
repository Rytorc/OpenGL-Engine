#include "Primitive.h"

Primitive::Primitive(
    Shader* shader, 
    float3 position, 
    float3 rotation, 
    float3 scale
    ): 
    m_Shader(shader),
    m_Position(position), 
    m_Rotation(rotation), 
    m_Scale(scale)
{
    glGenVertexArrays(1, &this->m_VAO);
    glGenBuffers(1, &this->m_VBO);
    glGenBuffers(1, &this->m_EBO);

    glBindVertexArray(this->m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);

    this->CreatePrimitive();
}

void Primitive::CreatePrimitive()
{
    float vertices[] = {
        0.5f, 0.5f, 0.0f, //Top Right
        0.5f, -0.5f, 0.0f,  //Bottom Right
        -0.5f, -0.5f, 0.0f, //Bottom Left
        -0.5f, 0.5f, 0.0f   //Top Left
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Primitive::Render()
{
    glUseProgram(*this->m_Shader->GetShaderProgram());
    glBindVertexArray(this->m_VAO);

    //FOR TESTING
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}