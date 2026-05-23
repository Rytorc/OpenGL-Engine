#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Shader/Shader.h"

class Window 
{
    public:
        Window(int initWidth, int initHeight);

    private:
        bool CreateWindow();
        void processInput(GLFWwindow *window);

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);
        };

    private:
        int width = 800;
        int height = 600;
        Shader* m_Shader;
};

#endif