#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

#include "MSList.h"
#include "star.hpp"

//-----------------------------------------------------------
//과제물
// 1. 이클래스 숙지하고 프로젝트를 생성하시오
// 완료
// 
// 2. #include <vector>    대신에 #include "MSList.h" 를 만드시오. (MSList.h, MSList.cpp)
//    ( Musoen(무소은엔진용) Struct(자료구조) List(리스트) )
//    ( vector는 절대 쓰지 마시오)]
// 완료- MSList.h 생성함
// 
// 3. MSList 헤더파일 참조해서 cpp 만들것.
// 완료- MSList.cpp 생성함
// 
// 4. cpp파일에 함수 구현 내용을 작성하시오. ( ObjectTest처럼 )
// 완료- 각각 TestMObject, TestMSList 클래스에 구현 내용 적어둠
// 
// 5. 게임에 5주차 과제였던 별을 손톱크기로 조그맣게 그릴 수 있도록 star.hpp의 크리스탈 수정.
// 완료- star.hpp 수정됨
// 
// 6. 랜덤하게 화면에 위치와 색을 바꿔가며 별 300 개를 그릴 수 있도록 작성하시오.
//    (List에 모든 Star객체들을 담아주세요)
//    (화면에 알록달록한 별이 가득하게 random 이라는 stl을 사용해서 만들어주세요.)
// 완료- random 리스트 선언함, 작동 확인

using namespace std;

int main(void)
{
	MSList random;							//MSList random 선언
	HeadNode* randomHeadNode;				//포인터 randomHeadNode 선언

	randomHeadNode = random.createList();	//randomHeadNode가 리스트 random의 HeadNode 주소를 가짐

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

	//Star 객체를 생성하는 부분
	MObject* temp[300];
	for (int i = 0; i < 300; i++)
	{
		temp[i] = new Star();						//Star 생성자 300번 돌려서
		random.pushBack(randomHeadNode,temp[i]);	//리스트 random에 집어넣기
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		//배경색 지정
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Star에 있는 render()함수
		for (int i = 0; i<300; i++)
		{
			temp[i]->render();
		}

		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;

}