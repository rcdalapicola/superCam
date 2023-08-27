#include "buffer.h"


Buffer::Buffer() : arrayType(GL_ARRAY_BUFFER), id(0) {
    glGenBuffers(1, &id);
    bind();
    glEnableVertexAttribArray(0);
};

Buffer::Buffer(GLenum p_arrayType) : arrayType(p_arrayType), id(0) {
    glGenBuffers(1, &id);
    bind();
};

IndexBuffer::IndexBuffer() : Buffer(GL_ELEMENT_ARRAY_BUFFER)
{
};

void Buffer::bind() {
    glBindBuffer(arrayType, id);
};

void Buffer::unbind() {
    glBindBuffer(arrayType, 0);
};

void Buffer::data(size_t size, const void* data) {
    glBufferData(arrayType, size, data, GL_STATIC_DRAW);
};
