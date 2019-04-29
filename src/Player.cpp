#include "Player.h"

#include "Game.h"
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
    health = 100;
}

Player::~Player()
{
    //dtor
}

void Player::update() {
    Game *g = (Game*) game;
    GLint damage = g->collided(v);
    if (health > 0) health -= damage;

    angle += 3;
}

void Player::draw() {
    glPushMatrix();
    glTranslated((v[0][0] + v[2][0])/2.0, (v[0][1] + v[1][1])/2.0, 0);
//    glRotated(angle, 0, 0, 1);

    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);

        glVertex2d(10, -10);
        glVertex2d(10, 10);
        glVertex2d(-10, 10);
        glVertex2d(-10, -10);

        glVertex2d(4, 10);
        glVertex2d(4, 14);
        glVertex2d(-4, 14);
        glVertex2d(-4, 10);

    glEnd();

    glPopMatrix();
}

void Player::nextLevel() {

}

void Player::keyUp(unsigned char key, int x, int y) {
}

void Player::keyDown(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        GLdouble xx = (v[0][0] + v[2][0])/2.0;
        GLdouble yy = (v[0][1] + v[1][1])/2.0 + 20;

        GLdouble bulletPos[4][2] = {
            {2 + xx, -5 + yy},
            {2 + xx, 5 + yy},
            {-2 + xx, 5 + yy},
            {-2 + xx, -5 + yy}
        };
        Bullet *bullet = new Bullet(game, bulletPos);
        ((Game*)game)->objects.push_back(bullet);
        break;
    }
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
