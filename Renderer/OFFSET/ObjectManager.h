#pragma once

unsigned int CreateVAO() {
    unsigned int VAO;
    glCreateVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    return VAO;
}

unsigned int Create2fBuffer(float* Vertices, int Lenght) {

    unsigned int BufferID;
    glCreateBuffers(1, &BufferID);
    glBindBuffer(GL_ARRAY_BUFFER, BufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Lenght, Vertices, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    return BufferID;

}

unsigned int CreateIndexBuffer(unsigned int* Index, int Lenght) {

    unsigned int BufferID;
    glCreateBuffers(1, &BufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Lenght, Index, GL_DYNAMIC_DRAW);

    return BufferID;

}