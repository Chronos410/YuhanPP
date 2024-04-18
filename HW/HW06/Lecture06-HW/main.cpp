#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <list>				//stl 리스트를 사용하는 다른 방법
#include "Star.hpp"

//-----------------------------------------------------------
//과제물
// 1. 이클래스 숙지하고 프로젝트를 생성하시오
// 2. #include <vector>    대신에 #include "MSList.h" 를 만드시오. (MSList.h, MSList.cpp)
//    ( Musoen(무소은엔진용) Struct(자료구조) List(리스트) )
//    ( vector는 절대 쓰지 마시오)
// 3. MSList 헤더파일 참조해서 cpp 만들것.
// 4. cpp파일에 함수 구현 내용을 작성하시오. ( ObjectTest처럼 )
// 
// 5. 게임에 5주차 과제였던 별을 손톱크기로 조그맣게 그릴 수 있도록 star.hpp의 크리스탈 수정.
// 6. 랜덤하게 화면에 위치와 색을 바꿔가며 별 300 개를 그릴 수 있도록 작성하시오.
//    (List에 모든 Star객체들을 담아주세요)
//    (화면에 알록달록한 별이 가득하게 random 이라는 stl을 사용해서 만들어주세요.)

using namespace std;		//와! 귀찮음 해결!

list<MObject*> starList;	//일단 잘 만들어져있는 std::list로 가동실험
							//근데 어짜피 내가 그 리스트를 만들어야 되잖아? 안될꺼야 아마

int init() {

	MObject* temp[300];

	for (int i = 0; i < 300; i++) 
	{
		temp[i] = new Star();
		starList.push_back(temp[i]);
	}

	return 0;
}

int rendermain()
{
	glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto i = starList.begin(); i != starList.end(); ++i)
	{
		MObject* a = *i;
		a->render();
	}
	return 0;
}

int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "Lecture06-HW", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	init();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		rendermain();

		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;

}