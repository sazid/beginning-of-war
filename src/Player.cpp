#include "Player.h"

#include <GL/glut.h>
#include <iostream>

Player::Player(void *game, GLdouble vert[4][2]) : GameObject(game, vert)
{
    this->game = game;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] = vert[i][j];
        }
    }

    movementSpeed = 5;
}

Player::~Player()
{
    //dtor
}

void Player::update() {

}

void Player::draw() {
    glPushMatrix();

    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);

        for (int i = 0; i < 4; ++i) {
            glVertex2dv(v[i]);
        }

    glEnd();

    glPopMatrix();
}

void Player::nextLevel() {

}

void Player::keyUp(unsigned char key, int x, int y) {
}

void Player::keyDown(unsigned char key, int x, int y) {
}

void Player::specialKeyUp(int key, int x, int y) {
}

void Player::specialKeyDown(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        for (int i = 0; i < 4; ++i) {
            v[i][1] += movementSpeed;
        }
        break;
    case GLUT_KEY_DOWN:
        for (int i = 0; i < 4; ++i) {
            v[i][1] -= movementSpeed;
        }
        break;
    case GLUT_KEY_RIGHT:
        for (int i = 0; i < 4; ++i) {
            v[i][0] += movementSpeed;
        }
        break;
    case GLUT_KEY_LEFT:
        for (int i = 0; i < 4; ++i) {
            v[i][0] -= movementSpeed;
        }
        break;
    }
}
