/*
 * File: comp_nav_filter_data.c
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

/* Block parameters (auto storage) */
P_comp_nav_filter_T comp_nav_filter_P = {
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  9600.0,                              /* Expression: 9600
                                        * Referenced by: '<Root>/Bound'
                                        */
  -9600.0,                             /* Expression: -9600
                                        * Referenced by: '<Root>/Bound'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  9600.0,                              /* Expression: 9600
                                        * Referenced by: '<Root>/Bound1'
                                        */
  -9600.0,                             /* Expression: -9600
                                        * Referenced by: '<Root>/Bound1'
                                        */
  0.005,                               /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                        * Referenced by: '<Root>/Discrete-Time Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator2'
                                        */
  9600.0,                              /* Expression: 9600
                                        * Referenced by: '<Root>/Bound2'
                                        */
  -9600.0,                             /* Expression: -9600
                                        * Referenced by: '<Root>/Bound2'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_A
   * Referenced by: '<S1>/Discrete Zero-Pole'
   */
  { 0.998718321F, 1.0F, 2.07485151F, -1.16691875F, 1.16691875F, 1.0F,
    3.07485151F, -1.16691875F, 7.74966649E-25F, 1.0F, 3.07485151F, -1.16691875F,
    -1.35791619E-13F, 0.000217689652F, 0.0109933149F, -3.86297543E-5F,
    3.86297543E-5F, 1.0F, 3.07485151F, -1.16691875F, -1.35791619E-13F,
    0.000217689652F, -0.0796521381F, 0.506697416F, 0.871603966F, -0.400967687F,
    0.400967687F, 1.0F, 3.07485151F, -1.16691875F, -1.35791619E-13F,
    0.000217689652F, -0.0796521381F, 0.506697416F, -0.455662131F, 0.634141564F,
    1.77445722F, -0.88527447F, 0.88527447F, 1.0F, 3.07485151F, -1.16691875F,
    -1.35791619E-13F, 0.000217689652F, -0.0796521381F, 0.506697416F,
    -0.455662131F, 0.634141564F, -0.155851901F, 0.166553259F, 1.97982109F,
    -0.989894688F, 0.989894688F, 0.0F, 2.80024219E-31F },
  1.0F,                                /* Computed Parameter: DiscreteZeroPole_B
                                        * Referenced by: '<S1>/Discrete Zero-Pole'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_C
   * Referenced by: '<S1>/Discrete Zero-Pole'
   */
  { 0.0880442634F, 0.270723045F, -0.102740511F, -1.19556735E-14F, 1.91663257E-5F,
    -0.00701291393F, 0.0446118F, -0.0401184373F, 0.0558325276F, -0.0137218656F,
    0.0146640586F, -0.00126821199F, 0.00127540214F },
  1.0F,                                /* Computed Parameter: P1_Gain
                                        * Referenced by: '<Root>/P1'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_A_g
   * Referenced by: '<S2>/Discrete Zero-Pole'
   */
  { 0.998718321F, 1.0F, 2.07485151F, -1.16691875F, 1.16691875F, 1.0F,
    3.07485151F, -1.16691875F, 7.74966649E-25F, 1.0F, 3.07485151F, -1.16691875F,
    -1.35791619E-13F, 0.000217689652F, 0.0109933149F, -3.86297543E-5F,
    3.86297543E-5F, 1.0F, 3.07485151F, -1.16691875F, -1.35791619E-13F,
    0.000217689652F, -0.0796521381F, 0.506697416F, 0.871603966F, -0.400967687F,
    0.400967687F, 1.0F, 3.07485151F, -1.16691875F, -1.35791619E-13F,
    0.000217689652F, -0.0796521381F, 0.506697416F, -0.455662131F, 0.634141564F,
    1.77445722F, -0.88527447F, 0.88527447F, 1.0F, 3.07485151F, -1.16691875F,
    -1.35791619E-13F, 0.000217689652F, -0.0796521381F, 0.506697416F,
    -0.455662131F, 0.634141564F, -0.155851901F, 0.166553259F, 1.97982109F,
    -0.989894688F, 0.989894688F, -0.0476345122F, 0.0F },
  1.0F,                                /* Computed Parameter: DiscreteZeroPole_B_f
                                        * Referenced by: '<S2>/Discrete Zero-Pole'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_C_p
   * Referenced by: '<S2>/Discrete Zero-Pole'
   */
  { 0.0880442634F, 0.270723045F, -0.102740511F, -1.19556735E-14F, 1.91663257E-5F,
    -0.00701291393F, 0.0446118F, -0.0401184373F, 0.0558325276F, -0.0137218656F,
    0.0146640586F, -0.00126821199F, 0.00127540214F },
  1.0F,                                /* Computed Parameter: P2_Gain
                                        * Referenced by: '<Root>/P2'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_A_a
   * Referenced by: '<S3>/Discrete Zero-Pole'
   */
  { 0.998718321F, 1.0F, 2.07485151F, -1.16691875F, 1.16691875F, 1.0F,
    3.07485151F, -1.16691875F, 7.74966649E-25F, 1.0F, 3.07485151F, -1.16691875F,
    -1.35791619E-13F, 0.000217689652F, 0.0109933149F, -3.86297543E-5F,
    3.86297543E-5F, 1.0F, 3.07485151F, -1.16691875F, -1.35791619E-13F,
    0.000217689652F, -0.0796521381F, 0.506697416F, 0.871603966F, -0.400967687F,
    0.400967687F, 1.0F, 3.07485151F, -1.16691875F, -1.35791619E-13F,
    0.000217689652F, -0.0796521381F, 0.506697416F, -0.455662131F, 0.634141564F,
    1.77445722F, -0.88527447F, 0.88527447F, 1.0F, 3.07485151F, -1.16691875F,
    -1.35791619E-13F, 0.000217689652F, -0.0796521381F, 0.506697416F,
    -0.455662131F, 0.634141564F, -0.155851901F, 0.166553259F, 1.97982109F,
    -0.989894688F, 0.989894688F, 0.0F, 0.0F },
  1.0F,                                /* Computed Parameter: DiscreteZeroPole_B_m
                                        * Referenced by: '<S3>/Discrete Zero-Pole'
                                        */

  /*  Computed Parameter: DiscreteZeroPole_C_j
   * Referenced by: '<S3>/Discrete Zero-Pole'
   */
  { 0.0880442634F, 0.270723045F, -0.102740511F, -1.19556735E-14F, 1.91663257E-5F,
    -0.00701291393F, 0.0446118F, -0.0401184373F, 0.0558325276F, -0.0137218656F,
    0.0146640586F, -0.00126821199F, 0.00127540214F },
  1.0F                                 /* Computed Parameter: P3_Gain
                                        * Referenced by: '<Root>/P3'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
