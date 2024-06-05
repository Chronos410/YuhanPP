#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법
#include <iostream>
#include <GLFW/glfw3.h>
#include <chrono>

float playerX = -0.5f;
float playerY = -0.5f;
float playerX_velocity = 0.0f;
float playerY_velocity = 0.0f;
float playerSize = 0.1f;
float playerScale = playerSize / 2.0f;

float landX = 0.0f;
float landXsize = 2.0f;
float landXscale = landXsize / 2.0f;
float landY = -0.9f;
float landYsize = 0.2f;
float landYscale = landYsize / 2.0f;

float gravity = (9.8f * 0.1f) / (60.0f);

//디버그목적
int ss;
float lowVelocity = 0.0f;

void errorCallback(int error, const char* description) {
    std::cerr << "코드" << error << description;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc가 && 눌리면
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        playerY_velocity = playerY_velocity + 0.1f;
    }
}

void render_Land()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(landX - landXscale, landY + landYscale);
    glVertex2f(landX + landXscale, landY + landYscale);
    glVertex2f(landX + landXscale, landY - landYscale);
    glVertex2f(landX - landXscale, landY - landYscale);

    glEnd();
}
void render_Player()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(playerX - playerScale, playerY + playerScale);
    glVertex2f(playerX + playerScale, playerY + playerScale);
    glVertex2f(playerX + playerScale, playerY - playerScale);
    glVertex2f(playerX - playerScale, playerY - playerScale);

    glEnd();
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Lecture14", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, key_callback);

    glfwSwapInterval(1);//프레임을 모니터 주사율에 맞춤 => 지금은 60fps

    auto startTime = std::chrono::system_clock::now();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        std::chrono::duration<double>sec = std::chrono::system_clock::now() - startTime;

        glfwPollEvents();
        /* Render here */

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear 할 색
        glClear(GL_COLOR_BUFFER_BIT);

        if ((playerX - playerScale) > (landX - landXscale) && (playerX - playerScale) < (landX + landXscale) || (playerX + playerScale) > (landX - landXscale) && (playerX + playerScale) < (landX + landXscale))
        {
            if ((playerY - playerScale) > (landY - landYscale) && (playerY - playerScale) < (landY + landYscale) || (playerY + playerScale) > (landY - landYscale) && (playerY + playerScale) < (landY + landYscale))
            {
                playerY_velocity = 0.0f;
            }
        }

        playerY_velocity = playerY_velocity - gravity;

        playerX = playerX + playerX_velocity;
        playerY = playerY + playerY_velocity;
        //속도 적용

        if (playerY - playerScale < landY + landYscale)     //땅 뚫고 들어가기 방지
        {
            playerY = landY + landYscale + playerScale;
            playerY_velocity = 0.0f;
        }

        render_Land();
        render_Player();
        //연산 끝나고 렌더

        if (sec.count() > 2 && sec.count() < 3) 
        {
            std::cout << ss << std::endl;
            ss++;
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}