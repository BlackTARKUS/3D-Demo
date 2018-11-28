#include "viewpane.h"
#include "house.h"
#include "lgeom.h"
#include "glFuncs.h"

Viewpane::Viewpane() {

}

void Viewpane::init(int window_width, int window_height) {
	this->origin = { window_width/2.0f, window_height/2.0f };

	this->house.pos = origin;
}

void Viewpane::render() {

	clearScreen();

	// draw the Text
	//for(unsigned i=0; i < this->text.size(); i++) {
	//	this->text[i].render();
	//}

	// Draw the axis
	//for(unsigned i=0; i < this->axis.size(); i++) {
	//	this->axis[i].render();
	//}

	// Draw the House
    this->house.render();
	
	swapBuffers();
}
