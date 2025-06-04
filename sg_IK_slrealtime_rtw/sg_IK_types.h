/*
 * sg_IK_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sg_IK".
 *
 * Model version              : 1.1029
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C++ source code generated on : Tue Jun  3 11:24:39 2025
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sg_IK_types_h_
#define RTW_HEADER_sg_IK_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_b_dsp_FIRFilter_0_sg_IK_T
#define struct_b_dsp_FIRFilter_0_sg_IK_T

struct b_dsp_FIRFilter_0_sg_IK_T
{
  int32_T S0_isInitialized;
  real_T W0_states[762];
  real_T P0_InitialStates;
  real_T P1_Coefficients[763];
};

#endif                                 /* struct_b_dsp_FIRFilter_0_sg_IK_T */

#ifndef struct_b_dspcodegen_FIRFilter_sg_IK_T
#define struct_b_dspcodegen_FIRFilter_sg_IK_T

struct b_dspcodegen_FIRFilter_sg_IK_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_sg_IK_T cSFunObject;
};

#endif                               /* struct_b_dspcodegen_FIRFilter_sg_IK_T */

#ifndef struct_dsp_LowpassFilter_sg_IK_T
#define struct_dsp_LowpassFilter_sg_IK_T

struct dsp_LowpassFilter_sg_IK_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_sg_IK_T *FilterObj;
  b_dspcodegen_FIRFilter_sg_IK_T _pobj0;
};

#endif                                 /* struct_dsp_LowpassFilter_sg_IK_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_sg_IK_T RT_MODEL_sg_IK_T;

#endif                                 /* RTW_HEADER_sg_IK_types_h_ */
