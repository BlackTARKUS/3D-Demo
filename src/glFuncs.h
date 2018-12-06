#ifndef GLFUNCS_H
#define GLFUNCS_H

#include <GL/glut.h>
#include "point.h"

void setupGlut( int wpx, int wpy, int wdx, int wdy );
void setupGL( int wdx, int wdy );
void reshape( int w, int h );
void SpinDisplay( void );
void display( void );
float getSign(point a, point b, point c);
int pointInTriangle(int x, int y);
void renderStrokeFontString(char *string);

#endif // GLFUNCS_H
