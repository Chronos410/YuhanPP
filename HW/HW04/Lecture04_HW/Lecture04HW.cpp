#pragma comment(lib, "opengl32.lib")    //프로젝트 추가 종속성에 lib 추가
#include <iostream>
#include <GLFW/glfw3.h>

bool ismove = false;    //커서 callback이 호출될때 true, 호출되지 않으면 0.1초 뒤 false
bool isclick = false;   //마우스의 버튼이 눌려있으면 true, 아니면 false

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
    glfwSetTime(0.0);   //시간 초기화
        
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && ismove && isclick)          //좌클릭 중 움직임
    {
        red = 1.0f; green = 0.0f; blue = 1.0f; alpha = 1.0f;
    }
    else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS && ismove && isclick)    //우클릭 중 움직임
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

        glfwSetMouseButtonCallback(window, mouse_button_callback);  //마우스 버튼 클릭시 작동
        
        glfwSetCursorPosCallback(window, mouse_cursor_callback);    //마우스 커서 이동시 작동

        
        //if (glfwGetTime() < 0.01)   //커서 콜백 함수를 호출한지 0.01초 이내라면?
        //{
        //    ismove = true;
        //}
        //else
        //{
        //    ismove = false;
        //}

        glfwGetTime() < 0.01 ? ismove = true : ismove = false;

        if (!ismove && isclick && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)         //좌클릭 시 색변경(녹색)
        {
            red = 0.0f; green = 1.0f; blue = 0.0f; alpha = 1.0f;
        }
        else if (!ismove && isclick && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)   //우클릭 시 색변경(빨간색)
        {
            red = 1.0f; green = 0.0f; blue = 0.0f; alpha = 1.0f;
        }

        glClearColor(red, green, blue, alpha);          //색 지정

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