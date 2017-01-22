/*
 * File: eee.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 01-Oct-2015 23:53:36
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "eee.h"
#include "sqrt.h"
#include "mod.h"
#include "eee_rtwutil.h"

/* Function Declarations */
static void eml_matlab_zggev(creal_T A[4], int *info, creal_T alpha1[2], creal_T
  beta1[2], creal_T V[4]);
static void eml_matlab_zhgeqz(creal_T A[4], int ilo, int ihi, creal_T Z[4], int *
  info, creal_T alpha1[2], creal_T beta1[2]);
static double eml_matlab_zlangeM(const creal_T x[4]);
static double eml_matlab_zlanhs(const creal_T A[4], int ilo, int ihi);
static void eml_matlab_zlartg(const creal_T f, const creal_T g, double *cs,
  creal_T *sn, creal_T *r);
static void eml_matlab_ztgevc(const creal_T A[4], creal_T V[4]);

/* Function Definitions */

/*
 * Arguments    : creal_T A[4]
 *                int *info
 *                creal_T alpha1[2]
 *                creal_T beta1[2]
 *                creal_T V[4]
 * Return Type  : void
 */
static void eml_matlab_zggev(creal_T A[4], int *info, creal_T alpha1[2], creal_T
  beta1[2], creal_T V[4])
{
  double anrm;
  int i;
  int nzcount;
  boolean_T ilascl;
  double anrmto;
  double cfromc;
  double ctoc;
  boolean_T notdone;
  double cfrom1;
  double cto1;
  double mul;
  creal_T b_A[4];
  signed char rscale[2];
  int ilo;
  int ihi;
  int j;
  int ii;
  boolean_T exitg3;
  int jj;
  boolean_T exitg4;
  boolean_T guard2 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  static const signed char iv0[4] = { 1, 0, 0, 1 };

  *info = 0;
  anrm = eml_matlab_zlangeM(A);
  if (!((!rtIsInf(anrm)) && (!rtIsNaN(anrm)))) {
    for (i = 0; i < 2; i++) {
      alpha1[i].re = rtNaN;
      alpha1[i].im = 0.0;
      beta1[i].re = rtNaN;
      beta1[i].im = 0.0;
    }

    for (nzcount = 0; nzcount < 4; nzcount++) {
      V[nzcount].re = rtNaN;
      V[nzcount].im = 0.0;
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
      cfromc = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        cfrom1 = cfromc * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          cfromc = cfrom1;
        } else if (fabs(cto1) > fabs(cfromc)) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / cfromc;
          notdone = false;
        }

        for (nzcount = 0; nzcount < 4; nzcount++) {
          A[nzcount].re *= mul;
          A[nzcount].im *= mul;
        }
      }
    }

    memcpy(&b_A[0], &A[0], sizeof(creal_T) << 2);
    for (i = 0; i < 2; i++) {
      rscale[i] = 0;
    }

    ilo = 1;
    ihi = 2;
    i = 0;
    j = 0;
    notdone = false;
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
        if ((b_A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (b_A[(ii + ((jj - 1) <<
               1)) - 1].im != 0.0) || (ii == jj)) {
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
        notdone = true;
        exitg3 = true;
      } else {
        ii--;
      }
    }

    if (!notdone) {
      i = 0;
      j = 0;
      notdone = false;
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
          if ((b_A[(ii + ((jj - 1) << 1)) - 1].re != 0.0) || (b_A[(ii + ((jj - 1)
                 << 1)) - 1].im != 0.0) || (ii == jj)) {
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
          notdone = true;
          exitg1 = true;
        } else {
          jj++;
        }
      }

      if (!notdone) {
      } else {
        if (i != 1) {
          for (nzcount = 0; nzcount + 1 < 3; nzcount++) {
            cfromc = b_A[(i + (nzcount << 1)) - 1].re;
            ctoc = b_A[(i + (nzcount << 1)) - 1].im;
            b_A[(i + (nzcount << 1)) - 1] = b_A[nzcount << 1];
            b_A[nzcount << 1].re = cfromc;
            b_A[nzcount << 1].im = ctoc;
          }
        }

        if (j != 1) {
          for (nzcount = 0; nzcount + 1 < 3; nzcount++) {
            cfromc = b_A[nzcount + ((j - 1) << 1)].re;
            ctoc = b_A[nzcount + ((j - 1) << 1)].im;
            b_A[nzcount + ((j - 1) << 1)] = b_A[nzcount];
            b_A[nzcount].re = cfromc;
            b_A[nzcount].im = ctoc;
          }
        }

        rscale[0] = (signed char)j;
        ilo = 2;
        rscale[1] = 2;
      }
    } else {
      if (i != 2) {
        for (nzcount = 0; nzcount < 2; nzcount++) {
          cfromc = b_A[nzcount << 1].re;
          ctoc = b_A[nzcount << 1].im;
          b_A[nzcount << 1] = b_A[1 + (nzcount << 1)];
          b_A[1 + (nzcount << 1)].re = cfromc;
          b_A[1 + (nzcount << 1)].im = ctoc;
        }
      }

      if (j != 2) {
        for (nzcount = 0; nzcount + 1 < 3; nzcount++) {
          cfromc = b_A[nzcount].re;
          ctoc = b_A[nzcount].im;
          b_A[nzcount] = b_A[2 + nzcount];
          b_A[2 + nzcount].re = cfromc;
          b_A[2 + nzcount].im = ctoc;
        }
      }

      rscale[1] = (signed char)j;
      ihi = 1;
      rscale[0] = 1;
    }

    for (nzcount = 0; nzcount < 4; nzcount++) {
      V[nzcount].re = iv0[nzcount];
      V[nzcount].im = 0.0;
    }

    eml_matlab_zhgeqz(b_A, ilo, ihi, V, info, alpha1, beta1);
    if (*info != 0) {
    } else {
      eml_matlab_ztgevc(b_A, V);
      if (ilo > 1) {
        for (i = 0; i + 1 >= 1; i--) {
          nzcount = rscale[i] - 1;
          if (rscale[i] != i + 1) {
            for (j = 0; j < 2; j++) {
              cfromc = V[i + (j << 1)].re;
              ctoc = V[i + (j << 1)].im;
              V[i + (j << 1)] = V[nzcount + (j << 1)];
              V[nzcount + (j << 1)].re = cfromc;
              V[nzcount + (j << 1)].im = ctoc;
            }
          }
        }
      }

      if (ihi < 2) {
        nzcount = rscale[1] - 1;
        if (rscale[1] != 2) {
          for (j = 0; j < 2; j++) {
            cfromc = V[1 + (j << 1)].re;
            ctoc = V[1 + (j << 1)].im;
            V[1 + (j << 1)] = V[nzcount + (j << 1)];
            V[nzcount + (j << 1)].re = cfromc;
            V[nzcount + (j << 1)].im = ctoc;
          }
        }
      }

      for (nzcount = 0; nzcount < 2; nzcount++) {
        cfromc = fabs(V[1 + (nzcount << 1)].re) + fabs(V[1 + (nzcount << 1)].im);
        ctoc = fabs(V[nzcount << 1].re) + fabs(V[nzcount << 1].im);
        if (cfromc > ctoc) {
          ctoc = cfromc;
        }

        if (ctoc >= 6.7178761075670888E-139) {
          ctoc = 1.0 / ctoc;
          for (ii = 0; ii < 2; ii++) {
            V[ii + (nzcount << 1)].re *= ctoc;
            V[ii + (nzcount << 1)].im *= ctoc;
          }
        }
      }

      if (ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          cto1 = anrm / 4.9896007738368E+291;
          if ((fabs(cfrom1) > fabs(anrm)) && (anrm != 0.0)) {
            mul = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (fabs(cto1) > fabs(anrmto)) {
            mul = 4.9896007738368E+291;
            anrm = cto1;
          } else {
            mul = anrm / anrmto;
            notdone = false;
          }

          for (nzcount = 0; nzcount < 2; nzcount++) {
            alpha1[nzcount].re *= mul;
            alpha1[nzcount].im *= mul;
          }
        }
      }
    }
  }
}

/*
 * Arguments    : creal_T A[4]
 *                int ilo
 *                int ihi
 *                creal_T Z[4]
 *                int *info
 *                creal_T alpha1[2]
 *                creal_T beta1[2]
 * Return Type  : void
 */
static void eml_matlab_zhgeqz(creal_T A[4], int ilo, int ihi, creal_T Z[4], int *
  info, creal_T alpha1[2], creal_T beta1[2])
{
  int jp1;
  double eshift_re;
  double eshift_im;
  double ctemp_re;
  double ctemp_im;
  double rho_re;
  double rho_im;
  double anorm;
  double temp;
  double b_atol;
  double sigma2_im;
  double ascale;
  boolean_T failed;
  int j;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int ifirst;
  int istart;
  int ilast;
  int ilastm1;
  int iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int jiter;
  int32_T exitg1;
  boolean_T exitg3;
  boolean_T ilazro;
  boolean_T b_guard1 = false;
  creal_T t1;
  creal_T d;
  boolean_T exitg2;
  double temp2;
  double tempr;
  boolean_T guard3 = false;
  int x;
  *info = 0;
  for (jp1 = 0; jp1 < 2; jp1++) {
    alpha1[jp1].re = 0.0;
    alpha1[jp1].im = 0.0;
    beta1[jp1].re = 1.0;
    beta1[jp1].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp_re = 0.0;
  ctemp_im = 0.0;
  rho_re = 0.0;
  rho_im = 0.0;
  anorm = eml_matlab_zlanhs(A, ilo, ihi);
  temp = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (temp > 2.2250738585072014E-308) {
    b_atol = temp;
  }

  sigma2_im = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    sigma2_im = anorm;
  }

  ascale = 1.0 / sigma2_im;
  failed = true;
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
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1)) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (fabs(A[ilast + (ilastm1 << 1)].re) + fabs(A[ilast + (ilastm1 <<
          1)].im) <= b_atol) {
          A[ilast + (ilastm1 << 1)].re = 0.0;
          A[ilast + (ilastm1 << 1)].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          exitg3 = false;
          while ((!exitg3) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (fabs(A[j + ((j - 1) << 1)].re) + fabs(A[j + ((j - 1) << 1)]
                        .im) <= b_atol) {
              A[j].re = 0.0;
              A[j].im = 0.0;
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
              if (b_mod(iiter) != 0) {
                anorm = -(A[ilast + (ilast << 1)].re - A[ilastm1 + (ilastm1 << 1)]
                          .re);
                sigma2_im = -(A[ilast + (ilast << 1)].im - A[ilastm1 + (ilastm1 <<
                  1)].im);
                if (sigma2_im == 0.0) {
                  t1.re = anorm / 2.0;
                  t1.im = 0.0;
                } else if (anorm == 0.0) {
                  t1.re = 0.0;
                  t1.im = sigma2_im / 2.0;
                } else {
                  t1.re = anorm / 2.0;
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
                anorm = A[ilastm1 + (ilastm1 << 1)].re - (t1.re + d.re);
                sigma2_im = A[ilastm1 + (ilastm1 << 1)].im - (t1.im + d.im);
                if (rt_hypotd_snf(rho_re - A[ilast + (ilast << 1)].re, rho_im -
                                  A[ilast + (ilast << 1)].im) <= rt_hypotd_snf
                    (anorm - A[ilast + (ilast << 1)].re, sigma2_im - A[ilast +
                     (ilast << 1)].im)) {
                  anorm = rho_re;
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
                anorm = eshift_re;
                sigma2_im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp_re = A[j + (j << 1)].re - anorm;
                ctemp_im = A[j + (j << 1)].im - sigma2_im;
                temp = ascale * (fabs(ctemp_re) + fabs(ctemp_im));
                temp2 = ascale * (fabs(A[jp1 + (j << 1)].re) + fabs(A[jp1 + (j <<
                  1)].im));
                tempr = temp;
                if (temp2 > temp) {
                  tempr = temp2;
                }

                if ((tempr < 1.0) && (tempr != 0.0)) {
                  temp /= tempr;
                  temp2 /= tempr;
                }

                if ((fabs(A[j + ((j - 1) << 1)].re) + fabs(A[j + ((j - 1) << 1)]
                      .im)) * temp2 <= temp * b_atol) {
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
                  ctemp_re = rho_re;
                  ctemp_im = rho_im;
                } else {
                  ctemp_re = A[(ifirst + ((ifirst - 1) << 1)) - 1].re - anorm;
                  ctemp_im = A[(ifirst + ((ifirst - 1) << 1)) - 1].im -
                    sigma2_im;
                }

                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              sigma2_im = fabs(ctemp_re);
              temp = fabs(ctemp_im);
              if (temp > sigma2_im) {
                sigma2_im = temp;
              }

              temp = fabs(A[istart + ((istart - 1) << 1)].re);
              anorm = fabs(A[istart + ((istart - 1) << 1)].im);
              if (anorm > temp) {
                temp = anorm;
              }

              if (temp > sigma2_im) {
                sigma2_im = temp;
              }

              t1.re = ctemp_re;
              t1.im = ctemp_im;
              d = A[istart + ((istart - 1) << 1)];
              guard3 = false;
              if (sigma2_im >= 7.4428285367870146E+137) {
                do {
                  t1.re *= 1.3435752215134178E-138;
                  t1.im *= 1.3435752215134178E-138;
                  d.re *= 1.3435752215134178E-138;
                  d.im *= 1.3435752215134178E-138;
                  sigma2_im *= 1.3435752215134178E-138;
                } while (!(sigma2_im < 7.4428285367870146E+137));

                guard3 = true;
              } else if (sigma2_im <= 1.3435752215134178E-138) {
                if ((A[istart + ((istart - 1) << 1)].re == 0.0) && (A[istart +
                     ((istart - 1) << 1)].im == 0.0)) {
                  tempr = 1.0;
                  t1.re = 0.0;
                  t1.im = 0.0;
                } else {
                  do {
                    t1.re *= 7.4428285367870146E+137;
                    t1.im *= 7.4428285367870146E+137;
                    d.re *= 7.4428285367870146E+137;
                    d.im *= 7.4428285367870146E+137;
                    sigma2_im *= 7.4428285367870146E+137;
                  } while (!(sigma2_im > 1.3435752215134178E-138));

                  guard3 = true;
                }
              } else {
                guard3 = true;
              }

              if (guard3) {
                anorm = t1.re * t1.re + t1.im * t1.im;
                temp = d.re * d.re + d.im * d.im;
                sigma2_im = temp;
                if (1.0 > temp) {
                  sigma2_im = 1.0;
                }

                if (anorm <= sigma2_im * 2.0041683600089728E-292) {
                  if ((ctemp_re == 0.0) && (ctemp_im == 0.0)) {
                    tempr = 0.0;
                    temp = rt_hypotd_snf(d.re, d.im);
                    t1.re = d.re / temp;
                    t1.im = -d.im / temp;
                  } else {
                    temp2 = sqrt(temp);
                    tempr = rt_hypotd_snf(t1.re, t1.im) / temp2;
                    temp = fabs(ctemp_re);
                    anorm = fabs(ctemp_im);
                    if (anorm > temp) {
                      temp = anorm;
                    }

                    if (temp > 1.0) {
                      temp = rt_hypotd_snf(ctemp_re, ctemp_im);
                      t1.re = ctemp_re / temp;
                      t1.im = ctemp_im / temp;
                    } else {
                      anorm = 7.4428285367870146E+137 * ctemp_re;
                      sigma2_im = 7.4428285367870146E+137 * ctemp_im;
                      temp = rt_hypotd_snf(anorm, sigma2_im);
                      t1.re = anorm / temp;
                      t1.im = sigma2_im / temp;
                    }

                    sigma2_im = d.re / temp2;
                    anorm = -d.im / temp2;
                    temp2 = t1.re;
                    t1.re = t1.re * sigma2_im - t1.im * anorm;
                    t1.im = temp2 * anorm + t1.im * sigma2_im;
                  }
                } else {
                  sigma2_im = sqrt(1.0 + temp / anorm);
                  tempr = 1.0 / sigma2_im;
                  temp += anorm;
                  temp2 = sigma2_im * t1.re / temp;
                  anorm = sigma2_im * t1.im / temp;
                  t1.re = temp2 * d.re - anorm * -d.im;
                  t1.im = temp2 * -d.im + anorm * d.re;
                }
              }

              j = istart;
              jp1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  eml_matlab_zlartg(A[1 + (jp1 << 1)], A[j + (jp1 << 1)], &tempr,
                                    &t1, &A[1 + (jp1 << 1)]);
                  A[2 + (jp1 << 1)].re = 0.0;
                  A[2 + (jp1 << 1)].im = 0.0;
                }

                for (jp1 = j - 1; jp1 + 1 < 3; jp1++) {
                  d.re = tempr * A[(j + (jp1 << 1)) - 1].re + (t1.re * A[1 +
                    (jp1 << 1)].re - t1.im * A[1 + (jp1 << 1)].im);
                  d.im = tempr * A[(j + (jp1 << 1)) - 1].im + (t1.re * A[1 +
                    (jp1 << 1)].im + t1.im * A[1 + (jp1 << 1)].re);
                  anorm = A[(j + (jp1 << 1)) - 1].im;
                  sigma2_im = A[(j + (jp1 << 1)) - 1].re;
                  A[1 + (jp1 << 1)].re = tempr * A[j + (jp1 << 1)].re - (t1.re *
                    A[(j + (jp1 << 1)) - 1].re + t1.im * A[(j + (jp1 << 1)) - 1]
                    .im);
                  A[1 + (jp1 << 1)].im = tempr * A[j + (jp1 << 1)].im - (t1.re *
                    anorm - t1.im * sigma2_im);
                  A[(j + (jp1 << 1)) - 1] = d;
                }

                t1.re = -t1.re;
                t1.im = -t1.im;
                x = j;
                if (ilast + 1 < j + 2) {
                  x = ilast - 1;
                }

                for (jp1 = 0; jp1 + 1 <= x + 2; jp1++) {
                  d.re = tempr * A[jp1 + (j << 1)].re + (t1.re * A[jp1 + ((j - 1)
                    << 1)].re - t1.im * A[jp1 + ((j - 1) << 1)].im);
                  d.im = tempr * A[jp1 + (j << 1)].im + (t1.re * A[jp1 + ((j - 1)
                    << 1)].im + t1.im * A[jp1 + ((j - 1) << 1)].re);
                  anorm = A[jp1 + (j << 1)].im;
                  sigma2_im = A[jp1 + (j << 1)].re;
                  A[jp1 + ((j - 1) << 1)].re = tempr * A[jp1 + ((j - 1) << 1)].
                    re - (t1.re * A[jp1 + (j << 1)].re + t1.im * A[jp1 + (j << 1)]
                          .im);
                  A[jp1 + ((j - 1) << 1)].im = tempr * A[jp1 + ((j - 1) << 1)].
                    im - (t1.re * anorm - t1.im * sigma2_im);
                  A[2 + jp1] = d;
                }

                for (jp1 = 0; jp1 < 2; jp1++) {
                  d.re = tempr * Z[jp1 + (j << 1)].re + (t1.re * Z[jp1 + ((j - 1)
                    << 1)].re - t1.im * Z[jp1 + ((j - 1) << 1)].im);
                  d.im = tempr * Z[jp1 + (j << 1)].im + (t1.re * Z[jp1 + ((j - 1)
                    << 1)].im + t1.im * Z[jp1 + ((j - 1) << 1)].re);
                  anorm = Z[jp1 + (j << 1)].im;
                  sigma2_im = Z[jp1 + (j << 1)].re;
                  Z[jp1 + ((j - 1) << 1)].re = tempr * Z[jp1 + ((j - 1) << 1)].
                    re - (t1.re * Z[jp1 + (j << 1)].re + t1.im * Z[jp1 + (j << 1)]
                          .im);
                  Z[jp1 + ((j - 1) << 1)].im = tempr * Z[jp1 + ((j - 1) << 1)].
                    im - (t1.re * anorm - t1.im * sigma2_im);
                  Z[2 + jp1] = d;
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
    for (j = 0; j + 1 < ilo; j++) {
      alpha1[j] = A[j + (j << 1)];
    }
  }
}

/*
 * Arguments    : const creal_T x[4]
 * Return Type  : double
 */
static double eml_matlab_zlangeM(const creal_T x[4])
{
  double y;
  int k;
  boolean_T exitg1;
  double absxk;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    absxk = rt_hypotd_snf(x[k].re, x[k].im);
    if (rtIsNaN(absxk)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > y) {
        y = absxk;
      }

      k++;
    }
  }

  return y;
}

/*
 * Arguments    : const creal_T A[4]
 *                int ilo
 *                int ihi
 * Return Type  : double
 */
static double eml_matlab_zlanhs(const creal_T A[4], int ilo, int ihi)
{
  double f;
  double scale;
  double sumsq;
  boolean_T firstNonZero;
  int j;
  int i0;
  int i;
  double reAij;
  double imAij;
  double temp2;
  f = 0.0;
  if (ilo > ihi) {
  } else {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (j = ilo; j <= ihi; j++) {
      i0 = j + 1;
      if (ihi < j + 1) {
        i0 = ihi;
      }

      for (i = ilo; i <= i0; i++) {
        reAij = A[(i + ((j - 1) << 1)) - 1].re;
        imAij = A[(i + ((j - 1) << 1)) - 1].im;
        if (reAij != 0.0) {
          reAij = fabs(reAij);
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
          reAij = fabs(imAij);
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

    f = scale * sqrt(sumsq);
  }

  return f;
}

/*
 * Arguments    : const creal_T f
 *                const creal_T g
 *                double *cs
 *                creal_T *sn
 *                creal_T *r
 * Return Type  : void
 */
static void eml_matlab_zlartg(const creal_T f, const creal_T g, double *cs,
  creal_T *sn, creal_T *r)
{
  double scale;
  double f2s;
  double g2;
  double fs_re;
  double fs_im;
  double gs_re;
  double gs_im;
  int count;
  int rescaledir;
  boolean_T guard1 = false;
  double g2s;
  scale = fabs(f.re);
  f2s = fabs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = fabs(g.re);
  g2 = fabs(g.im);
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
        r->re = rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        f2s = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / f2s;
        sn->im = -gs_im / f2s;
      } else {
        g2s = sqrt(g2);
        *cs = rt_hypotd_snf(fs_re, fs_im) / g2s;
        f2s = fabs(f.re);
        g2 = fabs(f.im);
        if (g2 > f2s) {
          f2s = g2;
        }

        if (f2s > 1.0) {
          f2s = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / f2s;
          fs_im = f.im / f2s;
        } else {
          g2 = 7.4428285367870146E+137 * f.re;
          scale = 7.4428285367870146E+137 * f.im;
          f2s = rt_hypotd_snf(g2, scale);
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
      f2s = sqrt(1.0 + g2 / scale);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      f2s = scale + g2;
      g2 = r->re / f2s;
      f2s = r->im / f2s;
      sn->re = g2 * gs_re - f2s * -gs_im;
      sn->im = g2 * -gs_im + f2s * gs_re;
      if (rescaledir > 0) {
        for (rescaledir = 1; rescaledir <= count; rescaledir++) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
        }
      } else {
        if (rescaledir < 0) {
          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

/*
 * Arguments    : const creal_T A[4]
 *                creal_T V[4]
 * Return Type  : void
 */
static void eml_matlab_ztgevc(const creal_T A[4], creal_T V[4])
{
  double d_re;
  double anorm;
  double scale;
  double ascale;
  int je;
  double temp;
  double salpha_re;
  double salpha_im;
  double acoeff;
  boolean_T b0;
  boolean_T b1;
  double y;
  creal_T work1[2];
  int jr;
  double dmin;
  double d_im;
  double work1_re;
  double work1_im;
  creal_T work2[2];
  int jc;
  d_re = (fabs(A[2].re) + fabs(A[2].im)) + (fabs(A[3].re) + fabs(A[3].im));
  anorm = fabs(A[0].re) + fabs(A[0].im);
  if (d_re > anorm) {
    anorm = d_re;
  }

  scale = anorm;
  if (2.2250738585072014E-308 > anorm) {
    scale = 2.2250738585072014E-308;
  }

  ascale = 1.0 / scale;
  for (je = 0; je < 2; je++) {
    scale = (fabs(A[(((1 - je) << 1) - je) + 1].re) + fabs(A[(((1 - je) << 1) -
               je) + 1].im)) * ascale;
    if (1.0 > scale) {
      scale = 1.0;
    }

    temp = 1.0 / scale;
    salpha_re = ascale * (temp * A[(((1 - je) << 1) - je) + 1].re);
    salpha_im = ascale * (temp * A[(((1 - je) << 1) - je) + 1].im);
    acoeff = temp * ascale;
    if ((fabs(temp) >= 2.2250738585072014E-308) && (fabs(acoeff) <
         2.0041683600089728E-292)) {
      b0 = true;
    } else {
      b0 = false;
    }

    if ((fabs(salpha_re) + fabs(salpha_im) >= 2.2250738585072014E-308) && (fabs
         (salpha_re) + fabs(salpha_im) < 2.0041683600089728E-292)) {
      b1 = true;
    } else {
      b1 = false;
    }

    scale = 1.0;
    if (b0) {
      scale = anorm;
      if (4.9896007738368E+291 < anorm) {
        scale = 4.9896007738368E+291;
      }

      scale *= 2.0041683600089728E-292 / fabs(temp);
    }

    if (b1) {
      d_re = 2.0041683600089728E-292 / (fabs(salpha_re) + fabs(salpha_im));
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (b0 || b1) {
      d_re = fabs(acoeff);
      y = fabs(salpha_re) + fabs(salpha_im);
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

      if (b0) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      if (b1) {
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
    dmin = 2.2204460492503131E-16 * fabs(acoeff) * anorm;
    d_re = 2.2204460492503131E-16 * (fabs(salpha_re) + fabs(salpha_im));
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
    jr = 0;
    while (jr <= -je) {
      d_re = acoeff * A[0].re - salpha_re;
      d_im = acoeff * A[0].im - salpha_im;
      if (fabs(d_re) + fabs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0;
      }

      if ((fabs(d_re) + fabs(d_im) < 1.0) && (fabs(work1[0].re) + fabs(work1[0].
            im) >= 2.2471164185778949E+307 * (fabs(d_re) + fabs(d_im)))) {
        temp = 1.0 / (fabs(work1[0].re) + fabs(work1[0].im));
        for (jr = 0; jr <= 1 - je; jr++) {
          work1[jr].re *= temp;
          work1[jr].im *= temp;
        }
      }

      work1_re = -work1[0].re;
      work1_im = -work1[0].im;
      if (d_im == 0.0) {
        if (-work1[0].im == 0.0) {
          work1[0].re = -work1[0].re / d_re;
          work1[0].im = 0.0;
        } else if (-work1[0].re == 0.0) {
          work1[0].re = 0.0;
          work1[0].im = work1_im / d_re;
        } else {
          work1[0].re = -work1[0].re / d_re;
          work1[0].im = work1_im / d_re;
        }
      } else if (d_re == 0.0) {
        if (-work1[0].re == 0.0) {
          work1[0].re = -work1[0].im / d_im;
          work1[0].im = 0.0;
        } else if (-work1[0].im == 0.0) {
          work1[0].re = 0.0;
          work1[0].im = -(work1_re / d_im);
        } else {
          work1[0].re = -work1[0].im / d_im;
          work1[0].im = -(work1_re / d_im);
        }
      } else {
        temp = fabs(d_re);
        scale = fabs(d_im);
        if (temp > scale) {
          y = d_im / d_re;
          scale = d_re + y * d_im;
          work1[0].re = (-work1[0].re + y * -work1[0].im) / scale;
          work1[0].im = (work1_im - y * work1_re) / scale;
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

          work1[0].re = (-work1[0].re * y + -work1[0].im * scale) / temp;
          work1[0].im = (work1_im * y - work1_re * scale) / temp;
        } else {
          y = d_re / d_im;
          scale = d_im + y * d_re;
          work1[0].re = (y * -work1[0].re + -work1[0].im) / scale;
          work1[0].im = (y * work1_im - work1_re) / scale;
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

    d_re = fabs(work2[1].re) + fabs(work2[1].im);
    scale = fabs(work2[0].re) + fabs(work2[0].im);
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

/*
 * Arguments    : const double a[4]
 *                creal_T ans1[4]
 *                creal_T ans2[4]
 * Return Type  : void
 */
void eee(const double a[4], creal_T ans1[4], creal_T ans2[4])
{
  creal_T b_a[4];
  int j;
  creal_T beta1[2];
  creal_T alpha1[2];
  int coltop;
  double colnorm;
  double scale;
  double absxk;
  double t;
  for (j = 0; j < 4; j++) {
    b_a[j].re = a[j];
    b_a[j].im = 0.0;
  }

  eml_matlab_zggev(b_a, &j, alpha1, beta1, ans1);
  for (coltop = 0; coltop < 4; coltop += 2) {
    colnorm = 0.0;
    scale = 2.2250738585072014E-308;
    for (j = coltop; j + 1 <= coltop + 2; j++) {
      absxk = fabs(ans1[j].re);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }

      absxk = fabs(ans1[j].im);
      if (absxk > scale) {
        t = scale / absxk;
        colnorm = 1.0 + colnorm * t * t;
        scale = absxk;
      } else {
        t = absxk / scale;
        colnorm += t * t;
      }
    }

    colnorm = scale * sqrt(colnorm);
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
      t = fabs(beta1[j].re);
      scale = fabs(beta1[j].im);
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
}

/*
 * File trailer for eee.c
 *
 * [EOF]
 */
