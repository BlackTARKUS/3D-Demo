#ifndef HOUSE_H
#define HOUSE_H

#include "point.h"
#include <vector>

class House {
private:
public:
	std::vector<point> V; // polygon vertices as vector

	House();
	void colo(int, int&, int&, int&);
	void render();
	void rotate();
};

#endif // HOUSE_H
