#include "glFuncs.h"
#include "globals.h"
#include <math.h>

void setupGlut( int wpx, int wpy, int wdx, int wdy ) {
	// pass dummy args to glutInit
	int myargc = 0;
	char *myargv[1] = {(char*)"blank"};
	glutInit(&myargc, myargv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(wdx, wdy);
	glutInitWindowPosition(wpx, wpy);
	glutCreateWindow("Houses");
	setupGL(wdx, wdy);
}

void setupGL( int wdx, int wdy ) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// set viewport to be same dimensions as window
	gluOrtho2D(0.0, wdx, 0.0, wdy);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(2.0);
}

// Alternative to gluPerspective
void glCustom(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar) {

	GLfloat m[16] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
					 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
	float xmax = zFar + zNear;
	float xmin = zNear - zFar;

	// determines xmax using the tangent of the horizontal FOV and pi/360
	float f = atan(fovy/2);

	m[0]  = f/aspect;
	m[5]  = f;
	m[10] = xmax/xmin;
	m[11] = (2*xmax)/xmin;
	m[14] = -1.0;

	glLoadMatrixf(m);
}

void reshape( int w, int h ) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch(VIEWMODE){
		case 0:
			gluPerspective(ZOOMSCALE,1.0,0.1,100.0);     break;
		case 1:
			glOrtho(-2.0, 2.0, -2.0, 2.0, -1.5, 100.0);  break;
		case 2:
			glCustom(ZOOMSCALE,1.0,0.1,100.0);           break;
	};

	glMatrixMode (GL_MODELVIEW);
}

// Render a string as a stroke font in 3D space
void renderStrokeFontString(char *string) {
	char *c;
	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
}

//////////////////////////////////////////////////////
// determine if point is in triangle
// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
//////////////////////////////////////////////////////
float getSign(point a, point b, point c) {
	return ( (c.x - b.x) * (a.y - b.y) - (a.x -  b.x) * (c.y - b.y) );
}
// Used to check if mouse coords are inside of the triangle at the base of VP
int pointInTriangle(int x, int y) {
	point p = {(float)x, (float)y, 0.0};
	point a = {0.0,(float)WINDOW_MAX_Y,0.0};
	point b = {(float)WINDOW_MAX_X,(float)WINDOW_MAX_Y,0.0};
	point c = {(float)(WINDOW_MAX_X/2),(float)(WINDOW_MAX_Y/2),0.0};
	float ABP = getSign(a,b,p);
	float BCP = getSign(b,c,p);
	float CAP = getSign(c,a,p);
	// if Z components match, then the mouse is in the triangle
	return (ABP>0 && BCP>0 && CAP>0) || (ABP<0 && BCP<0 && CAP<0);
}
