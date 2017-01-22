/*
 * File: sigm.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 22-Sep-2015 21:20:39
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "sigm.h"

/* Function Definitions */

/*
 * Arguments    : float P
 * Return Type  : float
 */
float sigm(float P)
{
  return 1.0F / (1.0F + (real32_T)exp(-P));
}

/*
 * File trailer for sigm.c
 *
 * [EOF]
 */
