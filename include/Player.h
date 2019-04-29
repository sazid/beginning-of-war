#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <GL/glut.h>

class Player : public GameObject
{
    public:
        Player(void*, GLdouble[4][2]);
        virtual ~Player();

        void update() override;
        void draw() override;
        void nextLevel() override;

    protected:

    private:
};

#endif // PLAYER_H
