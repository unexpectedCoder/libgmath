/* Description of functions for creating math objects - */
/* functions make just allocate the memory without init data. */
#ifndef GMATHVECTOR_H_SENTRY
#define GMATHVECTOR_H_SENTRY

#include "gmathtypes.h"

void gm_create_vec(gmvec *pv, gmdim_t dim);
/* Create the math vector. */
/* The function witout suffix _r init passed pointer: */
/* if it is NULL than does nothing. */
/* Params: */
/* - pv - vector's object pointer; */
/* - dim - vector's dimension. */
/* Exceptions (set new value of gm_errno global variable): */
/* - gmerr_nullptr; */
/* - gmerr_meanlessdim. */
void gm_init_vec(gmvec *pv, gmdim_t dim, gmdata_t val);
/* Create and init N-dimension vector. */
/* allocated inside of this function for the returned object. */
/* Params: */
/* - pv - vector object's pointer; */
/* - dim - vector's dimension; */
/* - val - initial value. */
/* Exceptions (set new value of gm_errno global variable): */
/* - gmerr_nullptr; */
/* - gmerr_meanlessdim. */
void gm_arr2vec(gmvec *pv, const gmdata_t *arr, gmdim_t size);
/* Init a new vector object 'pv' using existing array 'arr'. */
/* Params: */
/* - pv - pointer to the allocated vector object; */
/* - arr - pointer to the exsisting initial array; */
/* - size - the array size. */
/* Exceptions: */
/* - gmerr_nullptr; */
/* - gmerr_arrsize. */
int is_zero_vec(const gmvec *pv);
/* Return 1 if the vector contains only zeros */
/* or if pv is NULL. Return 0 otherwise. */
gmdata_t get_veci(const gmvec *pv, gmdim_t i);
/* Return vector's 'i'th coordinate. */
/* Params: */
/* - pv - pointer to the vector object; */
/* - i - coordinate index. */
/* Exceptions: */
/* - gmerr_nullptr; */
/* - gmerr_outrange. */
void gm_free_vec(gmvec *pv);
/* Free math object memory. */
/* In pv == NULL case does nothing. */

#endif /* GMATHVECTOR_H_SENTRY */

