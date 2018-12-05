#include <GL/glut.h>
#include "glFuncs.h"
#include "globals.h"
#include "viewpane.h"
#include "house.h"

#include <iostream>

void Viewpane::MouseClicked(int button, int state, int x, int y) { 
	switch(button){
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN){
			if(y > (WINDOW_MAX_Y/2)) {
				if(this->house.alpha.z < 10.0) {
					this->house.alpha.z += 1.0;	
				}
				
			}
			else if(x > (WINDOW_MAX_X/2) ) {
				if(this->house.alpha.x < 10.0) {
					this->house.alpha.x += 1.0;	
				}
			}
			else{
				if(this->house.alpha.y < 10.0) {
					this->house.alpha.y += 1.0;	
				}
			}
			glutIdleFunc(SpinDisplay);
		}
		break;
	}
}

void Viewpane::KeySpecial(int key, int x, int y) {
	switch(key){
	case GLUT_KEY_PAGE_UP: // Move camera closer to house
		if(ZOOMSCALE < 175.0) { // Beyond this zoomscale things break 
			ZOOMSCALE += 5.0;
		}
		reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
		break;
	case GLUT_KEY_PAGE_DOWN: // move camera further from house
		if(ZOOMSCALE > 5.0) { // Beyond this zoomscale things break
			ZOOMSCALE -= 5.0;
		}
		reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
		break;
	}
}

void Viewpane::KeyDown(unsigned char key, int x, int y) { 
	switch(key){
	case 's': // Stop house animation
		glutIdleFunc(display);
		break;
	case 'r': // Reset house position and size
		this->house.theta = {0.0,0.0,0.0};
		this->house.alpha = {0.0,0.0,0.0};
		ZOOMSCALE = 80;
		glutPostRedisplay();
		reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
		break;
	case 'R': // Reset house position, size, and camera position and perspective
		this->house.theta = {0.0,0.0,0.0};
		this->house.alpha = {0.0,0.0,0.0};
		ZOOMSCALE = 80;
		glutPostRedisplay();
		reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
		break;
	case 'q':
		exit(0);
		break;
	}
}
