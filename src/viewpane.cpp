#include "viewpane.h"
#include "house.h"
#include "lgeom.h"
#include "glFuncs.h"

Viewpane::Viewpane() {

}

void Viewpane::init(int window_width, int window_height) {
	this->origin = { window_width/2.0f, window_height/2.0f };

	this->house.pos = origin;
}

void Viewpane::render() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();             /* clear the matrix */
	// the camera back
	glTranslatef(0.0, 0.0, -10.0);
	gluLookAt (6.0, 5.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);


	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	// draw the current view mode in the top right
	char mode[5] = {'$','m','o','d','e'};
	for(unsigned i = 0; i < 5; i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, mode[i]);
	}

	// Draw the axis
	float Len = 8.0;
	glPointSize(1.0);
	glBegin(GL_LINES);
	glVertex3i(0,Len,0);
	glVertex3i(0,-Len,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3i(Len,0,0);
	glVertex3i(-Len,0,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3i(0,0,Len);
	glVertex3i(0,0,-Len);
	glEnd();

	// Draw the House
    this->house.render();
	
}
