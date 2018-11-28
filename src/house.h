#ifndef HOUSE_H
#define HOUSE_H

#include "lgeom.h"
#include <vector>

class House {
private:
public:
	vec3 pos; // position
	float theta; // rotation
	float alpha; // rotational velocity
	std::vector<vec3> verts; // polygon vertices
	
	House();
	House(vec3 position);
	void rotate(float,float,float,float);
	void render();
};

#endif // HOUSE_H

