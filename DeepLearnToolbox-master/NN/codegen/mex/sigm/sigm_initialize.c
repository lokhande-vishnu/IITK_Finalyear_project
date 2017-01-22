/*
 * sigm_initialize.c
 *
 * Code generation for function 'sigm_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sigm.h"
#include "sigm_initialize.h"
#include "sigm_data.h"

/* Function Definitions */
void sigm_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (sigm_initialize.c) */
