#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법
#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

void EventHandler()
{
    cout << "그아악" << endl;
}





void errorCallback(int error, const char* description) {
    std::cerr << "코드" << error << description;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc가 && 눌리면
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}



int main(void)
{
    void (*onCollisionEnter)();

    onCollisionEnter = EventHandler;


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Lecture15", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, key_callback);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        /* Render here */

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f); //clear 할 색
        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}