/*
 * sigm_terminate.c
 *
 * Code generation for function 'sigm_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sigm.h"
#include "sigm_terminate.h"
#include "sigm_data.h"

/* Function Definitions */
void sigm_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void sigm_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (sigm_terminate.c) */
