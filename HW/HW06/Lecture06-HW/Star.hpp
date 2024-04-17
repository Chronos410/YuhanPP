#include "MObject.h"
#include <GLFW/glfw3.h>
#include <random>

class Star : public MObject
{
    float x = 0;
    float y = 0;
    float red, green, blue = 0;

public: 
    Star()          //Star()�� ��ü�� ������ ������ ����Ǵ� "������"
    {          
        std::random_device rd;

        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dis(-1.0f, 1.0f);

        std::mt19937 colorgen(rd());
        std::uniform_real_distribution<float> colordis(0.0f, 1.0f);
        //�������� �̾Ƴ��� �Լ�

        x = dis(gen);
        y = dis(gen);
        red = colordis(colorgen);
        green = colordis(colorgen);
        blue = colordis(colorgen);
        //������ Star ��ü�� ������ ��ġ, ���� ���� �������� �Է�
    }
	void render()   //�� �׸��� �Լ�, 5���� ������ ������ ����. �׾� ���������ϱ�
	{
        float scaleFactor = 0.5f;       //���� ����� ���̴µ� ��Ȱ���ߴ�.
        float xFactor = x;
        float yFactor = y;              //���� ��ġ�� ����
        
        glBegin(GL_TRIANGLES);
        glColor3f(red, green, blue);    //���� ���� ����

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