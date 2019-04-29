#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GL/glut.h>

class GameObject
{
    public:
        // Vertices for bounding box of the object
        // 4 vertices, each having two values - x, y
        // The bounding box will be used for collision detection
        GLdouble v[4][2];
        GLint collisionDamage {0};
        void *game;

        GameObject(void*, GLdouble[4][2]);
        virtual ~GameObject();
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void nextLevel() = 0;
        virtual void keyUp(unsigned char, int, int);
        virtual void keyDown(unsigned char, int, int);
        virtual void specialKeyUp(int, int, int);
        virtual void specialKeyDown(int, int, int);

    protected:

    private:
};

#endif // GAMEOBJECT_H
