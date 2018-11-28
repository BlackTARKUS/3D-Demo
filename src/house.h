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
	mat4 transform;
	std::vector<vec3> verts; // polygon vertices
	std::vector<vec3> Tverts; // transformed vertices

	House();
	House(vec3 position);
	void update();
	void render();
};

#endif // HOUSE_H

