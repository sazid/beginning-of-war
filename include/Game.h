#ifndef GAME_H
#define GAME_H

#include <vector>
#include <GL/glut.h>
#include <random>
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "../utils.h"

class Game
{
    public:
        GLint level;
        GLint score;
        GLboolean newGame;

        Game();
        virtual ~Game();
        void update();
        void draw();
        void nextLevel();

        void createObjects();

        void specialKeyDown(int, int, int);
        void specialKeyUp(int, int, int);
        void keyDown(unsigned char, int, int);
        void keyUp(unsigned char, int, int);

        // Return 0 if not collided, otherwise return a
        // positive integer indicating the amount of damage taken
        // Also, returning negative may also be used to increase
        // health by colliding with med-kits
        GLint collided(GLdouble[4][2]);
        std::vector<GameObject* > objects;

    protected:

    private:
        Player *player;
        Enemy *enemy;
};

#endif // GAME_H
