#ifndef HOUSE_H
#define HOUSE_H

#include "point.h"
#include <vector>

class House {
private:
public:
	point theta; // rotation angle
	point alpha; // rotational velocity
	std::vector<point> V; // polygon vertices as vector

	House();
	void colo(int, int&, int&, int&);
	void render();
	void rotate();
};

#endif // HOUSE_H
