#pragma comment(lib, "opengl32.lib")    //프로젝트 추가 종속성에 lib 추가
#include <iostream>
#include <GLFW/glfw3.h>

float red = 0.0f;
float green = 0.0f;
float blue = 0.0f;
float alpha = 1.0f;
bool isdrag = false;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        red = 1.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        red = 0.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) 
    {
        red = 0.0f; green = 1.0f; blue = 0.0f; alpha = 1.0f;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        red = 0.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
    }
}


void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        return;
    }
    double x;
    double y;
    glfwGetCursorPos(window, &x, &y);
}

int main(void)
{

    

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Lecture04_HW", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwSetMouseButtonCallback(window, mouse_button_callback);  //버튼 콜백

        glfwSetCursorPosCallback(window, mouse_cursor_callback);    //커서 콜백 제발 이게 뭐에요

        glClearColor(red, green, blue, alpha);  //색 지정

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}