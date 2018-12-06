#include <GL/glut.h>
#include "glFuncs.h"
#include "globals.h"
#include "viewpane.h"
#include "house.h"

void Viewpane::MouseClicked(int button, int state, int x, int y) { 
	switch(button){
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN){
			if(pointInTriangle(x,y)) {
				if(ALPHA.z < 10.0) {
					ALPHA.z += 1.0;	
				}
				
			}
			else if(x > (WINDOW_MAX_X/2) ) {
				if(ALPHA.x < 10.0) {
					ALPHA.x += 1.0;	
				}
			}
			else{
				if(ALPHA.y < 10.0) {
					ALPHA.y += 1.0;	
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
		THETA = {0.0,0.0,0.0};
		ALPHA = {0.0,0.0,0.0};
		glutPostRedisplay();
		reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
		break;
	case 'R': // Reset house position, size, and camera position and perspective
		THETA = {0.0,0.0,0.0};
		ALPHA = {0.0,0.0,0.0};
		ZOOMSCALE = 80;
		VIEWMODE = 0;
		glutPostRedisplay();
		reshape(WINDOW_MAX_X, WINDOW_MAX_Y);
		break;
	case 'q':
		exit(0);
		break;
	}
}
