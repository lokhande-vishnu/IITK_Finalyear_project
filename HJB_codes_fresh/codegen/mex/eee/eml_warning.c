/*
 * eml_warning.c
 *
 * Code generation for function 'eml_warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "eee.h"
#include "eml_warning.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 16, 13, "eml_warning",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m"
};

static emlrtMCInfo b_emlrtMCI = { 16, 5, "eml_warning",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m"
};

static emlrtRSInfo bc_emlrtRSI = { 16, "eml_warning",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m"
};

/* Function Declarations */
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);
static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m2;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m2, 1, &pArray, "message", true, location);
}

static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "warning", true, location);
}

void eml_warning(const emlrtStack *sp)
{
  int32_T i0;
  static const char_T varargin_1[24] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'e',
    'i', 'g', ':', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r', 'g', 'e', 'n', 'c',
    'e' };

  char_T u[24];
  const mxArray *y;
  static const int32_T iv1[2] = { 1, 24 };

  const mxArray *m0;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i0 = 0; i0 < 24; i0++) {
    u[i0] = varargin_1[i0];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 24, m0, &u[0]);
  emlrtAssign(&y, m0);
  st.site = &bc_emlrtRSI;
  warning(&st, message(&st, y, &emlrtMCI), &b_emlrtMCI);
}

/* End of code generation (eml_warning.c) */
