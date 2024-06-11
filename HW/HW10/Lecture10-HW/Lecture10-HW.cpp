#pragma comment(lib, "opengl32.lib")    //추가 종속성 lib 추가 하는 법
#define PI 3.141592f
#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

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


//태양 1번 무늬에 사용되는 변수
float sunalpha_x = -0.15f;
float sunalpha_y = 0.0f;

//태양 2번 무늬에 사용되는 변수
float sunbeta_x = 0.15f;
float sunbeta_y = -0.15f;
float sunbeta_degree;

//태양 1,2번 무늬가 같이 쓰는 변수
float sun_speed = 0.222f; //회전 속도 (2 RPM)

//지구에 사용되는 변수
float earth_x = 0.6f;
float earth_y = 0.0f;
float earth_speed = 0.111f;   //공전 속도 (1 RPM)
float earth_degree;         //공전 각도

//달에 사용되는 변수
float moon_scale = 0.05f;
float moon_x = 0.25f;
float moon_y = 0.0f;
float moon_speed = 2.222f;    //공전속도 (20 RPM)

int RenderSun() {

    //태양 본체
    glColor3f(1.0f, 0.851f, 0.4f);           //FFD966
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) 
    {
        float theta = 2.0f * PI * float(i) / float(360);
        float xsize = 0.2;
        float ysize = 0.2;
        glVertex2f(xsize * cosf(theta) - ysize * sinf(theta), xsize * sinf(theta) + ysize * cos(theta));        //회전공식에 0~360을 대입해서 나온 좌표에 폴리곤 점?을 찍는다
    }
    glEnd();

    //태양 외곽선 
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
    //본체랑 차이점은 폴리곤이냐 선이냐 밖에 없음 + 색상

    //태양 1번 무늬
    glColor3f(1.0f, 0.902f, 0.6f);    //FFE699
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)   //폴리곤의 점을 360번 찍는다
    {
        float theta = (2.0f * PI * float(i) / float(360));   // 1회전, 1세타 = 2 파이 * 현재 각도

        float xsize = 0.07;    
        float ysize = 0.07;    //크기
        
        float x = xsize * cosf(theta) - ysize * sinf(theta);
        float y = xsize * sinf(theta) + ysize * cos(theta);

        glVertex2f(x + sunalpha_x, y + sunalpha_y);
        //회전 공식으로 나오는 폴리곤의 각 점에 sunalpha_x,y 좌표를 더해서 (계산은 update에서함) 공전을 나타냄 
    }
    glEnd();

    //태양 2번 무늬
    glColor3f(1.0f, 0.753f, 0.0f);    //FFC000
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)     //폴리곤의 점을 360번 찍는다
    {
        float theta = (2.0f * PI * float(i) / float(360));

        float xsize = 0.03;
        float ysize = 0.07;

        float x = xsize * cosf(theta) * cosf(sunbeta_degree) - ysize * sinf(theta) * sinf(sunbeta_degree);
        float y = xsize * cosf(theta) * sinf(sunbeta_degree) + ysize * sinf(theta) * cosf(sunbeta_degree);
        //타원 그리는 공식 (sunbeta_degree)부분이 회전을 담당

        glVertex2f(x + sunbeta_x, y + sunbeta_y); // + sunbeta가 공전하는 좌표
    }
    glEnd();

    return 0;
}

int RenderEarth(){

    //지구
    glColor3f(0.357f, 0.608f, 0.835f);    //5B9BD5
    glBegin(GL_QUADS);

    float xsize = 0.07f;
    float ysize = 0.07f;

    float x = xsize * cosf(earth_degree * 6) - ysize * sinf(earth_degree * 6);
    float y = xsize * sinf(earth_degree * 6) + ysize * cos(earth_degree * 6);
    //자전은 6rpm 이고 
    //공전은 1rpm 이니까 공전 각도에 x6하면 야호 딱 맞는다

    glVertex2f(x + earth_x, y + earth_y);
    glVertex2f(-y + earth_x, x + earth_y);
    glVertex2f(-x + earth_x, -y + earth_y);
    glVertex2f(y + earth_x, -x + earth_y);
    glEnd();

    //지구 외곽선
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

    //달 외곽선
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

    //달 본체
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
        lastTime = currentTime;     //대충 시간 deltaTime구하는 방법 복붙
        std::wcout << glfwGetTime() << std::endl;   //점점증가
        std::wcout << deltaTime << std::endl;       // 프레임당 시간이라 늘어나지않음

        //태양의 1, 2번 무늬가 위치할 좌표 x, y 와 2번 무늬가 필요로 하는 현재 각도
        sunalpha_x = sunalpha_x * cosf(sun_speed * deltaTime) - sunalpha_y * sinf(sun_speed * deltaTime);
        sunalpha_y = sunalpha_x * sinf(sun_speed * deltaTime) + sunalpha_y * cosf(sun_speed * deltaTime);
        
        sunbeta_x = sunbeta_x * cosf(sun_speed * deltaTime) - sunbeta_y * sinf(sun_speed * deltaTime);
        sunbeta_y = sunbeta_x * sinf(sun_speed * deltaTime) + sunbeta_y * cosf(sun_speed * deltaTime);
        sunbeta_degree = atan2f(sunbeta_y, sunbeta_x); // atan2f는 -180 ~ 180의 값
        
        //지구가 위치할 좌표와 그 각도
        earth_x = earth_x * cosf(earth_speed * deltaTime) - earth_y * sinf(earth_speed * deltaTime);
        earth_y = earth_x * sinf(earth_speed * deltaTime) + earth_y * cosf(earth_speed * deltaTime);
        earth_degree = atan2f(earth_y, earth_x);

        //달이 위치할 좌표
        moon_x = moon_x * cosf(moon_speed * deltaTime) - moon_y * sinf(moon_speed * deltaTime);
        moon_y = moon_x * sinf(moon_speed * deltaTime) + moon_y * cosf(moon_speed * deltaTime);


        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //clear 할 색
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