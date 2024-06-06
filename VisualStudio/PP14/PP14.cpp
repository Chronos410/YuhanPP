#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법
#include <iostream>
#include <GLFW/glfw3.h>
#include <chrono>
#include <thread>
#include<time.h>

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

bool isLanded = false;

const int TARGET_FPS = 60;
const double TARGET_FRAME_TIME = 1.0 / TARGET_FPS;

//디버그목적
int ff=0;
std::chrono::duration<double> ss;


void tryJump()
{
    if (isLanded)
    {
        isLanded = false;
        playerY_velocity = playerY_velocity + 0.6f;
    }
}

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
        //playerY_velocity = playerY_velocity + 0.6f;
        tryJump();
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

    auto st = std::chrono::steady_clock::now();

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

    glfwSwapInterval(0);//프레임을 모니터 주사율에 맞춤 => 끄기

    auto startTime = std::chrono::steady_clock::now();
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        auto frameStartTime = std::chrono::steady_clock::now();

        glfwPollEvents();
        /* Render here */

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear 할 색
        glClear(GL_COLOR_BUFFER_BIT);


        if ((playerX - playerScale) > (landX - landXscale) && (playerX - playerScale) < (landX + landXscale) || (playerX + playerScale) > (landX - landXscale) && (playerX + playerScale) < (landX + landXscale))
        {
            if ((playerY - playerScale) > (landY - landYscale) && (playerY - playerScale) < (landY + landYscale) || (playerY + playerScale) > (landY - landYscale) && (playerY + playerScale) < (landY + landYscale))
            {
                playerY_velocity = 0.0f;
                isLanded = true;
            }
        }//충돌체크


        playerY_velocity = playerY_velocity - gravity;
        //플레이어 Y 속도에 중력 적용

        playerX = playerX + playerX_velocity/TARGET_FPS;
        playerY = playerY + playerY_velocity/TARGET_FPS;
        //플레이어 위치에 속도 적용

        if (playerY - playerScale < landY + landYscale)     //땅 뚫고 들어가기 방지
        {
            playerY = landY + landYscale + playerScale;
            playerY_velocity = 0.0f;
            isLanded = true;
        }

        render_Land();
        render_Player();
        //연산 끝나고 렌더

        


        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        auto frameEndTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = frameEndTime - frameStartTime;

        // 목표 프레임 시간까지 대기
        double sleepTime = TARGET_FRAME_TIME - elapsedTime.count();
        if (sleepTime > 0) {
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
        }
        std::chrono::duration<double> ss = std::chrono::steady_clock::now() - st;
        if (ss.count() > 2.0 && ss.count() < 3.0)
        {
            ff++;

            std::cout << TARGET_FRAME_TIME - elapsedTime.count() << std::endl;
            std::cout << ff << std::endl;
        }

    }

    glfwTerminate();
    return 0;
}