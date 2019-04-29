#include "Game.h"

#include <iostream>

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

GLint Game::collided(GameObject &obj) {
    for (GameObject &o : this->objects) {

    }

    return 0;
}

void Game::nextLevel() {
    // Depending on this->level change the current background

    for (GameObject &o : this->objects) {
        o.nextLevel();
    }
}

void Game::update() {
    for (GameObject &o : this->objects) {
        o.update();
    }
}

void Game::draw() {
    for (GameObject &o : this->objects) {
        o.draw();
    }
}

void Game::keyDown(unsigned char key, int x, int y) {
    for (GameObject &o : this->objects) {
        o.keyDown(key, x, y);
    }
}

void Game::keyUp(unsigned char key, int x, int y) {
    for (GameObject &o : this->objects) {
        o.keyUp(key, x, y);
    }
}

void Game::specialKeyDown(int key, int x, int y) {
    for (GameObject &o : this->objects) {
        o.specialKeyDown(key, x, y);
    }
}

void Game::specialKeyUp(int key, int x, int y) {
    for (GameObject &o : this->objects) {
        o.specialKeyUp(key, x, y);
    }
}
