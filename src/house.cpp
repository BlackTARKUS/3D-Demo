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

}

// rotate House with new rotation direction
void House::rotate(float theta,float x,float y,float z) {
	glPushMatrix();
	glRotatef(theta,x,y,z);
	this->render();
	glPopMatrix();
}

// draw the House
void House::render() {

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	for(unsigned j=0;j<this->verts.size();j++) {

		glBegin(GL_POLYGON);
		for(unsigned i=0;i<4;i++) {
			glVertex3f(this->verts[i].x,
					   this->verts[i].y,
					   this->verts[i].z);
		}
		glEnd();
	}

	glutSwapBuffers();
}
