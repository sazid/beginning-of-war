#include "Enemy.h"
#include "Game.h"

#include <GL/glut.h>
#include <iostream>
#include <ctime>

Enemy::Enemy(void *game, GLdouble vert[4][2], GLint h, GLdouble speed) : GameObject(game, vert)
{
    this->game = game;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] = vert[i][j];
        }
    }

    time(NULL);

    movementSpeed = speed;
    collisionDamage = 20;
    health = h;
    originalHealth = h;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::update() {
    for (int i = 0; i < 4; ++i) {
        v[i][1] -= 1;
    }

    Game *g = (Game*) game;
    GLint damage = g->collided(v, 0);
    if (health > 0) health -= damage;

    if (health <= 0) {
        for (int i = 0; i < 4; ++i) {
            v[i][1] = 500;
        }
    }
}

void Enemy::draw() {
    glPushMatrix();
    glTranslated(0, 0, 0);

    glColor3ub(rand() % 255, rand() % 255, rand() % 255);

    GLdouble healthRatio = 100.0 * (GLdouble) health / (GLdouble) originalHealth;

    if (healthRatio >= 80) {
        glColor3ub(255, 0, 140);
    } else if (healthRatio >= 60) {
        glColor3ub(190, 0, 100);
    } else if (healthRatio >= 40) {
        glColor3ub(130, 0, 70);
    } else if (healthRatio >= 20) {
        glColor3ub(75, 0, 40);
    } else {
        glColor3ub(0, 0, 0);
    }

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
}

void Enemy::specialKeyUp(int key, int x, int y) {
}

void Enemy::specialKeyDown(int key, int x, int y) {
}
