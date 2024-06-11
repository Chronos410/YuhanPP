#pragma comment(lib, "opengl32.lib")    //�߰� ���Ӽ� lib �߰� �ϴ� ��
#define PI 3.141592f
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

void errorCallback(int error, const char* description) {
    std::cerr << "�ڵ�" << error << description;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc�� && ������
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}


//�¾� 1�� ���̿� ���Ǵ� ����
float sunalpha_x = -0.15f;
float sunalpha_y = 0.0f;

//�¾� 2�� ���̿� ���Ǵ� ����
float sunbeta_x = 0.15f;
float sunbeta_y = -0.15f;
float sunbeta_degree;

//�¾� 1,2�� ���̰� ���� ���� ����
float sun_speed = 0.222f; //ȸ�� �ӵ� (2 RPM)

//������ ���Ǵ� ����
float earth_x = 0.6f;
float earth_y = 0.0f;
float earth_speed = 0.111f;   //���� �ӵ� (1 RPM)
float earth_degree;         //���� ����

//�޿� ���Ǵ� ����
float moon_scale = 0.05f;
float moon_x = 0.25f;
float moon_y = 0.0f;
float moon_speed = 2.222f;    //�����ӵ� (20 RPM)

int RenderSun() {

    //�¾� ��ü
    glColor3f(1.0f, 0.851f, 0.4f);           //FFD966
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) 
    {
        float theta = 2.0f * PI * float(i) / float(360);
        float xsize = 0.2;
        float ysize = 0.2;
        glVertex2f(xsize * cosf(theta) - ysize * sinf(theta), xsize * sinf(theta) + ysize * cos(theta));        //ȸ�����Ŀ� 0~360�� �����ؼ� ���� ��ǥ�� ������ ��?�� ��´�
    }
    glEnd();

    //�¾� �ܰ��� 
    glColor3f(0.7725f, 0.3529f, 0.0667f);     //C55A11
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) 
    {
        float theta = 2.0f * PI * float(i) / float(360);
        float xsize = 0.2;
        float ysize = 0.2;
        glVertex2f(xsize * cosf(theta) - ysize * sinf(theta), xsize * sinf(theta) + ysize * cos(theta));    
    }
    glEnd();
    //��ü�� �������� �������̳� ���̳� �ۿ� ���� + ����

    //�¾� 1�� ����
    glColor3f(1.0f, 0.902f, 0.6f);    //FFE699
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)   //�������� ���� 360�� ��´�
    {
        float theta = (2.0f * PI * float(i) / float(360));   // 1ȸ��, 1��Ÿ = 2 ���� * ���� ����

        float xsize = 0.07;    
        float ysize = 0.07;    //ũ��
        
        float x = xsize * cosf(theta) - ysize * sinf(theta);
        float y = xsize * sinf(theta) + ysize * cos(theta);

        glVertex2f(x + sunalpha_x, y + sunalpha_y);
        //ȸ�� �������� ������ �������� �� ���� sunalpha_x,y ��ǥ�� ���ؼ� (����� update������) ������ ��Ÿ�� 
    }
    glEnd();

    //�¾� 2�� ����
    glColor3f(1.0f, 0.753f, 0.0f);    //FFC000
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)     //�������� ���� 360�� ��´�
    {
        float theta = (2.0f * PI * float(i) / float(360));

        float xsize = 0.03;
        float ysize = 0.07;

        float x = xsize * cosf(theta) * cosf(sunbeta_degree) - ysize * sinf(theta) * sinf(sunbeta_degree);
        float y = xsize * cosf(theta) * sinf(sunbeta_degree) + ysize * sinf(theta) * cosf(sunbeta_degree);
        //Ÿ�� �׸��� ���� (sunbeta_degree)�κ��� ȸ���� ���

        glVertex2f(x + sunbeta_x, y + sunbeta_y); // + sunbeta�� �����ϴ� ��ǥ
    }
    glEnd();

    return 0;
}

int RenderEarth(){

    //����
    glColor3f(0.357f, 0.608f, 0.835f);    //5B9BD5
    glBegin(GL_QUADS);

    float xsize = 0.07f;
    float ysize = 0.07f;

    float x = xsize * cosf(earth_degree * 6) - ysize * sinf(earth_degree * 6);
    float y = xsize * sinf(earth_degree * 6) + ysize * cos(earth_degree * 6);
    //������ 6rpm �̰� 
    //������ 1rpm �̴ϱ� ���� ������ x6�ϸ� ��ȣ �� �´´�

    glVertex2f(x + earth_x, y + earth_y);
    glVertex2f(-y + earth_x, x + earth_y);
    glVertex2f(-x + earth_x, -y + earth_y);
    glVertex2f(y + earth_x, -x + earth_y);
    glEnd();

    //���� �ܰ���
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x + earth_x, y + earth_y);
    glVertex2f(-y + earth_x, x + earth_y);
    glVertex2f(-x + earth_x, -y + earth_y);
    glVertex2f(y + earth_x, -x + earth_y);
    glEnd();

    return 0;
}

float xcal(float x, float y)
{
    float result = x * cosf(earth_degree * 20) - y * sinf(earth_degree * 20);

    return result;
}
float ycal(float x, float y)
{
    float result = x * sinf(earth_degree * 20) + y * cos(earth_degree * 20);

    return result;
}

int renderStar() {

    //�� �ܰ���
    glColor3f(0.0f, 0.0f, 0.0f);    //000000
    glBegin(GL_LINE_LOOP);

    glVertex2f((xcal(-0.6f, 0.4f) * moon_scale) + moon_x + earth_x, (ycal(-0.6f, 0.4f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.6f, 0.4f) * moon_scale) + moon_x + earth_x, (ycal(0.6f, 0.4f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.0f, -0.4f) * moon_scale) + moon_x + earth_x, (ycal(0.0f, -0.4f) * moon_scale) + moon_y + earth_y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f((xcal(-0.2f, -0.2f) * moon_scale) + moon_x + earth_x, (ycal(-0.2f, -0.2f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.0f, 1.0f) * moon_scale) + moon_x + earth_x, (ycal(0.0f, 1.0f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.4f, -0.6f) * moon_scale) + moon_x + earth_x, (ycal(0.4f, -0.6f) * moon_scale) + moon_y + earth_y);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f((xcal(-0.4f, -0.6f) * moon_scale) + moon_x + earth_x, (ycal(-0.4f, -0.6f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.0f, 1.0f) * moon_scale) + moon_x + earth_x, (ycal(0.0f, 1.0f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.2f, -0.2f) * moon_scale) + moon_x + earth_x, (ycal(0.2f, -0.2f) * moon_scale) + moon_y + earth_y);
    glEnd();

    //�� ��ü
    glColor3f(1.0f, 0.949f, 0.0f);    //FFF200
    glBegin(GL_TRIANGLES);

    glVertex2f((xcal(-0.6f, 0.4f) * moon_scale) + moon_x + earth_x, (ycal(-0.6f, 0.4f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.6f, 0.4f) * moon_scale) + moon_x + earth_x, (ycal(0.6f, 0.4f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.0f, -0.4f) * moon_scale) + moon_x + earth_x, (ycal(0.0f, -0.4f) * moon_scale) + moon_y + earth_y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((xcal(-0.2f, -0.2f) * moon_scale) + moon_x + earth_x, (ycal(-0.2f, -0.2f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.0f, 1.0f) * moon_scale) + moon_x + earth_x, (ycal(0.0f, 1.0f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.4f, -0.6f) * moon_scale) + moon_x + earth_x, (ycal(0.4f, -0.6f) * moon_scale) + moon_y + earth_y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((xcal(-0.4f, -0.6f) * moon_scale) + moon_x + earth_x, (ycal(-0.4f, -0.6f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.0f, 1.0f) * moon_scale) + moon_x + earth_x, (ycal(0.0f, 1.0f) * moon_scale) + moon_y + earth_y);
    glVertex2f((xcal(0.2f, -0.2f) * moon_scale) + moon_x + earth_x, (ycal(0.2f, -0.2f) * moon_scale) + moon_y + earth_y);
    glEnd();

    return 0;
}

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(1100, 1100, "Lecture10-HW", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, key_callback);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        static double lastTime = glfwGetTime();
        double currentTime = glfwGetTime();
        float deltaTime = static_cast<float>(currentTime - lastTime);
        lastTime = currentTime;     //���� �ð� deltaTime���ϴ� ��� ����
        std::wcout << glfwGetTime() << std::endl;   //��������
        std::wcout << deltaTime << std::endl;       // �����Ӵ� �ð��̶� �þ������

        //�¾��� 1, 2�� ���̰� ��ġ�� ��ǥ x, y �� 2�� ���̰� �ʿ�� �ϴ� ���� ����
        sunalpha_x = sunalpha_x * cosf(sun_speed * deltaTime) - sunalpha_y * sinf(sun_speed * deltaTime);
        sunalpha_y = sunalpha_x * sinf(sun_speed * deltaTime) + sunalpha_y * cosf(sun_speed * deltaTime);
        
        sunbeta_x = sunbeta_x * cosf(sun_speed * deltaTime) - sunbeta_y * sinf(sun_speed * deltaTime);
        sunbeta_y = sunbeta_x * sinf(sun_speed * deltaTime) + sunbeta_y * cosf(sun_speed * deltaTime);
        sunbeta_degree = atan2f(sunbeta_y, sunbeta_x); // atan2f�� -180 ~ 180�� ��
        
        //������ ��ġ�� ��ǥ�� �� ����
        earth_x = earth_x * cosf(earth_speed * deltaTime) - earth_y * sinf(earth_speed * deltaTime);
        earth_y = earth_x * sinf(earth_speed * deltaTime) + earth_y * cosf(earth_speed * deltaTime);
        earth_degree = atan2f(earth_y, earth_x);

        //���� ��ġ�� ��ǥ
        moon_x = moon_x * cosf(moon_speed * deltaTime) - moon_y * sinf(moon_speed * deltaTime);
        moon_y = moon_x * sinf(moon_speed * deltaTime) + moon_y * cosf(moon_speed * deltaTime);


        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //clear �� ��
        glClear(GL_COLOR_BUFFER_BIT);

        RenderSun();
        RenderEarth();
        renderStar();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}