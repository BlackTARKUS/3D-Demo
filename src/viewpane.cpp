#include "glFuncs.h"
#include "house.h"
#include "lgeom.h"
#include "viewpane.h"
#include "sign.h"

Viewpane::Viewpane() {}

void Viewpane::init(int window_width, int window_height) {
	this->origin = { window_width/2.0f, window_height/2.0f };
}

void Viewpane::render() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();
	gluLookAt (-2.25, 1.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	drawAxis();

	// Draw Sign
	glColor3ub(255,255,255);
	glLineWidth(8.0);
	renderStrokeFontString( -1.5, 1.25, 1.25, (char*)"Hello World!");

    this->house.render();
}

// Draw the axis and lebel them with a bitmap font
void Viewpane::drawAxis(){
	float Len = 20.0; // Length of the Axis
	glLineWidth(2.0);

	// Y Axis
	glColor3ub(255,0,0);
	glRasterPos2f(0.1, 2.1);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
	glBegin(GL_LINES);
		glVertex3i(0,Len,0);
		glVertex3i(0,-Len,0);
	glEnd();

	// Z Axis
	glColor3ub(0,0,255);
	glRasterPos2f(28.0, -18.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Z');
	glColor3ub(0,255,0);
	glBegin(GL_LINES);
		glVertex3i(Len,0,0);
		glVertex3i(-Len,0,0);
	glEnd();

	// X Axis
	glColor3ub(0,255,0);
	glRasterPos2f(-2.2, -0.18);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
	glColor3ub(0,0,255);
	glBegin(GL_LINES);
		glVertex3i(0,0,Len);
		glVertex3i(0,0,-Len);
	glEnd();
}
