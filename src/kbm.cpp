#include <GL/glut.h>

void Viewpane::MouseClicked(int button, int state, int x, int y){ 
	switch(key){
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN){
			// Do Stuff
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN){
			// Do Stuff
		}
		break;
	}
}

void Viewpane::KeySpecial(int key, int x, int y){
	switch(key){
	case GLUT_KEY_PAGE_UP: // Move camera closer to house
		// Do Stuff
		break;
	case GLUT_KEY_PAGE_DOWN: // move camera further from house
		// Do Stuff
		break;
	}
}

void Viewpane::KeyDown(unsigned char key, int x, int y){ 
	switch(key){
	case 's': // Reset stop house animation
		// Do Stuff
		break;
	case 'r': // Reset house position and size
		// Do Stuff
		break;
	case 'R': // Reset house position, size, and camera position and perspective
		// Do Stuff
		break;
	case 'q':
		exit(0);
		break;
	}
}
