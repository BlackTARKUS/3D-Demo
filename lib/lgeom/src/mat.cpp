#include "mat.h"

// ensures that a matrix is a size 16 array
mat4 mat4fromArray(float *ma) {
	mat4 result;
	for(int i=0; i<16; i++) {
		result.e[i] = ma[i];
	}
	return result;
}

// handler for modification with 2 matrices
mat4 matmult(mat4 A, mat4 B) {
	mat4 result;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			result.e[i*4+j]= 0.0;
			for(int k=0; k<4; k++) {
				result.e[i*4+j] += A.e[i*4+k] * B.e[k*4+j]; 
			}
		}
	}
	return result;
}

mat4 mat4Identity() {
	mat4 id;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			id.e[i*4 + j] = 0.0;
		}
		id.e[i*4 + i] = 1.0;
	}
	return id;
}

// Overloaded operator to handle multiplying 2 matrices
mat4 operator *(mat4 T1, mat4 T2) {
	return matmult(T1, T2);
}
