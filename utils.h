#pragma once

#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

#include "constants.h"

void drawString(GLdouble x, GLdouble y, std::string const& s, void* font);
void drawCircle(GLdouble cx, GLdouble cy, GLfloat r, GLint steps);
void drawRectangle(GLdouble x, GLdouble y, GLdouble w, GLdouble h);
void drawWithMirror(std::vector<std::pair<GLdouble, GLdouble> > v);

//class Player;
