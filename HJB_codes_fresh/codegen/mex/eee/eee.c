/*
 * eee.c
 *
 * Code generation for function 'eee'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "eee.h"
#include "eml_warning.h"
#include "mod.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_error.h"
#include "sqrt.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 3, "eee",
  "C:\\Users\\vishnu\\Desktop\\NN\\HJB_codes_fresh\\eee.m" };

static emlrtRSInfo b_emlrtRSI = { 65, "eig",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"
};

static emlrtRSInfo c_emlrtRSI = { 71, "eig",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"
};

static emlrtRSInfo d_emlrtRSI = { 8, "eml_xgeev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\eml_xgeev.m"
};

static emlrtRSInfo e_emlrtRSI = { 8, "eml_lapack_xgeev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\internal\\eml_lapack_xgeev.m"
};

static emlrtRSInfo h_emlrtRSI = { 39, "eml_matlab_zggev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggev.m"
};

static emlrtRSInfo i_emlrtRSI = { 84, "eml_matlab_zggev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggev.m"
};

static emlrtRSInfo j_emlrtRSI = { 100, "eml_matlab_zggev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggev.m"
};

static emlrtRSInfo k_emlrtRSI = { 101, "eml_matlab_zggev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggev.m"
};

static emlrtRSInfo l_emlrtRSI = { 106, "eml_matlab_zggev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggev.m"
};

static emlrtRSInfo m_emlrtRSI = { 108, "eml_matlab_zggev",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggev.m"
};

static emlrtRSInfo n_emlrtRSI = { 14, "sqrt",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"
};

static emlrtRSInfo t_emlrtRSI = { 20, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo y_emlrtRSI = { 62, "eml_matlab_zgghrd",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgghrd.m"
};

static emlrtRSInfo ab_emlrtRSI = { 64, "eml_matlab_zgghrd",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgghrd.m"
};

static emlrtRSInfo bb_emlrtRSI = { 77, "eml_matlab_zgghrd",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgghrd.m"
};

static emlrtRSInfo cb_emlrtRSI = { 79, "eml_matlab_zgghrd",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zgghrd.m"
};

static emlrtRSInfo db_emlrtRSI = { 67, "eml_matlab_zlartg",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlartg.m"
};

static emlrtRSInfo eb_emlrtRSI = { 93, "eml_matlab_zlartg",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlartg.m"
};

static emlrtRSInfo fb_emlrtRSI = { 102, "eml_matlab_zlartg",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlartg.m"
};

static emlrtRSInfo gb_emlrtRSI = { 106, "eml_matlab_zlartg",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlartg.m"
};

static emlrtRSInfo hb_emlrtRSI = { 10, "eml_zrot_rows",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_zrot_rows.m"
};

static emlrtRSInfo ib_emlrtRSI = { 10, "eml_zrot_cols",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_zrot_cols.m"
};

static emlrtRSInfo jb_emlrtRSI = { 37, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo kb_emlrtRSI = { 50, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo lb_emlrtRSI = { 110, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo mb_emlrtRSI = { 402, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo nb_emlrtRSI = { 409, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo ob_emlrtRSI = { 412, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo pb_emlrtRSI = { 421, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo qb_emlrtRSI = { 423, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo rb_emlrtRSI = { 435, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo sb_emlrtRSI = { 447, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

static emlrtRSInfo tb_emlrtRSI = { 20, "eml_matlab_zlanhs",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlanhs.m"
};

static emlrtRSInfo ub_emlrtRSI = { 21, "eml_matlab_zlanhs",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlanhs.m"
};

static emlrtRSInfo vb_emlrtRSI = { 57, "eml_matlab_zlanhs",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zlanhs.m"
};

static emlrtRSInfo wb_emlrtRSI = { 32, "eml_matlab_zggbak",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zggbak.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 113, 5, "eml_matlab_ztgevc",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_ztgevc.m"
};

static emlrtRSInfo dc_emlrtRSI = { 332, "eml_matlab_zhgeqz",
  "C:\\Program Files\\MATLAB\\MATLAB Production Server\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\lapack\\matlab\\eml_matlab_zhgeqz.m"
};

/* Function Declarations */
static void b_eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn);
static void eml_matlab_zggbal(creal_T A[4], int32_T *ilo, int32_T *ihi, int32_T
  rscale[2]);
static void eml_matlab_zggev(const emlrtStack *sp, creal_T A[4], int32_T *info,
  creal_T alpha1[2], creal_T beta1[2], creal_T V[4]);
static void eml_matlab_zhgeqz(const emlrtStack *sp, creal_T A[4], int32_T ilo,
  int32_T ihi, creal_T Z[4], int32_T *info, creal_T alpha1[2], creal_T beta1[2]);
static real_T eml_matlab_zlanhs(const emlrtStack *sp, const creal_T A[4],
  int32_T ilo, int32_T ihi);
static void eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn, creal_T *r);
static void eml_matlab_ztgevc(const emlrtStack *sp, const creal_T A[4], creal_T
  V[4]);

/* Function Definitions */
static void b_eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn)
{
  real_T scale;
  real_T f2s;
  real_T g2;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2s;
  boolean_T b2;
  boolean_T b3;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  scale = muDoubleScalarAbs(f.re);
  f2s = muDoubleScalarAbs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = muDoubleScalarAbs(g.re);
  g2 = muDoubleScalarAbs(g.im);
  if (g2 > f2s) {
    f2s = g2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        scale = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / scale;
        sn->im = -gs_im / scale;
      } else {
        st.site = &db_emlrtRSI;
        if (g2 < 0.0) {
          b_st.site = &n_emlrtRSI;
          eml_error(&b_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        f2s = muDoubleScalarAbs(f.re);
        g2 = muDoubleScalarAbs(f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0) {
          scale = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / scale;
          fs_im = f.im / scale;
        } else {
          f2s = 7.4428285367870146E+137 * f.re;
          g2 = 7.4428285367870146E+137 * f.im;
          scale = muDoubleScalarHypot(f2s, g2);
          fs_re = f2s / scale;
          fs_im = g2 / scale;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      st.site = &eb_emlrtRSI;
      f2s = 1.0 + g2 / scale;
      if (f2s < 0.0) {
        b_st.site = &n_emlrtRSI;
        eml_error(&b_st);
      }

      f2s = muDoubleScalarSqrt(f2s);
      *cs = 1.0 / f2s;
      scale += g2;
      fs_re = f2s * fs_re / scale;
      fs_im = f2s * fs_im / scale;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
      if (rescaledir > 0) {
        st.site = &fb_emlrtRSI;
        if (1 > count) {
          b2 = false;
        } else {
          b2 = (count > 2147483646);
        }

        if (b2) {
          b_st.site = &t_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }
      } else {
        if (rescaledir < 0) {
          st.site = &gb_emlrtRSI;
          if (1 > count) {
            b3 = false;
          } else {
            b3 = (count > 2147483646);
          }

          if (b3) {
            b_st.site = &t_emlrtRSI;
            check_forloop_overflow_error(&b_st, true);
          }
        }
      }
    }
  }
}

static void eml_matlab_zggbal(creal_T A[4], int32_T *ilo, int32_T *ihi, int32_T
  rscale[2])
{
  int32_T i;
  int32_T j;
  boolean_T found;
  int32_T ii;
  boolean_T exitg3;
  int32_T nzcount;
  int32_T jj;
  boolean_T exitg4;
  boolean_T guard2 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  real_T atmp_re;
  real_T atmp_im;
  for (i = 0; i < 2; i++) {
    rscale[i] = 0;
  }

  *ilo = 1;
  *ihi = 2;
  i = 0;
  j = 0;
  found = false;
  ii = 2;
  exitg3 = false;
  while ((!exitg3) && (ii > 0)) {
    nzcount = 0;
    i = ii;
    j = 2;
    jj = 1;
    exitg4 = false;
    while ((!exitg4) && (jj <= 2)) {
      guard2 = false;
      if ((A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (A[(ii + ((jj - 1) << 1))
           - 1].im != 0.0) || (ii == jj)) {
        if (nzcount == 0) {
          j = jj;
          nzcount = 1;
          guard2 = true;
        } else {
          nzcount = 2;
          exitg4 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        jj++;
      }
    }

    if (nzcount < 2) {
      found = true;
      exitg3 = true;
    } else {
      ii--;
    }
  }

  if (!found) {
    i = 0;
    j = 0;
    found = false;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 2)) {
      nzcount = 0;
      i = 2;
      j = jj;
      ii = 1;
      exitg2 = false;
      while ((!exitg2) && (ii <= 2)) {
        guard1 = false;
        if ((A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (A[(ii + ((jj - 1) << 1))
             - 1].im != 0.0) || (ii == jj)) {
          if (nzcount == 0) {
            i = ii;
            nzcount = 1;
            guard1 = true;
          } else {
            nzcount = 2;
            exitg2 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ii++;
        }
      }

      if (nzcount < 2) {
        found = true;
        exitg1 = true;
      } else {
        jj++;
      }
    }

    if (!found) {
    } else {
      if (i != 1) {
        for (ii = 0; ii + 1 < 3; ii++) {
          atmp_re = A[(i + (ii << 1)) - 1].re;
          atmp_im = A[(i + (ii << 1)) - 1].im;
          A[(i + (ii << 1)) - 1] = A[ii << 1];
          A[ii << 1].re = atmp_re;
          A[ii << 1].im = atmp_im;
        }
      }

      if (j != 1) {
        for (ii = 0; ii + 1 < 3; ii++) {
          atmp_re = A[ii + ((j - 1) << 1)].re;
          atmp_im = A[ii + ((j - 1) << 1)].im;
          A[ii + ((j - 1) << 1)] = A[ii];
          A[ii].re = atmp_re;
          A[ii].im = atmp_im;
        }
      }

      rscale[0] = j;
      *ilo = 2;
      rscale[1] = 2;
    }
  } else {
    if (i != 2) {
      for (ii = 0; ii < 2; ii++) {
        atmp_re = A[(i + (ii << 1)) - 1].re;
        atmp_im = A[(i + (ii << 1)) - 1].im;
        A[(i + (ii << 1)) - 1] = A[1 + (ii << 1)];
        A[1 + (ii << 1)].re = atmp_re;
        A[1 + (ii << 1)].im = atmp_im;
      }
    }

    if (j != 2) {
      for (ii = 0; ii + 1 < 3; ii++) {
        atmp_re = A[ii + ((j - 1) << 1)].re;
        atmp_im = A[ii + ((j - 1) << 1)].im;
        A[ii + ((j - 1) << 1)] = A[2 + ii];
        A[2 + ii].re = atmp_re;
        A[2 + ii].im = atmp_im;
      }
    }

    rscale[1] = j;
    *ihi = 1;
    rscale[0] = 1;
  }
}

static void eml_matlab_zggev(const emlrtStack *sp, creal_T A[4], int32_T *info,
  creal_T alpha1[2], creal_T beta1[2], creal_T V[4])
{
  real_T anrm;
  int32_T jrow;
  boolean_T exitg1;
  real_T absxk;
  int32_T i;
  boolean_T ilascl;
  real_T anrmto;
  real_T ctoc;
  boolean_T notdone;
  real_T cfrom1;
  real_T stemp_re;
  real_T stemp_im;
  creal_T b_A[4];
  int32_T rscale[2];
  int32_T ihi;
  int32_T ilo;
  static const int8_T iv0[4] = { 1, 0, 0, 1 };

  int32_T jcol;
  creal_T tmp;
  boolean_T b_jcol;
  int32_T j;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  *info = 0;
  st.site = &h_emlrtRSI;
  anrm = 0.0;
  jrow = 0;
  exitg1 = false;
  while ((!exitg1) && (jrow < 4)) {
    absxk = muDoubleScalarHypot(A[jrow].re, A[jrow].im);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }

      jrow++;
    }
  }

  if (!((!muDoubleScalarIsInf(anrm)) && (!muDoubleScalarIsNaN(anrm)))) {
    for (i = 0; i < 2; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (jrow = 0; jrow < 4; jrow++) {
      V[jrow].re = rtNaN;
      V[jrow].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      absxk = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        cfrom1 = absxk * 2.0041683600089728E-292;
        stemp_re = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          stemp_im = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (stemp_re > absxk) {
          stemp_im = 4.9896007738368E+291;
          ctoc = stemp_re;
        } else {
          stemp_im = ctoc / absxk;
          notdone = false;
        }

        for (jrow = 0; jrow < 4; jrow++) {
          A[jrow].re *= stemp_im;
          A[jrow].im *= stemp_im;
        }
      }
    }

    memcpy(&b_A[0], &A[0], sizeof(creal_T) << 2);
    st.site = &i_emlrtRSI;
    eml_matlab_zggbal(b_A, &ilo, &ihi, rscale);
    st.site = &j_emlrtRSI;
    for (jrow = 0; jrow < 4; jrow++) {
      V[jrow].re = iv0[jrow];
      V[jrow].im = 0.0;
    }

    if (ihi < ilo + 2) {
    } else {
      for (jcol = ilo - 1; jcol + 1 < ihi - 1; jcol++) {
        for (jrow = ihi - 1; jrow + 1 > jcol + 2; jrow--) {
          b_st.site = &y_emlrtRSI;
          eml_matlab_zlartg(&b_st, b_A[(jrow + (jcol << 1)) - 1], b_A[jrow +
                            (jcol << 1)], &cfrom1, &tmp, &b_A[(jrow + (jcol << 1))
                            - 1]);
          b_A[jrow + (jcol << 1)].re = 0.0;
          b_A[jrow + (jcol << 1)].im = 0.0;
          b_st.site = &ab_emlrtRSI;
          c_st.site = &hb_emlrtRSI;
          if (jcol + 2 > ihi) {
            b_jcol = false;
          } else {
            b_jcol = (ihi > 2147483646);
          }

          if (b_jcol) {
            d_st.site = &t_emlrtRSI;
            check_forloop_overflow_error(&d_st, true);
          }

          for (j = jcol + 1; j + 1 <= ihi; j++) {
            stemp_re = cfrom1 * b_A[(jrow + (j << 1)) - 1].re + (tmp.re *
              b_A[jrow + (j << 1)].re - tmp.im * b_A[jrow + (j << 1)].im);
            stemp_im = cfrom1 * b_A[(jrow + (j << 1)) - 1].im + (tmp.re *
              b_A[jrow + (j << 1)].im + tmp.im * b_A[jrow + (j << 1)].re);
            absxk = b_A[(jrow + (j << 1)) - 1].im;
            ctoc = b_A[(jrow + (j << 1)) - 1].re;
            b_A[jrow + (j << 1)].re = cfrom1 * b_A[jrow + (j << 1)].re - (tmp.re
              * b_A[(jrow + (j << 1)) - 1].re + tmp.im * b_A[(jrow + (j << 1)) -
              1].im);
            b_A[jrow + (j << 1)].im = cfrom1 * b_A[jrow + (j << 1)].im - (tmp.re
              * absxk - tmp.im * ctoc);
            b_A[(jrow + (j << 1)) - 1].re = stemp_re;
            b_A[(jrow + (j << 1)) - 1].im = stemp_im;
          }

          tmp.re = -tmp.re;
          tmp.im = -tmp.im;
          b_st.site = &bb_emlrtRSI;
          c_st.site = &ib_emlrtRSI;
          for (i = ilo - 1; i + 1 <= ihi; i++) {
            stemp_re = cfrom1 * b_A[i + (jrow << 1)].re + (tmp.re * b_A[i +
              ((jrow - 1) << 1)].re - tmp.im * b_A[i + ((jrow - 1) << 1)].im);
            stemp_im = cfrom1 * b_A[i + (jrow << 1)].im + (tmp.re * b_A[i +
              ((jrow - 1) << 1)].im + tmp.im * b_A[i + ((jrow - 1) << 1)].re);
            absxk = b_A[i + (jrow << 1)].im;
            ctoc = b_A[i + (jrow << 1)].re;
            b_A[i + ((jrow - 1) << 1)].re = cfrom1 * b_A[i + ((jrow - 1) << 1)].
              re - (tmp.re * b_A[i + (jrow << 1)].re + tmp.im * b_A[i + (jrow <<
                     1)].im);
            b_A[i + ((jrow - 1) << 1)].im = cfrom1 * b_A[i + ((jrow - 1) << 1)].
              im - (tmp.re * absxk - tmp.im * ctoc);
            b_A[i + (jrow << 1)].re = stemp_re;
            b_A[i + (jrow << 1)].im = stemp_im;
          }

          b_st.site = &cb_emlrtRSI;
          c_st.site = &ib_emlrtRSI;
          for (i = 0; i < 2; i++) {
            stemp_re = cfrom1 * V[i + (jrow << 1)].re + (tmp.re * V[i + ((jrow -
              1) << 1)].re - tmp.im * V[i + ((jrow - 1) << 1)].im);
            stemp_im = cfrom1 * V[i + (jrow << 1)].im + (tmp.re * V[i + ((jrow -
              1) << 1)].im + tmp.im * V[i + ((jrow - 1) << 1)].re);
            absxk = V[i + (jrow << 1)].im;
            ctoc = V[i + (jrow << 1)].re;
            V[i + ((jrow - 1) << 1)].re = cfrom1 * V[i + ((jrow - 1) << 1)].re -
              (tmp.re * V[i + (jrow << 1)].re + tmp.im * V[i + (jrow << 1)].im);
            V[i + ((jrow - 1) << 1)].im = cfrom1 * V[i + ((jrow - 1) << 1)].im -
              (tmp.re * absxk - tmp.im * ctoc);
            V[i + (jrow << 1)].re = stemp_re;
            V[i + (jrow << 1)].im = stemp_im;
          }
        }
      }
    }

    st.site = &k_emlrtRSI;
    eml_matlab_zhgeqz(&st, b_A, ilo, ihi, V, info, alpha1, beta1);
    if (*info != 0) {
    } else {
      st.site = &l_emlrtRSI;
      eml_matlab_ztgevc(&st, b_A, V);
      st.site = &m_emlrtRSI;
      if (ilo > 1) {
        for (i = ilo - 2; i + 1 >= 1; i--) {
          jrow = rscale[i] - 1;
          if (rscale[i] != i + 1) {
            for (j = 0; j < 2; j++) {
              tmp = V[i + (j << 1)];
              V[i + (j << 1)] = V[jrow + (j << 1)];
              V[jrow + (j << 1)] = tmp;
            }
          }
        }
      }

      if (ihi < 2) {
        b_st.site = &wb_emlrtRSI;
        while (ihi + 1 < 3) {
          jrow = rscale[ihi] - 1;
          if (rscale[ihi] != ihi + 1) {
            for (j = 0; j < 2; j++) {
              tmp = V[ihi + (j << 1)];
              V[ihi + (j << 1)] = V[jrow + (j << 1)];
              V[jrow + (j << 1)] = tmp;
            }
          }

          ihi++;
        }
      }

      for (jrow = 0; jrow < 2; jrow++) {
        absxk = muDoubleScalarAbs(V[1 + (jrow << 1)].re) + muDoubleScalarAbs(V[1
          + (jrow << 1)].im);
        ctoc = muDoubleScalarAbs(V[jrow << 1].re) + muDoubleScalarAbs(V[jrow <<
          1].im);
        if (absxk > ctoc) {
          ctoc = absxk;
        }

        if (ctoc >= 6.7178761075670888E-139) {
          ctoc = 1.0 / ctoc;
          for (jcol = 0; jcol < 2; jcol++) {
            V[jcol + (jrow << 1)].re *= ctoc;
            V[jcol + (jrow << 1)].im *= ctoc;
          }
        }
      }

      if (ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          stemp_re = anrm / 4.9896007738368E+291;
          if ((cfrom1 > anrm) && (anrm != 0.0)) {
            stemp_im = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (stemp_re > anrmto) {
            stemp_im = 4.9896007738368E+291;
            anrm = stemp_re;
          } else {
            stemp_im = anrm / anrmto;
            notdone = false;
          }

          for (jrow = 0; jrow < 2; jrow++) {
            alpha1[jrow].re *= stemp_im;
            alpha1[jrow].im *= stemp_im;
          }
        }
      }
    }
  }
}

static void eml_matlab_zhgeqz(const emlrtStack *sp, creal_T A[4], int32_T ilo,
  int32_T ihi, creal_T Z[4], int32_T *info, creal_T alpha1[2], creal_T beta1[2])
{
  int32_T jp1;
  real_T eshift_re;
  real_T eshift_im;
  creal_T ctemp;
  real_T rho_re;
  real_T rho_im;
  real_T anorm;
  real_T sigma2_re;
  real_T b_atol;
  real_T sigma2_im;
  real_T ascale;
  boolean_T failed;
  int32_T j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T ifirst;
  int32_T istart;
  int32_T ilast;
  int32_T ilastm1;
  int32_T iiter;
  int32_T maxit;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  boolean_T b4;
  int32_T jiter;
  int32_T exitg1;
  boolean_T exitg3;
  boolean_T ilazro;
  boolean_T b_guard1 = false;
  creal_T t1;
  creal_T d;
  boolean_T exitg2;
  real_T temp2;
  real_T tempr;
  int32_T b_ihi;
  boolean_T b5;
  boolean_T b6;
  boolean_T b7;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  *info = 0;
  for (jp1 = 0; jp1 < 2; jp1++) {
    alpha1[jp1].re = 0.0;
    alpha1[jp1].im = 0.0;
    beta1[jp1].re = 1.0;
    beta1[jp1].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  rho_re = 0.0;
  rho_im = 0.0;
  st.site = &jb_emlrtRSI;
  anorm = eml_matlab_zlanhs(&st, A, ilo, ihi);
  sigma2_re = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (sigma2_re > 2.2250738585072014E-308) {
    b_atol = sigma2_re;
  }

  sigma2_im = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    sigma2_im = anorm;
  }

  ascale = 1.0 / sigma2_im;
  failed = true;
  st.site = &kb_emlrtRSI;
  for (j = ihi; j + 1 < 3; j++) {
    alpha1[j] = A[j + (j << 1)];
  }

  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    iiter = 0;
    maxit = 30 * ((ihi - ilo) + 1);
    goto60 = false;
    goto70 = false;
    goto90 = false;
    st.site = &lb_emlrtRSI;
    if (1 > maxit) {
      b4 = false;
    } else {
      b4 = (maxit > 2147483646);
    }

    if (b4) {
      b_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= maxit) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (muDoubleScalarAbs(A[ilast + (ilastm1 << 1)].re) +
                   muDoubleScalarAbs(A[ilast + (ilastm1 << 1)].im) <= b_atol) {
          A[ilast + (ilastm1 << 1)].re = 0.0;
          A[ilast + (ilastm1 << 1)].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (muDoubleScalarAbs(A[j + ((j - 1) << 1)].re) +
                       muDoubleScalarAbs(A[j + ((j - 1) << 1)].im) <= b_atol) {
              A[j + ((j - 1) << 1)].re = 0.0;
              A[j + ((j - 1) << 1)].im = 0.0;
              ilazro = true;
            } else {
              ilazro = false;
            }

            if (ilazro) {
              ifirst = j + 1;
              goto70 = true;
              exitg3 = true;
            } else {
              j--;
            }
          }
        }

        if (goto60 || goto70) {
          ilazro = true;
        } else {
          ilazro = false;
        }

        if (!ilazro) {
          for (jp1 = 0; jp1 < 2; jp1++) {
            alpha1[jp1].re = rtNaN;
            alpha1[jp1].im = 0.0;
            beta1[jp1].re = rtNaN;
            beta1[jp1].im = 0.0;
          }

          for (jp1 = 0; jp1 < 4; jp1++) {
            Z[jp1].re = rtNaN;
            Z[jp1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          b_guard1 = false;
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = A[ilast + (ilast << 1)];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              b_guard1 = true;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              st.site = &dc_emlrtRSI;
              if (b_mod(&st, iiter) != 0) {
                sigma2_re = -(A[ilast + (ilast << 1)].re - A[ilastm1 + (ilastm1 <<
                  1)].re);
                sigma2_im = -(A[ilast + (ilast << 1)].im - A[ilastm1 + (ilastm1 <<
                  1)].im);
                if (sigma2_im == 0.0) {
                  t1.re = sigma2_re / 2.0;
                  t1.im = 0.0;
                } else if (sigma2_re == 0.0) {
                  t1.re = 0.0;
                  t1.im = sigma2_im / 2.0;
                } else {
                  t1.re = sigma2_re / 2.0;
                  t1.im = sigma2_im / 2.0;
                }

                d.re = (t1.re * t1.re - t1.im * t1.im) + (A[ilastm1 + (ilast <<
                  1)].re * A[ilast + (ilastm1 << 1)].re - A[ilastm1 + (ilast <<
                  1)].im * A[ilast + (ilastm1 << 1)].im);
                d.im = (t1.re * t1.im + t1.im * t1.re) + (A[ilastm1 + (ilast <<
                  1)].re * A[ilast + (ilastm1 << 1)].im + A[ilastm1 + (ilast <<
                  1)].im * A[ilast + (ilastm1 << 1)].re);
                b_sqrt(&d);
                rho_re = A[ilastm1 + (ilastm1 << 1)].re - (t1.re - d.re);
                rho_im = A[ilastm1 + (ilastm1 << 1)].im - (t1.im - d.im);
                sigma2_re = A[ilastm1 + (ilastm1 << 1)].re - (t1.re + d.re);
                sigma2_im = A[ilastm1 + (ilastm1 << 1)].im - (t1.im + d.im);
                if (muDoubleScalarHypot(rho_re - A[ilast + (ilast << 1)].re,
                                        rho_im - A[ilast + (ilast << 1)].im) <=
                    muDoubleScalarHypot(sigma2_re - A[ilast + (ilast << 1)].re,
                                        sigma2_im - A[ilast + (ilast << 1)].im))
                {
                  sigma2_re = rho_re;
                  sigma2_im = rho_im;
                  rho_re = t1.re - d.re;
                  rho_im = t1.im - d.im;
                } else {
                  rho_re = t1.re + d.re;
                  rho_im = t1.im + d.im;
                }
              } else {
                eshift_re += A[ilast + (ilastm1 << 1)].re;
                eshift_im += A[ilast + (ilastm1 << 1)].im;
                sigma2_re = eshift_re;
                sigma2_im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = A[j + (j << 1)].re - sigma2_re;
                ctemp.im = A[j + (j << 1)].im - sigma2_im;
                anorm = ascale * (muDoubleScalarAbs(ctemp.re) +
                                  muDoubleScalarAbs(ctemp.im));
                temp2 = ascale * (muDoubleScalarAbs(A[jp1 + (j << 1)].re) +
                                  muDoubleScalarAbs(A[jp1 + (j << 1)].im));
                tempr = anorm;
                if (temp2 > anorm) {
                  tempr = temp2;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  anorm /= tempr;
                  temp2 /= tempr;
                }

                if ((muDoubleScalarAbs(A[j + ((j - 1) << 1)].re) +
                     muDoubleScalarAbs(A[j + ((j - 1) << 1)].im)) * temp2 <=
                    anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                if (ifirst == ilastm1 + 1) {
                  ctemp.re = rho_re;
                  ctemp.im = rho_im;
                } else {
                  ctemp.re = A[(ifirst + ((ifirst - 1) << 1)) - 1].re -
                    sigma2_re;
                  ctemp.im = A[(ifirst + ((ifirst - 1) << 1)) - 1].im -
                    sigma2_im;
                }

                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              st.site = &mb_emlrtRSI;
              b_eml_matlab_zlartg(&st, ctemp, A[istart + ((istart - 1) << 1)],
                                  &anorm, &t1);
              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  st.site = &nb_emlrtRSI;
                  eml_matlab_zlartg(&st, A[(j + (jp1 << 1)) - 1], A[j + (jp1 <<
                    1)], &anorm, &t1, &A[(j + (jp1 << 1)) - 1]);
                  A[j + (jp1 << 1)].re = 0.0;
                  A[j + (jp1 << 1)].im = 0.0;
                }

                st.site = &ob_emlrtRSI;
                b_st.site = &hb_emlrtRSI;
                for (jp1 = j - 1; jp1 + 1 < 3; jp1++) {
                  d.re = anorm * A[(j + (jp1 << 1)) - 1].re + (t1.re * A[j +
                    (jp1 << 1)].re - t1.im * A[j + (jp1 << 1)].im);
                  d.im = anorm * A[(j + (jp1 << 1)) - 1].im + (t1.re * A[j +
                    (jp1 << 1)].im + t1.im * A[j + (jp1 << 1)].re);
                  sigma2_re = A[(j + (jp1 << 1)) - 1].im;
                  sigma2_im = A[(j + (jp1 << 1)) - 1].re;
                  A[j + (jp1 << 1)].re = anorm * A[j + (jp1 << 1)].re - (t1.re *
                    A[(j + (jp1 << 1)) - 1].re + t1.im * A[(j + (jp1 << 1)) - 1]
                    .im);
                  A[j + (jp1 << 1)].im = anorm * A[j + (jp1 << 1)].im - (t1.re *
                    sigma2_re - t1.im * sigma2_im);
                  A[(j + (jp1 << 1)) - 1] = d;
                }

                t1.re = -t1.re;
                t1.im = -t1.im;
                b_ihi = j + 2;
                if (ilast + 1 < j + 2) {
                  b_ihi = ilast + 1;
                }

                st.site = &pb_emlrtRSI;
                b_st.site = &ib_emlrtRSI;
                if (1 > b_ihi) {
                  b5 = false;
                } else {
                  b5 = (b_ihi > 2147483646);
                }

                if (b5) {
                  c_st.site = &t_emlrtRSI;
                  check_forloop_overflow_error(&c_st, true);
                }

                for (jp1 = 0; jp1 + 1 <= b_ihi; jp1++) {
                  d.re = anorm * A[jp1 + (j << 1)].re + (t1.re * A[jp1 + ((j - 1)
                    << 1)].re - t1.im * A[jp1 + ((j - 1) << 1)].im);
                  d.im = anorm * A[jp1 + (j << 1)].im + (t1.re * A[jp1 + ((j - 1)
                    << 1)].im + t1.im * A[jp1 + ((j - 1) << 1)].re);
                  sigma2_re = A[jp1 + (j << 1)].im;
                  sigma2_im = A[jp1 + (j << 1)].re;
                  A[jp1 + ((j - 1) << 1)].re = anorm * A[jp1 + ((j - 1) << 1)].
                    re - (t1.re * A[jp1 + (j << 1)].re + t1.im * A[jp1 + (j << 1)]
                          .im);
                  A[jp1 + ((j - 1) << 1)].im = anorm * A[jp1 + ((j - 1) << 1)].
                    im - (t1.re * sigma2_re - t1.im * sigma2_im);
                  A[jp1 + (j << 1)] = d;
                }

                st.site = &qb_emlrtRSI;
                b_st.site = &ib_emlrtRSI;
                for (jp1 = 0; jp1 < 2; jp1++) {
                  d.re = anorm * Z[jp1 + (j << 1)].re + (t1.re * Z[jp1 + ((j - 1)
                    << 1)].re - t1.im * Z[jp1 + ((j - 1) << 1)].im);
                  d.im = anorm * Z[jp1 + (j << 1)].im + (t1.re * Z[jp1 + ((j - 1)
                    << 1)].im + t1.im * Z[jp1 + ((j - 1) << 1)].re);
                  sigma2_re = Z[jp1 + (j << 1)].im;
                  sigma2_im = Z[jp1 + (j << 1)].re;
                  Z[jp1 + ((j - 1) << 1)].re = anorm * Z[jp1 + ((j - 1) << 1)].
                    re - (t1.re * Z[jp1 + (j << 1)].re + t1.im * Z[jp1 + (j << 1)]
                          .im);
                  Z[jp1 + ((j - 1) << 1)].im = anorm * Z[jp1 + ((j - 1) << 1)].
                    im - (t1.re * sigma2_re - t1.im * sigma2_im);
                  Z[jp1 + (j << 1)] = d;
                }

                jp1 = j - 1;
                j++;
              }
            }

            b_guard1 = true;
          }

          if (b_guard1) {
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      st.site = &rb_emlrtRSI;
      if (1 > ilast + 1) {
        b6 = false;
      } else {
        b6 = (ilast + 1 > 2147483646);
      }

      if (b6) {
        b_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (jp1 = 0; jp1 + 1 <= ilast + 1; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }

      for (jp1 = 0; jp1 < 4; jp1++) {
        Z[jp1].re = rtNaN;
        Z[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    st.site = &sb_emlrtRSI;
    if (1 > ilo - 1) {
      b7 = false;
    } else {
      b7 = (ilo - 1 > 2147483646);
    }

    if (b7) {
      b_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = 0; j + 1 < ilo; j++) {
      alpha1[j] = A[j + (j << 1)];
    }
  }
}

static real_T eml_matlab_zlanhs(const emlrtStack *sp, const creal_T A[4],
  int32_T ilo, int32_T ihi)
{
  real_T f;
  real_T scale;
  real_T sumsq;
  boolean_T firstNonZero;
  boolean_T b_ilo;
  int32_T j;
  int32_T b;
  boolean_T c_ilo;
  int32_T i;
  real_T reAij;
  real_T imAij;
  real_T temp2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  f = 0.0;
  if (ilo > ihi) {
  } else {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    st.site = &tb_emlrtRSI;
    if (ilo > ihi) {
      b_ilo = false;
    } else {
      b_ilo = (ihi > 2147483646);
    }

    if (b_ilo) {
      b_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&b_st, true);
    }

    for (j = ilo; j <= ihi; j++) {
      b = j + 1;
      if (ihi < j + 1) {
        b = ihi;
      }

      st.site = &ub_emlrtRSI;
      if (ilo > b) {
        c_ilo = false;
      } else {
        c_ilo = (b > 2147483646);
      }

      if (c_ilo) {
        b_st.site = &t_emlrtRSI;
        check_forloop_overflow_error(&b_st, true);
      }

      for (i = ilo; i <= b; i++) {
        reAij = A[(i + ((j - 1) << 1)) - 1].re;
        imAij = A[(i + ((j - 1) << 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = muDoubleScalarAbs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }

        if (imAij != 0.0) {
          reAij = muDoubleScalarAbs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = reAij;
            firstNonZero = false;
          } else if (scale < reAij) {
            temp2 = scale / reAij;
            sumsq = 1.0 + sumsq * temp2 * temp2;
            scale = reAij;
          } else {
            temp2 = reAij / scale;
            sumsq += temp2 * temp2;
          }
        }
      }
    }

    st.site = &vb_emlrtRSI;
    if (sumsq < 0.0) {
      b_st.site = &n_emlrtRSI;
      eml_error(&b_st);
    }

    f = scale * muDoubleScalarSqrt(sumsq);
  }

  return f;
}

static void eml_matlab_zlartg(const emlrtStack *sp, const creal_T f, const
  creal_T g, real_T *cs, creal_T *sn, creal_T *r)
{
  real_T scale;
  real_T f2s;
  real_T g2;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  int32_T count;
  int32_T rescaledir;
  boolean_T guard1 = false;
  real_T g2s;
  boolean_T b0;
  boolean_T b1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  scale = muDoubleScalarAbs(f.re);
  f2s = muDoubleScalarAbs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = muDoubleScalarAbs(g.re);
  g2 = muDoubleScalarAbs(g.im);
  if (g2 > f2s) {
    f2s = g2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  guard1 = false;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    scale = fs_re * fs_re + fs_im * fs_im;
    g2 = gs_re * gs_re + gs_im * gs_im;
    f2s = g2;
    if (1.0 > g2) {
      f2s = 1.0;
    }

    if (scale <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = muDoubleScalarHypot(g.re, g.im);
        r->im = 0.0;
        f2s = muDoubleScalarHypot(gs_re, gs_im);
        sn->re = gs_re / f2s;
        sn->im = -gs_im / f2s;
      } else {
        st.site = &db_emlrtRSI;
        if (g2 < 0.0) {
          b_st.site = &n_emlrtRSI;
          eml_error(&b_st);
        }

        g2s = muDoubleScalarSqrt(g2);
        *cs = muDoubleScalarHypot(fs_re, fs_im) / g2s;
        f2s = muDoubleScalarAbs(f.re);
        g2 = muDoubleScalarAbs(f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0) {
          f2s = muDoubleScalarHypot(f.re, f.im);
          fs_re = f.re / f2s;
          fs_im = f.im / f2s;
        } else {
          g2 = 7.4428285367870146E+137 * f.re;
          scale = 7.4428285367870146E+137 * f.im;
          f2s = muDoubleScalarHypot(g2, scale);
          fs_re = g2 / f2s;
          fs_im = scale / f2s;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = *cs * f.re + (sn->re * g.re - sn->im * g.im);
        r->im = *cs * f.im + (sn->re * g.im + sn->im * g.re);
      }
    } else {
      st.site = &eb_emlrtRSI;
      f2s = 1.0 + g2 / scale;
      if (f2s < 0.0) {
        b_st.site = &n_emlrtRSI;
        eml_error(&b_st);
      }

      f2s = muDoubleScalarSqrt(f2s);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      f2s = scale + g2;
      g2 = r->re / f2s;
      f2s = r->im / f2s;
      sn->re = g2 * gs_re - f2s * -gs_im;
      sn->im = g2 * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        st.site = &fb_emlrtRSI;
        if (1 > count) {
          b0 = false;
        } else {
          b0 = (count > 2147483646);
        }

        if (b0) {
          b_st.site = &t_emlrtRSI;
          check_forloop_overflow_error(&b_st, true);
        }

        for (rescaledir = 1; rescaledir <= count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (rescaledir < 0) {
          st.site = &gb_emlrtRSI;
          if (1 > count) {
            b1 = false;
          } else {
            b1 = (count > 2147483646);
          }

          if (b1) {
            b_st.site = &t_emlrtRSI;
            check_forloop_overflow_error(&b_st, true);
          }

          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

static void eml_matlab_ztgevc(const emlrtStack *sp, const creal_T A[4], creal_T
  V[4])
{
  real_T d_re;
  real_T anorm;
  real_T scale;
  real_T ascale;
  int32_T je;
  real_T temp;
  real_T salpha_re;
  real_T salpha_im;
  real_T acoeff;
  boolean_T b8;
  boolean_T b9;
  real_T y;
  creal_T work1[2];
  int32_T jr;
  real_T dmin;
  real_T d_im;
  real_T work1_re;
  real_T work1_im;
  creal_T work2[2];
  int32_T jc;
  d_re = (muDoubleScalarAbs(A[2].re) + muDoubleScalarAbs(A[2].im)) +
    (muDoubleScalarAbs(A[3].re) + muDoubleScalarAbs(A[3].im));
  anorm = muDoubleScalarAbs(A[0].re) + muDoubleScalarAbs(A[0].im);
  if (d_re > anorm) {
    anorm = d_re;
  }

  scale = anorm;
  if (2.2250738585072014E-308 > anorm) {
    scale = 2.2250738585072014E-308;
  }

  ascale = 1.0 / scale;
  for (je = 0; je < 2; je++) {
    scale = (muDoubleScalarAbs(A[(((1 - je) << 1) - je) + 1].re) +
             muDoubleScalarAbs(A[(((1 - je) << 1) - je) + 1].im)) * ascale;
    if (1.0 > scale) {
      scale = 1.0;
    }

    temp = 1.0 / scale;
    salpha_re = ascale * (temp * A[(((1 - je) << 1) - je) + 1].re);
    salpha_im = ascale * (temp * A[(((1 - je) << 1) - je) + 1].im);
    acoeff = temp * ascale;
    if ((muDoubleScalarAbs(temp) >= 2.2250738585072014E-308) &&
        (muDoubleScalarAbs(acoeff) < 2.0041683600089728E-292)) {
      b8 = true;
    } else {
      b8 = false;
    }

    if ((muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im) >=
         2.2250738585072014E-308) && (muDoubleScalarAbs(salpha_re) +
         muDoubleScalarAbs(salpha_im) < 2.0041683600089728E-292)) {
      b9 = true;
    } else {
      b9 = false;
    }

    scale = 1.0;
    if (b8) {
      scale = anorm;
      if (4.9896007738368E+291 < anorm) {
        scale = 4.9896007738368E+291;
      }

      scale *= 2.0041683600089728E-292 / muDoubleScalarAbs(temp);
    }

    if (b9) {
      d_re = 2.0041683600089728E-292 / (muDoubleScalarAbs(salpha_re) +
        muDoubleScalarAbs(salpha_im));
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (b8 || b9) {
      d_re = muDoubleScalarAbs(acoeff);
      y = muDoubleScalarAbs(salpha_re) + muDoubleScalarAbs(salpha_im);
      if (1.0 > d_re) {
        d_re = 1.0;
      }

      if (y > d_re) {
        d_re = y;
      }

      d_re = 1.0 / (2.2250738585072014E-308 * d_re);
      if (d_re < scale) {
        scale = d_re;
      }

      if (b8) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      if (b9) {
        salpha_re *= scale;
        salpha_im *= scale;
      } else {
        salpha_re *= scale;
        salpha_im *= scale;
      }
    }

    for (jr = 0; jr < 2; jr++) {
      work1[jr].re = 0.0;
      work1[jr].im = 0.0;
    }

    work1[1 - je].re = 1.0;
    work1[1 - je].im = 0.0;
    dmin = 2.2204460492503131E-16 * muDoubleScalarAbs(acoeff) * anorm;
    d_re = 2.2204460492503131E-16 * (muDoubleScalarAbs(salpha_re) +
      muDoubleScalarAbs(salpha_im));
    if (d_re > dmin) {
      dmin = d_re;
    }

    if (2.2250738585072014E-308 > dmin) {
      dmin = 2.2250738585072014E-308;
    }

    jr = 0;
    while (jr <= -je) {
      work1[0].re = acoeff * A[(1 - je) << 1].re;
      work1[0].im = acoeff * A[(1 - je) << 1].im;
      jr = 1;
    }

    work1[1 - je].re = 1.0;
    work1[1 - je].im = 0.0;
    emlrtForLoopVectorCheckR2012b((2.0 + -(real_T)je) - 1.0, -1.0, 1.0,
      mxDOUBLE_CLASS, 1 - je, &c_emlrtRTEI, sp);
    jr = 0;
    while (jr <= -je) {
      d_re = acoeff * A[(-je << 1) - je].re - salpha_re;
      d_im = acoeff * A[(-je << 1) - je].im - salpha_im;
      if (muDoubleScalarAbs(d_re) + muDoubleScalarAbs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0;
      }

      if ((muDoubleScalarAbs(d_re) + muDoubleScalarAbs(d_im) < 1.0) &&
          (muDoubleScalarAbs(work1[-je].re) + muDoubleScalarAbs(work1[-je].im) >=
           2.2471164185778949E+307 * (muDoubleScalarAbs(d_re) +
            muDoubleScalarAbs(d_im)))) {
        temp = 1.0 / (muDoubleScalarAbs(work1[-je].re) + muDoubleScalarAbs
                      (work1[-je].im));
        for (jr = 0; jr <= 1 - je; jr++) {
          work1[jr].re *= temp;
          work1[jr].im *= temp;
        }
      }

      work1_re = -work1[-je].re;
      work1_im = -work1[-je].im;
      if (d_im == 0.0) {
        if (-work1[-je].im == 0.0) {
          work1[-je].re = -work1[-je].re / d_re;
          work1[-je].im = 0.0;
        } else if (-work1[-je].re == 0.0) {
          work1[-je].re = 0.0;
          work1[-je].im = work1_im / d_re;
        } else {
          work1[-je].re = -work1[-je].re / d_re;
          work1[-je].im = work1_im / d_re;
        }
      } else if (d_re == 0.0) {
        if (-work1[-je].re == 0.0) {
          work1[-je].re = -work1[-je].im / d_im;
          work1[-je].im = 0.0;
        } else if (-work1[-je].im == 0.0) {
          work1[-je].re = 0.0;
          work1[-je].im = -(work1_re / d_im);
        } else {
          work1[-je].re = -work1[-je].im / d_im;
          work1[-je].im = -(work1_re / d_im);
        }
      } else {
        temp = muDoubleScalarAbs(d_re);
        scale = muDoubleScalarAbs(d_im);
        if (temp > scale) {
          y = d_im / d_re;
          scale = d_re + y * d_im;
          work1[-je].re = (-work1[-je].re + y * -work1[-je].im) / scale;
          work1[-je].im = (work1_im - y * work1_re) / scale;
        } else if (scale == temp) {
          if (d_re > 0.0) {
            y = 0.5;
          } else {
            y = -0.5;
          }

          if (d_im > 0.0) {
            scale = 0.5;
          } else {
            scale = -0.5;
          }

          work1[-je].re = (-work1[-je].re * y + -work1[-je].im * scale) / temp;
          work1[-je].im = (work1_im * y - work1_re * scale) / temp;
        } else {
          y = d_re / d_im;
          scale = d_im + y * d_re;
          work1[-je].re = (y * -work1[-je].re + -work1[-je].im) / scale;
          work1[-je].im = (y * work1_im - work1_re) / scale;
        }
      }

      jr = 1;
    }

    for (jr = 0; jr < 2; jr++) {
      work2[jr].re = 0.0;
      work2[jr].im = 0.0;
    }

    for (jc = 0; jc <= 1 - je; jc++) {
      for (jr = 0; jr < 2; jr++) {
        work2[jr].re += V[jr + (jc << 1)].re * work1[jc].re - V[jr + (jc << 1)].
          im * work1[jc].im;
        work2[jr].im += V[jr + (jc << 1)].re * work1[jc].im + V[jr + (jc << 1)].
          im * work1[jc].re;
      }
    }

    d_re = muDoubleScalarAbs(work2[1].re) + muDoubleScalarAbs(work2[1].im);
    scale = muDoubleScalarAbs(work2[0].re) + muDoubleScalarAbs(work2[0].im);
    if (d_re > scale) {
      scale = d_re;
    }

    if (scale > 2.2250738585072014E-308) {
      temp = 1.0 / scale;
      for (jr = 0; jr < 2; jr++) {
        V[jr + ((1 - je) << 1)].re = temp * work2[jr].re;
        V[jr + ((1 - je) << 1)].im = temp * work2[jr].im;
      }
    } else {
      for (jr = 0; jr < 2; jr++) {
        V[jr + ((1 - je) << 1)].re = 0.0;
        V[jr + ((1 - je) << 1)].im = 0.0;
      }
    }
  }
}

void eee(const emlrtStack *sp, const real_T a[4], creal_T ans1[4], creal_T ans2
         [4])
{
  creal_T b_a[4];
  int32_T j;
  creal_T beta1[2];
  creal_T alpha1[2];
  int32_T info;
  int32_T coltop;
  real_T colnorm;
  real_T scale;
  real_T absxk;
  real_T t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &b_emlrtRSI;
  c_st.site = &d_emlrtRSI;
  for (j = 0; j < 4; j++) {
    b_a[j].re = a[j];
    b_a[j].im = 0.0;
  }

  d_st.site = &e_emlrtRSI;
  eml_matlab_zggev(&d_st, b_a, &info, alpha1, beta1, ans1);
  for (coltop = 0; coltop < 4; coltop += 2) {
    colnorm = 0.0;
    scale = 2.2250738585072014E-308;
    for (j = coltop; j + 1 <= coltop + 2; j++) {
      absxk = muDoubleScalarAbs(ans1[j].re);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }

      absxk = muDoubleScalarAbs(ans1[j].im);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }
    }

    colnorm = scale * muDoubleScalarSqrt(colnorm);
    for (j = coltop; j + 1 <= coltop + 2; j++) {
      scale = ans1[j].im;
      if (ans1[j].im == 0.0) {
        ans1[j].re /= colnorm;
        ans1[j].im = 0.0;
      } else if (ans1[j].re == 0.0) {
        ans1[j].re = 0.0;
        ans1[j].im = scale / colnorm;
      } else {
        ans1[j].re /= colnorm;
        ans1[j].im = scale / colnorm;
      }
    }
  }

  for (j = 0; j < 4; j++) {
    ans2[j].re = 0.0;
    ans2[j].im = 0.0;
  }

  for (j = 0; j < 2; j++) {
    if (beta1[j].im == 0.0) {
      if (alpha1[j].im == 0.0) {
        ans2[j + (j << 1)].re = alpha1[j].re / beta1[j].re;
        ans2[j + (j << 1)].im = 0.0;
      } else if (alpha1[j].re == 0.0) {
        ans2[j + (j << 1)].re = 0.0;
        ans2[j + (j << 1)].im = alpha1[j].im / beta1[j].re;
      } else {
        ans2[j + (j << 1)].re = alpha1[j].re / beta1[j].re;
        ans2[j + (j << 1)].im = alpha1[j].im / beta1[j].re;
      }
    } else if (beta1[j].re == 0.0) {
      if (alpha1[j].re == 0.0) {
        ans2[j + (j << 1)].re = alpha1[j].im / beta1[j].im;
        ans2[j + (j << 1)].im = 0.0;
      } else if (alpha1[j].im == 0.0) {
        ans2[j + (j << 1)].re = 0.0;
        ans2[j + (j << 1)].im = -(alpha1[j].re / beta1[j].im);
      } else {
        ans2[j + (j << 1)].re = alpha1[j].im / beta1[j].im;
        ans2[j + (j << 1)].im = -(alpha1[j].re / beta1[j].im);
      }
    } else {
      t = muDoubleScalarAbs(beta1[j].re);
      scale = muDoubleScalarAbs(beta1[j].im);
      if (t > scale) {
        scale = beta1[j].im / beta1[j].re;
        absxk = beta1[j].re + scale * beta1[j].im;
        ans2[j + (j << 1)].re = (alpha1[j].re + scale * alpha1[j].im) / absxk;
        ans2[j + (j << 1)].im = (alpha1[j].im - scale * alpha1[j].re) / absxk;
      } else if (scale == t) {
        if (beta1[j].re > 0.0) {
          scale = 0.5;
        } else {
          scale = -0.5;
        }

        if (beta1[j].im > 0.0) {
          absxk = 0.5;
        } else {
          absxk = -0.5;
        }

        ans2[j + (j << 1)].re = (alpha1[j].re * scale + alpha1[j].im * absxk) /
          t;
        ans2[j + (j << 1)].im = (alpha1[j].im * scale - alpha1[j].re * absxk) /
          t;
      } else {
        scale = beta1[j].re / beta1[j].im;
        absxk = beta1[j].im + scale * beta1[j].re;
        ans2[j + (j << 1)].re = (scale * alpha1[j].re + alpha1[j].im) / absxk;
        ans2[j + (j << 1)].im = (scale * alpha1[j].im - alpha1[j].re) / absxk;
      }
    }
  }

  if (info != 0) {
    b_st.site = &c_emlrtRSI;
    eml_warning(&b_st);
  }
}

/* End of code generation (eee.c) */
