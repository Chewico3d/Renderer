#pragma once

bool Itirenate(int StartIndex, int Count, unsigned int vao, unsigned int ibo) {

    bool state = glfwWindowShouldClose(window);

    if (state)
        return false;

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();

    return true;

}