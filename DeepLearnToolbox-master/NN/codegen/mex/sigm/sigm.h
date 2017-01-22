/*
 * sigm.h
 *
 * Code generation for function 'sigm'
 *
 */

#ifndef __SIGM_H__
#define __SIGM_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "sigm_types.h"

/* Function Declarations */
extern real32_T sigm(real32_T P);

#ifdef __WATCOMC__

#pragma aux sigm value [8087];

#endif
#endif

/* End of code generation (sigm.h) */
