#pragma once

#include <GLFW/glfw3.h>

class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
        // Handle collision logic for generic Object
    }

    virtual void Draw() const {
        // Default draw method (does nothing)
    }
};

class Player : public Object {
private:
    float size; // 플레이어 정사각형 한 변의 길이 (픽셀 단위)
public:
    Player(float size) : size(size) {}

    void OnCollisionEnter(Object& other) override {
        // Handle collision logic for Player
    }

    void Draw() const override {
        // Draw red square for Player
        glColor3ub(255, 0, 0); // Red color
        glBegin(GL_QUADS);
        glVertex2f(-size / 800.0f, -size / 600.0f);
        glVertex2f(size / 800.0f, -size / 600.0f);
        glVertex2f(size / 800.0f, size / 600.0f);
        glVertex2f(-size / 800.0f, size / 600.0f);
        glEnd();

        // Draw outline
        glLineWidth(3.0f);
        glColor3ub(255, 255, 255); // White outline
        glBegin(GL_LINE_LOOP);
        glVertex2f(-size / 800.0f, -size / 600.0f);
        glVertex2f(size / 800.0f, -size / 600.0f);
        glVertex2f(size / 800.0f, size / 600.0f);
        glVertex2f(-size / 800.0f, size / 600.0f);
        glEnd();
    }
};

class Floor : public Object {
private:
    float height; // 바닥의 높이 (픽셀 단위)
public:
    Floor(float height) : height(height) {}

    void OnCollisionEnter(Object& other) override {
        // Handle collision logic for Floor
    }

    void Draw() const override {
        // Draw yellow ground
        glColor3ub(255, 200, 15); // Yellow color
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); // Bottom-left corner
        glVertex2f(1.0f, -1.0f); // Bottom-right corner
        glVertex2f(1.0f, -(100.0f / 200.0f)); // Top-right corner (바닥으로부터 100px 위치)
        glVertex2f(-1.0f, -(100.0f / 200.0f)); // Top-left corner (바닥으로부터 100px 위치)
        glEnd();
    } 
};
class EnemyBlock : public Object {
private:
    float width;  // 장애물의 너비 (픽셀 단위)
    float height; // 장애물의 높이 (픽셀 단위)
public:
    EnemyBlock(float width, float height) : width(width), height(height) {}

    void OnCollisionEnter(Object& other) override {
        // Handle collision logic for EnemyBlock
    }

    void Draw() const override {
        // Draw green block
        glColor3ub(0, 255, 0); // Green color
        glBegin(GL_QUADS);
        glVertex2f(-width / 400.0f, -height / 300.0f); // 픽셀 단위로 좌표 설정
        glVertex2f(width / 400.0f, -height / 300.0f);
        glVertex2f(width / 400.0f, height / 300.0f);
        glVertex2f(-width / 400.0f, height / 300.0f);
        glEnd();
    }

};


