#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <algorithm>

const double gravity = 9.8;
const double velocityMax = 1.0;
const double jumpVelocity = 2.0;

struct Player
{
    float x, y;
    float vy;
    bool isJumping;
} player;

struct Collider
{
    float x, y, width, height;
};

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void drawPlayer(const Player& player)
{
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.8f, 0.85f);
    glVertex2f(player.x, player.y);
    glVertex2f(player.x, player.y + 0.3f);
    glVertex2f(player.x - 0.2f, player.y + 0.3f);
    glVertex2f(player.x - 0.2f, player.y);
    glEnd();
}

void drawGround()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-1.0f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glEnd();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && !player.isJumping)
    {
        player.vy = jumpVelocity;
        player.isJumping = true;
    }
}

bool checkCollision(const Player& player, const Collider& collider)
{
    float playerLeft = player.x - 0.2f;
    float playerRight = player.x;
    float playerTop = player.y + 0.3f;
    float playerBottom = player.y;

    float colliderLeft = collider.x;
    float colliderRight = collider.x + collider.width;
    float colliderTop = collider.y + collider.height;
    float colliderBottom = collider.y;

    return !(playerLeft > colliderRight || playerRight < colliderLeft || playerTop < colliderBottom || playerBottom > colliderTop);
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1280, 768, "error", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    player.x = 0.0f;
    player.y = -0.7f;
    player.vy = 0.0f;
    player.isJumping = false;

    Collider groundCollider = { -1.0f, -1.0f, 2.0f, 0.3f };

    double lastTime = glfwGetTime();
    double deltaTime;

    while (!glfwWindowShouldClose(window))
    {
        double currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        glfwPollEvents();
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        player.vy -= gravity * deltaTime;
        player.vy = std::max(player.vy, -static_cast<float>(velocityMax));
        player.y += player.vy * deltaTime;

        if (checkCollision(player, groundCollider))
        {
            player.y = groundCollider.y + groundCollider.height;
            player.vy = 0.0f;
            player.isJumping = false;
        }

        drawPlayer(player);
        drawGround();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}