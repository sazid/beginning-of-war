#include "utils.h"

void drawString(GLdouble x, GLdouble y, std::string const& s, void* font) {
    // font - GLUT_BITMAP_HELVETICA_18 or anything available
    glRasterPos2d(x, y);
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        glutBitmapCharacter(font, s[i]);
    }
}

void drawCircle(GLdouble cx, GLdouble cy, GLfloat r, GLint steps) {
    glBegin(GL_TRIANGLE_FAN);
        // Center of the circle
        glVertex2f(cx, cy);
        GLfloat angle;
        for (GLint i = 0; i <= steps; ++i) {
            angle = i * 2.0f * PI / steps;
            glVertex2f(std::cos(angle) * r + cx, std::sin(angle) * r + cy);
        }
    glEnd();
}

void drawRectangle(GLdouble x, GLdouble y, GLdouble w, GLdouble h) {
    glBegin(GL_QUADS);

        glVertex2d(x, y);
        glVertex2d(x, y + h);
        glVertex2d(x - w, y + h);
        glVertex2d(x - w, y);

    glEnd();
}

void drawWithMirror(std::vector<std::pair<GLdouble, GLdouble> > v) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < (int)v.size(); ++i) {
		glVertex2d(v[i].first, v[i].second);
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 0; i < (int)v.size(); ++i) {
		glVertex2d(-v[i].first, v[i].second);
	}
	glEnd();
}
