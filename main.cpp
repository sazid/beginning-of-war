#include <windows.h>
#include "utils.h"
#include "Player.cpp"

void display();
void reshape(GLsizei width, GLsizei height);
void initOpenGL();
void specialKeyDown(int, int, int);
void specialKeyUp(int, int, int);
void keyDown(unsigned char, int, int);
void keyUp(unsigned char, int, int);
void createObjects();
bool checkCollision(GLdouble, GLdouble);

void Timer(GLint value);

std::default_random_engine re;
GLint refreshTimeMillis = 16;

GLfloat px=-1.0f;
GLfloat py=-1.0f;

GLboolean moveup=false, movedown=false,moveright=false,moveleft=false;

Player *p1;

int main(int argc, char **argv) {
    // Initialize glut
    glutInit(&argc, argv);

    // Set display mode
    // GLUT_DOUBLE - enable double buffering
    // GLUT_RGBA - RGBA color for display
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);

    // Set window size
    glutInitWindowSize(500, 500);

    // Set window position
    glutInitWindowPosition(100, 100);

    // Create the window
    glutCreateWindow("Beginning Of War");

    // Initialize OpenGL
    initOpenGL();

    // Set the display function callback, which will be called
    // over and over again, from glut's main loop
    glutDisplayFunc(display);

    // Keyboard interaction callback functions for arrow
    // and other special keys
    glutSpecialFunc(specialKeyDown);
    glutSpecialUpFunc(specialKeyUp);

    // Keyboard interaction for normal keys
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);

    createObjects();

    // Callback for when glut will remain idle
    // glutIdleFunc(display);

    // Callback for when the window state is changed (like resize)
    glutReshapeFunc(reshape);

    // Callback for controlling timer (FPS)
    glutTimerFunc(0, Timer, 0);

    // Start the main loop
    glutMainLoop();


    return 0;
}

void Timer(GLint value) {
    glutPostRedisplay();
    glutTimerFunc(refreshTimeMillis, Timer, 0);
}

void createObjects() {
    p1 = new Player;
}

GLdouble worldPos = 0.0;
void display() {
    // Use the preset color (using glClearColor) to redraw the color buffer
    // Call this to clear the current buffer and start anew
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(-2, 2, -2, 2);

	// To operate on Model-View matrix
	glMatrixMode(GL_MODELVIEW);
	// Reset the Model-View matrix
	glLoadIdentity();

	glClearColor(0.913, 0.6, 0.184, 1.0f);
	glBegin(GL_QUADS);
	glColor3ub(56,142,60);
	glVertex2f(-1.95,-1.95);
	glVertex2f(-1.95,1.95);
	glVertex2f(1.95,1.95);
	glVertex2f(1.95,-1.95);
	glEnd();



    p1->update(px,py,1,1,0,0);

    GLdouble newX = 0, newY = 0;
    if(moveup){
        newY=0.05;
    }
    else if(movedown){
        newY=-0.05;
    }

    if(moveright){
        newX=0.05;
    }
    else  if(moveleft){
        newX=-0.05;
    }

    if (!checkCollision(px + newX, py + newY)) {
        px += newX;
        py += newY;
    } else {
        drawString(-.3, 1, "Collided", GLUT_BITMAP_TIMES_ROMAN_24);
    }

    // After all the drawing is done, swap the two buffers (double buffer)
    // MUST CALL this
    glutSwapBuffers();
}

// return true if collision occurs else false
bool checkCollision(GLdouble x, GLdouble y) {
    if (x >= -0.5 && x <= 0.5 && y >= -0.45 && y <= 0.45) return true;
    if (x >= 1.67) return true;
    if (x <= -1.67) return true;
    if (y >= 1.75) return true;
    if (y <= -1.75) return true;
    return false;
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

void initOpenGL() {
    // set the color
    glClearColor(0, 0, 0, 1);
}


void keyDown(unsigned char key, int x, int y) {


}

void keyUp(unsigned char key, int x, int y) {
}

void specialKeyDown(int key, int x, int y) {
    switch(key)
    {
        case GLUT_KEY_UP:
        moveup=true;
        break;

        case GLUT_KEY_DOWN:
        movedown= true;
        break;

        case GLUT_KEY_RIGHT:
            moveright = true;
        break;

        case GLUT_KEY_LEFT:
            moveleft = true;
        break;

    }
}

void specialKeyUp(int key, int x, int y) {
    switch(key)
    {
        case GLUT_KEY_UP:
        moveup=false;
        break;

        case GLUT_KEY_DOWN:
        movedown= false;
        break;

        case GLUT_KEY_RIGHT:
            moveright = false;
        break;

        case GLUT_KEY_LEFT:
            moveleft = false;
        break;
    }
}
