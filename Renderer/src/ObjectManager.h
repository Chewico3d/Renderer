#pragma once

unsigned int Create2fBuffer(float* Vertices, int Lenght) {

    unsigned int BufferID;
    glCreateBuffers(1, &BufferID);
    glBindBuffer(GL_ARRAY_BUFFER, BufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * Lenght, Vertices, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, Vertices);

    return BufferID;

}