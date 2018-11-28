#include "intersect.h"

// Uses two points as parametric line equation
vec3 line_coords(vec3 p1, vec3 p2) {
	float A = p2.y-p1.y;
	float B = p1.x-p2.x;
	float C = p1.y*p2.x-p1.x*p2.y;
	vec3 uVec = {A,B,C};
	return uVec;
}

// Determines if point p falls on line segment pApB
int point_on_line(vec3 p, vec3 pA, vec3 pB) {
	vec3 L = line_coords(pA, pB);
	if(p.x*L.x + p.y*L.y + L.z != 0){
		return 0; // not on line
	}
	if((p.x < pA.x && p.x < pB.x)||(p.x > pA.x && p.x > pB.x)) {
		return -1; // On line but not segment
	}
	return 1; // On Segment
}

/* Checks for an intersection between two lines. If an intersection is found,
 * the point of intersection is stored in i
*/
int intersect_ll(vec3 pA, vec3 pB, vec3 b1, vec3 b2, vec3 *i) {
	vec3 u1 = line_coords(pA, pB);
	vec3 u2 = line_coords(b1, b2);
	vec3 p = vec3Cross(u1, u2);

	if(p.z==0){ return 0; }
	p.x = p.x/p.z;
	p.y = p.y/p.z;
	p.z = 0.0;
	*i = p;
	return 1;
}

// Checks for intersection point of two line segments.
int intersect_ss(vec3 pA, vec3 pB, vec3 b1, vec3 b2, vec3 *i) {

	float ua, ub;
	float denom;

	denom = (pB.x-pA.x)*(-b2.y+b1.y) - (-b2.x+b1.x)*(pB.y-pA.y);
	ua = (b1.x-pA.x)*(-b2.y+b1.y) - (-b2.x+b1.x)*(b1.y-pA.y);
	ub = (pB.x-pA.x)*(b1.y-pA.y) - (b1.x-pA.x)*(pB.y-pA.y);
	ua /= denom;
	ub /= denom;

	if(ua<0.0 || ua>1.0 || ub<0.0 || ub>1.0)
		return 0; // no intersection
	i->x = pA.x + ua*(pB.x - pA.x);
	i->y = pA.y + ua*(pB.y - pA.y);
	if(ua==0.0 || ua==1.0 || ub==0.0 || ub==0.0) // tip intersection
		return -1; // intersection at endpoint
	return 1; // intersection found
	
}

// Checks for intersection point of line and segment.
int intersect_ls(vec3 pA, vec3 pB, vec3 b1, vec3 b2, vec3 *i) {
	vec3 n = vec3Diff(pB,pA);
	n = {n.y, -n.x, 0.0};
	float d1 = vec3Dot(n, vec3Diff(b1, pA));
	float d2 = vec3Dot(n, vec3Diff(b2, pA));
	if( (d1>0 && d2 > 0) || (d1 < 0 && d2 < 0) ){
		return 0; // no intersection
	}
	intersect_ll(pA, pB, b1, b2, i);
	if( d1==0 || d2==0 ){
		return -1; // intersection at endpoint
	}
	return 1; // intersection found
}

