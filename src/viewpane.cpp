#include "viewpane.h"
#include "house.h"
#include "lgeom.h"
#include "glFuncs.h"

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

	// Draw the axis
	float Len = 12.0; // Length of the Axis
	glPointSize(1.0);
	glColor3ub(255,0,0);
	glBegin(GL_LINES);
		glVertex3i(0,Len,0);
		glVertex3i(0,-Len,0);
	glEnd();
	glColor3ub(0,255,0);
	glBegin(GL_LINES);
		glVertex3i(Len,0,0);
		glVertex3i(-Len,0,0);
	glEnd();
	glColor3ub(0,0,255);
	glBegin(GL_LINES);
		glVertex3i(0,0,Len);
		glVertex3i(0,0,-Len);
	glEnd();

	// Draw the House
    this->house.render();
}
