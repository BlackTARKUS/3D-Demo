#ifndef HOUSE_H
#define HOUSE_H

#include "lgeom.h"
#include <vector>

class House {
private:
public:
	vec3 theta; // rotation angle
	float alpha; // rotational velocity
	std::vector<vec3> V; // polygon vertices
	
	House();
	void rotate(float,float,float,float);
	void colo(int, int&, int&, int&);
	void render();
};

#endif // HOUSE_H

