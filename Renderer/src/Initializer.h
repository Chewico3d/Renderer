#pragma once

GLFWwindow* window;

bool InitRenderer(int PixelX, int PixelY, const char* Name) {

    
    /* Initialize the library */
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(PixelX, PixelY, Name, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
        return false;


    glfwSwapInterval(1);

    return true;

}