#ifndef VIEWPANE_H
#define VIEWPANE_H

#include "point.h"
#include "house.h"
#include <vector>

struct Viewpane {
public:
	point origin; // will be the center of the viewpane
	House house;
	float zoomscale;

	void drawAxis();

	Viewpane();
	void init(int window_width, int window_height);
	void render();

	void MouseClicked(int button, int state, int x, int y);
	void KeySpecial(int key, int x, int y);
	void KeyDown(unsigned char key, int x, int y);
};

void initMenu();
void mainMenuHandler(int choice);
void viewMenuHandler(int choice);
void polygonMenuHandler(int choice);


#endif // VIEWPANE_H
