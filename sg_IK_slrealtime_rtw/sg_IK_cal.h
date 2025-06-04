#ifndef RTW_HEADER_sg_IK_cal_h_
#define RTW_HEADER_sg_IK_cal_h_
#include "rtwtypes.h"
#include "sg_IK_types.h"

/* Storage class 'PageSwitching', for system '<Root>' */
struct sg_IK_cal_type {
  real_T BList[30];                    /* Variable: BList
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T M[16];                        /* Variable: M
                                        * Referenced by: '<S157>/Constant4'
                                        */
  real_T SList[30];                    /* Variable: SList
                                        * Referenced by: '<S157>/Constant3'
                                        */
  real_T Manual_State_Switch;          /* Variable: Manual_State_Switch
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T Operation_Mode;               /* Variable: Operation_Mode
                                        * Referenced by:
                                        *   '<S163>/Constant'
                                        *   '<S169>/Constant1'
                                        */
  real_T State_Mode_Selector;          /* Variable: State_Mode_Selector
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Traj_method;                  /* Variable: Traj_method
                                        * Referenced by: '<S163>/Constant9'
                                        */
  real_T Winch_EnableHeaveComp;        /* Variable: Winch_EnableHeaveComp
                                        * Referenced by: '<S169>/Constant'
                                        */
  real_T Winch_NewCmd;                 /* Variable: Winch_NewCmd
                                        * Referenced by: '<S163>/Constant2'
                                        */
  real_T Winch_PosRef;                 /* Variable: Winch_PosRef
                                        * Referenced by: '<S163>/Constant1'
                                        */
  real_T controlMode;                  /* Variable: controlMode
                                        * Referenced by: '<S1>/controlMode'
                                        */
  real_T new_command_traj;             /* Variable: new_command_traj
                                        * Referenced by: '<S163>/Constant10'
                                        */
  real_T v_max;                        /* Variable: v_max
                                        * Referenced by: '<S163>/Constant3'
                                        */
  real_T x_coordinate_traj;            /* Variable: x_coordinate_traj
                                        * Referenced by: '<S157>/Constant7'
                                        */
  real_T y_coordinate_traj;            /* Variable: y_coordinate_traj
                                        * Referenced by: '<S157>/Constant5'
                                        */
  real_T z_coordinate_traj;            /* Variable: z_coordinate_traj
                                        * Referenced by: '<S157>/Constant6'
                                        */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S41>/Integral Gain'
                                       */
  real_T DiscretePIDController1_I;   /* Mask Parameter: DiscretePIDController1_I
                                      * Referenced by: '<S89>/Integral Gain'
                                      */
  real_T DiscretePIDController2_I;   /* Mask Parameter: DiscretePIDController2_I
                                      * Referenced by: '<S137>/Integral Gain'
                                      */
  real_T DiscretePIDController_I_c; /* Mask Parameter: DiscretePIDController_I_c
                                     * Referenced by: '<S201>/Integral Gain'
                                     */
  real_T DiscretePIDController_I_f; /* Mask Parameter: DiscretePIDController_I_f
                                     * Referenced by: '<S252>/Integral Gain'
                                     */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S44>/Integrator'
                               */
  real_T DiscretePIDController1_InitialC;
                              /* Mask Parameter: DiscretePIDController1_InitialC
                               * Referenced by: '<S92>/Integrator'
                               */
  real_T DiscretePIDController2_InitialC;
                              /* Mask Parameter: DiscretePIDController2_InitialC
                               * Referenced by: '<S140>/Integrator'
                               */
  real_T DiscretePIDController_Initial_b;
                              /* Mask Parameter: DiscretePIDController_Initial_b
                               * Referenced by: '<S204>/Integrator'
                               */
  real_T DiscretePIDController_Initial_h;
                              /* Mask Parameter: DiscretePIDController_Initial_h
                               * Referenced by: '<S255>/Integrator'
                               */
  real_T DiscretePIDController_LowerSatu;
                              /* Mask Parameter: DiscretePIDController_LowerSatu
                               * Referenced by: '<S51>/Saturation'
                               */
  real_T DiscretePIDController1_LowerSat;
                              /* Mask Parameter: DiscretePIDController1_LowerSat
                               * Referenced by: '<S99>/Saturation'
                               */
  real_T DiscretePIDController2_LowerSat;
                              /* Mask Parameter: DiscretePIDController2_LowerSat
                               * Referenced by: '<S147>/Saturation'
                               */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S49>/Proportional Gain'
                                       */
  real_T DiscretePIDController1_P;   /* Mask Parameter: DiscretePIDController1_P
                                      * Referenced by: '<S97>/Proportional Gain'
                                      */
  real_T DiscretePIDController2_P;   /* Mask Parameter: DiscretePIDController2_P
                                      * Referenced by: '<S145>/Proportional Gain'
                                      */
  real_T DiscretePIDController_P_h; /* Mask Parameter: DiscretePIDController_P_h
                                     * Referenced by: '<S209>/Proportional Gain'
                                     */
  real_T DiscretePIDController_P_l; /* Mask Parameter: DiscretePIDController_P_l
                                     * Referenced by: '<S260>/Proportional Gain'
                                     */
  real_T DiscretePIDController_UpperSatu;
                              /* Mask Parameter: DiscretePIDController_UpperSatu
                               * Referenced by: '<S51>/Saturation'
                               */
  real_T DiscretePIDController1_UpperSat;
                              /* Mask Parameter: DiscretePIDController1_UpperSat
                               * Referenced by: '<S99>/Saturation'
                               */
  real_T DiscretePIDController2_UpperSat;
                              /* Mask Parameter: DiscretePIDController2_UpperSat
                               * Referenced by: '<S147>/Saturation'
                               */
  real_T Constant4_Value;              /* Expression: 2
                                        * Referenced by: '<S163>/Constant4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 0.2
                                        * Referenced by: '<S169>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.2
                                        * Referenced by: '<S169>/Saturation1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S169>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 1.57
                                        * Referenced by: '<S159>/Constant8'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S159>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S159>/Constant1'
                                        */
  real_T enable_65cm_offset_Em8000_Value;/* Expression: 0
                                          * Referenced by: '<S6>/enable_65cm_offset_Em8000'
                                          */
  real_T Winch_Correction_And_ClawLenght;/* Expression: 0.70+0.30
                                          * Referenced by: '<S2>/Winch_Correction_And_ClawLenght'
                                          */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S44>/Integrator'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S92>/Integrator'
                                      */
  real_T Integrator_gainval_h;       /* Computed Parameter: Integrator_gainval_h
                                      * Referenced by: '<S140>/Integrator'
                                      */
  real_T Zero_ref_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Zero_ref'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S1>/Saturation4'
                                        */
  real_T Integrator_gainval_hf;     /* Computed Parameter: Integrator_gainval_hf
                                     * Referenced by: '<S204>/Integrator'
                                     */
  real_T Saturation1_UpperSat_b;       /* Expression: 0.2
                                        * Referenced by: '<S168>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_j;       /* Expression: -0.2
                                        * Referenced by: '<S168>/Saturation1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S168>/Gain'
                                        */
  real_T Integrator_gainval_j;       /* Computed Parameter: Integrator_gainval_j
                                      * Referenced by: '<S255>/Integrator'
                                      */
  real_T Saturation1_UpperSat_a;       /* Expression: 1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_e;       /* Expression: -1
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  uint32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S3>/Delay'
                                    */
  uint32_T Constant1_Value_o;          /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S3>/Constant1'
                                        */
  int16_T Gain_Gain_l;                 /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S8>/Gain'
                                        */
  uint16_T UDPSend_toPort;             /* Computed Parameter: UDPSend_toPort
                                        * Referenced by: '<S3>/UDP Send'
                                        */
  uint8_T UDPReceive_fmAddress[4];   /* Computed Parameter: UDPReceive_fmAddress
                                      * Referenced by: '<S2>/UDP Receive'
                                      */
  uint8_T UDPReceive_fmAddress_o[4];
                                   /* Computed Parameter: UDPReceive_fmAddress_o
                                    * Referenced by: '<S8>/UDP Receive'
                                    */
  uint8_T UDPSend_toAddress[4];        /* Computed Parameter: UDPSend_toAddress
                                        * Referenced by: '<S3>/UDP Send'
                                        */
  boolean_T Memory2_InitialCondition;
                                 /* Computed Parameter: Memory2_InitialCondition
                                  * Referenced by: '<S7>/Memory2'
                                  */
  boolean_T Memory3_InitialCondition;
                                 /* Computed Parameter: Memory3_InitialCondition
                                  * Referenced by: '<S5>/Memory3'
                                  */
};

/* Storage class 'PageSwitching' */
extern sg_IK_cal_type sg_IK_cal_impl;
extern sg_IK_cal_type *sg_IK_cal;

#endif                                 /* RTW_HEADER_sg_IK_cal_h_ */
