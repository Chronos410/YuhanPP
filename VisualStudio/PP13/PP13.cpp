#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법
#include <iostream>
#include <GLFW/glfw3.h>
#include "Land.h"
#include "Player.h"

float playerX = -0.5f;
float playerY = -0.5f;
float playerX_velocity = 0.0f;
float playerY_velocity = 0.0f;
float playerScale = 0.05f;

float landX = 0.0f;
float landXscale = 1.0f;
float landY = -0.9f;
float landYscale = 0.1f;

float gravity = 0.00098f;

bool isLanded = false;

void errorCallback(int error, const char* description) {
    std::cerr << "코드" << error << description;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc가 && 눌리면
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && isLanded) 
    {
        playerY_velocity = 0.02f;
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
    window = glfwCreateWindow(1000, 1000, "GameEngine4", NULL, NULL);
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

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear 할 색
        glClear(GL_COLOR_BUFFER_BIT);

        playerX = playerX + playerX_velocity;
        playerY = playerY + playerY_velocity;
        playerY_velocity = playerY_velocity - gravity;

        if (playerY - playerScale < landY + landYscale)     //땅 뚫고 들어가기 방지
        {
            playerY = landY + landYscale + playerScale;
            playerY_velocity = 0.0f;
        }

        //render_Land();
        //render_Player();
        Land land1;
        land1.RenderLand(landX, landY, landXscale, landYscale);
        Player(playerX, playerY, playerScale, playerX_velocity, playerY_velocity);
        

        if ((playerX - playerScale) > (landX - landXscale) && (playerX - playerScale) < (landX + landXscale) || (playerX + playerScale) > (landX - landXscale) && (playerX + playerScale) < (landX + landXscale))
        {
            if ((playerY - playerScale) > (landY - landYscale) && (playerY - playerScale) < (landY + landYscale) || (playerY + playerScale) > (landY - landYscale) && (playerY + playerScale) < (landY + landYscale))
            {
                isLanded = true;
                playerY_velocity = 0.0f;
            }
            else
            {
                isLanded = false;
            }
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}