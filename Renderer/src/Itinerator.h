#pragma once

bool Itirenate(int StartIndex, int Count) {

    bool state = glfwWindowShouldClose(window);

    if (state)
        return false;

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, StartIndex, Count);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();

    return true;

}