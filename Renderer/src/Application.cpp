#include "Classes/Header/IndexBuffer.h"
#include "Classes/Header/VertexBuffer.h"
#include "Initializer.h"

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

    {

        VertexBuffer VB(Verices, 4 * 2 * sizeof(float));
        IndexBuffer IB(Indexs, 6);
        IB.Bind();

        float Val = 0;
        float Increment = 0.02f;


    }

    glfwTerminate();
    return 0;
}