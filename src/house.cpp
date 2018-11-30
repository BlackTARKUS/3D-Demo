#include "house.h"
#include "glFuncs.h"
#include <stdlib.h>

House::House() {
	// Bottom Face
	this->V.push_back( {-1.0, -1.0, 0.0} );
	this->V.push_back( {-1.0,  1.0, 0.0} );
	this->V.push_back( { 1.0,  1.0, 0.0} );
	this->V.push_back( { 1.0, -1.0, 0.0} );

	// Left Face
	this->V.push_back( {-1.0, -1.0, 0.0} );
	this->V.push_back( {-1.0, -1.0, 1.0} );
	this->V.push_back( { 1.0, -1.0, 1.0} );
	this->V.push_back( { 1.0, -1.0, 0.0} );

	// Right Face
	this->V.push_back( {-1.0,  1.0, 0.0} );
	this->V.push_back( {-1.0,  1.0, 1.0} );
	this->V.push_back( { 1.0,  1.0, 1.0} );
	this->V.push_back( { 1.0,  1.0, 0.0} );

	// Back Face
	this->V.push_back( {-1.0, -1.0, 0.0} );
	this->V.push_back( {-1.0, -1.0, 1.0} );
	this->V.push_back( {-1.0,  1.0, 1.0} );
	this->V.push_back( {-1.0,  1.0, 0.0} );

	// Front Face
	this->V.push_back( { 1.0, -1.0, 0.0} );
	this->V.push_back( { 1.0, -1.0, 1.0} );
	this->V.push_back( { 1.0,  1.0, 1.0} );
	this->V.push_back( { 1.0,  1.0, 0.0} );

	// Top Face
	this->V.push_back( { 1.0,  1.0, 1.0} );
	this->V.push_back( {-1.0,  1.0, 1.0} );
	this->V.push_back( {-1.0, -1.0, 1.0} );
	this->V.push_back( { 1.0, -1.0, 1.0} );

	// Roof Front Face
	this->V.push_back( { 1.0, -1.0, 0.0} );
	this->V.push_back( { 1.0, -1.0, 1.0} );
	this->V.push_back( { 1.0,  1.0, 1.0} );
	this->V.push_back( { 1.0,  1.0, 0.0} );
}

// rotate House with new rotation direction
void House::rotate(float theta,float x,float y,float z) {
	glPushMatrix();
	glRotatef(theta,x,y,z);
	this->render();
	glPopMatrix();
}

void House::colo(int i, int &c1, int &c2, int &c3){
	switch(i){
		case 0:
			c1 = 0; c2 = 153; c3 = 255;
			break;
		case 4:
			c1 = 102; c2 = 255; c3 = 153;
			break;
		case 8:
			c1 = 255; c2 = 102; c3 = 102;
			break;
		case 12:
			c1 = 255; c2 = 102; c3 = 255;
			break;
		case 16:
			c1 = 255; c2 = 255; c3 = 102;
			break;
		case 20:
			c1 = 51; c2 = 153; c3 = 51;
			break;
		case 24:
			c1 = 204; c2 = 102; c3 = 153;
			break;
		case 28:
			c1 = 102; c2 = 51; c3 = 0;
			break;
	}
}

// draw the House
void House::render() {
	int c1, c2, c3;

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	for(unsigned i=0;i<this->V.size();i+=4) {
		colo(i,c1,c2,c3);
		glColor3ub(c1,c2,c3);
		glBegin(GL_POLYGON);
			glVertex3i(this->V[i].x,this->V[i].y,this->V[i].z);
			glVertex3i(this->V[i+1].x,this->V[i+1].y,this->V[i+1].z);
			glVertex3i(this->V[i+2].x,this->V[i+2].y,this->V[i+2].z);
			glVertex3i(this->V[i+3].x,this->V[i+3].y,this->V[i+3].z);
		glEnd();
	}
}
