#include "globals.h"
#include <GL/glut.h>

// Specify the values to place and size the window on the screen
int WINDOW_POSITION_X = 550;
int WINDOW_POSITION_Y = 50;
int WINDOW_MAX_X = 600;
int WINDOW_MAX_Y = 600;

float ZOOMSCALE = 80;
int VIEWMODE = 0;
int FILLMODE = GL_POLYGON;
int DRAWAXES = 1;
int DRAWSIGN = 1;

point THETA = {0.0,0.0,0.0};
point ALPHA = {0.0,0.0,0.0};
