#include "glFuncs.h"
#include "globals.h"
#include "house.h"
#include "sign.h"
#include "viewpane.h"

Viewpane::Viewpane() {}

void Viewpane::init(int window_width, int window_height) {
	this->origin = { window_width/2.0f, window_height/2.0f };
	initMenu();
}

void Viewpane::render() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Positions our camera at an angle to view our 3D space
	gluLookAt(-2.25, 1.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	drawAxis(); /* Draws the axis and their labels in the viewport */

	glPushMatrix();
	this->house.rotate();
	this->house.render();
	glPopMatrix();
}

// Draw the axis and lebel them with a bitmap font
void Viewpane::drawAxis(){
	float Len = 20.0; // Length of the Axis
	glLineWidth(2.0);

	// Y Axis
	glColor3ub(255,0,0);
	glPushMatrix();
	glTranslatef(0.0, 2.0, 0.2);
	glRotatef(100.0, 0.0, 1.0, 0.0);
	glScalef(0.00175,0.00175,1.0);
	renderStrokeFontString( (char*)"Y" );
	glPopMatrix();

	glBegin(GL_LINES);
		glVertex3i(0,Len,0);
		glVertex3i(0,-Len,0);
	glEnd();

	// Z Axis
	glColor3ub(0,0,255);
	glPushMatrix();
	glTranslatef(0.2, -0.1, 2.1);
	glRotatef(-45.0, 0.0, 1.0, 0.0);
	glScalef(0.00175,0.00175,1.0);
	renderStrokeFontString( (char*)"Z" );
	glPopMatrix();

	glColor3ub(0,255,0);
	glBegin(GL_LINES);
		glVertex3i(Len,0,0);
		glVertex3i(-Len,0,0);
	glEnd();

	// X Axis
	glColor3ub(0,255,0);
	glPushMatrix();
	glTranslatef(-2.2, 0.2, 0.2);
	glRotatef(40.0, 0.0, 1.0, 0.0);
	glScalef(0.00175,0.00175,1.0);
	renderStrokeFontString( (char*)"X" );
	glPopMatrix();

	glColor3ub(0,0,255);
	glBegin(GL_LINES);
		glVertex3i(0,0,Len);
		glVertex3i(0,0,-Len);
	glEnd();
}

///////////////////////////////////////////////////////////////
// 						Menu Handling					 	 //
///////////////////////////////////////////////////////////////

void mainMenuHandler(int choice) {

	switch(choice) {
		case 1:
			break;
		case 2:
			break;
		case 3: /* Reset all values back to their initial state */
			THETA = {0.0,0.0,0.0};
			ALPHA = {0.0,0.0,0.0};
			ZOOMSCALE = 80;
			glutPostRedisplay();
			reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
			break;
		case 4: exit(0); break;
	}
}
void viewMenuHandler(int choice) {

	switch(choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
	}
}
void polygonMenuHandler(int choice) {

	switch(choice) {
		case 1:
			break;
		case 2:
			break;
	}
}

void initMenu() {

	int vMenu = glutCreateMenu(viewMenuHandler);
	glutAddMenuEntry("glPerspective", 1);
	glutAddMenuEntry("glOrtho", 2);
	glutAddMenuEntry("glCustom", 3);

	int pMenu = glutCreateMenu(polygonMenuHandler);
	glutAddMenuEntry("Filled Faces", 1);
	glutAddMenuEntry("Wire Mesh", 2);

	//add entries to our menu
	int menu = glutCreateMenu(mainMenuHandler);
	glutAddSubMenu("Viewing mode", vMenu);
	glutAddMenuEntry("Toggle Axes", 1);
	glutAddMenuEntry("Toggle Sign", 2);
	glutAddSubMenu("Polygon Fill Mode", pMenu);
	glutAddMenuEntry("Reset", 3);
	glutAddMenuEntry("Quit", 4);

	// attach the menu to the right button
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
}
