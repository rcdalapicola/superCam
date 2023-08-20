#include "superCam.h"

#include <algorithm>
#include <iostream>
// #include <opencv2/opencv.hpp>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void sc::test() {
    std::cout << "Testing Supercam!" << std::endl;
}

bool _compareString(const string& str1, const string& str2) {
    return strcmp(str1.c_str(), str2.c_str()) > 0 ? false : true;
}

void sc::sortString(std::vector<std::string>& inputList) {
    auto inputSize = inputList.size();
    // std::string** orderedList = new string*[inputSize];
    cout << "Size: " << inputList.size();
    // orderedList[0] = &inputList[0];
    // for (int inputIndex = 1; inputIndex < inputSize; ++inputIndex) {
    //     int orderedIndex = 0;
    //     for (; orderedIndex < inputIndex; ++orderedIndex) {

    //     }
    // }

    sort(inputList.begin(), inputList.end(), _compareString);
}

void sc::printStrings(const std::vector<std::string>& inputList) {
    cout << "String list: ";
    for (const string& str: inputList) {
        cout << str << "; ";
    }
    cout << endl;
}

static int compileShader(unsigned int type, const string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        cout << "Failed to compile!" << endl;
        cout << message << endl;
        glDeleteShader(id);
    }

    return id;
}

static int createShader(const string& vertexShader, const string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int sc::mainGL(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        cout << "GLEW NOT INITIALIZED!" << endl;
    }

    float positions[] = {
        -0.5f, -0.5f,
        0, 0.5f,
        0.5f, -0.5f
    };

    unsigned int buffId;
    glGenBuffers(1, &buffId);
    glBindBuffer(GL_ARRAY_BUFFER, buffId);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    string vertexShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";
    string fragmentShader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "\n"
        "void main() {\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

    int shader = createShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void sc::process(unsigned int image, int rows, int columns, int channels) {
    
}