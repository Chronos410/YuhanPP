#pragma comment(lib, "opengl32.lib")    //프로젝트 추가 종속성에 lib 추가
#include <iostream>
#include <GLFW/glfw3.h>

double mouseX;          //클릭한 시점의 마우스 좌표 저장
double mouseY;
bool isdrag = false;    //마우스를 드래그 중에 true, 릴리즈시 false

float red = 0.0f;
float green = 0.0f;
float blue = 0.0f;
float alpha = 1.0f;


void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    //left down
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)           
    {
        glfwGetCursorPos(window, &mouseX, &mouseY);
        red = 0.0f; green = 1.0f; blue = 0.0f; alpha = 1.0f;
    }

    //left up
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)    
    {
        red = 0.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
        isdrag = false;
    }

    //right down
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)     
    {
        glfwGetCursorPos(window, &mouseX, &mouseY);
        red = 1.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
    }

    //right up
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)   
    {
        red = 0.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
        isdrag = false;
    }

    //idle
    else                                                                    
    {
        red = 0.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
        isdrag = false;
    }
}


void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{   
    //left drag
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && (mouseX != xpos || mouseY != ypos))  
    {
        red = 1.0f; green = 0.0f; blue = 1.0f; alpha = 1.0f;
    }
    //right drag
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS && (mouseX != xpos || mouseY != ypos)) 
    {
        red = 0.0f; green = 0.0f; blue = 1.0f; alpha = 1.0f;
    }   
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "Lecture04_HW", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        
        
        glfwSetMouseButtonCallback(window, mouse_button_callback);  //버튼 콜백
        glfwSetCursorPosCallback(window, mouse_cursor_callback);    //커서 콜백

        glClearColor(red, green, blue, alpha);  //색 지정

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}