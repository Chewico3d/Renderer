#include "Renderer.h"

int main(void)
{

    if (!InitRenderer(860, 860, "Fuck"))
        return 0;

    float* Verices = new float[6]{
        -.5f, -.5f,
        0, .5f,
        .5f, -.5f

    };

    unsigned int* BufferID = Create2fBuffer(Verices, 6);
    
    /* Loop until the user closes the window */
    while (Itirenate(0,3));

    glfwTerminate();
    return 0;
}