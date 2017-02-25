/*
 * File: comp_nav_filter.h
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

#ifndef RTW_HEADER_comp_nav_filter_h_
#define RTW_HEADER_comp_nav_filter_h_
#ifndef comp_nav_filter_COMMON_INCLUDES_
# define comp_nav_filter_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* comp_nav_filter_COMMON_INCLUDES_ */

#include "comp_nav_filter_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T DiscreteZeroPole;           /* '<S1>/Discrete Zero-Pole' */
  real32_T P1;                         /* '<Root>/P1' */
  real32_T DiscreteZeroPole_l;         /* '<S2>/Discrete Zero-Pole' */
  real32_T P2;                         /* '<Root>/P2' */
  real32_T DiscreteZeroPole_i;         /* '<S3>/Discrete Zero-Pole' */
  real32_T P3;                         /* '<Root>/P3' */
} B_comp_nav_filter_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<Root>/Discrete-Time Integrator2' */
  real32_T DiscreteZeroPole_DSTATE[13];/* '<S1>/Discrete Zero-Pole' */
  real32_T DiscreteZeroPole_DSTATE_g[13];/* '<S2>/Discrete Zero-Pole' */
  real32_T DiscreteZeroPole_DSTATE_m[13];/* '<S3>/Discrete Zero-Pole' */
} DW_comp_nav_filter_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T roll_accel;                 /* '<Root>/roll_accel' */
  real_T roll_gyro;                    /* '<Root>/roll_gyro' */
  real32_T pitch_accel;                /* '<Root>/pitch_accel' */
  real_T pitch_gyro;                   /* '<Root>/pitch_gyro' */
  real32_T yaw_accel;                  /* '<Root>/yaw_accel' */
  real_T yaw_gyro;                     /* '<Root>/yaw_gyro' */
} ExtU_comp_nav_filter_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T roll_est;                     /* '<Root>/roll_est' */
  real_T pitch_est;                    /* '<Root>/pitch_est' */
  real_T yaw_est;                      /* '<Root>/yaw_est' */
} ExtY_comp_nav_filter_T;

/* Parameters (auto storage) */
struct P_comp_nav_filter_T_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<Root>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Bound_UpperSat;               /* Expression: 9600
                                        * Referenced by: '<Root>/Bound'
                                        */
  real_T Bound_LowerSat;               /* Expression: -9600
                                        * Referenced by: '<Root>/Bound'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<Root>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T Bound1_UpperSat;              /* Expression: 9600
                                        * Referenced by: '<Root>/Bound1'
                                        */
  real_T Bound1_LowerSat;              /* Expression: -9600
                                        * Referenced by: '<Root>/Bound1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<Root>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator2'
                                        */
  real_T Bound2_UpperSat;              /* Expression: 9600
                                        * Referenced by: '<Root>/Bound2'
                                        */
  real_T Bound2_LowerSat;              /* Expression: -9600
                                        * Referenced by: '<Root>/Bound2'
                                        */
  real32_T DiscreteZeroPole_A[55];     /* Computed Parameter: DiscreteZeroPole_A
                                        * Referenced by: '<S1>/Discrete Zero-Pole'
                                        */
  real32_T DiscreteZeroPole_B;         /* Computed Parameter: DiscreteZeroPole_B
                                        * Referenced by: '<S1>/Discrete Zero-Pole'
                                        */
  real32_T DiscreteZeroPole_C[13];     /* Computed Parameter: DiscreteZeroPole_C
                                        * Referenced by: '<S1>/Discrete Zero-Pole'
                                        */
  real32_T P1_Gain;                    /* Computed Parameter: P1_Gain
                                        * Referenced by: '<Root>/P1'
                                        */
  real32_T DiscreteZeroPole_A_g[55];   /* Computed Parameter: DiscreteZeroPole_A_g
                                        * Referenced by: '<S2>/Discrete Zero-Pole'
                                        */
  real32_T DiscreteZeroPole_B_f;       /* Computed Parameter: DiscreteZeroPole_B_f
                                        * Referenced by: '<S2>/Discrete Zero-Pole'
                                        */
  real32_T DiscreteZeroPole_C_p[13];   /* Computed Parameter: DiscreteZeroPole_C_p
                                        * Referenced by: '<S2>/Discrete Zero-Pole'
                                        */
  real32_T P2_Gain;                    /* Computed Parameter: P2_Gain
                                        * Referenced by: '<Root>/P2'
                                        */
  real32_T DiscreteZeroPole_A_a[55];   /* Computed Parameter: DiscreteZeroPole_A_a
                                        * Referenced by: '<S3>/Discrete Zero-Pole'
                                        */
  real32_T DiscreteZeroPole_B_m;       /* Computed Parameter: DiscreteZeroPole_B_m
                                        * Referenced by: '<S3>/Discrete Zero-Pole'
                                        */
  real32_T DiscreteZeroPole_C_j[13];   /* Computed Parameter: DiscreteZeroPole_C_j
                                        * Referenced by: '<S3>/Discrete Zero-Pole'
                                        */
  real32_T P3_Gain;                    /* Computed Parameter: P3_Gain
                                        * Referenced by: '<Root>/P3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_comp_nav_filter_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_comp_nav_filter_T comp_nav_filter_P;

/* Block signals (auto storage) */
extern B_comp_nav_filter_T comp_nav_filter_B;

/* Block states (auto storage) */
extern DW_comp_nav_filter_T comp_nav_filter_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_comp_nav_filter_T comp_nav_filter_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_comp_nav_filter_T comp_nav_filter_Y;

/* Model entry point functions */
extern void comp_nav_filter_initialize(void);
extern void comp_nav_filter_step(void);
extern void comp_nav_filter_terminate(void);

/* Real-time Model object */
extern RT_MODEL_comp_nav_filter_T *const comp_nav_filter_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'comp_nav_filter'
 * '<S1>'   : 'comp_nav_filter/Discrete fractional Transfer Fcn'
 * '<S2>'   : 'comp_nav_filter/Discrete fractional Transfer Fcn1'
 * '<S3>'   : 'comp_nav_filter/Discrete fractional Transfer Fcn2'
 */
#endif                                 /* RTW_HEADER_comp_nav_filter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
