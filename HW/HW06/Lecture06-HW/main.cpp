#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

#include "MSList.h"
#include "star.hpp"

//-----------------------------------------------------------
//������
// 1. ��Ŭ���� �����ϰ� ������Ʈ�� �����Ͻÿ�
// �Ϸ�
// 
// 2. #include <vector>    ��ſ� #include "MSList.h" �� ����ÿ�. (MSList.h, MSList.cpp)
//    ( Musoen(������������) Struct(�ڷᱸ��) List(����Ʈ) )
//    ( vector�� ���� ���� ���ÿ�)]
// �Ϸ�- MSList.h ������
// 
// 3. MSList ������� �����ؼ� cpp �����.
// �Ϸ�- MSList.cpp ������
// 
// 4. cpp���Ͽ� �Լ� ���� ������ �ۼ��Ͻÿ�. ( ObjectTestó�� )
// �Ϸ�- ���� TestMObject, TestMSList Ŭ������ ���� ���� �����
// 
// 5. ���ӿ� 5���� �������� ���� ����ũ��� ���׸İ� �׸� �� �ֵ��� star.hpp�� ũ����Ż ����.
// �Ϸ�- star.hpp ������
// 
// 6. �����ϰ� ȭ�鿡 ��ġ�� ���� �ٲ㰡�� �� 300 ���� �׸� �� �ֵ��� �ۼ��Ͻÿ�.
//    (List�� ��� Star��ü���� ����ּ���)
//    (ȭ�鿡 �˷ϴ޷��� ���� �����ϰ� random �̶�� stl�� ����ؼ� ������ּ���.)
// �Ϸ�- random ����Ʈ ������, �۵� Ȯ��

using namespace std;

int main(void)
{
	MSList random;							//MSList random ����
	HeadNode* randomHeadNode;				//������ randomHeadNode ����

	randomHeadNode = random.createList();	//randomHeadNode�� ����Ʈ random�� HeadNode �ּҸ� ����

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

	//Star ��ü�� �����ϴ� �κ�
	MObject* temp[300];
	for (int i = 0; i < 300; i++)
	{
		temp[i] = new Star();						//Star ������ 300�� ������
		random.pushBack(randomHeadNode,temp[i]);	//����Ʈ random�� ����ֱ�
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		//���� ����
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Star�� �ִ� render()�Լ�
		for (int i = 0; i<300; i++)
		{
			temp[i]->render();
		}

		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;

}