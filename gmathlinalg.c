#include "gmathlinalg.h"
#include <stdlib.h>
#include <math.h>
#include "gmatherr.h"
#include "gmathmacro.h"

extern enum gmatherr_codes gm_errno;

gmdata_t vecnorm(const gmvec *pv)
{
    gmdim_t i;
    gmdata_t res;
    if (!pv) {
        gm_errno = gmerr_nullptr;
        gm_perror(VAR_NAME(vecnorm));
        exit(gm_errno);
    }
    if (is_zero_vec(pv))
        return 0;
    res = 0;
    for (i = 0; i < pv->dim; i++)
        res += pv->essence[i] * pv->essence[i];
#if defined(GMDATA_T_FLOAT)
    return sqrtf(res);
#elif defined(GMDATA_T_LDOUBLE)
    return sqrtl(res);
#else
    return sqrt(res);
#endif
}

gmdata_t vecnorm2(const gmvec *pv)
{
    gmdim_t i;
    gmdata_t res;
    if (!pv) {
        gm_errno = gmerr_nullptr;
        gm_perror(VAR_NAME(vecnorm2));
        exit(gm_errno);
    }
    if (is_zero_vec(pv))
        return 0;
    res = 0;
    for (i = 0; i < pv->dim; i++)
        res += pv->essence[i] * pv->essence[i];
    return res;
}

void normalize(gmvec *pv)
{
    gmdim_t i;
    gmdata_t norm;
    if (!pv) {
        gm_errno = gmerr_nullptr;
        return;
    }
    if (is_zero_vec(pv)) {
        gm_errno = gmerr_zvecnorm;
        return;
    }
    norm = vecnorm(pv);
    for (i = 0; i < pv->dim; i++)
        pv->essence[i] /= norm;
}

