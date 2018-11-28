
#include "misc.h"

// function that uses modulus wrapping to treat arrays as circular linked lists 
int mod_wrap(int i, int n) {
	return (i % n + n) % n;
}

