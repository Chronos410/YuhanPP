#include "MObject.h"
#include <GLFW/glfw3.h>
#include <random>

class Star : public MObject
{
    float x = 0;
    float y = 0;
    float red, green, blue = 0;

public: 
    Star()          //Star()로 객체가 생성될 때마다 실행되는 "생성자"
    {          
        std::random_device rd;

        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

        std::mt19937 colorgen(rd());
        std::uniform_real_distribution<float> colordis(0.0f, 1.0f);
        //랜덤값을 뽑아내는 함수

        x = dis(gen);
        y = dis(gen);
        red = colordis(colorgen);
        green = colordis(colorgen);
        blue = colordis(colorgen);
        //각각의 Star 객체가 가지는 위치, 색상 값을 랜덤으로 입력
    }
	void render()   //별 그리는 함수, 5주차 과제와 동일한 구조. 그야 복붙했으니까
	{
        float scaleFactor = 0.5f;       //조금 사이즈를 줄이는데 재활용했다.
        float xFactor = x;
        float yFactor = y;              //랜덤 위치값 적용
        
        glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);    //랜덤 색상값 적용

        glVertex2f((-0.6f * scaleFactor) + xFactor, (0.4f * scaleFactor) + yFactor);
        glVertex2f((0.6f * scaleFactor) + xFactor, (0.4f * scaleFactor) + yFactor);
        glVertex2f((0.0f * scaleFactor) + xFactor, (-0.4f * scaleFactor) + yFactor);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);

        glVertex2f((-0.2f * scaleFactor) + xFactor, (-0.2f * scaleFactor) + yFactor);
        glVertex2f((0.0f * scaleFactor) + xFactor, (1.0f * scaleFactor) + yFactor);
        glVertex2f((0.4f * scaleFactor) + xFactor, (-0.8f * scaleFactor) + yFactor);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);

        glVertex2f((-0.4f * scaleFactor) + xFactor, (-0.8f * scaleFactor) + yFactor);
        glVertex2f((0.0f * scaleFactor) + xFactor, (1.0f * scaleFactor) + yFactor);
        glVertex2f((0.2f * scaleFactor) + xFactor, (-0.2f * scaleFactor) + yFactor);

        glEnd();
	}
};