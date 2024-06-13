#pragma comment(lib, "opengl32.lib")    //�߰� ���Ӽ� lib �߰� �ϴ� ��
#define PI 3.141592f
#include <iostream>
#include <GLFW/glfw3.h>
#include "Bird.h"
#include <chrono>
#include <thread>



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
void renderCircle() {
    //�¾� ��ü
    glColor3f(1.0f, 0.851f, 0.4f);           //FFD966
    glBegin(GL_POLYGON);

    float size = 0.05f; //������
    int seg = 50;       //���׸�Ʈ ��

    for (int i = 0; i < seg; i++)
    {
        float theta = 2.0f * PI * float(i) / float(seg);
        glVertex2f(size * cosf(theta) - size * sinf(theta), size * sinf(theta) + size * cos(theta));        //ȸ�����Ŀ� 0~360�� �����ؼ� ���� ��ǥ�� ������ ��?�� ��´�
    }
    glEnd();

    //�¾� �ܰ��� 
    glColor3f(0.7725f, 0.3529f, 0.0667f);     //C55A11
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < seg; i++)
    {
        float theta = 2.0f * PI * float(i) / float(seg);
        glVertex2f(size * cosf(theta) - size * sinf(theta), size * sinf(theta) + size * cos(theta));
    }
    glEnd();
}

int windowX, windowY = 1000;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "DinoRun1", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, key_callback);

    /* ������ */
    float frame = 1000 / 60;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point prev_end = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::steady_clock::duration runningTime = end - start;
    int delay_ms = 0;
    int running_s = 0;
    int running_ss = 0;

    Bird* bb = new Bird();

    while (!glfwWindowShouldClose(window))
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        prev_end = end;
        end = std::chrono::steady_clock::now();
        std::chrono::steady_clock::duration gap = end - prev_end;
        delay_ms = frame - std::chrono::duration_cast<std::chrono::milliseconds>(gap).count();

        running_ss = running_s;
        runningTime = end - start;
        running_s = std::chrono::duration_cast<std::chrono::seconds>(runningTime).count();

        if (bb->getX() < -1.2f)
        {
            bb->goback();
        }

        bb->render();
        
        glfwPollEvents();

        renderCircle();

        

        glfwSwapBuffers(window);

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear �� ��
        glClear(GL_COLOR_BUFFER_BIT);

        

    }
    delete bb;
    glfwTerminate();
    return 0;
}