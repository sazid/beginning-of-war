#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(void *game, GLdouble vert[4][2])
{
    this->game = game;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] = vert[i][j];
        }
    }
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::keyUp(unsigned char, int, int) {
}

void GameObject::keyDown(unsigned char, int, int) {
}

void GameObject::specialKeyUp(int, int, int) {
}

void GameObject::specialKeyDown(int, int, int) {
}
