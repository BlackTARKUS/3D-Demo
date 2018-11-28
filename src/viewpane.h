#ifndef VIEWPANE_H
#define VIEWPANE_H

#include "lgeom.h"
//#include "house.h"
#include <vector>

class Viewpane {
private:
public:
	vec3 origin; // will be the center of the viewpane
    //House house;

	// TODO 
	// add text indicator to viewpane

	Viewpane();
	void init(int window_width, int window_height);
	void update();
	void render();

	void MouseClicked(int button, int state, int x, int y);
	void KeyboardSpecial(int key, int x, int y);
	void KeyboardDown(unsigned char key, int x, int y);
};

#endif // VIEWPANE_H
