#include "Header/IndexBuffer.h"

IndexBuffer::IndexBuffer(const void* data, unsigned int count) : m_Count(count)
{
    glGenBuffers(1, &m_Renderer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Renderer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_DYNAMIC_DRAW);

}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_Renderer);

}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Renderer);

}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
