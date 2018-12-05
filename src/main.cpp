#include <GL/glut.h>
#include "glFuncs.h"
#include "globals.h"
#include "viewpane.h"
#include "menu.h"

Viewpane VP;

void display( void ) {
	VP.render();
	glutSwapBuffers();
}

/* Defines the angle at which the polygon is drawn as a function of the previous
 * angle + the delta value, then posts the polygon for redisplay
*/
void SpinDisplay( void ) {
	VP.house.theta.x = VP.house.theta.x + VP.house.alpha.x;
	VP.house.theta.y = VP.house.theta.y + VP.house.alpha.y;
	VP.house.theta.z = VP.house.theta.z + VP.house.alpha.z;
	if(VP.house.theta.x > 360.0) {VP.house.theta.x = VP.house.theta.x - 360.0;}
	if(VP.house.theta.y > 360.0) {VP.house.theta.y = VP.house.theta.y - 360.0;}
	if(VP.house.theta.z > 360.0) {VP.house.theta.z = VP.house.theta.z - 360.0;}
	glutPostRedisplay();
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
	glutMainLoop();
}

