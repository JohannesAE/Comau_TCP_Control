#include "sg_IK.h"

/* Storage class 'PageSwitching' */
sg_IK_cal_type sg_IK_cal_impl = {
  /* Variable: BList
   * Referenced by: '<S5>/Constant1'
   */
  { 0.0, 0.0, -1.0, 0.0, -2.61918, 0.0, 0.0, 1.0, 0.0, 1.4099999999999997, 0.0,
    -2.26918, 0.0, -1.0, 0.0, -0.25, 0.0, 2.26918, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  /* Variable: M
   * Referenced by: '<S157>/Constant4'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2.61918, 0.0,
    2.2399999999999998, 1.0 },

  /* Variable: SList
   * Referenced by: '<S157>/Constant3'
   */
  { 0.0, 0.0, -1.0, -0.0, 0.0, -0.0, 0.0, 1.0, 0.0, -0.83, -0.0, 0.35, 0.0, -1.0,
    0.0, 1.9899999999999998, -0.0, -0.35, 0.0, 1.0, 0.0, -2.2399999999999998,
    -0.0, 2.61918, 0.0, 0.0, 1.0, -0.0, -2.61918, -0.0 },

  /* Variable: Manual_State_Switch
   * Referenced by: '<S6>/Constant4'
   */
  0.0,

  /* Variable: Operation_Mode
   * Referenced by:
   *   '<S163>/Constant'
   *   '<S169>/Constant1'
   */
  2.0,

  /* Variable: State_Mode_Selector
   * Referenced by: '<S6>/Constant'
   */
  2.0,

  /* Variable: Traj_method
   * Referenced by: '<S163>/Constant9'
   */
  1.0,

  /* Variable: Winch_EnableHeaveComp
   * Referenced by: '<S169>/Constant'
   */
  0.0,

  /* Variable: Winch_NewCmd
   * Referenced by: '<S163>/Constant2'
   */
  0.0,

  /* Variable: Winch_PosRef
   * Referenced by: '<S163>/Constant1'
   */
  10.0,

  /* Variable: controlMode
   * Referenced by: '<S1>/controlMode'
   */
  2.0,

  /* Variable: new_command_traj
   * Referenced by: '<S163>/Constant10'
   */
  0.0,

  /* Variable: v_max
   * Referenced by: '<S163>/Constant3'
   */
  0.0,

  /* Variable: x_coordinate_traj
   * Referenced by: '<S157>/Constant7'
   */
  0.0,

  /* Variable: y_coordinate_traj
   * Referenced by: '<S157>/Constant5'
   */
  0.0,

  /* Variable: z_coordinate_traj
   * Referenced by: '<S157>/Constant6'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S41>/Integral Gain'
   */
  0.0125,

  /* Mask Parameter: DiscretePIDController1_I
   * Referenced by: '<S89>/Integral Gain'
   */
  0.0125,

  /* Mask Parameter: DiscretePIDController2_I
   * Referenced by: '<S137>/Integral Gain'
   */
  0.0125,

  /* Mask Parameter: DiscretePIDController_I_c
   * Referenced by: '<S201>/Integral Gain'
   */
  0.09,

  /* Mask Parameter: DiscretePIDController_I_f
   * Referenced by: '<S252>/Integral Gain'
   */
  0.09,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S44>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController1_InitialC
   * Referenced by: '<S92>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController2_InitialC
   * Referenced by: '<S140>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_b
   * Referenced by: '<S204>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_h
   * Referenced by: '<S255>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_LowerSatu
   * Referenced by: '<S51>/Saturation'
   */
  -0.2,

  /* Mask Parameter: DiscretePIDController1_LowerSat
   * Referenced by: '<S99>/Saturation'
   */
  -0.2,

  /* Mask Parameter: DiscretePIDController2_LowerSat
   * Referenced by: '<S147>/Saturation'
   */
  -0.2,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S49>/Proportional Gain'
   */
  0.25,

  /* Mask Parameter: DiscretePIDController1_P
   * Referenced by: '<S97>/Proportional Gain'
   */
  0.25,

  /* Mask Parameter: DiscretePIDController2_P
   * Referenced by: '<S145>/Proportional Gain'
   */
  0.25,

  /* Mask Parameter: DiscretePIDController_P_h
   * Referenced by: '<S209>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: DiscretePIDController_P_l
   * Referenced by: '<S260>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: DiscretePIDController_UpperSatu
   * Referenced by: '<S51>/Saturation'
   */
  0.2,

  /* Mask Parameter: DiscretePIDController1_UpperSat
   * Referenced by: '<S99>/Saturation'
   */
  0.2,

  /* Mask Parameter: DiscretePIDController2_UpperSat
   * Referenced by: '<S147>/Saturation'
   */
  0.2,

  /* Expression: 2
   * Referenced by: '<S163>/Constant4'
   */
  2.0,

  /* Expression: 0.2
   * Referenced by: '<S169>/Saturation1'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<S169>/Saturation1'
   */
  -0.2,

  /* Expression: -1
   * Referenced by: '<S169>/Gain'
   */
  -1.0,

  /* Expression: 1.57
   * Referenced by: '<S159>/Constant8'
   */
  1.57,

  /* Expression: 0
   * Referenced by: '<S159>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S159>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/enable_65cm_offset_Em8000'
   */
  0.0,

  /* Expression: 0.70+0.30
   * Referenced by: '<S2>/Winch_Correction_And_ClawLenght'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S44>/Integrator'
   */
  0.001,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S92>/Integrator'
   */
  0.001,

  /* Computed Parameter: Integrator_gainval_h
   * Referenced by: '<S140>/Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S1>/Zero_ref'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation2'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation2'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation3'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation3'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation4'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation4'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_hf
   * Referenced by: '<S204>/Integrator'
   */
  0.001,

  /* Expression: 0.2
   * Referenced by: '<S168>/Saturation1'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<S168>/Saturation1'
   */
  -0.2,

  /* Expression: -1
   * Referenced by: '<S168>/Gain'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S255>/Integrator'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation1'
   */
  -1.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S3>/Delay'
   */
  0U,

  /* Computed Parameter: Constant1_Value_o
   * Referenced by: '<S3>/Constant1'
   */
  1U,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S8>/Gain'
   */
  16777,

  /* Computed Parameter: UDPSend_toPort
   * Referenced by: '<S3>/UDP Send'
   */
  50050U,

  /* Computed Parameter: UDPReceive_fmAddress
   * Referenced by: '<S2>/UDP Receive'
   */
  { 192U, 168U, 90U, 50U },

  /* Computed Parameter: UDPReceive_fmAddress_o
   * Referenced by: '<S8>/UDP Receive'
   */
  { 192U, 168U, 80U, 10U },

  /* Computed Parameter: UDPSend_toAddress
   * Referenced by: '<S3>/UDP Send'
   */
  { 192U, 168U, 90U, 50U },

  /* Computed Parameter: Memory2_InitialCondition
   * Referenced by: '<S7>/Memory2'
   */
  false,

  /* Computed Parameter: Memory3_InitialCondition
   * Referenced by: '<S5>/Memory3'
   */
  false
};

sg_IK_cal_type *sg_IK_cal = &sg_IK_cal_impl;
