#pragma once
#include "Renderer.h"

struct VertexBufferElement {
	unsigned int Type;
	unsigned int Count;
	bool Normalized;

};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;

public:
	VertexBufferLayout();

	template<typename T>
	void Push(unsigned int count) {
		static_assert(false);

	}

	template<>
	void Push<float>(unsigned int count) {

		m_Elements.push_back({ GL_FLOAT, count, false });
		m_Stride += sizeof(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned int>(unsigned int count) {

		m_Elements.push_back({ GL_UNSIGNED_INT, count, false });
		m_Stride += sizeof(GL_BYTE);

	}

	inline std::vector<VertexBufferElement> GetElements() const& { return m_Elements; }
	inline unsigned int GetStride() const& { return m_Stride; }


};

