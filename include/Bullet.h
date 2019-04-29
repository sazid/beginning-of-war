#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include <GL/glut.h>

class Bullet : public GameObject
{
    public:
        GLint movementSpeed;

        Bullet(void*, GLdouble[4][2]);
        virtual ~Bullet();

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

#endif // BULLET_H
