#pragma once

#include <GLFW/glfw3.h>
#include <random>
struct StarStruct
{
	float x, y = 0;
	float red, green, blue = 0;

	(void*)StarGen() {
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
	}
	(void*)Render() {
        float scaleFactor = 0.4f;       //조금 사이즈를 줄이는데 재활용했다.
        float xFactor = x;
        float yFactor = y;              //랜덤 위치값 적용

        glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);    //랜덤 색상값 적용 이하 동일

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

