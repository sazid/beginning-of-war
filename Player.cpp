#include "utils.h"

class Player {
public:
    void start() {

    }

    void update(GLfloat px,GLfloat py,GLfloat gx, GLfloat gy,GLfloat tx, GLfloat ty) {
        //gun
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(gx,gy,0);

        glBegin(GL_QUADS);
        glColor3ub(0,96,100);
        glVertex2f(-.2,-.05);
        glVertex2f(-.2,.05);
        glVertex2f(.1,.05);
        glVertex2f(.1,-.05);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(38,50,56);
        glVertex2f(-.2,-.02);
        glVertex2f(-.2,.02);
        glVertex2f(.15,.02);
        glVertex2f(.15,-.02);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(38,50,56);
        glVertex2f(-.15,-.08);
        glVertex2f(-.12,.02);
        glVertex2f(.0,.02);
        glVertex2f(-.02,-.08);
        glEnd();

        glPopMatrix();

        //player
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(px,py,0);


        glBegin(GL_QUADS);
        glColor3ub(229,57,53);
        glVertex2f(-.3,-.1);
        glVertex2f(-.3,.1);
        glVertex2f(.3,.1);
        glVertex2f(.3,-.1);
        glEnd();

        glBegin(GL_QUADS);

        glColor3ub(255,235,59);
        glVertex2f(-.2,-.2);
        glVertex2f(-.2,.2);
        glVertex2f(.2,.2);
        glVertex2f(.2,-.2);

        glEnd();

        glPopMatrix();

        //tree
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(tx,ty,0);

        glBegin(GL_QUADS);
        glColor3ub(124,179,66);
        glVertex2f(-.3,-.3);
        glVertex2f(-.3,.3);
        glVertex2f(.3,.3);
        glVertex2f(.3,-.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(192,202,51);
        glVertex2f(-.15,-.3);
        glVertex2f(-.15,.3);
        glVertex2f(.15,.3);
        glVertex2f(.15,-.3);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(192,202,51);
        glVertex2f(-.3,-.15);
        glVertex2f(-.3,.15);
        glVertex2f(.3,.15);
        glVertex2f(.3,-.15);
        glEnd();

        glPopMatrix();



    }
};
