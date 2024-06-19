#include "Transform.h"
#include "Object.h"
#include <cmath>

// Simple pseudo-random number generator
unsigned int seed = 0;

float pseudoRandom() {
    seed = (8253729 * seed + 2396403); // Example constants
    return seed * (1.0f / 4294967296.0f);
}

float randomFloat(float min, float max) {
    return min + (max - min) * pseudoRandom();
}

void updateEnemyPosition(float& x, float speed, float deltaTime) {
    x -= speed * deltaTime;
}

void updateStarPosition(float& x, float speed, float deltaTime) {
    x -= speed * deltaTime;
}

void resetEnemyPositions(EnemyBlock& enemy, float resetThreshold) {
    if (enemy.posX4 < resetThreshold) {
        enemy.posX1 = 705.0f;
        enemy.posX2 = 1630.0f;
        enemy.posX3 = 2460.0f;
        enemy.posX4 = 2600.0f;
    }
}

void resetStarPosition(float& x, float resetThreshold, float newX) {
    if (x < resetThreshold) {
        x = newX;
    }
}

void applyGravityAndJump(float& posY, float& velocityY, bool& isJumping, float gravity, float deltaTime) {
    if (isJumping) {
        velocityY -= gravity * deltaTime;
        posY -= velocityY * deltaTime;  // ���� �� y��ǥ�� ����

        if (posY >= 450.0f) { // �ٴ� ��ġ�� ����
            posY = 450.0f;
            velocityY = 0.0f;
            isJumping = false;
        }
    }
}