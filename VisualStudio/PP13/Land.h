#pragma once
#pragma comment(lib, "opengl32.lib")
#include <GLFW/glfw3.h>

class Land 
{
public:
    Land(){}
    void RenderLand(float landX, float landY, float landXscale, float landYscale)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);

        glVertex2f(landX - landXscale, landY + landYscale);
        glVertex2f(landX + landXscale, landY + landYscale);
        glVertex2f(landX + landXscale, landY - landYscale);
        glVertex2f(landX - landXscale, landY - landYscale);

        glEnd();
    }
    ~Land() 
    {
    };
};

