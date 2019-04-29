#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <GL/glut.h>

class Player : public GameObject
{
    public:
        GLint movementSpeed;

        Player(void*, GLdouble[4][2]);
        virtual ~Player();

        void update() override;
        void draw() override;
        void nextLevel() override;

        void keyUp(unsigned char, int, int) override;
        void keyDown(unsigned char, int, int) override;
        void specialKeyUp(int, int, int) override;
        void specialKeyDown(int, int, int) override;

    protected:

    private:
};

#endif // PLAYER_H
