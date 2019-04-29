#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include <GL/glut.h>

class Enemy : public GameObject
{
    public:
        GLint movementSpeed;
        GLint health;

        Enemy(void*, GLdouble[4][2], GLint, GLdouble);
        virtual ~Enemy();

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

#endif // ENEMY_H
