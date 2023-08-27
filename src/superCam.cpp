#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "superCam.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// #include <opencv2/opencv.hpp>

#include "buffer.h"
#include "glfwContext.h"
#include "shader.h"

using namespace std;


unsigned char* sc::mainGL(int windowWidth, int windowHeight)
{
    glfwContext context;
    
    context.newWindow(windowWidth, windowHeight);
    context.setSwapInterval(1);

    float vertexes[] = {
        -1.0f, -1.0f,
        1.0f, 1.0f,
        1.0f, -1.0f,
        -1.0f, 1.0f,
    };
    const int vertexesElements = 4 * 2;

    unsigned int indexes[] = {
        0, 1, 2,
        0, 3, 1
    };
    const int indexesElements =6;

    Buffer vertexesBuffer;
    vertexesBuffer.bind();
    vertexesBuffer.data(vertexesElements * sizeof(float), vertexes);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    IndexBuffer indexesBuffer;
    indexesBuffer.bind();
    indexesBuffer.data(indexesElements * sizeof(float), indexes);

    Shader shader(VertexShaderPath::BASIC, FragmentShaderPath::CIRCLE);
    shader.bind();
    
    int location = glGetUniformLocation(shader.m_program, "u_Resolution");
    glUniform2f(location, windowWidth, windowHeight);

    int colorLocation = glGetUniformLocation(shader.m_program, "u_Color");

    float r = 0.0f;
    static const float increment = 0.01f;
    float step = increment;
    /* Loop until the user closes the window */
    while (context.isWindowOpen())
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUniform1f(colorLocation, r);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    
        r += step;

        context.process();
    }
    
    GLubyte* pixels = new GLubyte[windowWidth * windowHeight * 3];  // RGB format
    glReadPixels(0, 0, windowWidth, windowHeight, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    return static_cast<unsigned char*>(pixels);
}

void sc::process(unsigned int image, int rows, int columns, int channels) {
    
}