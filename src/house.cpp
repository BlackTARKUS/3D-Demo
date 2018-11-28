#include "house.h"
#include "glFuncs.h"

House::House() {
}

// creating House with specified geometry
House::House(vec3 position) : pos(position) {
	// Bottom Face
	this->verts.push_back( {-1.0, -1.0, 0.0} );
	this->verts.push_back( {-1.0,  1.0, 0.0} );
	this->verts.push_back( { 1.0,  1.0, 0.0} );
	this->verts.push_back( { 1.0, -1.0, 0.0} );

	// Left Face
	this->verts.push_back( {-1.0, -1.0, 0.0} );
	this->verts.push_back( {-1.0, -1.0, 1.0} );
	this->verts.push_back( { 1.0, -1.0, 1.0} );
	this->verts.push_back( { 1.0, -1.0, 0.0} );

	// Right Face
	this->verts.push_back( {-1.0,  1.0, 0.0} );
	this->verts.push_back( {-1.0,  1.0, 1.0} );
	this->verts.push_back( { 1.0,  1.0, 1.0} );
	this->verts.push_back( { 1.0,  1.0, 0.0} );

	// Back Face
	this->verts.push_back( {-1.0, -1.0, 0.0} );
	this->verts.push_back( {-1.0, -1.0, 1.0} );
	this->verts.push_back( {-1.0,  1.0, 1.0} );
	this->verts.push_back( {-1.0,  1.0, 0.0} );

	// Front Face
	this->verts.push_back( { 1.0, -1.0, 0.0} );
	this->verts.push_back( { 1.0, -1.0, 1.0} );
	this->verts.push_back( { 1.0,  1.0, 1.0} );
	this->verts.push_back( { 1.0,  1.0, 0.0} );

	// Top Face
	this->verts.push_back( {-1.0, -1.0, 1.0} );
	this->verts.push_back( {-1.0,  1.0, 1.0} );
	this->verts.push_back( { 1.0,  1.0, 1.0} );
	this->verts.push_back( { 1.0, -1.0, 1.0} );

	// Define the default values of the transformation vertices
	this->Tverts = verts;
}

// rotate House with new rotation direction
void House::rotate(float theta,float x,float y,float z) {
	glPushMatrix();
	glRotatef(theta,x,y,z);
	this->render();
	glPopMatrix();
}

void House::render() {
	// draw the House
	glBegin(GL_POLYGON);
	for(unsigned i=0; i < this->Tverts.size(); i++) {
		glVertex3f(this->Tverts[i].x, this->Tverts[i].y, 0.0);
	}
	glEnd();
}
