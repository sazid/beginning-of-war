#include "Enemy.h"

#include <GL/glut.h>
#include <iostream>

Enemy::Enemy(void *game, GLdouble vert[4][2]) : GameObject(game, vert)
{
    this->game = game;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] = vert[i][j];
        }
    }

    movementSpeed = 5;
    collisionDamage = 20;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::update() {
    for (int i = 0; i < 4; ++i) {
        v[i][1] -= 1;
    }
}

void Enemy::draw() {
    glPushMatrix();
    glTranslated(0, 0, 0);

    glColor3ub(200, 200, 200);
    glBegin(GL_QUADS);

        for (int i = 0; i < 4; ++i) {
            glVertex2dv(v[i]);
        }

    glEnd();

    glPopMatrix();
}

void Enemy::nextLevel() {

}

void Enemy::keyUp(unsigned char key, int x, int y) {
}

void Enemy::keyDown(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        for (int i = 0; i < 4; ++i) {
            v[i][1] += movementSpeed;
        }
        break;
    case 's':
        for (int i = 0; i < 4; ++i) {
            v[i][1] -= movementSpeed;
        }
        break;
    case 'd':
        for (int i = 0; i < 4; ++i) {
            v[i][0] += movementSpeed;
        }
        break;
    case 'a':
        for (int i = 0; i < 4; ++i) {
            v[i][0] -= movementSpeed;
        }
        break;
    }
}

void Enemy::specialKeyUp(int key, int x, int y) {
}

void Enemy::specialKeyDown(int key, int x, int y) {
}
