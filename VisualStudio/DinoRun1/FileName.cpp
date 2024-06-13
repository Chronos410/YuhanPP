#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법
#define PI 3.141592f
#include <iostream>
#include <GLFW/glfw3.h>
#include "Bird.h"
#include <chrono>
#include <thread>



void errorCallback(int error, const char* description) {
    std::cerr << "코드" << error << description;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc가 && 눌리면
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
void renderCircle() {
    //태양 본체
    glColor3f(1.0f, 0.851f, 0.4f);           //FFD966
    glBegin(GL_POLYGON);

    float size = 0.05f; //반지름
    int seg = 50;       //세그먼트 수

    for (int i = 0; i < seg; i++)
    {
        float theta = 2.0f * PI * float(i) / float(seg);
        glVertex2f(size * cosf(theta) - size * sinf(theta), size * sinf(theta) + size * cos(theta));        //회전공식에 0~360을 대입해서 나온 좌표에 폴리곤 점?을 찍는다
    }
    glEnd();

    //태양 외곽선 
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

    /* 프레임 */
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

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear 할 색
        glClear(GL_COLOR_BUFFER_BIT);

        

    }
    delete bb;
    glfwTerminate();
    return 0;
}