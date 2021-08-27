#ifndef GMATHERR_H_SENTRY
#define GMATHERR_H_SENTRY

/* Error codes of gmath lib */
enum gmatherr_codes {
    gmerr_no,           /* no error */
    gmerr_nullptr,      /* null pointer dereference */
    gmerr_meanlessdim,  /* meaningless dimension */
    gmerr_arrsize,      /* invalid array size */
    gmerr_outrange,     /* index is out of range */
    gmerr_zvecnorm      /* computing norm of zero vector */
};
enum gmatherr_codes gm_errno;   /* global error code variable */

void gm_perror(const char *hstr);
/* Write the text of the error in stdout. */
/* In no error case do nothing. */
/* Params: */
/* - hstr - helper string (to help find where the error appeared). */

#endif /* GMATHERR_H_SENTRY */

