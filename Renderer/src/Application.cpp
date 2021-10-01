#include "Renderer.h"

int main(void)
{

    if (!InitRenderer(860, 860, "Fuck"))
        return 0;

    float* Verices = new float[8]{
        -.5f,  .5f,
         .5f,  .5f,
        -.5f, -.5f,
         .5f, -.5f

    };

    unsigned int* Indexs = new unsigned int[6]{
        0,1,2,
        2,1,3

    };

    unsigned int BufferID = Create2fBuffer(Verices, 8);
    unsigned int IndexID = CreateIndexBuffer(Indexs, 6);
    unsigned int ProgramID = CreateProgram("Others/Shaders/SimpleShader.shader");

    SetUniform4f("u_Color", ProgramID, 1, .4f, .3f);
    /* Loop until the user closes the window */

    float Val = 0;
    float Increment = 0.02f;
    while (Itirenate(0, 3)) {
        if (Val > 1 || Val < 0)
            Increment *= -1;

        Val += Increment;
        SetUniform4f("u_Color", ProgramID, Val, .4f, 0);

    }


    glfwTerminate();
    return 0;
}