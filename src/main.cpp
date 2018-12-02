#include <GL/glut.h>
#include "glFuncs.h"
#include "globals.h"
#include "viewpane.h"

Viewpane VP;

void display( void ) {
	VP.render();
	glutSwapBuffers();
}

// relay functions for key handling
void MouseClicked(int button, int state, int x, int y) {
	VP.MouseClicked(button, state, x, y);
}
void KeyDown(unsigned char key, int x, int y) { VP.KeyDown(key, x, y); }
void KeySpecial(int key, int x, int y) { VP.KeySpecial(key, x, y); }

int main(int argc, char** argv) {

	setupGlut(
		WINDOW_POSITION_X,
		WINDOW_POSITION_Y,
		WINDOW_MAX_X,
		WINDOW_MAX_Y
	);

	VP.init(WINDOW_MAX_X, WINDOW_MAX_Y);

	glutMouseFunc(MouseClicked);
	glutSpecialFunc(KeySpecial);
	glutKeyboardFunc(KeyDown);

	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
}

