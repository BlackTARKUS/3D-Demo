#ifndef MISC_H
#define MISC_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
// function that uses modulus wrapping to treat arrays as circular linked lists 
int mod_wrap(int i, int n);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MISC_H
