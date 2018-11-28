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
}

void update( void ) {
	v.update();
	display();
}

// relay functions for key handling
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
	glutSpecialFunc(KeyboardSpecial);
	glutKeyboardFunc(KeyboardDown);

	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(update);
	glutMainLoop();
}

