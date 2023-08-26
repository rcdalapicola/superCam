#include "glfwContext.h"

#include <iostream>


glfwContext::glfwContext() {
    if (!glfwInit()) {
        //TODO: Handle error
        std::cout << "GLFW could not be initialized./n";
    }
};

glfwContext::~glfwContext() {
    glfwTerminate();
};

void glfwContext::newWindow(int width, int height, const char* name) {
    window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        //TODO: Handle error
        std::cout << "GLFW window could not be create./n";
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "GLEW NOT INITIALIZED!\n";
    }
};

void glfwContext::setSwapInterval(int interval) {
    glfwSwapInterval(interval);
};

bool glfwContext::isWindowOpen() {
    return !glfwWindowShouldClose(window);
}

void glfwContext::process() {
    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    
    /* Poll for and process events */
    glfwPollEvents();
}