#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <list>				//stl ����Ʈ�� ����ϴ� �ٸ� ���
#include "Star.hpp"

//-----------------------------------------------------------
//������
// 1. ��Ŭ���� �����ϰ� ������Ʈ�� �����Ͻÿ�
// 2. #include <vector>    ��ſ� #include "MSList.h" �� ����ÿ�. (MSList.h, MSList.cpp)
//    ( Musoen(������������) Struct(�ڷᱸ��) List(����Ʈ) )
//    ( vector�� ���� ���� ���ÿ�)
// 3. MSList ������� �����ؼ� cpp �����.
// 4. cpp���Ͽ� �Լ� ���� ������ �ۼ��Ͻÿ�. ( ObjectTestó�� )
// 
// 5. ���ӿ� 5���� �������� ���� ����ũ��� ���׸İ� �׸� �� �ֵ��� star.hpp�� ũ����Ż ����.
// 6. �����ϰ� ȭ�鿡 ��ġ�� ���� �ٲ㰡�� �� 300 ���� �׸� �� �ֵ��� �ۼ��Ͻÿ�.
//    (List�� ��� Star��ü���� ����ּ���)
//    (ȭ�鿡 �˷ϴ޷��� ���� �����ϰ� random �̶�� stl�� ����ؼ� ������ּ���.)

using namespace std;		//��! ������ �ذ�!

list<MObject*> starList;	//�ϴ� �� ��������ִ� std::list�� ��������
							//�ٵ� ��¥�� ���� �� ����Ʈ�� ������ ���ݾ�? �ȵɲ��� �Ƹ�

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
	//glfw���̺귯�� �ʱ�ȭ
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