#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"
#include "Transform.h"

Player* player = new Player();
Floor* floorObj = new Floor();
EnemyBlock* lowWall = new EnemyBlock(false, 100.0f);
EnemyBlock* highWall = new EnemyBlock(true, 500.0f);


void errorCallback(int error, const char* description)
{
	printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

int Physics()
{
	player->Update();
	lowWall->Update(false);
	lowWall->GoBack();
	highWall->Update(true);
	highWall->GoBack();
	return 0;
}

int Initialize()
{
	return 0;
}

const int TARGET_FPS = 60;
const double TARGET_FRAME_TIME = 1.0 / TARGET_FPS;
auto startTime = std::chrono::steady_clock::now();
auto frameStartTime = std::chrono::steady_clock::now();
auto frameEndTime = std::chrono::steady_clock::now();
int Update()
{
	frameEndTime = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsedTime = frameEndTime - frameStartTime;

	// 목표 프레임 시간까지 대기
	double sleepTime = TARGET_FRAME_TIME - elapsedTime.count();
	if (sleepTime > 0) {
		std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
	}
	return 0;

}

int Render()
{
	glClearColor(0.0f, 0.1176470588235294f, 0.392156862745098f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	player->Render();
	floorObj->Render();
	lowWall->Render();
	highWall->Render();
	return 0;
}


int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	Initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		Physics();
		Update();
		Render();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}