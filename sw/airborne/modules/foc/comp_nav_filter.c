/*
 * File: comp_nav_filter.c
 *
 * Code generated for Simulink model 'comp_nav_filter'.
 *
 * Model version                  : 1.48
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Fri Feb 24 19:39:57 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "comp_nav_filter.h"
#include "comp_nav_filter_private.h"

/* Block signals (auto storage) */
B_comp_nav_filter_T comp_nav_filter_B;

/* Block states (auto storage) */
DW_comp_nav_filter_T comp_nav_filter_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_comp_nav_filter_T comp_nav_filter_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_comp_nav_filter_T comp_nav_filter_Y;

/* Real-time model */
RT_MODEL_comp_nav_filter_T comp_nav_filter_M_;
RT_MODEL_comp_nav_filter_T *const comp_nav_filter_M = &comp_nav_filter_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (comp_nav_filter_M->Timing.TaskCounters.TID[1])++;
  if ((comp_nav_filter_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.5s, 0.0s] */
    comp_nav_filter_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void comp_nav_filter_step(void)
{
  real_T rtb_DiscreteTimeIntegrator2;
  real_T rtb_Sum6;
  real_T rtb_Sum2;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator2 = comp_nav_filter_DW.DiscreteTimeIntegrator_DSTATE;

  /* Saturate: '<Root>/Bound' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  if (comp_nav_filter_DW.DiscreteTimeIntegrator_DSTATE >=
      comp_nav_filter_P.Bound_UpperSat) {
    /* Outport: '<Root>/roll_est' */
    comp_nav_filter_Y.roll_est = comp_nav_filter_P.Bound_UpperSat;
  } else if (comp_nav_filter_DW.DiscreteTimeIntegrator_DSTATE <=
             comp_nav_filter_P.Bound_LowerSat) {
    /* Outport: '<Root>/roll_est' */
    comp_nav_filter_Y.roll_est = comp_nav_filter_P.Bound_LowerSat;
  } else {
    /* Outport: '<Root>/roll_est' */
    comp_nav_filter_Y.roll_est =
      comp_nav_filter_DW.DiscreteTimeIntegrator_DSTATE;
  }

  /* End of Saturate: '<Root>/Bound' */
  if (comp_nav_filter_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteZeroPole: '<S1>/Discrete Zero-Pole' */
    {
      {
        static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pCidx = &colCidxRow0[0];
        const real32_T *pC0 = comp_nav_filter_P.DiscreteZeroPole_C;
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0];
        real32_T *y0 = &comp_nav_filter_B.DiscreteZeroPole;
        int_T numNonZero = 12;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }
    }
  }

  /* Gain: '<Root>/P1' incorporates:
   *  Inport: '<Root>/roll_accel'
   *  Sum: '<Root>/Sum5'
   */
  comp_nav_filter_B.P1 = (comp_nav_filter_U.roll_accel - (real32_T)
    rtb_DiscreteTimeIntegrator2) * comp_nav_filter_P.P1_Gain;

  /* Sum: '<Root>/Sum6' incorporates:
   *  Inport: '<Root>/roll_gyro'
   */
  rtb_Sum6 = comp_nav_filter_U.roll_gyro + comp_nav_filter_B.DiscreteZeroPole;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator2 =
    comp_nav_filter_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Saturate: '<Root>/Bound1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   */
  if (comp_nav_filter_DW.DiscreteTimeIntegrator1_DSTATE >=
      comp_nav_filter_P.Bound1_UpperSat) {
    /* Outport: '<Root>/pitch_est' */
    comp_nav_filter_Y.pitch_est = comp_nav_filter_P.Bound1_UpperSat;
  } else if (comp_nav_filter_DW.DiscreteTimeIntegrator1_DSTATE <=
             comp_nav_filter_P.Bound1_LowerSat) {
    /* Outport: '<Root>/pitch_est' */
    comp_nav_filter_Y.pitch_est = comp_nav_filter_P.Bound1_LowerSat;
  } else {
    /* Outport: '<Root>/pitch_est' */
    comp_nav_filter_Y.pitch_est =
      comp_nav_filter_DW.DiscreteTimeIntegrator1_DSTATE;
  }

  /* End of Saturate: '<Root>/Bound1' */
  if (comp_nav_filter_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteZeroPole: '<S2>/Discrete Zero-Pole' */
    {
      {
        static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pCidx = &colCidxRow0[0];
        const real32_T *pC0 = comp_nav_filter_P.DiscreteZeroPole_C_p;
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0];
        real32_T *y0 = &comp_nav_filter_B.DiscreteZeroPole_l;
        int_T numNonZero = 12;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }
    }
  }

  /* Gain: '<Root>/P2' incorporates:
   *  Inport: '<Root>/pitch_accel'
   *  Sum: '<Root>/Sum1'
   */
  comp_nav_filter_B.P2 = (comp_nav_filter_U.pitch_accel - (real32_T)
    rtb_DiscreteTimeIntegrator2) * comp_nav_filter_P.P2_Gain;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Inport: '<Root>/pitch_gyro'
   */
  rtb_Sum2 = comp_nav_filter_U.pitch_gyro + comp_nav_filter_B.DiscreteZeroPole_l;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  rtb_DiscreteTimeIntegrator2 =
    comp_nav_filter_DW.DiscreteTimeIntegrator2_DSTATE;

  /* Saturate: '<Root>/Bound2' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
   */
  if (comp_nav_filter_DW.DiscreteTimeIntegrator2_DSTATE >=
      comp_nav_filter_P.Bound2_UpperSat) {
    /* Outport: '<Root>/yaw_est' */
    comp_nav_filter_Y.yaw_est = comp_nav_filter_P.Bound2_UpperSat;
  } else if (comp_nav_filter_DW.DiscreteTimeIntegrator2_DSTATE <=
             comp_nav_filter_P.Bound2_LowerSat) {
    /* Outport: '<Root>/yaw_est' */
    comp_nav_filter_Y.yaw_est = comp_nav_filter_P.Bound2_LowerSat;
  } else {
    /* Outport: '<Root>/yaw_est' */
    comp_nav_filter_Y.yaw_est =
      comp_nav_filter_DW.DiscreteTimeIntegrator2_DSTATE;
  }

  /* End of Saturate: '<Root>/Bound2' */
  if (comp_nav_filter_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteZeroPole: '<S3>/Discrete Zero-Pole' */
    {
      {
        static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pCidx = &colCidxRow0[0];
        const real32_T *pC0 = comp_nav_filter_P.DiscreteZeroPole_C_j;
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0];
        real32_T *y0 = &comp_nav_filter_B.DiscreteZeroPole_i;
        int_T numNonZero = 12;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }
    }
  }

  /* Gain: '<Root>/P3' incorporates:
   *  Inport: '<Root>/yaw_accel'
   *  Sum: '<Root>/Sum3'
   */
  comp_nav_filter_B.P3 = (comp_nav_filter_U.yaw_accel - (real32_T)
    rtb_DiscreteTimeIntegrator2) * comp_nav_filter_P.P3_Gain;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Inport: '<Root>/yaw_gyro'
   */
  rtb_DiscreteTimeIntegrator2 = comp_nav_filter_U.yaw_gyro +
    comp_nav_filter_B.DiscreteZeroPole_i;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  comp_nav_filter_DW.DiscreteTimeIntegrator_DSTATE +=
    comp_nav_filter_P.DiscreteTimeIntegrator_gainval * rtb_Sum6;
  if (comp_nav_filter_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteZeroPole: '<S1>/Discrete Zero-Pole' */
    {
      real32_T xnew[13];
      xnew[0] = (comp_nav_filter_P.DiscreteZeroPole_A[0])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0];
      xnew[0] += comp_nav_filter_P.DiscreteZeroPole_B*comp_nav_filter_B.P1;
      xnew[1] = (comp_nav_filter_P.DiscreteZeroPole_A[1])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0]
        + (comp_nav_filter_P.DiscreteZeroPole_A[2])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[1]
        + (comp_nav_filter_P.DiscreteZeroPole_A[3])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[2];
      xnew[2] = (comp_nav_filter_P.DiscreteZeroPole_A[4])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[1];
      xnew[3] = (comp_nav_filter_P.DiscreteZeroPole_A[5])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0]
        + (comp_nav_filter_P.DiscreteZeroPole_A[6])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[1]
        + (comp_nav_filter_P.DiscreteZeroPole_A[7])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[2]
        + (comp_nav_filter_P.DiscreteZeroPole_A[8])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[3];
      xnew[4] = 0.0;

      {
        static const int_T colAidxRow5[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow5[0];
        const real32_T *pA9 = &comp_nav_filter_P.DiscreteZeroPole_A[9];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0];
        real32_T *pxnew5 = &xnew[5];
        int_T numNonZero = 6;
        *pxnew5 = (*pA9++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA9++) * xd[*pAidx++];
        }
      }

      xnew[6] = (comp_nav_filter_P.DiscreteZeroPole_A[16])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[5];

      {
        static const int_T colAidxRow7[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

        const int_T *pAidx = &colAidxRow7[0];
        const real32_T *pA17 = &comp_nav_filter_P.DiscreteZeroPole_A[17];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0];
        real32_T *pxnew7 = &xnew[7];
        int_T numNonZero = 8;
        *pxnew7 = (*pA17++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA17++) * xd[*pAidx++];
        }
      }

      xnew[8] = (comp_nav_filter_P.DiscreteZeroPole_A[26])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[7];

      {
        static const int_T colAidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow9[0];
        const real32_T *pA27 = &comp_nav_filter_P.DiscreteZeroPole_A[27];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0];
        real32_T *pxnew9 = &xnew[9];
        int_T numNonZero = 10;
        *pxnew9 = (*pA27++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA27++) * xd[*pAidx++];
        }
      }

      xnew[10] = (comp_nav_filter_P.DiscreteZeroPole_A[38])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[9];

      {
        static const int_T colAidxRow11[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pAidx = &colAidxRow11[0];
        const real32_T *pA39 = &comp_nav_filter_P.DiscreteZeroPole_A[39];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0];
        real32_T *pxnew11 = &xnew[11];
        int_T numNonZero = 12;
        *pxnew11 = (*pA39++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA39++) * xd[*pAidx++];
        }
      }

      xnew[12] = (comp_nav_filter_P.DiscreteZeroPole_A[52])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE[11];
      (void) memcpy(&comp_nav_filter_DW.DiscreteZeroPole_DSTATE[0], xnew,
                    sizeof(real32_T)*13);
    }
  }

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  comp_nav_filter_DW.DiscreteTimeIntegrator1_DSTATE +=
    comp_nav_filter_P.DiscreteTimeIntegrator1_gainval * rtb_Sum2;
  if (comp_nav_filter_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteZeroPole: '<S2>/Discrete Zero-Pole' */
    {
      real32_T xnew[13];
      xnew[0] = (comp_nav_filter_P.DiscreteZeroPole_A_g[0])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0];
      xnew[0] += comp_nav_filter_P.DiscreteZeroPole_B_f*comp_nav_filter_B.P2;
      xnew[1] = (comp_nav_filter_P.DiscreteZeroPole_A_g[1])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0]
        + (comp_nav_filter_P.DiscreteZeroPole_A_g[2])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[1]
        + (comp_nav_filter_P.DiscreteZeroPole_A_g[3])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[2];
      xnew[2] = (comp_nav_filter_P.DiscreteZeroPole_A_g[4])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[1];
      xnew[3] = (comp_nav_filter_P.DiscreteZeroPole_A_g[5])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0]
        + (comp_nav_filter_P.DiscreteZeroPole_A_g[6])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[1]
        + (comp_nav_filter_P.DiscreteZeroPole_A_g[7])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[2]
        + (comp_nav_filter_P.DiscreteZeroPole_A_g[8])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[3];
      xnew[4] = 0.0;

      {
        static const int_T colAidxRow5[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow5[0];
        const real32_T *pA9 = &comp_nav_filter_P.DiscreteZeroPole_A_g[9];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0];
        real32_T *pxnew5 = &xnew[5];
        int_T numNonZero = 6;
        *pxnew5 = (*pA9++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA9++) * xd[*pAidx++];
        }
      }

      xnew[6] = (comp_nav_filter_P.DiscreteZeroPole_A_g[16])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[5];

      {
        static const int_T colAidxRow7[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

        const int_T *pAidx = &colAidxRow7[0];
        const real32_T *pA17 = &comp_nav_filter_P.DiscreteZeroPole_A_g[17];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0];
        real32_T *pxnew7 = &xnew[7];
        int_T numNonZero = 8;
        *pxnew7 = (*pA17++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA17++) * xd[*pAidx++];
        }
      }

      xnew[8] = (comp_nav_filter_P.DiscreteZeroPole_A_g[26])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[7];

      {
        static const int_T colAidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow9[0];
        const real32_T *pA27 = &comp_nav_filter_P.DiscreteZeroPole_A_g[27];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0];
        real32_T *pxnew9 = &xnew[9];
        int_T numNonZero = 10;
        *pxnew9 = (*pA27++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA27++) * xd[*pAidx++];
        }
      }

      xnew[10] = (comp_nav_filter_P.DiscreteZeroPole_A_g[38])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[9];

      {
        static const int_T colAidxRow11[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pAidx = &colAidxRow11[0];
        const real32_T *pA39 = &comp_nav_filter_P.DiscreteZeroPole_A_g[39];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0];
        real32_T *pxnew11 = &xnew[11];
        int_T numNonZero = 12;
        *pxnew11 = (*pA39++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA39++) * xd[*pAidx++];
        }
      }

      xnew[12] = (comp_nav_filter_P.DiscreteZeroPole_A_g[52])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[11];
      (void) memcpy(&comp_nav_filter_DW.DiscreteZeroPole_DSTATE_g[0], xnew,
                    sizeof(real32_T)*13);
    }
  }

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  comp_nav_filter_DW.DiscreteTimeIntegrator2_DSTATE +=
    comp_nav_filter_P.DiscreteTimeIntegrator2_gainval *
    rtb_DiscreteTimeIntegrator2;
  if (comp_nav_filter_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for DiscreteZeroPole: '<S3>/Discrete Zero-Pole' */
    {
      real32_T xnew[13];
      xnew[0] = (comp_nav_filter_P.DiscreteZeroPole_A_a[0])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0];
      xnew[0] += comp_nav_filter_P.DiscreteZeroPole_B_m*comp_nav_filter_B.P3;
      xnew[1] = (comp_nav_filter_P.DiscreteZeroPole_A_a[1])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0]
        + (comp_nav_filter_P.DiscreteZeroPole_A_a[2])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[1]
        + (comp_nav_filter_P.DiscreteZeroPole_A_a[3])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[2];
      xnew[2] = (comp_nav_filter_P.DiscreteZeroPole_A_a[4])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[1];
      xnew[3] = (comp_nav_filter_P.DiscreteZeroPole_A_a[5])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0]
        + (comp_nav_filter_P.DiscreteZeroPole_A_a[6])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[1]
        + (comp_nav_filter_P.DiscreteZeroPole_A_a[7])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[2]
        + (comp_nav_filter_P.DiscreteZeroPole_A_a[8])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[3];
      xnew[4] = 0.0;

      {
        static const int_T colAidxRow5[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow5[0];
        const real32_T *pA9 = &comp_nav_filter_P.DiscreteZeroPole_A_a[9];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0];
        real32_T *pxnew5 = &xnew[5];
        int_T numNonZero = 6;
        *pxnew5 = (*pA9++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA9++) * xd[*pAidx++];
        }
      }

      xnew[6] = (comp_nav_filter_P.DiscreteZeroPole_A_a[16])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[5];

      {
        static const int_T colAidxRow7[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

        const int_T *pAidx = &colAidxRow7[0];
        const real32_T *pA17 = &comp_nav_filter_P.DiscreteZeroPole_A_a[17];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0];
        real32_T *pxnew7 = &xnew[7];
        int_T numNonZero = 8;
        *pxnew7 = (*pA17++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA17++) * xd[*pAidx++];
        }
      }

      xnew[8] = (comp_nav_filter_P.DiscreteZeroPole_A_a[26])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[7];

      {
        static const int_T colAidxRow9[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pAidx = &colAidxRow9[0];
        const real32_T *pA27 = &comp_nav_filter_P.DiscreteZeroPole_A_a[27];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0];
        real32_T *pxnew9 = &xnew[9];
        int_T numNonZero = 10;
        *pxnew9 = (*pA27++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA27++) * xd[*pAidx++];
        }
      }

      xnew[10] = (comp_nav_filter_P.DiscreteZeroPole_A_a[38])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[9];

      {
        static const int_T colAidxRow11[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pAidx = &colAidxRow11[0];
        const real32_T *pA39 = &comp_nav_filter_P.DiscreteZeroPole_A_a[39];
        const real32_T *xd = &comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0];
        real32_T *pxnew11 = &xnew[11];
        int_T numNonZero = 12;
        *pxnew11 = (*pA39++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA39++) * xd[*pAidx++];
        }
      }

      xnew[12] = (comp_nav_filter_P.DiscreteZeroPole_A_a[52])*
        comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[11];
      (void) memcpy(&comp_nav_filter_DW.DiscreteZeroPole_DSTATE_m[0], xnew,
                    sizeof(real32_T)*13);
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void comp_nav_filter_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)comp_nav_filter_M, 0,
                sizeof(RT_MODEL_comp_nav_filter_T));

  /* block I/O */
  (void) memset(((void *) &comp_nav_filter_B), 0,
                sizeof(B_comp_nav_filter_T));

  /* states (dwork) */
  (void) memset((void *)&comp_nav_filter_DW, 0,
                sizeof(DW_comp_nav_filter_T));

  /* external inputs */
  (void) memset((void *)&comp_nav_filter_U, 0,
                sizeof(ExtU_comp_nav_filter_T));

  /* external outputs */
  (void) memset((void *)&comp_nav_filter_Y, 0,
                sizeof(ExtY_comp_nav_filter_T));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  comp_nav_filter_DW.DiscreteTimeIntegrator_DSTATE =
    comp_nav_filter_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  comp_nav_filter_DW.DiscreteTimeIntegrator1_DSTATE =
    comp_nav_filter_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  comp_nav_filter_DW.DiscreteTimeIntegrator2_DSTATE =
    comp_nav_filter_P.DiscreteTimeIntegrator2_IC;
}

/* Model terminate function */
void comp_nav_filter_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
