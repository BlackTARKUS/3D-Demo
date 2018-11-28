#include <GL/glut.h>
#include "viewpane.h"

void Viewpane::MouseClicked(int button, int state, int x, int y) { 
	switch(button){
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN){
			if(x > 250) {
				this->house.theta.x += 10.0;
			}
			else{
				this->house.theta.y += 10.0;
			}

		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN){
			// Generate context Menu
		}
		break;
	}
}

void Viewpane::KeySpecial(int key, int x, int y) {
	switch(key){
	case GLUT_KEY_PAGE_UP: // Move camera closer to house
		this->zoomScale += 5.0;
		break;
	case GLUT_KEY_PAGE_DOWN: // move camera further from house
		this->zoomScale -= 5.0;
		break;
	}
}

void Viewpane::KeyDown(unsigned char key, int x, int y) { 
	switch(key){
	case 's': // Stop house animation
		glutIdleFunc(NULL);
		break;
	case 'r': // Reset house position and size
		// Do Stuff
		break;
	case 'R': // Reset house position, size, and camera position and perspective
		this->zoomScale = 0;
		break;
	case 'q':
		exit(0);
		break;
	}
}
