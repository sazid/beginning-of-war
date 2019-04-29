#include "Game.h"

#include <iostream>

Game::Game() :
    level(1),
    score(0),
    tickVal(0),
    objects()
{
    urdEnemyX = new std::uniform_real_distribution<GLdouble>(-300, 300);
    urdEnemyY = new std::uniform_real_distribution<GLdouble>( 350, 450);

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
}

void Game::spawnEnemy() {
    GLdouble x = (*urdEnemyX)(re);
    GLdouble y = (*urdEnemyY)(re);

    GLdouble enemyPos[4][2] = {
        {x+10, y},
        {x+10, y + 20},
        {x-10, y + 20},
        {x-10, y}
    };
    enemy = new Enemy(this, enemyPos, 20 + (10 * (score / 10)), 2 + (score / 10));
    objects.push_back(enemy);
}

void Game::tick() {
    spawnEnemy();
}

GLint Game::collided(GLdouble vert[4][2], GLint type) {
    int sz = (int) objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];

        GLdouble oLeft = o->v[2][0],
            oRight = o->v[0][0],
            oTop = o->v[1][1],
            oBottom = o->v[0][1],

            objLeft = vert[2][0],
            objRight = vert[0][0],
            objTop = vert[1][1],
            objBottom = vert[0][1];

        if (objRight >= oLeft && objLeft <= oRight && objBottom <= oTop && objTop >= oBottom) {
            if (type == 0 && dynamic_cast<Bullet*>(o)) {
                // enemy with bullet
                ++score;
                objects.erase(objects.begin() + i);
                return o->collisionDamage;
            } else if (type == 1 && dynamic_cast<Enemy*>(o)) {
                // player with enemy
                objects.erase(objects.begin() + i);
                return o->collisionDamage;
            }
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

void Game::removeObjects() {
    std::vector<int> pos;

    int sz = objects.size();
    for (int i = 1; i < sz; ++i) {
        GameObject *o = objects[i];
        if (o->v[0][1] < -450 || o->v[1][1] > 550)
            pos.push_back(i);
    }

    auto b = objects.begin();
    for (int i : pos) {
        objects.erase(b + i);
    }
}

void Game::update() {
    if (player->health <= 0) {
        gameOver = true;
    }

    int sz = objects.size();
    for (int i = 0; i < sz; ++i) {
        GameObject *o = objects[i];
        o->update();
    }

    //if (score > 0 && score % 10 == 0) ++level;

    removeObjects();
}

void Game::draw() {
    if (gameOver) {
        drawString(-150, 9, "Game over! Press 'R' to play again.", GLUT_BITMAP_HELVETICA_18);
    } else {
        int sz = objects.size();
        for (int i = 0; i < sz; ++i) {
            GameObject *o = objects[i];
            o->draw();
        }

        glColor3ub(50, 50, 50);
        drawString(-290, 275, "Score: " + std::to_string(score), GLUT_BITMAP_HELVETICA_18);
        drawString(-290, 250, "Health: " + std::to_string(player->health), GLUT_BITMAP_HELVETICA_18);
        drawString(-290, 225, "Level: " + std::to_string(score / 10), GLUT_BITMAP_HELVETICA_18);
    }
}

void Game::restart() {
    level = 1;
    score = 0;
    player->health = 100;
    for (GameObject *o : objects) {
        delete o;
    }

    objects.clear();
    createObjects();
    gameOver = false;
}

void Game::keyDown(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
        case 'R':
            restart();
            break;
    }

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
