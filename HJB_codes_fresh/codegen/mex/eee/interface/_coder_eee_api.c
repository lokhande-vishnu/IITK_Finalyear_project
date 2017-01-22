/*
 * _coder_eee_api.c
 *
 * Code generation for function '_coder_eee_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "eee.h"
#include "_coder_eee_api.h"
#include "eee_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *a, const
  char_T *identifier))[4];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u[4]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  real_T (*ret)[4];
  int32_T iv3[2];
  int32_T i;
  for (i = 0; i < 2; i++) {
    iv3[i] = 2;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv3);
  ret = (real_T (*)[4])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

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
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [4])
{
  const mxArray *y;
  static const int32_T iv2[2] = { 2, 2 };

  const mxArray *m1;
  creal_T b_u[4];
  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxCOMPLEX);
  memcpy(&b_u[0], &u[0], sizeof(creal_T) << 2);
  emlrtExportNumericArrayR2013b(sp, m1, b_u, 8);
  emlrtAssign(&y, m1);
  return y;
}

void eee_api(const mxArray * const prhs[1], const mxArray *plhs[2])
{
  real_T (*a)[4];
  creal_T ans2[4];
  creal_T ans1[4];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  a = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "a");

  /* Invoke the target function */
  eee(&st, *a, ans1, ans2);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, ans1);
  plhs[1] = emlrt_marshallOut(&st, ans2);
}

/* End of code generation (_coder_eee_api.c) */
