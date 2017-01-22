/*
 * File: _coder_sigm_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 22-Sep-2015 21:20:39
 */

#ifndef ___CODER_SIGM_API_H__
#define ___CODER_SIGM_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_sigm_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real32_T sigm(real32_T P);
extern void sigm_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
extern void sigm_atexit(void);
extern void sigm_initialize(void);
extern void sigm_terminate(void);
extern void sigm_xil_terminate(void);

#endif

/*
 * File trailer for _coder_sigm_api.h
 *
 * [EOF]
 */
