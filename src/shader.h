#ifndef SHADER_H
#define SHADER_H

#include <string>


enum class FragmentShaderSource {CIRCLE, FRACTAL, HEART};
enum class VertexShaderSource {BASIC};

class FragmentShaderPath {
    public:
        static const std::string CIRCLE;
        static const std::string FRACTAL;
        static const std::string HEART;
};

class VertexShaderPath {
    public:
        static const std::string BASIC;
};

class Shader {
    private:

        static int compileShader(unsigned int type, const std::string& source);
        static unsigned int createShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        static std::string Shader::loadShader(const std::string& shaderSourcePath);
    public:
        unsigned int m_program;
        Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
        ~Shader();
        void bind();
        void unbind();
        int bindVariable(const char* varName);
        void uniform1f(int variable, float f1);
        void uniform2f(int variable, float f1, float f2);

};

#endif // SHADER_H