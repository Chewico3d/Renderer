#pragma once
#include "Renderer.h"

class VertexBuffer
{
private :
	unsigned int m_Renderer;
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind();
	void Unbind();

};
