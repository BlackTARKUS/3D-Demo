#ifndef GLFUNCS_H
#define GLFUNCS_H

#include <GL/glut.h>
#include "point.h"

float getSign( point a, point b, point c );
int pointInTriangle( int x, int y );
void display( void );
void glCustom( GLfloat, GLfloat, GLfloat, GLfloat );
void renderBitmapFontString( char *string );
void renderStrokeFontString( char *string );
void reshape( int w, int h );
void setupGL( int wdx, int wdy );
void setupGlut( int wpx, int wpy, int wdx, int wdy );
void SpinDisplay( void );

#endif // GLFUNCS_H
