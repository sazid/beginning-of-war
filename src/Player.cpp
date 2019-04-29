#include "Player.h"

#include <GL/glut.h>

Player::Player(void *game, GLdouble vert[4][2]) : GameObject(game, vert)
{
    this->game = game;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] = vert[i][j];
        }
    }
}

Player::~Player()
{
    //dtor
}

void Player::update() {

}

void Player::draw() {

}

void Player::nextLevel() {

}
