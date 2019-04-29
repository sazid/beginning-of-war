#include "Bullet.h"

#include <GL/glut.h>
#include <iostream>

Bullet::Bullet(void *game, GLdouble vert[4][2]) : GameObject(game, vert)
{
    this->game = game;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] = vert[i][j];
        }
    }

    movementSpeed = 10;
    collisionDamage = 20;
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::update() {
    for (int i = 0; i < 4; ++i) {
        v[i][1] += 5;
    }
}

void Bullet::draw() {
    glPushMatrix();
    glTranslated((v[0][0] + v[2][0])/2.0, (v[0][1] + v[1][1])/2.0, 0);

    glColor3ub(255, 50, 50);
    glBegin(GL_QUADS);

        glVertex2d(2, -5);
        glVertex2d(2, 5);
        glVertex2d(-2, 5);
        glVertex2d(-2, -5);

    glEnd();

    glPopMatrix();
}

void Bullet::nextLevel() {
}

void Bullet::keyUp(unsigned char key, int x, int y) {
}

void Bullet::keyDown(unsigned char key, int x, int y) {
}

void Bullet::specialKeyUp(int key, int x, int y) {
}

void Bullet::specialKeyDown(int key, int x, int y) {
}
