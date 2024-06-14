#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"

void errorCallback(int error, const char* description)
{
    printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Handle key events if needed
}

int Physics()
{
    // Perform physics calculations if needed
    return 0;
}

int Initialize()
{
    // Perform initialization if needed
    return 0;
}

void Update(Player& player)
{
    // Perform game logic update if needed
    // For example, move player based on input
}

void Render(Player& player, Floor& floor, EnemyBlock& obstacleLow, EnemyBlock& obstacleHigh)
{
    // Clear the screen with a dark blue color (assuming 1 pixel = 1 cm)
    glClearColor(0.0f, 0.1176f, 0.3922f, 1.0f); // RGBA 값으로 설정
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw floor
    floor.Draw();

    // Draw player
    player.Draw();

    // Draw obstacles
    glPushMatrix();
    glTranslatef(-300.0f, 0.0f, 0.0f); // 첫 번째 장애물 위치
    obstacleLow.Draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(500.0f, 0.0f, 0.0f); // 두 번째 장애물 위치
    obstacleHigh.Draw();
    glPopMatrix();
}





int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // GLFW 라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    Initialize();

    // 플레이어 객체 생성
    Player player(50.0f); // 플레이어 객체 생성 (50px 정사각형)

    // 바닥 객체 생성
    Floor floor(100.0f); // 바닥 객체 생성 (100px 높이)

    // 장애물 객체 생성
    EnemyBlock obstacleLow(500.0f, 100.0f);   // 낮은 장애물 (높이 100px)
    EnemyBlock obstacleHigh(500.0f, 300.0f);  // 높은 장애물 (높이 300px)   

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        Physics();
        Update(player);

        Render(player, floor, obstacleLow, obstacleHigh);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
