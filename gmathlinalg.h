/* Description of functions for creating math objects - */
/* functions make just allocate the memory without init data. */
#ifndef GMATHLINALG_H_SENTRY
#define GMATHLINALG_H_SENTRY

#include "gmathvector.h"

gmdata_t vecnorm(const gmvec *pv);
gmdata_t vecnorm2(const gmvec *pv);
/* Compute the vector's norm and square norm (norm^2). */
/* If vector is zero than return 0. */
/* - pv - pointer to the vector's object. */
/* Exceptions: */
/* - gmerr_nullptr. */
void normalize(gmvec *pv);
/* Normalize the vector. */
/* Params: */
/* - pv - pointer to the vector's object. */
/* Exceptions: */
/* - gmerr_nullptr; */
/* - gmerr_zvecnorm. */

#endif /* GMATHLINALG_H_SENTRY */

