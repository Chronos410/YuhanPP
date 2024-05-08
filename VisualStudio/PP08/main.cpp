#pragma comment(lib, "opengl32.lib")    //�߰� ���Ӽ� lib �߰� �ϴ� ��
#define PI 3.141592
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

void errorCallback(int error, const char* description) {
    std::cerr << "�ڵ�" << error << description;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc�� && ������
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
int render() {
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f, 0.0f);

    glEnd();
    return 0;
}
int renderStar() {

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.6f, 0.4f);
    glVertex2f(0.6f, 0.4f);
    glVertex2f(0.0f, -0.4f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.4f, -0.8f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.4f, -0.8f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.2f, -0.2f);

    glEnd();

    return 0;
}
float x;
float y;
float ax;
float ay;
int renderline()
{
    ax = x + cos(1 * (PI / 180));
    ay = y + sin(1 * (PI / 180));
    for (int i = 0; i < 360; i++) 
    {
        glBegin(GL_LINE);
        glColor3f(1.0f, 1.0f, 1.0f);
        glLineWidth(1.0f);
        glVertex2f(x, y);
        glVertex2f(ax, ay);
        glEnd();
    }
    x = ax; y = ay;
    return 0;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 768, "GameEngine4", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();


        /* Render here */
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear �� ��
        glClear(GL_COLOR_BUFFER_BIT);
        renderline();

        /* Swap front and back buffers */

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}