#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Buffer {
    protected:
        unsigned int id;
        const GLenum arrayType;
        Buffer(GLenum p_arrayType);

    public:
        Buffer();

        // virtual ~Buffer();

        void bind();

        void data(size_t size, const void* data);
};

class IndexBuffer : public Buffer {
    public:
        IndexBuffer();
};

#endif //SHADER_H
