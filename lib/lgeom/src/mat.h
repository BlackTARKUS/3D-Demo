#ifndef MAT_H
#define MAT_H

#include "vec.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// Defines a 4x4 matrix using an array of size 16
typedef struct mat4 {
	float e[16];
} mat4;

mat4 mat4FromArray(float *ma);
mat4 matmult(mat4 A, mat4 B);
mat4 mat4Identity();

#ifdef __cplusplus
}

// Operator overloading for multiplying two matrices
mat4 operator *(mat4 T1, mat4 T2);

#endif // __cplusplus

#endif // MAT_H

