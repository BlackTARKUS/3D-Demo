#ifndef HOUSE_H
#define HOUSE_H

#include "lgeom.h"
#include <vector>

class House {
private:
public:
	vec3 theta; // rotation angle
	vec3 alpha; // rotational velocity
	std::vector<vec3> V; // polygon vertices as vector

	House();
	void colo(int, int&, int&, int&);
	void render();
	void rotate();
};

#endif // HOUSE_H
