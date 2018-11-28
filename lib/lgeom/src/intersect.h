#ifndef INTERSECT_H
#define INTERSECT_H

#include "vec.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

vec3 line_coords(vec3 p1, vec3 p2);
int point_on_line(vec3 p, vec3 pA, vec3 pB);
int intersect_ll(vec3 pA, vec3 pB, vec3 b1, vec3 b2, vec3 *i);
int intersect_ss(vec3 pA, vec3 pB, vec3 b1, vec3 b2, vec3 *i);
int intersect_ls(vec3 pA, vec3 pB, vec3 b1, vec3 b2, vec3 *i);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // INTERSECT_H

