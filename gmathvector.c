#include "gmathvector.h"
#include <stdlib.h>
#include <math.h>
#include "gmatherr.h"
#include "gmathmacro.h"

extern enum gmatherr_codes gm_errno;

/* Vector creation functions */
void gm_create_vec(gmvec *pv, gmdim_t dim)
{
    if (pv && dim > 0) {
        pv->essence = malloc(dim*sizeof(gmdata_t));
        pv->dim = dim;
    } else if (!pv) {
        gm_errno = gmerr_nullptr;
    } else {
        gm_errno = gmerr_meanlessdim;
        pv->essence = NULL;
    }
}

/* Init functions */
void gm_init_vec(gmvec *pv, gmdim_t dim, gmdata_t val)
{
    if (pv && dim > 0) {
        gmdim_t i;
        pv->dim = dim;
        pv->essence = calloc((size_t)dim, sizeof(gmdata_t));    /* zeros */
        if (val != 0)
            for (i = 0; i < dim; i++)
                pv->essence[i] = val;
    } else if (!pv) {
        gm_errno = gmerr_nullptr;
    } else {
        gm_errno = gmerr_meanlessdim;
        pv->essence = NULL;
    }
}

void gm_arr2vec(gmvec *pv, const gmdata_t *arr, gmdim_t size)
{
    gmdim_t i;
    if (!pv) {
        gm_errno = gmerr_nullptr;
        return;
    }
    if (size < 1) {
        gm_errno = gmerr_arrsize;
        pv->essence = NULL;
        return;
    }
    pv->dim = size;
    for (i = 0; i < size; i++)
        pv->essence[i] = arr[i];
}

/* Accessing functions */
gmdata_t get_veci(const gmvec *pv, gmdim_t i)
{
    if (!pv) {
        gm_errno = gmerr_nullptr;
        gm_perror(VAR_NAME(get_veci));
        exit(gm_errno);
    }
    if (i < 0 || i >= pv->dim) {
        gm_errno = gmerr_outrange;
        gm_perror(VAR_NAME(get_veci));
        exit(gm_errno);
    }
    return pv->essence[i];
}

/* Checking functions */
int is_zero_vec(const gmvec *pv)
{
    gmdim_t i;
    if (!pv)
        return 1;
    for (i = 0; i < pv->dim; i++)
        if (pv->essence[i] != 0)
            return 0;
    return 1;
}

void gm_free_vec(gmvec *pv)
{
    if (pv) {
        if (pv->essence)
            free(pv->essence);
        free(pv);
    }
}

