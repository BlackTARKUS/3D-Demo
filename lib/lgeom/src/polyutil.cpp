#include "polyutil.h"
#include "misc.h"

//////////////////////////////////////////////////////
// Credit:
//   Shoelace formula
//   http://www.mathopenref.com/coordtrianglearea.html
//////////////////////////////////////////////////////
/* One can determine if a,b,c form a convex shape by checking if the area formed
 * by their resultant polygon is negative or positive. The area is calculated
 * using the dot product in a 2D space.
*/
float tri_area(vec3 a, vec3 b, vec3 c) {
	float area = 0.0;
	area += a.x*(b.y-c.y);
	area += b.x*(c.y-a.y);
	area += c.x*(a.y-b.y);
	return area/2.0;
}

//////////////////////////////////////////////////////
// http://geomalgorithms.com/a03-_inclusion.html
// Returns:
//   >0 a is left
//   =0 a is on line
//   <0 a is right
//////////////////////////////////////////////////////
float pointIsLeft(vec3 a, vec3 b, vec3 c) {
	return ( (c.x - b.x) * (a.y - b.y) - (a.x -  b.x) * (c.y - b.y) );
}

/* Check if a point lies within a triangle using the cross product and 
 * comparing the signs of the z components
*/
int point_in_triangle(vec3 p, vec3 a, vec3 b, vec3 c) {
	float ABP = pointIsLeft(a,b,p);
	float BCP = pointIsLeft(b,c,p);
	float CAP = pointIsLeft(c,a,p);
	return (ABP>0 && BCP>0 && CAP>0) || (ABP<0 && BCP<0 && CAP<0);
}

//////////////////////////////////////////////////////
// http://geomalgorithms.com/a03-_inclusion.html
// Winding number test for a point in a polygon.
// Return: wn = the winding number (=0 only when P is outside)
//////////////////////////////////////////////////////
int point_in_poly(vec3 p, vec3 *poly, unsigned N) {
	int wn = 0;
	int curr, next;

	curr = N-1;
	for(unsigned i=0; i<N; i++) {
		next = i;
		if(poly[curr].y <= p.y) {          // start y <= P.y
			if(poly[next].y > p.y)      // an upward crossing
				if(pointIsLeft(poly[curr], poly[next], p) > 0)  // P left of  edge
					wn++;            // have  a valid up intersect
		}
		else {                        // start y > P.y (no test needed)
			if(poly[next].y <= p.y)     // a downward crossing
				if(pointIsLeft(poly[curr], poly[next], p) < 0)  // P right of  edge
					wn--;            // have  a valid down intersect
		}
		curr = next;
	}
	return wn;
}

int point_in_poly(vec3 p, std::vector<vec3> poly) {
	return point_in_poly(p, &poly[0], poly.size());
}
