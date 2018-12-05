#include <GL/glut.h>
#include "house.h"

void initMenu(){
	// create a menu which uses processMenuEvents to handle functions
	menuMaster = glutCreateMenu(processMenuEvents);
	int axState = 0;
	int signSate = 0;

	/* Create submenu viewMenu */
	int vMen = glutCreateMenu(viewMenu);
	glutAddMenuEntry("glPerspective", 1);
	glutAddMenuEntry("glOrtho", 2);
	glutAddMenuEntry("glCustom", 3);

	/* Create submenu polyMenu */
	int vMen = glutCreateMenu(polyMenu);
	glutAddMenuEntry("Wire Mesh", 1);
	glutAddMenuEntry("Filled Faces", 2);

	/* Create main menu */
	int mMen = glutCreateMenu(mainMenu);
	glutAddMenuEntry("Viewing mode", 1);
	glutAddMenuEntry("Toggle Axes", 2);
	glutAddMenuEntry("Toggle Sign", 3);
	glutAddMenuEntry("Toggle Figure Fill Mode", 4);
	glutAddMenuEntry("Reset Figure", 5);
	glutAddMenuEntry("Quit", 6);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void mainMenu(int m) {
	switch(m){
		case 1:

			break;
		case 2:
			if(axState == 1){
				axState = 0;
				glutChangeToMenuEntry(2, "Toggle Axes On", 2);
			}
			else{
				axState = 1;
				glutChangeToMenuEntry(2, "Toggle Axes off", 2);
			}
			break;
		case 3:
			if(signState == 1){
				signState = 0;
				glutChangeToMenuEntry(3, "Toggle Sign On", 3);
			}
			else{
				signState = 1;
				glutChangeToMenuEntry(3, "Toggle Sign Off", 3);
			}
			break;
		case 5: /* Reset all values back to their initial state */
			this->house.theta = {0.0,0.0,0.0};
			this->house.alpha = {0.0,0.0,0.0};
			ZOOMSCALE = 80;
			glutPostRedisplay();
			reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
			break;
		case 6:  exit(0); break; /* Kill the program */
	};
}

// A submenu to control the viewmode
void viewMenu(int v){
	switch(value){
		case 1:  VIEWMODE = 0; break; /* glPerspective */
		case 2:  VIEWMODE = 1; break; /* glOrtho */
		case 3:  VIEWMODE = 2; break; /* glCustom */
	};
}

// A submenu to control the fillmode of the polygon
void polyMenu(int v){
	switch(value){
		case 1:  FILLMODE = GL_LINE_LOOP; break; /* Wire Mesh */
		case 2:  FILLMODE = GL_POLYGON; break; /* Filld Faces */
	};
}
