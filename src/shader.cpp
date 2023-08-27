#include "shader.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

static std::string buildShaderSourcePath(const char* shaderName) {
    static const std::string DIR = "C:/Users/rodol/vscodeProjects/cppImage/res/shaders/";
    const std::string path = DIR + std::string(shaderName) + ".shader";
    return path;
};

const std::string FragmentShaderPath::CIRCLE  = buildShaderSourcePath("fragmentCircle");
const std::string FragmentShaderPath::FRACTAL = buildShaderSourcePath("fragmentFractal");
const std::string FragmentShaderPath::HEART   = buildShaderSourcePath("fragmentHeart");
const std::string VertexShaderPath::BASIC  = buildShaderSourcePath("vertexBasic");


Shader::Shader(const std::string& vsPath, const std::string& fsPath) {
    m_program = createShader(vsPath, fsPath);
};

Shader::~Shader() {
    glDeleteProgram(m_program);
}

void Shader::bind() {
    glUseProgram(m_program);
}

void Shader::unbind() {
    glUseProgram(0);
}

unsigned int Shader::createShader(const std::string& p_vertexShaderPath, const std::string& p_fragmentShaderPath) {
    std::string vertexShaderString   = loadShader(p_vertexShaderPath);
    std::string fragmentShaderString = loadShader(p_fragmentShaderPath);

    unsigned int program = glCreateProgram();
    unsigned int compiledVertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderString);
    unsigned int compiledFragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderString);

    glAttachShader(program, compiledVertexShader);
    glAttachShader(program, compiledFragmentShader);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(compiledVertexShader);
    glDeleteShader(compiledFragmentShader);

    GLint fragCoordLocation = glGetUniformLocation(program, "FragCoord");
    glUniform2f(fragCoordLocation, 0.0f, 0.0f); // Set actual fragment coordinates

    GLint resolutionLocation = glGetUniformLocation(program, "resolution");
    glUniform2f(resolutionLocation, 800.0f, 600.0f); // Set actual resolution

    return program;
};

std::string Shader::loadShader(const std::string& shaderSourcePath) {
    std::ifstream shaderReader;
    std::stringstream shaderStream;

    shaderReader.open(shaderSourcePath);
    shaderStream << shaderReader.rdbuf();
    return shaderStream.str();
};


int Shader::compileShader(unsigned int type, const std::string& source) {
    int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        //TODO: Handle error!
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
    }

    return id;
};

int Shader::bindVariable(const char* varName) {
    return glGetUniformLocation(m_program, varName);
}

void Shader::uniform1f(int variable, float f1) {
    glUniform1f(variable, f1);
}

void Shader::uniform2f(int variable, float f1, float f2) {
    glUniform2f(variable, f1, f2);
}
