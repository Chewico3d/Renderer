#include "Header/VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_Renderer);
    glBindBuffer(GL_ARRAY_BUFFER, m_Renderer);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);

}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_Renderer);

}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Renderer);

}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}
