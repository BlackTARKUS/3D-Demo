#include "glFuncs.h"
#include "house.h"
#include "lgeom.h"
#include "viewpane.h"
#include "sign.h"

Viewpane::Viewpane() {

}

void Viewpane::init(int window_width, int window_height) {
	this->origin = { window_width/2.0f, window_height/2.0f };
}

void Viewpane::render() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();
	gluLookAt (-2.25, 1.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	// Draw the axis and lebel them with a bitmap font
	float Len = 20.0; // Length of the Axis
	glLineWidth(2.0);
	glColor3ub(255,0,0);
	glRasterPos2f(0.1, 2.1);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
	glBegin(GL_LINES);
		glVertex3i(0,Len,0);
		glVertex3i(0,-Len,0);
	glEnd();
	glColor3ub(0,255,0);
	glRasterPos2f(28.0, -18.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
	glBegin(GL_LINES);
		glVertex3i(Len,0,0);
		glVertex3i(-Len,0,0);
	glEnd();
	glColor3ub(0,0,255);
	glRasterPos2f(-2.1, -0.2);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Z');
	glBegin(GL_LINES);
		glVertex3i(0,0,Len);
		glVertex3i(0,0,-Len);
	glEnd();

	// Draw Sign
	//glColor3ub(255,255,255);
	//glLineWidth(8.0);
	//renderStrokeFontString( 0.0, 0.0, 0.0, (char*)"Hello World!");

	// Draw the House
    this->house.render();
}
