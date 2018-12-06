#include "glFuncs.h"
#include "globals.h"
#include "house.h"

/* The house is stored as a long series of sequential points in 3D space
 * which are then assembled into polygonal faces by the render function
 * colors are also assigned by the render function.
*/
House::House() {
	// <--------- Body Faces ---------> //
	this->V.push_back( {-1.0, 0.0, 0.0} ); /* <[[Bottom Face]]>     */
	this->V.push_back( {-1.0, 0.0, 1.0} );
	this->V.push_back( { 1.0, 0.0, 1.0} );
	this->V.push_back( { 1.0, 0.0, 0.0} ); /* <- End Face ->        */
	this->V.push_back( {-1.0, 0.0, 0.0} ); /* <[[Back Face]]>       */
	this->V.push_back( {-1.0, 1.0, 0.0} );
	this->V.push_back( { 1.0, 1.0, 0.0} );
	this->V.push_back( { 1.0, 0.0, 0.0} ); /* <- End Face ->        */
	this->V.push_back( {-1.0, 0.0, 0.0} ); /* <[[Left Face]]>       */
	this->V.push_back( {-1.0, 0.0, 1.0} );
	this->V.push_back( {-1.0, 1.0, 1.0} );
	this->V.push_back( {-1.0, 1.0, 0.0} ); /* <- End Face ->        */
	this->V.push_back( { 1.0, 0.0, 0.0} ); /* <[[Right Face]]>      */
	this->V.push_back( { 1.0, 0.0, 1.0} );
	this->V.push_back( { 1.0, 1.0, 1.0} );
	this->V.push_back( { 1.0, 1.0, 0.0} ); /* <- End Face ->        */
	this->V.push_back( { 1.0, 1.0, 1.0} ); /* <[[Front Face]]>      */
	this->V.push_back( {-1.0, 1.0, 1.0} );
	this->V.push_back( {-1.0, 0.0, 1.0} );
	this->V.push_back( { 1.0, 0.0, 1.0} ); /* <- End Face ->        */
	// <--------- Roof  Faces ---------> //
	this->V.push_back( {-1.1, 1.0,-0.1} );	/* <[[Top Left Face]]>  */
	this->V.push_back( {-1.1, 1.0, 1.1} );
	this->V.push_back( { 0.0, 1.2, 1.1} );
	this->V.push_back( { 0.0, 1.2,-0.1} ); /* <- End Face ->       */
	this->V.push_back( { 0.0, 1.2,-0.1} );	/* <[[Top Right Face]]> */
	this->V.push_back( { 0.0, 1.2, 1.1} );
	this->V.push_back( { 1.1, 1.0, 1.1} );
	this->V.push_back( { 1.1, 1.0,-0.1} ); /* <- End Face ->       */
	this->V.push_back( {-1.1, 1.0,-0.1} );	/* <[[Roof Base Face]]> */
	this->V.push_back( {-1.1, 1.0, 1.1} );
	this->V.push_back( { 1.1, 1.0, 1.1} );
	this->V.push_back( { 1.1, 1.0,-0.1} ); /* <- End Face ->       */
	this->V.push_back( { 0.0, 1.2, 1.1} );	/* <[[Front Triangle]]> */
	this->V.push_back( {-1.1, 1.0, 1.1} );
	this->V.push_back( { 1.1, 1.0, 1.1} ); /* <- End Face ->       */
	this->V.push_back( { 0.0, 1.2,-0.1} );	/* <[[back Triangle]]>  */
	this->V.push_back( {-1.1, 1.0,-0.1} );
	this->V.push_back( { 1.1, 1.0,-0.1} ); /* <- End Face ->       */
}

/* Stores a ton of predefined colours that I have specified ahead of time
 * colo function choses each of these sequentially per face so I could clean
 * the house's positional data up
*/
void House::colo(int i, int &c1, int &c2, int &c3){
	switch(i){
		case  0:  c1 =  0;  c2 = 153; c3 = 255; break;
		case  4:  c1 = 102; c2 = 255; c3 = 153; break;
		case  8:  c1 = 255; c2 = 102; c3 = 102; break;
		case 12:  c1 = 255; c2 = 102; c3 = 255; break;
		case 16:  c1 = 255; c2 = 255; c3 = 102; break;
		case 20:  c1 =  51; c2 = 153; c3 =  51; break;
		case 24:  c1 = 204; c2 = 102; c3 = 153; break;
		case 28:  c1 = 102; c2 =  51; c3 =   0; break;
		case 32:  c1 = 255; c2 = 255; c3 = 255; break;
		case 35:  c1 =  88; c2 =  88; c3 =  88; break;
	}
}

// draw the House
void House::render() {
	int c1, c2, c3;

	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_FILL);

	// Draw the faces made of squares
	for(unsigned i=0;i<32;i+=4) {
		colo(i,c1,c2,c3);
		glColor3ub(c1,c2,c3);
		glBegin(FILLMODE);
			glVertex3f(this->V[i].x,  this->V[i].y,  this->V[i].z);
			glVertex3f(this->V[i+1].x,this->V[i+1].y,this->V[i+1].z);
			glVertex3f(this->V[i+2].x,this->V[i+2].y,this->V[i+2].z);
			glVertex3f(this->V[i+3].x,this->V[i+3].y,this->V[i+3].z);
		glEnd();
	}
	// Draw the faces made of triangles
	for(unsigned i=32;i<this->V.size();i+=3) {
		colo(i,c1,c2,c3);
		glColor3ub(c1,c2,c3);
		glBegin(FILLMODE);
			glVertex3f(this->V[i].x,  this->V[i].y,  this->V[i].z);
			glVertex3f(this->V[i+1].x,this->V[i+1].y,this->V[i+1].z);
			glVertex3f(this->V[i+2].x,this->V[i+2].y,this->V[i+2].z);
		glEnd();
	}

	if(DRAWSIGN == 1){
		glColor3ub(255,255,255);
		glPushMatrix();
		glTranslatef(-0.75, 1.08, -0.025);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glRotatef(-80.0, 1.0, 0.0, 0.0);
		glScalef(0.00175,0.00175,1.0);
		renderStrokeFontString( (char*)"HelloWorld!" );
		glPopMatrix();
	}
}

void House::rotate() {
	glRotatef(THETA.x,1.0,0.0,0.0);
	glRotatef(THETA.y,0.0,1.0,0.0);
	glRotatef(THETA.z,0.0,0.0,1.0);
}
