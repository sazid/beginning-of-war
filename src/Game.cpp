#include "Game.h"

#include <iostream>

Game::Game() :
    level(1),
    score(0),
    objects()
{
    createObjects();
}

Game::~Game()
{
    for (GameObject *o : this->objects) {
        delete o;
    }
}

void Game::createObjects() {
    GLdouble pos[4][2] = {
        {10, -250},
        {10, -230},
        {-10, -230},
        {-10, -250}
    };
    player = new Player(this, pos);
    objects.push_back(player);

    GLdouble enemyPos[4][2] = {
        {10, 140},
        {10, 160},
        {-10, 160},
        {-10, 140}
    };
    enemy = new Enemy(this, enemyPos);
    objects.push_back(enemy);
}

GLint Game::collided(GLdouble vert[4][2]) {
    int sz = (int) objects.size();
    for (int i = 1; i < sz; ++i) {
        GameObject *o = objects[i];

        GLdouble oLeft = o->v[2][0],
            oRight = o->v[0][0],
            oTop = o->v[1][1],
            oBottom = o->v[0][1],

            objLeft = vert[2][0],
            objRight = vert[0][0],
            objTop = vert[1][1],
            objBottom = vert[0][1];

        //std::cout << "oLeft: " << oLeft << " oRight: " << oRight << " oTop: " << oTop << " oBottom: " << oBottom << '\n';
        //std::cout << "objLeft: " << objLeft << " objRight: " << objRight << " objTop: " << objTop << " objBottom: " << objBottom << std::endl;

        if (objRight >= oLeft && objLeft <= oRight && objBottom <= oTop && objTop >= oBottom) {
            for (int i = 0; i < 4; ++i) {
            //    o->v[i][1] = 200;
            }
            return o->collisionDamage;
        }
    }

    return 0;
}

void Game::nextLevel() {
    // Depending on this->level change the current background
    // and other player/enemy colors

    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->nextLevel();
    }
}

void Game::update() {
    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->update();
    }
}

void Game::draw() {
    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->draw();
    }

    glColor3ub(50, 50, 50);
    drawString(-290, 275, "Score: " + std::to_string(score), GLUT_BITMAP_HELVETICA_18);
    drawString(-290, 250, "Health: " + std::to_string(player->health), GLUT_BITMAP_HELVETICA_18);
}

void Game::keyDown(unsigned char key, int x, int y) {
    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->keyDown(key, x, y);
    }
}

void Game::keyUp(unsigned char key, int x, int y) {
    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->keyUp(key, x, y);
    }
}

void Game::specialKeyDown(int key, int x, int y) {
    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->specialKeyDown(key, x, y);
    }
}

void Game::specialKeyUp(int key, int x, int y) {
    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->specialKeyUp(key, x, y);
    }
}
