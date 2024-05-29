#pragma once
#pragma comment(lib, "opengl32.lib")
#include <GLFW/glfw3.h>

class Player
{
public:
    Player(float playerX, float playerY, float playerScale, float playerX_velocity, float playerY_velocity) {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex2f(playerX - playerScale, playerY + playerScale);
        glVertex2f(playerX + playerScale, playerY + playerScale);
        glVertex2f(playerX + playerScale, playerY - playerScale);
        glVertex2f(playerX - playerScale, playerY - playerScale);

        glEnd();

        playerX = playerX + playerX_velocity;
        playerY = playerY + playerY_velocity;
        playerY_velocity = playerY_velocity - 0.00098f;
	}
	~Player(){

	}
};

