/*
 * File: _coder_eee_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 01-Oct-2015 23:53:36
 */

#ifndef ___CODER_EEE_API_H__
#define ___CODER_EEE_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_eee_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void eee(real_T a[4], creal_T ans1[4], creal_T ans2[4]);
extern void eee_api(const mxArray *prhs[1], const mxArray *plhs[2]);
extern void eee_atexit(void);
extern void eee_initialize(void);
extern void eee_terminate(void);
extern void eee_xil_terminate(void);

#endif

/*
 * File trailer for _coder_eee_api.h
 *
 * [EOF]
 */
