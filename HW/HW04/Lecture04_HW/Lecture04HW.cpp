#pragma comment(lib, "opengl32.lib")    //������Ʈ �߰� ���Ӽ��� lib �߰�
#include <iostream>
#include <GLFW/glfw3.h>

double mouseX;          //Ŭ���� ������ ���콺 ��ǥ ����
double mouseY;
bool isdrag = false;    //���콺�� �巡�� �߿� true, ������� false

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
        
        
        glfwSetMouseButtonCallback(window, mouse_button_callback);  //��ư �ݹ�
        glfwSetCursorPosCallback(window, mouse_cursor_callback);    //Ŀ�� �ݹ�

        glClearColor(red, green, blue, alpha);  //�� ����

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