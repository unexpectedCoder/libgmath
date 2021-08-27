#include "gmathio.h"
#include <stdio.h>

/* Vector's printing brackets style */
enum {vec_openbr='[', vec_closebr=']'};

void gm_print_vector(const gmvec *pv, const char *vname)
{
    int i;
    if (!pv)
        return;
    printf("%dD ", pv->dim);
    if (vname && *vname)
        printf("'%s' = ", vname);
    printf("%c%-3.5f", vec_openbr, pv->essence[0]);
    for (i = 1; i < pv->dim; i++)
        printf(" ; %-3.5f", pv->essence[i]);
    printf("%c\n", vec_closebr);
}

