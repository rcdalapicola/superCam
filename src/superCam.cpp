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
    vertexesBuffer.data(vertexesElements * sizeof(float), vertexes);

    IndexBuffer indexesBuffer;
    indexesBuffer.data(indexesElements * sizeof(float), indexes);

    Shader shader(VertexShaderPath::BASIC, FragmentShaderPath::FRACTAL);
    shader.bind();
    
    auto resolution = shader.bindVariable("u_Resolution");
    shader.uniform2f(resolution, static_cast<float>(windowWidth), static_cast<float>(windowHeight));

    auto color = shader.bindVariable("u_Color");

    float r = 0.0f;
    static const float increment = 0.01f;
    float step = increment;
    /* Loop until the user closes the window */
    while (context.isWindowOpen())
    {
        /* Render here */
        context.clear();

        shader.uniform1f(color, r);
        context.render(6);
    
        r += step;

        context.process();
    }
    
    auto* pixels = context.getImage();

    return pixels;
}

void sc::process(unsigned int image, int rows, int columns, int channels) {
    
}