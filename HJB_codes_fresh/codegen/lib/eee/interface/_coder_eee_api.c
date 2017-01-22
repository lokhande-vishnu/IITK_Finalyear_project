/*
 * File: _coder_eee_api.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 01-Oct-2015 23:53:36
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_eee_api.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL, "eee", NULL,
  false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[4];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u[4]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[4]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[4]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  real_T (*ret)[4];
  int32_T iv1[2];
  int32_T i;
  for (i = 0; i < 2; i++) {
    iv1[i] = 2;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv1);
  ret = (real_T (*)[4])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *a
 *                const char_T *identifier
 * Return Type  : real_T (*)[4]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[4]
{
  real_T (*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a), &thisId);
  emlrtDestroyArray(&a);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const creal_T u[4]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [4])
{
  const mxArray *y;
  static const int32_T iv0[2] = { 2, 2 };

  const mxArray *m0;
  creal_T b_u[4];
  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxCOMPLEX);
  memcpy(&b_u[0], &u[0], sizeof(creal_T) << 2);
  emlrtExportNumericArrayR2013b(sp, m0, b_u, 8);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const mxArray *prhs[1]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void eee_api(const mxArray *prhs[1], const mxArray *plhs[2])
{
  real_T (*a)[4];
  creal_T ans2[4];
  creal_T ans1[4];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, false, -1);

  /* Marshall function inputs */
  a = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");

  /* Invoke the target function */
  eee(*a, ans1, ans2);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, ans1);
  plhs[1] = emlrt_marshallOut(&st, ans2);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void eee_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  eee_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void eee_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void eee_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_eee_api.c
 *
 * [EOF]
 */
