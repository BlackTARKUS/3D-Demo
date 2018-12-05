#include "glFuncs.h"
#include "globals.h"

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

void reshape( int w, int h ) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	switch(VIEWMODE){
		case 0:
			gluPerspective(ZOOMSCALE,1.0,0.1,100.0); break;
		case 1:
			glOrtho(-2.0, 2.0, -2.0, 2.0, -1.5, 100.0); break;
		case 2:
			break;
	};

	glMatrixMode (GL_MODELVIEW);
}
