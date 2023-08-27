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
    auto window = glfwCreateWindow(width, height, name, NULL, NULL);
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

    m_window = window;
    m_width = width;
    m_height = height;
};

void glfwContext::setSwapInterval(int interval) {
    glfwSwapInterval(interval);
};

bool glfwContext::isWindowOpen() {
    return !glfwWindowShouldClose(m_window);
}

void glfwContext::process() {
    /* Swap front and back buffers */
    glfwSwapBuffers(m_window);
    
    /* Poll for and process events */
    glfwPollEvents();
}

unsigned char* glfwContext::getImage() {
    unsigned char* pixels = new GLubyte[m_width * m_height * 3];  // RGB format
    glReadPixels(0, 0, m_width, m_height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    return pixels;
}

void glfwContext::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void glfwContext::render(int vertexesToRender) {
    glDrawElements(GL_TRIANGLES, vertexesToRender, GL_UNSIGNED_INT, nullptr);
}
