#pragma once
#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include "Transform.h"

// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
    }
};



// Derived classes
class Player : public Object {
public:
    Transform::Vertex playerPos = { -200, -50 };
    Transform::Vector playerSpeed = { 0, -9.8 };

    bool isLand = false;

    float xsize = 50.0f / 800.0f;
    float ysize = 50.0f / 600.0f;

    float xoutsize = 56.0f / 800.0f;
    float youtsize = 56.0f / 600.0f;
    float xpos = playerPos.x / 800.0f;
    float ypos = playerPos.y /600.0f;

    
    void OnCollisionEnter(Object& other) override {
        

    }
    void Update() 
    {
        if (isLand) 
        {
            
        }//ÂøÁö
        else {
            playerPos.y += playerSpeed.y_meter;
            ypos = playerPos.y / 600.0f;
        }//°øÁß
        
    }
    void Render() {

        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(xpos + xoutsize, ypos + youtsize);
        glVertex2f(xpos + xoutsize, ypos + -youtsize);
        glVertex2f(xpos + -xoutsize, ypos + -youtsize);
        glVertex2f(xpos + -xoutsize, ypos + youtsize);
        glEnd();


        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(xpos + xsize, ypos + ysize);
        glVertex2f(xpos + xsize, ypos + -ysize);
        glVertex2f(xpos + -xsize, ypos + -ysize);
        glVertex2f(xpos + -xsize, ypos + ysize);
        glEnd();
        
    }
};

class EnemyBlock : public Object {
public:
    Transform::Vertex wallPos = { 600, -400 };

    float xsize = 50.0f / 800.0f;
    float ysize = 100.0f / 600.0f;
    float xpos = 0.0f / 800.0f;
    float ypos = wallPos.y / 600.0f;



    EnemyBlock(bool isTall, float x) 
    {
        if (isTall) {
            //highwall
            ysize = 300.0f / 600.0f;
            ypos = -200.0f / 600.0f;
            xpos = 0.0f;
        }
        else {
            //lowwall
            ysize = 100.0f / 600.0f;
            ypos = -400.0f / 600.0f;
            xpos = 0.5f;
        }
        wallPos.x = x;
    }

    void OnCollisionEnter(Object& other) override {

    }
    void Update(bool isTall) {
        Transform::Vector wallMove = {-200, 0};
       
        
        wallPos = Transform::MoveVertex(wallPos, wallMove);
        
        xpos = wallPos.x / 800.0f;
    }
    void GoBack() {
        if (wallPos.x <= -800.0f)
        {
            wallPos.x = 800.0f;
        }
    }
    void Render() {
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
        

        glVertex2f(xpos + xsize, ypos + ysize);
        glVertex2f(xpos + xsize, ypos + -ysize);
        glVertex2f(xpos + -xsize, ypos + -ysize);
        glVertex2f(xpos + -xsize, ypos + ysize);
        glEnd();
    }
};

class Floor : public Object {
public:
    Transform::Vertex floorPos = { 0, -600 };
    float xsize = 800.0f / 800.0f;
    float ysize = 100.0f / 600.0f;
    float xpos = floorPos.x / 800.0f;
    float ypos = floorPos.y / 600.0f;

    void OnCollisionEnter(Object& other) override {
    }

    void Render() {
        glColor3f(1.0f, 0.7843137254901961f, 0.0588235294117647f);
        glBegin(GL_QUADS);
        

        glVertex2f(xpos + xsize, ypos + ysize);
        glVertex2f(xpos + xsize, ypos + -ysize);
        glVertex2f(xpos + -xsize, ypos + -ysize);
        glVertex2f(xpos + -xsize, ypos + ysize);
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
};


int PhysicsAABB(Object A, Object B)
{
    return 0;
}