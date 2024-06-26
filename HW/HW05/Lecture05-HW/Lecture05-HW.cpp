#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법

#include <iostream>
#include <GLFW/glfw3.h>

double xNow, yNow = 0.0;        //현재 마우스 위치
double x, y = 0.0;              //클릭할 때 저장되는 위치
float moon_x, moon_y = 0.0;   //실질적으로 이동하는 수치
float moon_scale = 1.0f;       //사이즈 변경 수치
bool leftc, rightc = false;     //좌,우 클릭에 따라 on off

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if ((button == GLFW_MOUSE_BUTTON_LEFT) && action == GLFW_PRESS)
    {
        glfwGetCursorPos(window, &x, &y);
        leftc = true;

    }
    else if ((button == GLFW_MOUSE_BUTTON_RIGHT) && action == GLFW_PRESS)
    {
        glfwGetCursorPos(window, &x, &y);
        rightc = true;
    }
    else {
        leftc = false;
        rightc = false;
    }
}

int renderStar() {

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f((-0.6f * scaleFactor) + xFactor, (0.4f * scaleFactor) + yFactor);
    glVertex2f((0.6f * scaleFactor) + xFactor, (0.4f * scaleFactor) + yFactor);
    glVertex2f((0.0f * scaleFactor) + xFactor, (-0.4f * scaleFactor) + yFactor);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f((-0.2f * scaleFactor) + xFactor, (-0.2f * scaleFactor) + yFactor);
    glVertex2f((0.0f * scaleFactor) + xFactor, (1.0f * scaleFactor) + yFactor);
    glVertex2f((0.4f * scaleFactor) + xFactor, (-0.8f * scaleFactor) + yFactor);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f((-0.4f * moon_scale) + moon_x, (-0.8f * moon_scale) + moon_y);
    glVertex2f((0.0f * moon_scale) + moon_x, (1.0f * moon_scale) + moon_y);
    glVertex2f((0.2f * moon_scale) + moon_x, (-0.2f * moon_scale) + moon_y);

    glEnd();

    return 0;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 768, "Lecture05-HW", NULL, NULL);
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

        glfwSetMouseButtonCallback(window, mouse_button_callback);

        glfwGetCursorPos(window, &xNow, &yNow);

        if (leftc)
        {
            xFactor = (xNow - x) * 0.002;
            yFactor = (y - yNow) * 0.002;
        }
        if (rightc)
        {
            scaleFactor = 1 + (xNow - x) * 0.001;
        }

        /* Render here */
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear 할 색
        glClear(GL_COLOR_BUFFER_BIT);

        renderStar();

        /* Swap front and back buffers */

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}