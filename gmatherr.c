#include "gmatherr.h"
#include <stdio.h>

static const char *gm_get_errmsg();
/* Return the text of the error. */
/* In no error case return the empty string. */

static const char *gm_get_errmsg()
{
    switch (gm_errno) {
    case gmerr_no: return "";
    case gmerr_nullptr: return "null pointer dereference";
    case gmerr_meanlessdim: return "meaningless dimension";
    case gmerr_arrsize: return "invalid array size";
    case gmerr_outrange: return "index is out of range";
    case gmerr_zvecnorm: return "computing norm of zero vector";
    }
    return "unknown error";
}

void gm_perror(const char *hstr)
{
    const char *errtxt = gm_get_errmsg();
    if (!*errtxt)
        return;
    fprintf(stderr, "Error (gmath %d): <%s>: %s\n", gm_errno, hstr, errtxt);
    fflush(stderr);
}

