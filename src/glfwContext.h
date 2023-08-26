#ifndef GLFWCONTEXT_H
#define GLFWCONTEXT_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class glfwContext final{
    private:
        GLFWwindow* window;

    public:
        glfwContext();
        ~glfwContext();
        void newWindow(int width, int height, const char* name = "New Window");
        void setSwapInterval(int interval);
        bool isWindowOpen();
        void process();
};

#endif // GLFWCONTEXT_H