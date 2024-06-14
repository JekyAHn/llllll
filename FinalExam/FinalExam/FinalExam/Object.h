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
    float size; // �÷��̾� ���簢�� �� ���� ���� (�ȼ� ����)
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
    float height; // �ٴ��� ���� (�ȼ� ����)
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
        glVertex2f(1.0f, -(100.0f / 200.0f)); // Top-right corner (�ٴ����κ��� 100px ��ġ)
        glVertex2f(-1.0f, -(100.0f / 200.0f)); // Top-left corner (�ٴ����κ��� 100px ��ġ)
        glEnd();
    } 
};
class EnemyBlock : public Object {
private:
    float width;  // ��ֹ��� �ʺ� (�ȼ� ����)
    float height; // ��ֹ��� ���� (�ȼ� ����)
public:
    EnemyBlock(float width, float height) : width(width), height(height) {}

    void OnCollisionEnter(Object& other) override {
        // Handle collision logic for EnemyBlock
    }

    void Draw() const override {
        // Draw green block
        glColor3ub(0, 255, 0); // Green color
        glBegin(GL_QUADS);
        glVertex2f(-width / 400.0f, -height / 300.0f); // �ȼ� ������ ��ǥ ����
        glVertex2f(width / 400.0f, -height / 300.0f);
        glVertex2f(width / 400.0f, height / 300.0f);
        glVertex2f(-width / 400.0f, height / 300.0f);
        glEnd();
    }

};


