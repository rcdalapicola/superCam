#ifndef BUFFER_H
#define BUFFER_H

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

        void bind();

        void unbind();

        void data(size_t size, const void* data);
};

class IndexBuffer : public Buffer {
    public:
        IndexBuffer();
};

#endif //BUFFER_H
