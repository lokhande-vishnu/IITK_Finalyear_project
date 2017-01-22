/*
 * sigm.c
 *
 * Code generation for function 'sigm'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sigm.h"

/* Function Definitions */
real32_T sigm(real32_T P)
{
  return 1.0F / (1.0F + muSingleScalarExp(-P));
}

/* End of code generation (sigm.c) */
