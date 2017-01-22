/*
 * eee_initialize.c
 *
 * Code generation for function 'eee_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "eee.h"
#include "eee_initialize.h"
#include "eee_data.h"

/* Function Definitions */
void eee_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (eee_initialize.c) */
