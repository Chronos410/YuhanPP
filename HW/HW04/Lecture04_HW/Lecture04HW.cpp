#pragma comment(lib, "opengl32.lib")    //������Ʈ �߰� ���Ӽ��� lib �߰�
#include <iostream>
#include <GLFW/glfw3.h>

bool ismove = false;    //Ŀ�� callback�� ȣ��ɶ� true, ȣ����� ������ 0.1�� �� false
bool isclick = false;   //���콺�� ��ư�� ���������� true, �ƴϸ� false

float red = 0.0f;
float green = 0.0f;
float blue = 0.0f;
float alpha = 1.0f;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if ((button == GLFW_MOUSE_BUTTON_LEFT || button == GLFW_MOUSE_BUTTON_RIGHT) && action == GLFW_PRESS)
    {
        isclick = true;
    }
    else if ((button == GLFW_MOUSE_BUTTON_LEFT || button == GLFW_MOUSE_BUTTON_RIGHT) && action == GLFW_RELEASE)
    {
        red = 0.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
        isclick = false;
    }
}

void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
    glfwSetTime(0.0);   //�ð� �ʱ�ȭ
        
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && ismove && isclick)          //��Ŭ�� �� ������
    {
        red = 1.0f; green = 0.0f; blue = 1.0f; alpha = 1.0f;
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS && ismove && isclick)    //��Ŭ�� �� ������
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

        glfwSetMouseButtonCallback(window, mouse_button_callback);  //���콺 ��ư Ŭ���� �۵�
        
        glfwSetCursorPosCallback(window, mouse_cursor_callback);    //���콺 Ŀ�� �̵��� �۵�

        
        //if (glfwGetTime() < 0.01)   //Ŀ�� �ݹ� �Լ��� ȣ������ 0.01�� �̳����?
        //{
        //    ismove = true;
        //}
        //else
        //{
        //    ismove = false;
        //}

        glfwGetTime() < 0.01 ? ismove = true : ismove = false;

        if (!ismove && isclick && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)         //��Ŭ�� �� ������(���)
        {
            red = 0.0f; green = 1.0f; blue = 0.0f; alpha = 1.0f;
        }
        else if (!ismove && isclick && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)   //��Ŭ�� �� ������(������)
        {
            red = 1.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
        }

        glClearColor(red, green, blue, alpha);          //�� ����

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