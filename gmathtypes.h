#ifndef GMATHTYPES_H_SENTRY
#define GMATHTYPES_H_SENTRY

#if defined(GDATA_T_FLOAT)
typedef float gmdata_t;         /* type of data */
#elif defined(GDATA_T_LDOUBLE)
typedef long double gmdata_t;
#else
typedef double gmdata_t;
#endif
typedef int gmdim_t;

/* Math vector object */
struct gmvector_s {
    gmdata_t *essence;
    gmdim_t dim;
};
typedef struct gmvector_s gmvec;

/* Math matrix object */
struct gmmatrix_s {
    gmdata_t **essence;
    gmdim_t rows, columns;
};
typedef struct gmmatrix_s gmmatr;

#endif /* GMATHTYPES_H_SENTRY */

