#include "glFuncs.h"
#include "house.h"
#include "point.h"
#include "viewpane.h"
#include "sign.h"
#include "globals.h"

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
	//glColor3ub(255,255,255);
	//glPushMatrix();
	//glLineWidth(8.0);
	//renderStrokeFontString( -1.5, 1.25, 1.25, (char*)"Hello World!");
	//glPopMatrix();

	this->house.render();
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
