#include <GL/glut.h>
#include "glFuncs.h"
#include "viewpane.h"

// Specify the values to place and size the window on the screen
const int WINDOW_POSITION_X = 500;
const int WINDOW_POSITION_Y = 5;
const int WINDOW_MAX_X = 1000;
const int WINDOW_MAX_Y = 1000;

Viewpane v;

void display( void ) {
	v.render();
	glutSwapBuffers();
}

void reshape( int w, int h ) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(10,10,10,10);
	glOrtho(-10.0, 10.0, -10.0, 10.0, 1.0, 20.0);

	glMatrixMode (GL_MODELVIEW);
}

// relay functions for key handling
void MouseClicked(int button, int state, int x, int y) { 
	v.MouseClicked(button, state, x, y); 
}
void KeyDown(unsigned char key, int x, int y) { v.KeyDown(key, x, y); }
void KeySpecial(int key, int x, int y) { v.KeySpecial(key, x, y); }

int main(int argc, char** argv) {

	setupGlut(
		WINDOW_POSITION_X,
		WINDOW_POSITION_Y,
		WINDOW_MAX_X,
		WINDOW_MAX_Y
	);

	v.init(WINDOW_MAX_X, WINDOW_MAX_Y);

	glutMouseFunc(MouseClicked);
	glutSpecialFunc(KeySpecial);
	glutKeyboardFunc(KeyDown);

	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
}

