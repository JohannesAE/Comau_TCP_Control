/*
 * sg_IK.h
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

#ifndef RTW_HEADER_sg_IK_h_
#define RTW_HEADER_sg_IK_h_
#include <cmath>
#include <cstring>
#include <math.h>
#include <cstring>
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "verify/verifyIntrf.h"
#include "slrealtime/libsrc/IP/udp.hpp"
#include "sg_IK_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "sg_IK_cal.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
struct B_sg_IK_T {
  real_T controlMode;                  /* '<S1>/controlMode' */
  real_T UDPReceive_o2;                /* '<S2>/UDP Receive' */
  real_T DataTypeConversion4[6];       /* '<S2>/Data Type Conversion4' */
  real_T DataTypeConversion5[6];       /* '<S2>/Data Type Conversion5' */
  real_T DataTypeConversion14[6];      /* '<S2>/Data Type Conversion14' */
  real_T Sum;                          /* '<S159>/Sum' */
  real_T Sum3;                         /* '<S159>/Sum3' */
  real_T Constant;                     /* '<S159>/Constant' */
  real_T Constant1;                    /* '<S159>/Constant1' */
  real_T Operation_Mode;               /* '<S163>/Constant' */
  real_T Constant_f;                   /* '<S6>/Constant' */
  real_T MS_Switch;                    /* '<S6>/Constant4' */
  real_T enable_65cm_offset_Em8000;    /* '<S6>/enable_65cm_offset_Em8000' */
  real_T UDPReceive_o2_c;              /* '<S8>/UDP Receive' */
  real_T CastToDouble[6];              /* '<S8>/Cast To Double' */
  real_T CastToDouble1[4];             /* '<S8>/Cast To Double1' */
  real_T DataTypeConversion2;          /* '<S2>/Data Type Conversion2' */
  real_T Pos;                          /* '<S2>/Sum1' */
  real_T Constant7;                    /* '<S157>/Constant7' */
  real_T Constant5;                    /* '<S157>/Constant5' */
  real_T Constant6;                    /* '<S157>/Constant6' */
  real_T MultiportSwitch[6];           /* '<S163>/Multiport Switch' */
  real_T Clock;                        /* '<S7>/Clock' */
  real_T MultiportSwitch1;             /* '<S163>/Multiport Switch1' */
  real_T MultiportSwitch2;             /* '<S163>/Multiport Switch2' */
  real_T MultiportSwitch3;             /* '<S163>/Multiport Switch3' */
  real_T Sum_f;                        /* '<S4>/Sum' */
  real_T ProportionalGain;             /* '<S49>/Proportional Gain' */
  real_T Integrator;                   /* '<S44>/Integrator' */
  real_T Sum_a;                        /* '<S53>/Sum' */
  real_T Saturation;                   /* '<S51>/Saturation' */
  real_T Sum3_e;                       /* '<S4>/Sum3' */
  real_T Sum1;                         /* '<S4>/Sum1' */
  real_T ProportionalGain_c;           /* '<S97>/Proportional Gain' */
  real_T Integrator_k;                 /* '<S92>/Integrator' */
  real_T Sum_d;                        /* '<S101>/Sum' */
  real_T Saturation_k;                 /* '<S99>/Saturation' */
  real_T Sum4;                         /* '<S4>/Sum4' */
  real_T Sum2;                         /* '<S4>/Sum2' */
  real_T ProportionalGain_o;           /* '<S145>/Proportional Gain' */
  real_T Integrator_j;                 /* '<S140>/Integrator' */
  real_T Sum_k;                        /* '<S149>/Sum' */
  real_T Saturation_e;                 /* '<S147>/Saturation' */
  real_T Sum5;                         /* '<S4>/Sum5' */
  real_T SWITCH1;                      /* '<S1>/SWITCH1' */
  real_T Saturation2;                  /* '<S1>/Saturation2' */
  real_T SWITCH2;                      /* '<S1>/SWITCH2' */
  real_T Saturation3;                  /* '<S1>/Saturation3' */
  real_T SWITCH3;                      /* '<S1>/SWITCH3' */
  real_T Saturation4;                  /* '<S1>/Saturation4' */
  real_T MultiportSwitch6;             /* '<S163>/Multiport Switch6' */
  real_T MultiportSwitch4;             /* '<S163>/Multiport Switch4' */
  real_T Winch_e;                      /* '<S168>/Sum' */
  real_T ProportionalGain_b;           /* '<S209>/Proportional Gain' */
  real_T Integrator_e;                 /* '<S204>/Integrator' */
  real_T Sum_e;                        /* '<S213>/Sum' */
  real_T DataTypeConversion10[6];      /* '<S2>/Data Type Conversion10' */
  real_T Sum2_i;                       /* '<S168>/Sum2' */
  real_T Saturation1;                  /* '<S168>/Saturation1' */
  real_T Gain;                         /* '<S168>/Gain' */
  real_T MultiportSwitch5;             /* '<S163>/Multiport Switch5' */
  real_T Clock1;                       /* '<S169>/Clock1' */
  real_T DataTypeConversion9[6];       /* '<S2>/Data Type Conversion9' */
  real_T MultiportSwitch_f;            /* '<S169>/Multiport Switch' */
  real_T Winch_e_f;                    /* '<S169>/Sum' */
  real_T ProportionalGain_a;           /* '<S260>/Proportional Gain' */
  real_T Integrator_o;                 /* '<S255>/Integrator' */
  real_T Sum_o;                        /* '<S264>/Sum' */
  real_T MultiportSwitch1_a;           /* '<S9>/Multiport Switch1' */
  real_T SWITCH4;                      /* '<S1>/SWITCH4' */
  real_T Saturation1_a;                /* '<S1>/Saturation1' */
  real_T IntegralGain;                 /* '<S41>/Integral Gain' */
  real_T IntegralGain_p;               /* '<S89>/Integral Gain' */
  real_T IntegralGain_f;               /* '<S137>/Integral Gain' */
  real_T theta0[5];
  /* '<S5>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Theta3 = (Theta3*+90deg) + Theta2_at_outport_0Inport1' */
  real_T x_IK[2];
  /* '<S157>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T y_IK[2];
  /* '<S157>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux2_at_outport_0Inport1' */
  real_T z_IK[2];
  /* '<S157>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' */
  real_T IntegralGain_l;               /* '<S201>/Integral Gain' */
  real_T IntegralGain_o;               /* '<S252>/Integral Gain' */
  real_T Vel;                          /* '<S2>/Data Type Conversion3' */
  real_T DataTypeConversion1[6];       /* '<S2>/Data Type Conversion1' */
  real_T DataTypeConversion6[6];       /* '<S2>/Data Type Conversion6' */
  real_T DataTypeConversion7[6];       /* '<S2>/Data Type Conversion7' */
  real_T DataTypeConversion8[6];       /* '<S2>/Data Type Conversion8' */
  real_T DataTypeConversion11[6];      /* '<S2>/Data Type Conversion11' */
  real_T DataTypeConversion12[6];      /* '<S2>/Data Type Conversion12' */
  real_T DataTypeConversion13[6];      /* '<S2>/Data Type Conversion13' */
  real_T PosRef;                      /* '<S169>/Winch_Posref_ramp_generator' */
  real_T Vel_FF;                      /* '<S169>/Winch_Posref_ramp_generator' */
  real_T Winch_Global_Pos_Z_out;       /* '<S169>/Winch_Local_to_Global' */
  real_T Winch_Global_Pos_Z;           /* '<S168>/Winch_Local_to_Global' */
  real_T Winch_PosRef;                 /* '<S168>/Lowpass Filter1' */
  real_T Sum2_j;                       /* '<S169>/Sum2' */
  real_T Saturation1_k;                /* '<S169>/Saturation1' */
  real_T Gain_f;                       /* '<S169>/Gain' */
  real_T p_Ball_space[3];              /* '<S8>/Camera_transform' */
  real_T p_Claw_space[3];              /* '<S8>/Camera_transform' */
  real_T Camera_space_frame_XYZ[3];    /* '<S8>/Camera_transform' */
  real_T Camera_space_frame_EUL[3];    /* '<S8>/Camera_transform' */
  real_T p[3];                         /* '<S7>/Trajectory_planner' */
  real_T p_vel[3];                     /* '<S7>/Trajectory_planner' */
  real_T Sum2_h;                       /* '<S160>/Sum2' */
  real_T Winch_Global_Pos_Z_h;         /* '<S6>/Winch_Local_to_Global' */
  real_T Traj_points_XYZ[6];           /* '<S6>/Chart' */
  real_T new_command;                  /* '<S6>/Chart' */
  real_T Traj_method;                  /* '<S6>/Chart' */
  real_T v_max;                        /* '<S6>/Chart' */
  real_T Winch_NewCmd;                 /* '<S6>/Chart' */
  real_T Winch_PosRef_e;               /* '<S6>/Chart' */
  real_T Winch_Mode_selector;          /* '<S6>/Chart' */
  real_T FF_Flag;                      /* '<S6>/Chart' */
  real_T TmpSignalConversionAtSFunctionI[3];/* '<S5>/IVK_solver' */
  real_T TmpSignalConversionAtSFunctio_h[5];/* '<S5>/IVK_solver' */
  real_T thetaListDot[5];              /* '<S5>/IVK_solver' */
  real_T TmpSignalConversionAtSFunctio_a[5];/* '<S157>/FK_solver' */
  real_T Endeff_local_xyz[3];          /* '<S157>/FK_solver' */
  real_T T_w_ee[16];                   /* '<S157>/FK_solver' */
  real_T T_b_ee[16];                   /* '<S157>/FK_solver' */
  real_T Endeff_world_xyz[3];          /* '<S157>/FK_solver' */
  uint32_T Delay;                      /* '<S3>/Delay' */
  uint32_T Add;                        /* '<S3>/Add' */
  uint32_T eMode;                      /* '<S2>/Byte Unpacking' */
  real32_T PLC_time;                   /* '<S2>/Byte Unpacking' */
  real32_T Comau_theta[6];             /* '<S2>/Byte Unpacking' */
  real32_T Comau_theta_vel[6];         /* '<S2>/Byte Unpacking' */
  real32_T Winch;                      /* '<S2>/Byte Unpacking' */
  real32_T Winch_vel;                  /* '<S2>/Byte Unpacking' */
  real32_T Em8000_transpos_and_rpy[6]; /* '<S2>/Byte Unpacking' */
  real32_T Em8000_transvel_and_rpyvel[6];/* '<S2>/Byte Unpacking' */
  real32_T Em8000_tranacc_and_rpyacc[6];/* '<S2>/Byte Unpacking' */
  real32_T Em8000_MRU_transpos_and_rpy[6];/* '<S2>/Byte Unpacking' */
  real32_T Em8000_MRU_transvel_and_rpyvel[6];/* '<S2>/Byte Unpacking' */
  real32_T Em1500_transpos_and_rpy[6]; /* '<S2>/Byte Unpacking' */
  real32_T Em1500_transvel_and_rpyvel[6];/* '<S2>/Byte Unpacking' */
  real32_T Em1500_tranacc_and_rpyacc[6];/* '<S2>/Byte Unpacking' */
  real32_T Em1500_MRU_transpos_and_rpy[6];/* '<S2>/Byte Unpacking' */
  real32_T Em1500_MRU_transvel_and_rpyvel[6];/* '<S2>/Byte Unpacking' */
  real32_T UDP_camera_IMU[4];          /* '<S8>/Byte_Unpacking' */
  real32_T CastToSingle1;              /* '<S1>/Cast To Single1' */
  real32_T CastToSingle2;              /* '<S1>/Cast To Single2' */
  real32_T CastToSingle3;              /* '<S1>/Cast To Single3' */
  real32_T CastToSingle;               /* '<S1>/Cast To Single' */
  real32_T Vel_FF_n;                   /* '<S168>/FeedForward_Switch' */
  int32_T Gain_k[6];                   /* '<S8>/Gain' */
  int16_T UDP_camera_detection[6];     /* '<S8>/Byte_Unpacking' */
  uint8_T UDPReceive_o1[304];          /* '<S2>/UDP Receive' */
  uint8_T UDPReceive_o1_i[29];         /* '<S8>/UDP Receive' */
  uint8_T Byte_Unpacking_o2;           /* '<S8>/Byte_Unpacking' */
  uint8_T BytePacking[136];            /* '<S3>/Byte Packing' */
  boolean_T Memory2;                   /* '<S7>/Memory2' */
  boolean_T Memory3;                   /* '<S5>/Memory3' */
  boolean_T UDP_Hooked_flag;           /* '<S8>/Boolean' */
  boolean_T bBall_InFrame;             /* '<S8>/Camera_transform' */
  boolean_T Traj_Running;              /* '<S7>/Trajectory_planner' */
  boolean_T Em8000_settled_flag;       /* '<S6>/is_Em8000_settled' */
  boolean_T Joint_LimitReached;        /* '<S5>/IVK_solver' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_sg_IK_T {
  dsp_LowpassFilter_sg_IK_T obj;       /* '<S168>/Lowpass Filter1' */
  real_T Integrator_DSTATE;            /* '<S44>/Integrator' */
  real_T Integrator_DSTATE_c;          /* '<S92>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S140>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S204>/Integrator' */
  real_T Integrator_DSTATE_cl;         /* '<S255>/Integrator' */
  real_T Sum2_DWORK1;                  /* '<S168>/Sum2' */
  real_T last_command;                /* '<S169>/Winch_Posref_ramp_generator' */
  real_T command_start_time;          /* '<S169>/Winch_Posref_ramp_generator' */
  real_T command_start_pos;           /* '<S169>/Winch_Posref_ramp_generator' */
  real_T current_target_pos;          /* '<S169>/Winch_Posref_ramp_generator' */
  real_T T_move;                      /* '<S169>/Winch_Posref_ramp_generator' */
  real_T actual_move_vel;             /* '<S169>/Winch_Posref_ramp_generator' */
  real_T target_idle_base_pos;        /* '<S169>/Winch_Posref_ramp_generator' */
  real_T p_Ball_space_persistent[3];   /* '<S8>/Camera_transform' */
  real_T p_Claw_space_persistent[3];   /* '<S8>/Camera_transform' */
  real_T abs_tf;                       /* '<S7>/Trajectory_planner' */
  real_T base_t;                       /* '<S7>/Trajectory_planner' */
  real_T last_command_f;               /* '<S7>/Trajectory_planner' */
  real_T new_points_x[2];              /* '<S7>/Trajectory_planner' */
  real_T new_points_y[2];              /* '<S7>/Trajectory_planner' */
  real_T new_points_z[2];              /* '<S7>/Trajectory_planner' */
  real_T Z_home;                       /* '<S6>/Chart' */
  real_T X_home;                       /* '<S6>/Chart' */
  real_T Y_home;                       /* '<S6>/Chart' */
  real_T X_Platform;                   /* '<S6>/Chart' */
  real_T Z_Platform;                   /* '<S6>/Chart' */
  real_T Y_Platform;                   /* '<S6>/Chart' */
  real_T Z_Offset;                     /* '<S6>/Chart' */
  real_T r_Offset;                     /* '<S6>/Chart' */
  real_T Target_Pos_Y;                 /* '<S6>/Chart' */
  real_T Target_Pos_X;                 /* '<S6>/Chart' */
  real_T Target_Pos_Z;                 /* '<S6>/Chart' */
  real_T unit_delta[2];                /* '<S6>/Chart' */
  real_T Sub_stage_switch;             /* '<S6>/Chart' */
  real_T Z_Up;                         /* '<S6>/Chart' */
  real_T norm_delta;                   /* '<S6>/Chart' */
  real_T delta_xy[2];                  /* '<S6>/Chart' */
  real_T Mode;                         /* '<S6>/Chart' */
  real_T Sub_stage_switch2;            /* '<S6>/Chart' */
  real_T X_Unhook;                     /* '<S6>/Chart' */
  real_T Y_Unhook;                     /* '<S6>/Chart' */
  real_T Z_Unhook;                     /* '<S6>/Chart' */
  real_T Em8000_settled_offset;        /* '<S6>/Chart' */
  real_T Hook_state_switch;            /* '<S6>/Chart' */
  real_T AutoSwitch;                   /* '<S6>/Chart' */
  void *UDPReceive_PWORK[2];           /* '<S2>/UDP Receive' */
  void *UDPReceive_PWORK_c[2];         /* '<S8>/UDP Receive' */
  void *UDPSend_PWORK;                 /* '<S3>/UDP Send' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Contr;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Winch;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_contr;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_IVK_s;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_IVK_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Theta;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_FK_so;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_FK__b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mux1_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mux2_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Mux3_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Const;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Opera;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ope_j;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ope_h;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ope_n;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Win_o;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_is_Em;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Con_f;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Traje;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Tra_b;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Tra_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Boole;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byte_;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Byt_g;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Camer;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Cam_f;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Cam_l;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ca_ll;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Ca_lo;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_FeedF;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Lowpa;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum_a;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Wi_op;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_W_opo;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Win_p;   /* synthesized block */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Win_m;   /* synthesized block */

  struct {
    void *AQHandles[2];
  } TAQSigLogging_InsertedFor_BusCr;   /* synthesized block */

  struct {
    void *AQHandles[24];
  } TAQSigLogging_InsertedFor_Bus_n;   /* synthesized block */

  uint32_T Delay_DSTATE;               /* '<S3>/Delay' */
  int32_T sfEvent;                     /* '<S6>/Chart' */
  uint32_T is_c9_sg_IK;                /* '<S6>/Chart' */
  uint32_T is_Manual_State_Switch_Mode;/* '<S6>/Chart' */
  uint32_T is_Hook_Ball;               /* '<S6>/Chart' */
  uint32_T is_Lower_payload_Onto_platform;/* '<S6>/Chart' */
  uint32_T is_Autonomous_Operation_Mode;/* '<S6>/Chart' */
  uint32_T is_Hook_Ball_o;             /* '<S6>/Chart' */
  uint32_T is_Lower_payload_Onto_platfor_p;/* '<S6>/Chart' */
  int_T UDPReceive_IWORK;              /* '<S2>/UDP Receive' */
  int_T ByteUnpacking_IWORK[32];       /* '<S2>/Byte Unpacking' */
  int_T UDPReceive_IWORK_d;            /* '<S8>/UDP Receive' */
  int_T Byte_Unpacking_IWORK[6];       /* '<S8>/Byte_Unpacking' */
  int_T BytePacking_IWORK[68];         /* '<S3>/Byte Packing' */
  int_T UDPSend_IWORK[2];              /* '<S3>/UDP Send' */
  uint16_T temporalCounter_i1;         /* '<S6>/Chart' */
  uint16_T temporalCounter_i2;         /* '<S6>/Chart' */
  uint8_T is_active_c9_sg_IK;          /* '<S6>/Chart' */
  boolean_T Memory2_PreviousInput;     /* '<S7>/Memory2' */
  boolean_T Memory3_PreviousInput;     /* '<S5>/Memory3' */
  boolean_T is_moving;                /* '<S169>/Winch_Posref_ramp_generator' */
  boolean_T first_run_not_empty;      /* '<S169>/Winch_Posref_ramp_generator' */
  boolean_T objisempty;                /* '<S168>/Lowpass Filter1' */
  boolean_T isInitialized;             /* '<S168>/Lowpass Filter1' */
  boolean_T p_Ball_space_persistent_not_emp;/* '<S8>/Camera_transform' */
  boolean_T p_Claw_space_persistent_not_emp;/* '<S8>/Camera_transform' */
  boolean_T abs_tf_not_empty;          /* '<S7>/Trajectory_planner' */
};

/* Invariant block signals (default storage) */
struct ConstB_sg_IK_T {
  real_T Width;                        /* '<S3>/Width' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_sg_IK_T {
  uint32_T Input1[3];                  /* '<Root>/Input1' */
  real32_T Input2[24];                 /* '<Root>/Input2' */
  real32_T Input3[3];                  /* '<Root>/Input3' */
};

/* Real-time Model Data Structure */
struct tag_RTM_sg_IK_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_sg_IK_T sg_IK_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern struct DW_sg_IK_T sg_IK_DW;

#ifdef __cplusplus

extern "C" {

#endif

  /* External inputs (root inport signals with default storage) */
  extern struct ExtU_sg_IK_T sg_IK_U;

#ifdef __cplusplus

}
#endif

extern const ConstB_sg_IK_T sg_IK_ConstB;/* constant block i/o */

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void sg_IK_initialize(void);
  extern void sg_IK_step(void);
  extern void sg_IK_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_sg_IK_T *const sg_IK_M;

#ifdef __cplusplus

}
#endif

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
 * '<Root>' : 'sg_IK'
 * '<S1>'   : 'sg_IK/Controller'
 * '<S2>'   : 'sg_IK/MotionLab_UDP_Recieve'
 * '<S3>'   : 'sg_IK/MotionLab_UDP_Send'
 * '<S4>'   : 'sg_IK/Controller/Closed Loop'
 * '<S5>'   : 'sg_IK/Controller/Inverse velocity and forward kinematics'
 * '<S6>'   : 'sg_IK/Controller/State Machine and Operation mode selecotr'
 * '<S7>'   : 'sg_IK/Controller/Trajectory planner'
 * '<S8>'   : 'sg_IK/Controller/UDP_Camera'
 * '<S9>'   : 'sg_IK/Controller/Winch_Controller'
 * '<S10>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller'
 * '<S11>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1'
 * '<S12>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2'
 * '<S13>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Anti-windup'
 * '<S14>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/D Gain'
 * '<S15>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Filter'
 * '<S16>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Filter ICs'
 * '<S17>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/I Gain'
 * '<S18>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Ideal P Gain'
 * '<S19>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S20>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Integrator'
 * '<S21>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Integrator ICs'
 * '<S22>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/N Copy'
 * '<S23>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/N Gain'
 * '<S24>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/P Copy'
 * '<S25>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Parallel P Gain'
 * '<S26>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Reset Signal'
 * '<S27>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Saturation'
 * '<S28>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Saturation Fdbk'
 * '<S29>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Sum'
 * '<S30>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Sum Fdbk'
 * '<S31>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tracking Mode'
 * '<S32>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tracking Mode Sum'
 * '<S33>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tsamp - Integral'
 * '<S34>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tsamp - Ngain'
 * '<S35>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/postSat Signal'
 * '<S36>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/preSat Signal'
 * '<S37>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S38>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/D Gain/Disabled'
 * '<S39>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Filter/Disabled'
 * '<S40>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Filter ICs/Disabled'
 * '<S41>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S42>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Integrator/Discrete'
 * '<S45>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S47>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/N Gain/Disabled'
 * '<S48>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/P Copy/Disabled'
 * '<S49>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Reset Signal/Disabled'
 * '<S51>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Saturation/Enabled'
 * '<S52>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Sum/Sum_PI'
 * '<S54>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S58>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Anti-windup'
 * '<S62>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/D Gain'
 * '<S63>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Filter'
 * '<S64>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Filter ICs'
 * '<S65>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/I Gain'
 * '<S66>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Ideal P Gain'
 * '<S67>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S68>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Integrator'
 * '<S69>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Integrator ICs'
 * '<S70>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/N Copy'
 * '<S71>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/N Gain'
 * '<S72>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/P Copy'
 * '<S73>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Parallel P Gain'
 * '<S74>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Reset Signal'
 * '<S75>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Saturation'
 * '<S76>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Saturation Fdbk'
 * '<S77>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Sum'
 * '<S78>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Sum Fdbk'
 * '<S79>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tracking Mode'
 * '<S80>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tracking Mode Sum'
 * '<S81>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tsamp - Integral'
 * '<S82>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tsamp - Ngain'
 * '<S83>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/postSat Signal'
 * '<S84>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/preSat Signal'
 * '<S85>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S86>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/D Gain/Disabled'
 * '<S87>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Filter/Disabled'
 * '<S88>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S89>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S90>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S91>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S92>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Integrator/Discrete'
 * '<S93>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S94>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S95>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/N Gain/Disabled'
 * '<S96>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/P Copy/Disabled'
 * '<S97>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S98>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S99>'  : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Saturation/Enabled'
 * '<S100>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S101>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Sum/Sum_PI'
 * '<S102>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S103>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S104>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S105>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tsamp - Integral/Passthrough'
 * '<S106>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S107>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S108>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S109>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Anti-windup'
 * '<S110>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/D Gain'
 * '<S111>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Filter'
 * '<S112>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Filter ICs'
 * '<S113>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/I Gain'
 * '<S114>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Ideal P Gain'
 * '<S115>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S116>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Integrator'
 * '<S117>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Integrator ICs'
 * '<S118>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/N Copy'
 * '<S119>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/N Gain'
 * '<S120>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/P Copy'
 * '<S121>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Parallel P Gain'
 * '<S122>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Reset Signal'
 * '<S123>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Saturation'
 * '<S124>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Saturation Fdbk'
 * '<S125>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Sum'
 * '<S126>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Sum Fdbk'
 * '<S127>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tracking Mode'
 * '<S128>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tracking Mode Sum'
 * '<S129>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tsamp - Integral'
 * '<S130>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tsamp - Ngain'
 * '<S131>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/postSat Signal'
 * '<S132>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/preSat Signal'
 * '<S133>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Anti-windup/Passthrough'
 * '<S134>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/D Gain/Disabled'
 * '<S135>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Filter/Disabled'
 * '<S136>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Filter ICs/Disabled'
 * '<S137>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S138>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S139>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S140>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Integrator/Discrete'
 * '<S141>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S142>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S143>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/N Gain/Disabled'
 * '<S144>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/P Copy/Disabled'
 * '<S145>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S146>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S147>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Saturation/Enabled'
 * '<S148>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S149>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Sum/Sum_PI'
 * '<S150>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S151>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S152>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S153>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tsamp - Integral/Passthrough'
 * '<S154>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S155>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S156>' : 'sg_IK/Controller/Closed Loop/Discrete PID Controller2/preSat Signal/Forward_Path'
 * '<S157>' : 'sg_IK/Controller/Inverse velocity and forward kinematics/Forward kinematics'
 * '<S158>' : 'sg_IK/Controller/Inverse velocity and forward kinematics/IVK_solver'
 * '<S159>' : 'sg_IK/Controller/Inverse velocity and forward kinematics/Theta3 = (Theta3*+90deg) + Theta2'
 * '<S160>' : 'sg_IK/Controller/Inverse velocity and forward kinematics/ThetaDot3*=ThetaDot3-ThetaDot2'
 * '<S161>' : 'sg_IK/Controller/Inverse velocity and forward kinematics/Forward kinematics/FK_solver'
 * '<S162>' : 'sg_IK/Controller/State Machine and Operation mode selecotr/Chart'
 * '<S163>' : 'sg_IK/Controller/State Machine and Operation mode selecotr/Operation_Mode_Selector'
 * '<S164>' : 'sg_IK/Controller/State Machine and Operation mode selecotr/Winch_Local_to_Global'
 * '<S165>' : 'sg_IK/Controller/State Machine and Operation mode selecotr/is_Em8000_settled'
 * '<S166>' : 'sg_IK/Controller/Trajectory planner/Trajectory_planner'
 * '<S167>' : 'sg_IK/Controller/UDP_Camera/Camera_transform'
 * '<S168>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp'
 * '<S169>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp'
 * '<S170>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller'
 * '<S171>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/FeedForward_Switch'
 * '<S172>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Winch_Local_to_Global'
 * '<S173>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Anti-windup'
 * '<S174>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/D Gain'
 * '<S175>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Filter'
 * '<S176>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Filter ICs'
 * '<S177>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/I Gain'
 * '<S178>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Ideal P Gain'
 * '<S179>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S180>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Integrator'
 * '<S181>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Integrator ICs'
 * '<S182>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/N Copy'
 * '<S183>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/N Gain'
 * '<S184>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/P Copy'
 * '<S185>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Parallel P Gain'
 * '<S186>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Reset Signal'
 * '<S187>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Saturation'
 * '<S188>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Saturation Fdbk'
 * '<S189>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Sum'
 * '<S190>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Sum Fdbk'
 * '<S191>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tracking Mode'
 * '<S192>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tracking Mode Sum'
 * '<S193>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tsamp - Integral'
 * '<S194>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tsamp - Ngain'
 * '<S195>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/postSat Signal'
 * '<S196>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/preSat Signal'
 * '<S197>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S198>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/D Gain/Disabled'
 * '<S199>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Filter/Disabled'
 * '<S200>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Filter ICs/Disabled'
 * '<S201>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S202>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S203>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S204>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Integrator/Discrete'
 * '<S205>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S206>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S207>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/N Gain/Disabled'
 * '<S208>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/P Copy/Disabled'
 * '<S209>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S210>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Reset Signal/Disabled'
 * '<S211>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Saturation/Passthrough'
 * '<S212>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S213>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Sum/Sum_PI'
 * '<S214>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S215>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S216>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S217>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S218>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S219>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S220>' : 'sg_IK/Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S221>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller'
 * '<S222>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Winch_Local_to_Global'
 * '<S223>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Winch_Posref_ramp_generator'
 * '<S224>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Anti-windup'
 * '<S225>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/D Gain'
 * '<S226>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Filter'
 * '<S227>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Filter ICs'
 * '<S228>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/I Gain'
 * '<S229>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Ideal P Gain'
 * '<S230>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S231>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Integrator'
 * '<S232>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Integrator ICs'
 * '<S233>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/N Copy'
 * '<S234>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/N Gain'
 * '<S235>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/P Copy'
 * '<S236>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Parallel P Gain'
 * '<S237>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Reset Signal'
 * '<S238>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Saturation'
 * '<S239>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Saturation Fdbk'
 * '<S240>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Sum'
 * '<S241>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Sum Fdbk'
 * '<S242>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tracking Mode'
 * '<S243>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tracking Mode Sum'
 * '<S244>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tsamp - Integral'
 * '<S245>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tsamp - Ngain'
 * '<S246>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/postSat Signal'
 * '<S247>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/preSat Signal'
 * '<S248>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S249>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/D Gain/Disabled'
 * '<S250>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Filter/Disabled'
 * '<S251>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Filter ICs/Disabled'
 * '<S252>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S253>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S254>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S255>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Integrator/Discrete'
 * '<S256>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S257>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S258>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/N Gain/Disabled'
 * '<S259>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/P Copy/Disabled'
 * '<S260>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S261>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Reset Signal/Disabled'
 * '<S262>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Saturation/Passthrough'
 * '<S263>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S264>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Sum/Sum_PI'
 * '<S265>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S266>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S267>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S268>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S269>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S270>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S271>' : 'sg_IK/Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_sg_IK_h_ */
