#include "Bird.h"
#include <iostream>
#define PI 3.141592f
#include <GLFW/glfw3.h>

float Bird_x = 0.4f;
float Bird_y = 0.4f;
float size = 0.1f;
int seg = 50;

Bird::Bird()
{

}

Bird::~Bird() 
{

}

void Bird::render() 
{
    glColor3f(1.0f, 0.851f, 0.4f);           //FFD966
    glBegin(GL_POLYGON);
    for (int i = 0; i < seg; i++)
    {
        float theta = 2.0f * PI * float(i) / float(seg);

        glVertex2f(Bird_x + size * cosf(theta) - size * sinf(theta), Bird_y + size * sinf(theta) + size * cos(theta));
    }
    glEnd();

    Bird_x = Bird_x - (0.2f / 60.0f);   //(x미터 / 초당)
}

void Bird::goback() 
{
    Bird_x = 1.2f;
}

float Bird::getX() {
    return Bird_x;
}