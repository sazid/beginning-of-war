#include <windows.h>
#include "utils.h"
#include "Game.h"

void display();
void reshape(GLsizei width, GLsizei height);
void initOpenGL();
void specialKeyDown(int, int, int);
void specialKeyUp(int, int, int);
void keyDown(unsigned char, int, int);
void keyUp(unsigned char, int, int);

void Timer(GLint value);
void Timer2(GLint value);

std::default_random_engine re;
GLint refreshTimeMillis = 16;
GLint secondTimerRefresh = 500;

// -------------- Game objects ----------------- //
Game game;

int main(int argc, char **argv) {
    // Initialize glut
    glutInit(&argc, argv);

    // Set display mode
    // GLUT_DOUBLE - enable double buffering
    // GLUT_RGBA - RGBA color for display
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);

    // Set window size
    glutInitWindowSize(600, 600);

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

    // Callback for when glut will remain idle
    // glutIdleFunc(display);

    // Callback for when the window state is changed (like resize)
    glutReshapeFunc(reshape);

    // Callback for controlling timer (FPS)
    glutTimerFunc(0, Timer, 0);
    glutTimerFunc(0, Timer2, 0);

    // Start the main loop
    glutMainLoop();


    return 0;
}

void Timer(GLint value) {
    // UPDATE HERE
    game.update();

    glutPostRedisplay();
    glutTimerFunc(refreshTimeMillis, Timer, 0);
}

void Timer2(GLint value) {
    // UPDATE HERE
    game.tick();

    glutPostRedisplay();
    glutTimerFunc(secondTimerRefresh, Timer2, 0);
}

GLdouble worldPos = 0.0;
void display() {
    // Use the preset color (using glClearColor) to redraw the color buffer
    // Call this to clear the current buffer and start anew
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(-300, 300, -300, 300);

	// To operate on Model-View matrix
	glMatrixMode(GL_MODELVIEW);
	// Reset the Model-View matrix
	glLoadIdentity();

	// DRAW HERE
	game.draw();

    // After all the drawing is done, swap the two buffers (double buffer)
    // MUST CALL this
    glutSwapBuffers();
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
    glClearColor(1, 1, 1, 1);
}

void keyDown(unsigned char key, int x, int y) {
    game.keyDown(key, x, y);
}

void keyUp(unsigned char key, int x, int y) {
    game.keyUp(key, x, y);
}

void specialKeyDown(int key, int x, int y) {
    game.specialKeyDown(key, x, y);
}

void specialKeyUp(int key, int x, int y) {
    game.specialKeyUp(key, x, y);
}
