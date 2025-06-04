/*
 * sg_IK.cpp
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

#include "rte_sg_IK_parameters.h"
#include "sg_IK.h"
#include "sg_IK_private.h"

/* Named constants for Chart: '<S6>/Chart' */
const uint32_T IN_Lower_payload_Onto_platform = 3U;
const uint32_T IN_Move_above_platform_While_lo = 2U;
const uint32_T IN_Move_to_above_platform_PickU = 4U;
const uint32_T sg_IK_IN_Ball_In_Frame = 1U;
const uint32_T sg_IK_IN_Go_home = 1U;
const uint32_T sg_IK_IN_Hook_Ball = 2U;
const uint32_T sg_IK_IN_Lift_Up = 2U;
const uint32_T sg_IK_IN_Lower_winch_To_unhook = 1U;
const uint32_T sg_IK_IN_Mode_selector_state = 3U;
const uint32_T sg_IK_IN_Move_Close_To_Ball = 3U;
const uint32_T sg_IK_IN_Move_Close_To_Ball_d = 2U;
const uint32_T sg_IK_IN_Move_in_to_ball = 4U;
const uint32_T sg_IK_IN_Move_in_to_ball_e = 3U;
const uint32_T sg_IK_IN_Move_to_side_unhook = 3U;
const uint32_T sg_IN_Autonomous_Operation_Mode = 1U;
const uint32_T sg__IN_Manual_State_Switch_Mode = 2U;
const uint32_T sg__IN_Stay_in_current_position = 5U;

/* Block signals (default storage) */
B_sg_IK_T sg_IK_B;

/* Block states (default storage) */
DW_sg_IK_T sg_IK_DW;

/* External inputs (root inport signals with default storage) */
ExtU_sg_IK_T sg_IK_U;

/* Real-time model */
RT_MODEL_sg_IK_T sg_IK_M_ = RT_MODEL_sg_IK_T();
RT_MODEL_sg_IK_T *const sg_IK_M = &sg_IK_M_;

/* Forward declaration for local functions */
static real_T sg_IK_norm(const real_T x[3]);
static void sg_IK_atan2(const real_T y_data[], const int32_T y_size[3], const
  real_T x_data[], const int32_T x_size[3], real_T r_data[], int32_T r_size[3]);
static void sg_IK_enter_atomic_Go_home_m(void);
static real_T sg_IK_norm_cd(const real_T x[2]);
static void sg_IK_Autonomous_Operation_Mode(void);
static void enter_atomic_Move_to_above_plat(void);
static void sg_IK_enter_atomic_Go_home(void);
static void sg_IK_Hook_Ball(void);
static void sg_IK_quinticTrajectoryPlanner(real_T t, real_T T, real_T P0, real_T
  Pf, real_T *pos, real_T *vel, real_T *acc);
static real_T sg_IK_xnrm2(int32_T n, const real_T x[30], int32_T ix0);
static void sg_IK_xscal(int32_T n, real_T a, real_T x[30], int32_T ix0);
static real_T sg_IK_xnrm2_f(int32_T n, const real_T x[5], int32_T ix0);
static void sg_IK_xscal_e(int32_T n, real_T a, real_T x[5], int32_T ix0);
static void sg_IK_xaxpy_gf(int32_T n, real_T a, const real_T x[6], int32_T ix0,
  real_T y[30], int32_T iy0);
static void sg_IK_xaxpy_g(int32_T n, real_T a, const real_T x[30], int32_T ix0,
  real_T y[6], int32_T iy0);
static real_T sg_IK_xdotc(int32_T n, const real_T x[30], int32_T ix0, const
  real_T y[30], int32_T iy0);
static void sg_IK_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[30], int32_T
  iy0);
static real_T sg_IK_xdotc_p(int32_T n, const real_T x[25], int32_T ix0, const
  real_T y[25], int32_T iy0);
static void sg_IK_xaxpy_gf2(int32_T n, real_T a, int32_T ix0, real_T y[25],
  int32_T iy0);
static void sg_IK_xscal_eu(real_T a, real_T x[30], int32_T ix0);
static void sg_IK_xscal_euh(real_T a, real_T x[25], int32_T ix0);
static void sg_IK_xswap(real_T x[25], int32_T ix0, int32_T iy0);
static void sg_IK_xswap_o(real_T x[30], int32_T ix0, int32_T iy0);
static void sg_IK_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void sg_IK_xrot(real_T x[25], int32_T ix0, int32_T iy0, real_T c, real_T
  s);
static void sg_IK_xrot_l(real_T x[30], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void sg_IK_svd(const real_T A[30], real_T U[30], real_T s[5], real_T V[25]);

/* Function for MATLAB Function: '<S157>/FK_solver' */
static real_T sg_IK_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(tmp_0), static_cast<real_T>(tmp));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S8>/Camera_transform' */
static void sg_IK_atan2(const real_T y_data[], const int32_T y_size[3], const
  real_T x_data[], const int32_T x_size[3], real_T r_data[], int32_T r_size[3])
{
  int32_T z_size_idx_2;
  int8_T csz_idx_2;
  if (y_size[2] <= x_size[2]) {
    csz_idx_2 = static_cast<int8_T>(y_size[2]);
  } else {
    csz_idx_2 = 0;
  }

  z_size_idx_2 = csz_idx_2;
  r_size[0] = 1;
  r_size[1] = 1;
  r_size[2] = csz_idx_2;
  if (0 <= z_size_idx_2 - 1) {
    r_data[0] = rt_atan2d_snf(y_data[0], x_data[0]);
  }
}

/* Function for Chart: '<S6>/Chart' */
static void sg_IK_enter_atomic_Go_home_m(void)
{
  /* Entry 'Go_home': '<S162>:384' */
  sg_IK_DW.AutoSwitch = 0.0;
  if (sg_IK_B.Em8000_settled_flag && (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0)))
  {
    sg_IK_DW.Em8000_settled_offset = 1.0;
  } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
    sg_IK_DW.Em8000_settled_offset = 0.65;
  } else {
    sg_IK_DW.Em8000_settled_offset = 0.0;
  }

  sg_IK_DW.X_home = -0.9;
  sg_IK_DW.Y_home = -1.3;
  sg_IK_DW.Z_home = 5.9 - sg_IK_DW.Em8000_settled_offset;
  sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
  sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_home;
  sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
  sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_home;
  sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
  sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_home;
  sg_IK_B.Traj_method = 2.0;
  sg_IK_B.v_max = 0.1;
  sg_IK_B.new_command++;
  sg_IK_B.Winch_PosRef_e = 10.0;
  sg_IK_B.Winch_Mode_selector = 1.0;
  sg_IK_B.FF_Flag = 0.0;
}

/* Function for Chart: '<S6>/Chart' */
static real_T sg_IK_norm_cd(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

/* Function for Chart: '<S6>/Chart' */
static void sg_IK_Autonomous_Operation_Mode(void)
{
  /* During 'Autonomous_Operation_Mode': '<S162>:170' */
  switch (sg_IK_DW.is_Autonomous_Operation_Mode) {
   case sg_IK_IN_Go_home:
    {
      boolean_T out;

      /* During 'Go_home': '<S162>:384' */
      out = ((sg_IK_DW.AutoSwitch == 1.0) && (sg_IK_DW.temporalCounter_i1 >=
              3000U));
      if (out) {
        /* Transition: '<S162>:416' */
        sg_IK_DW.is_Autonomous_Operation_Mode = sg_IK_IN_Hook_Ball;
        sg_IK_DW.temporalCounter_i2 = 0U;

        /* Entry Internal 'Hook_Ball': '<S162>:395' */
        /* Transition: '<S162>:396' */
        sg_IK_DW.is_Hook_Ball_o = IN_Move_to_above_platform_PickU;
        sg_IK_DW.temporalCounter_i1 = 0U;

        /* Entry 'Move_to_above_platform_PickUp': '<S162>:383' */
        if (sg_IK_B.Em8000_settled_flag && (!(sg_IK_B.enable_65cm_offset_Em8000
              != 0.0))) {
          sg_IK_DW.Em8000_settled_offset = 1.0;
        } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
          sg_IK_DW.Em8000_settled_offset = 0.65;
        } else {
          sg_IK_DW.Em8000_settled_offset = 0.0;
        }

        sg_IK_DW.X_Platform = 0.42;
        sg_IK_DW.Y_Platform = -1.57;
        sg_IK_DW.Z_Platform = 5.62 - sg_IK_DW.Em8000_settled_offset;
        sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
        sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_Platform;
        sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
        sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_Platform;
        sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
        sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_Platform;
        sg_IK_B.Traj_method = 2.0;
        sg_IK_B.v_max = 0.16;
        sg_IK_B.new_command++;
        sg_IK_B.Winch_Mode_selector = 1.0;
        sg_IK_B.Winch_PosRef_e = 3.15;
        sg_IK_B.FF_Flag = 1.0;
      } else {
        out = ((sg_IK_DW.AutoSwitch == 2.0) && (sg_IK_DW.temporalCounter_i1 >=
                3000U));
        if (out) {
          /* Transition: '<S162>:412' */
          sg_IK_DW.is_Autonomous_Operation_Mode = IN_Lower_payload_Onto_platform;
          sg_IK_DW.temporalCounter_i2 = 0U;

          /* Entry 'Lower_payload_Onto_platform': '<S162>:413' */
          /* Entry Internal 'Lower_payload_Onto_platform': '<S162>:413' */
          /* Transition: '<S162>:397' */
          sg_IK_DW.is_Lower_payload_Onto_platfor_p =
            IN_Move_above_platform_While_lo;
          sg_IK_DW.temporalCounter_i1 = 0U;

          /* Entry 'Move_above_platform_While_lowering_payload': '<S162>:406' */
          if (sg_IK_B.Em8000_settled_flag &&
              (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0))) {
            sg_IK_DW.Em8000_settled_offset = 1.0;
          } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
            sg_IK_DW.Em8000_settled_offset = 0.65;
          } else {
            sg_IK_DW.Em8000_settled_offset = 0.0;
          }

          sg_IK_DW.Sub_stage_switch2 = 0.0;
          sg_IK_DW.X_Platform = 0.41;
          sg_IK_DW.Y_Platform = -1.34;
          sg_IK_DW.Z_Platform = 5.67 - sg_IK_DW.Em8000_settled_offset;
          sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_Platform;
          sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_Platform;
          sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_Platform;
          sg_IK_B.Traj_method = 2.0;
          sg_IK_B.v_max = 0.16;
          sg_IK_B.new_command++;
          sg_IK_B.Winch_Mode_selector = 2.0;
          sg_IK_B.Winch_PosRef_e = 3.2;
          sg_IK_B.Winch_NewCmd++;
          sg_IK_B.FF_Flag = 1.0;
        } else if (!sg_IK_B.Memory2) {
          if (sg_IK_DW.Hook_state_switch == 1.0) {
            sg_IK_DW.AutoSwitch = 1.0;
          } else {
            sg_IK_DW.AutoSwitch = 2.0;
          }
        } else {
          sg_IK_DW.AutoSwitch = 0.0;
        }
      }
    }
    break;

   case sg_IK_IN_Hook_Ball:
    {
      boolean_T out;

      /* During 'Hook_Ball': '<S162>:395' */
      out = ((sg_IK_DW.AutoSwitch == 0.0) && (sg_IK_DW.temporalCounter_i2 >=
              1000U));
      if (out) {
        /* Transition: '<S162>:420' */
        /* Exit Internal 'Hook_Ball': '<S162>:395' */
        if (sg_IK_DW.is_Hook_Ball_o == sg_IK_IN_Move_in_to_ball_e) {
          /* Exit 'Move_in_to_ball': '<S162>:401' */
          sg_IK_DW.Sub_stage_switch = 0.0;
          sg_IK_DW.Hook_state_switch = 0.0;
          sg_IK_DW.is_Hook_Ball_o = 0U;
        } else {
          sg_IK_DW.is_Hook_Ball_o = 0U;
        }

        sg_IK_DW.is_Autonomous_Operation_Mode = sg_IK_IN_Go_home;
        sg_IK_DW.temporalCounter_i1 = 0U;
        sg_IK_enter_atomic_Go_home_m();
      } else {
        switch (sg_IK_DW.is_Hook_Ball_o) {
         case sg_IK_IN_Ball_In_Frame:
          /* During 'Ball_In_Frame': '<S162>:391' */
          if (sg_IK_DW.Sub_stage_switch == 2.0) {
            /* Transition: '<S162>:389' */
            sg_IK_DW.is_Hook_Ball_o = sg_IK_IN_Move_Close_To_Ball_d;
            sg_IK_DW.temporalCounter_i1 = 0U;

            /* Entry 'Move_Close_To_Ball': '<S162>:392' */
            sg_IK_DW.Z_Offset = 0.15;
            sg_IK_DW.r_Offset = 0.15;
            sg_IK_DW.delta_xy[0] = sg_IK_B.Endeff_world_xyz[0] -
              sg_IK_B.p_Ball_space[0];
            sg_IK_DW.delta_xy[1] = sg_IK_B.Endeff_world_xyz[1] -
              sg_IK_B.p_Ball_space[1];
            sg_IK_DW.norm_delta = sg_IK_norm_cd(sg_IK_DW.delta_xy);
            if (sg_IK_DW.norm_delta < 1.0E-6) {
              sg_IK_DW.Target_Pos_X = sg_IK_B.Endeff_world_xyz[0];
              sg_IK_DW.Target_Pos_Y = sg_IK_B.Endeff_world_xyz[1];
              sg_IK_B.v_max = 0.0;
            } else {
              sg_IK_DW.unit_delta[0] = sg_IK_DW.delta_xy[0] /
                sg_IK_DW.norm_delta;
              sg_IK_DW.unit_delta[1] = sg_IK_DW.delta_xy[1] /
                sg_IK_DW.norm_delta;
              sg_IK_DW.Target_Pos_X = sg_IK_DW.r_Offset * sg_IK_DW.unit_delta[0]
                + sg_IK_B.p_Ball_space[0];
              sg_IK_DW.Target_Pos_Y = sg_IK_DW.r_Offset * sg_IK_DW.unit_delta[1]
                + sg_IK_B.p_Ball_space[1];
              sg_IK_B.v_max = 0.02;
            }

            sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
            sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.Target_Pos_X;
            sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
            sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Target_Pos_Y;
            sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.Traj_method = 2.0;
            sg_IK_B.new_command++;
            sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2] - sg_IK_DW.Z_Offset;
            sg_IK_B.FF_Flag = 1.0;
          } else if (sg_IK_B.bBall_InFrame) {
            sg_IK_DW.Sub_stage_switch = 2.0;
          } else {
            sg_IK_DW.Sub_stage_switch = 1.0;
          }
          break;

         case sg_IK_IN_Move_Close_To_Ball_d:
          /* During 'Move_Close_To_Ball': '<S162>:392' */
          out = ((sg_IK_DW.Sub_stage_switch == 3.0) &&
                 (sg_IK_DW.temporalCounter_i1 >= 500U));
          if (out) {
            /* Transition: '<S162>:414' */
            sg_IK_DW.is_Hook_Ball_o = sg_IK_IN_Move_in_to_ball_e;

            /* Entry 'Move_in_to_ball': '<S162>:401' */
            sg_IK_DW.Z_Offset = 0.07;
            sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
            sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.p_Ball_space[0];
            sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
            sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.p_Ball_space[1] + 0.06;
            sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.Traj_method = 2.0;
            sg_IK_B.v_max = 0.02;
            sg_IK_B.new_command++;
            sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2];
            sg_IK_B.FF_Flag = 1.0;
          } else {
            sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2] - sg_IK_DW.Z_Offset;
            if (!sg_IK_B.Memory2) {
              sg_IK_DW.Sub_stage_switch = 3.0;
            } else {
              sg_IK_DW.Sub_stage_switch = 2.0;
            }
          }
          break;

         case sg_IK_IN_Move_in_to_ball_e:
          /* During 'Move_in_to_ball': '<S162>:401' */
          sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2] - sg_IK_DW.Z_Offset;
          if (!sg_IK_B.Memory2) {
            sg_IK_DW.AutoSwitch = 0.0;
          } else {
            sg_IK_DW.Sub_stage_switch = 2.0;
          }
          break;

         default:
          /* During 'Move_to_above_platform_PickUp': '<S162>:383' */
          out = ((sg_IK_DW.Sub_stage_switch == 1.0) &&
                 (sg_IK_DW.temporalCounter_i1 >= 1000U));
          if (out) {
            /* Transition: '<S162>:419' */
            sg_IK_DW.is_Hook_Ball_o = sg_IK_IN_Ball_In_Frame;

            /* Entry 'Ball_In_Frame': '<S162>:391' */
            if (sg_IK_B.bBall_InFrame) {
              sg_IK_DW.Sub_stage_switch = 1.0;
            } else {
              sg_IK_DW.Sub_stage_switch = 0.0;
              sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
              sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
              sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
              sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
              sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
              sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
              sg_IK_B.v_max = 0.0;
              sg_IK_B.new_command++;
            }
          } else {
            sg_IK_B.Winch_PosRef_e = 3.15;
            if (!sg_IK_B.Memory2) {
              sg_IK_DW.Sub_stage_switch = 1.0;
            }
          }
          break;
        }
      }
    }
    break;

   default:
    {
      boolean_T out;

      /* During 'Lower_payload_Onto_platform': '<S162>:413' */
      out = ((sg_IK_DW.AutoSwitch == 0.0) && (sg_IK_DW.temporalCounter_i2 >=
              1000U));
      if (out) {
        /* Transition: '<S162>:421' */
        /* Exit Internal 'Lower_payload_Onto_platform': '<S162>:413' */
        if (sg_IK_DW.is_Lower_payload_Onto_platfor_p ==
            sg_IK_IN_Move_to_side_unhook) {
          /* Exit 'Move_to_side_unhook': '<S162>:405' */
          sg_IK_DW.Sub_stage_switch2 = 0.0;
          sg_IK_DW.Hook_state_switch = 1.0;
          sg_IK_DW.is_Lower_payload_Onto_platfor_p = 0U;
        } else {
          sg_IK_DW.is_Lower_payload_Onto_platfor_p = 0U;
        }

        sg_IK_DW.is_Autonomous_Operation_Mode = sg_IK_IN_Go_home;
        sg_IK_DW.temporalCounter_i1 = 0U;
        sg_IK_enter_atomic_Go_home_m();
      } else {
        switch (sg_IK_DW.is_Lower_payload_Onto_platfor_p) {
         case sg_IK_IN_Lower_winch_To_unhook:
          /* During 'Lower_winch_To_unhook': '<S162>:393' */
          if (sg_IK_DW.temporalCounter_i1 >= 5000U) {
            /* Transition: '<S162>:400' */
            sg_IK_DW.is_Lower_payload_Onto_platfor_p =
              sg_IK_IN_Move_to_side_unhook;

            /* Entry 'Move_to_side_unhook': '<S162>:405' */
            if (sg_IK_B.Em8000_settled_flag &&
                (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0))) {
              sg_IK_DW.Em8000_settled_offset = 1.0;
            } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
              sg_IK_DW.Em8000_settled_offset = 0.65;
            } else {
              sg_IK_DW.Em8000_settled_offset = 0.0;
            }

            sg_IK_DW.X_Unhook = 0.0;
            sg_IK_DW.Y_Unhook = -1.62;
            sg_IK_DW.Z_Unhook = 5.62 - sg_IK_DW.Em8000_settled_offset;
            sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
            sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_Unhook;
            sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
            sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_Unhook;
            sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_Unhook;
            sg_IK_B.Traj_method = 2.0;
            sg_IK_B.v_max = 0.07;
            sg_IK_B.new_command++;
            sg_IK_B.Winch_PosRef_e = 3.01;
            sg_IK_B.Winch_NewCmd++;
            sg_IK_B.FF_Flag = 1.0;
          }
          break;

         case IN_Move_above_platform_While_lo:
          /* During 'Move_above_platform_While_lowering_payload': '<S162>:406' */
          out = ((sg_IK_DW.Sub_stage_switch2 == 1.0) &&
                 (sg_IK_DW.temporalCounter_i1 >= 1000U));
          if (out) {
            /* Transition: '<S162>:388' */
            sg_IK_DW.is_Lower_payload_Onto_platfor_p =
              sg_IK_IN_Lower_winch_To_unhook;
            sg_IK_DW.temporalCounter_i1 = 0U;

            /* Entry 'Lower_winch_To_unhook': '<S162>:393' */
            sg_IK_B.Winch_PosRef_e = 3.04;
            sg_IK_B.Winch_NewCmd++;
          } else if (!sg_IK_B.Memory2) {
            sg_IK_DW.Sub_stage_switch2 = 1.0;
          }
          break;

         default:
          /* During 'Move_to_side_unhook': '<S162>:405' */
          if (!sg_IK_B.Memory2) {
            sg_IK_DW.AutoSwitch = 0.0;
          }
          break;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S6>/Chart' */
static void enter_atomic_Move_to_above_plat(void)
{
  /* Entry 'Move_to_above_platform_PickUp': '<S162>:32' */
  if (sg_IK_B.Em8000_settled_flag && (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0)))
  {
    sg_IK_DW.Em8000_settled_offset = 1.0;
  } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
    sg_IK_DW.Em8000_settled_offset = 0.65;
  } else {
    sg_IK_DW.Em8000_settled_offset = 0.0;
  }

  sg_IK_DW.X_Platform = 0.42;
  sg_IK_DW.Y_Platform = -1.57;
  sg_IK_DW.Z_Platform = 5.62 - sg_IK_DW.Em8000_settled_offset;
  sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
  sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_Platform;
  sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
  sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_Platform;
  sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
  sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_Platform;
  sg_IK_B.Traj_method = 2.0;
  sg_IK_B.v_max = 0.12;
  sg_IK_B.new_command++;
  sg_IK_B.Winch_Mode_selector = 1.0;
  sg_IK_B.Winch_PosRef_e = 3.2;
  sg_IK_B.FF_Flag = 0.0;
}

/* Function for Chart: '<S6>/Chart' */
static void sg_IK_enter_atomic_Go_home(void)
{
  /* Entry 'Go_home': '<S162>:16' */
  if (sg_IK_B.Em8000_settled_flag && (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0)))
  {
    sg_IK_DW.Em8000_settled_offset = 1.0;
  } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
    sg_IK_DW.Em8000_settled_offset = 0.65;
  } else {
    sg_IK_DW.Em8000_settled_offset = 0.0;
  }

  sg_IK_DW.X_home = -0.9;
  sg_IK_DW.Y_home = -1.3;
  sg_IK_DW.Z_home = 5.9 - sg_IK_DW.Em8000_settled_offset;
  sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
  sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_home;
  sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
  sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_home;
  sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
  sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_home;
  sg_IK_B.Traj_method = 2.0;
  sg_IK_B.v_max = 0.1;
  sg_IK_B.new_command++;
  sg_IK_B.Winch_PosRef_e = 10.0;
  sg_IK_B.Winch_Mode_selector = 1.0;
  sg_IK_B.FF_Flag = 0.0;
}

/* Function for Chart: '<S6>/Chart' */
static void sg_IK_Hook_Ball(void)
{
  /* During 'Hook_Ball': '<S162>:43' */
  if (sg_IK_B.MS_Switch == 2.0) {
    /* Transition: '<S162>:56' */
    /* Exit Internal 'Hook_Ball': '<S162>:43' */
    sg_IK_DW.is_Hook_Ball = 0U;
    sg_IK_DW.is_Manual_State_Switch_Mode = IN_Move_to_above_platform_PickU;
    enter_atomic_Move_to_above_plat();
  } else if (sg_IK_B.MS_Switch == 1.0) {
    /* Transition: '<S162>:79' */
    /* Exit Internal 'Hook_Ball': '<S162>:43' */
    sg_IK_DW.is_Hook_Ball = 0U;
    sg_IK_DW.is_Manual_State_Switch_Mode = sg_IK_IN_Go_home;
    sg_IK_enter_atomic_Go_home();
  } else if (sg_IK_B.MS_Switch == 0.0) {
    /* Transition: '<S162>:78' */
    /* Exit Internal 'Hook_Ball': '<S162>:43' */
    sg_IK_DW.is_Hook_Ball = 0U;
    sg_IK_DW.is_Manual_State_Switch_Mode = sg__IN_Stay_in_current_position;

    /* Entry 'Stay_in_current_position': '<S162>:12' */
    sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
    sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
    sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
    sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
    sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
    sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
    sg_IK_B.Traj_method = 1.0;
    sg_IK_B.v_max = 0.0;
    sg_IK_B.new_command++;
    sg_IK_B.FF_Flag = 0.0;
    sg_IK_B.Winch_PosRef_e = 10.0;
    sg_IK_B.Winch_Mode_selector = 1.0;
  } else {
    switch (sg_IK_DW.is_Hook_Ball) {
     case sg_IK_IN_Ball_In_Frame:
      /* During 'Ball_In_Frame': '<S162>:50' */
      if (sg_IK_DW.Sub_stage_switch == 1.0) {
        /* Transition: '<S162>:54' */
        sg_IK_DW.is_Hook_Ball = sg_IK_IN_Move_Close_To_Ball;
        sg_IK_DW.temporalCounter_i1 = 0U;

        /* Entry 'Move_Close_To_Ball': '<S162>:52' */
        sg_IK_DW.Z_Offset = 0.15;
        sg_IK_DW.r_Offset = 0.15;
        sg_IK_DW.delta_xy[0] = sg_IK_B.Endeff_world_xyz[0] -
          sg_IK_B.p_Ball_space[0];
        sg_IK_DW.delta_xy[1] = sg_IK_B.Endeff_world_xyz[1] -
          sg_IK_B.p_Ball_space[1];
        sg_IK_DW.norm_delta = sg_IK_norm_cd(sg_IK_DW.delta_xy);
        if (sg_IK_DW.norm_delta < 1.0E-6) {
          sg_IK_DW.Target_Pos_X = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_DW.Target_Pos_Y = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.v_max = 0.0;
        } else {
          sg_IK_DW.unit_delta[0] = sg_IK_DW.delta_xy[0] / sg_IK_DW.norm_delta;
          sg_IK_DW.unit_delta[1] = sg_IK_DW.delta_xy[1] / sg_IK_DW.norm_delta;
          sg_IK_DW.Target_Pos_X = sg_IK_DW.r_Offset * sg_IK_DW.unit_delta[0] +
            sg_IK_B.p_Ball_space[0];
          sg_IK_DW.Target_Pos_Y = sg_IK_DW.r_Offset * sg_IK_DW.unit_delta[1] +
            sg_IK_B.p_Ball_space[1];
          sg_IK_B.v_max = 0.05;
        }

        sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
        sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.Target_Pos_X;
        sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
        sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Target_Pos_Y;
        sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
        sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
        sg_IK_B.Traj_method = 2.0;
        sg_IK_B.new_command++;
        sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2] - sg_IK_DW.Z_Offset;
        sg_IK_B.FF_Flag = 1.0;
      } else if (sg_IK_B.bBall_InFrame) {
        sg_IK_DW.Sub_stage_switch = 1.0;
      }
      break;

     case sg_IK_IN_Lift_Up:
      /* During 'Lift_Up': '<S162>:72' */
      break;

     case sg_IK_IN_Move_Close_To_Ball:
      {
        boolean_T out;

        /* During 'Move_Close_To_Ball': '<S162>:52' */
        out = ((sg_IK_DW.Sub_stage_switch == 2.0) &&
               (sg_IK_DW.temporalCounter_i1 >= 1000U));
        if (out) {
          /* Transition: '<S162>:70' */
          sg_IK_DW.is_Hook_Ball = sg_IK_IN_Move_in_to_ball;

          /* Entry 'Move_in_to_ball': '<S162>:69' */
          sg_IK_DW.Z_Offset = 0.07;
          sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.p_Ball_space[0];
          sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.p_Ball_space[1] + 0.04;
          sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_method = 2.0;
          sg_IK_B.v_max = 0.02;
          sg_IK_B.new_command++;
          sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2];
          sg_IK_B.FF_Flag = 1.0;
        } else {
          sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2] - sg_IK_DW.Z_Offset;
          if (!sg_IK_B.Memory2) {
            sg_IK_DW.Sub_stage_switch = 2.0;
          } else {
            sg_IK_DW.Sub_stage_switch = 1.0;
          }
        }
      }
      break;

     default:
      /* During 'Move_in_to_ball': '<S162>:69' */
      if (sg_IK_DW.Sub_stage_switch == 3.0) {
        /* Transition: '<S162>:73' */
        sg_IK_DW.is_Hook_Ball = sg_IK_IN_Lift_Up;

        /* Entry 'Lift_Up': '<S162>:72' */
        sg_IK_B.FF_Flag = 0.0;
        sg_IK_B.Winch_PosRef_e = 10.0;
      } else {
        sg_IK_B.Winch_PosRef_e = sg_IK_B.p_Ball_space[2] - sg_IK_DW.Z_Offset;
        if (!sg_IK_B.Memory2) {
          sg_IK_DW.Sub_stage_switch = 3.0;
        } else {
          sg_IK_DW.Sub_stage_switch = 2.0;
        }
      }
      break;
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S7>/Trajectory_planner' */
static void sg_IK_quinticTrajectoryPlanner(real_T t, real_T T, real_T P0, real_T
  Pf, real_T *pos, real_T *vel, real_T *acc)
{
  real_T A[9];
  real_T B[3];
  real_T a21;
  real_T coeff_idx_0;
  real_T maxval;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  if (t < 0.0) {
    t = 0.0;
  } else if (t > T) {
    t = T;
  }

  maxval = rt_powd_snf(T, 3.0);
  a21 = rt_powd_snf(T, 4.0);
  coeff_idx_0 = rt_powd_snf(T, 5.0);
  tmp = rt_powd_snf(T, 3.0);
  tmp_0 = rt_powd_snf(T, 4.0);
  tmp_1 = rt_powd_snf(T, 3.0);
  A[0] = maxval;
  A[3] = a21;
  A[6] = coeff_idx_0;
  A[1] = T * T * 3.0;
  A[4] = 4.0 * tmp;
  A[7] = 5.0 * tmp_0;
  A[2] = 6.0 * T;
  A[5] = T * T * 12.0;
  A[8] = 20.0 * tmp_1;
  B[0] = Pf - ((0.0 * T + P0) + T * T * 0.0);
  B[1] = 0.0 - 0.0 * T;
  B[2] = 0.0;
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(A[0]);
  a21 = std::abs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (std::abs(A[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] /= A[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (std::abs(A[r3 + 3]) > std::abs(A[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  maxval = B[r2] - B[r1] * A[r2];
  a21 = (B[r3] - B[r1] * A[r3]) - A[r3 + 3] * maxval;
  a21 /= A[r3 + 6];
  coeff_idx_0 = B[r1] - A[r1 + 6] * a21;
  maxval -= A[r2 + 6] * a21;
  maxval /= A[r2 + 3];
  coeff_idx_0 -= A[r1 + 3] * maxval;
  coeff_idx_0 /= A[r1];
  *pos = ((((0.0 * t + P0) + t * t * 0.0) + coeff_idx_0 * rt_powd_snf(t, 3.0)) +
          maxval * rt_powd_snf(t, 4.0)) + a21 * rt_powd_snf(t, 5.0);
  *vel = ((3.0 * coeff_idx_0 * (t * t) + 0.0 * t) + 4.0 * maxval * rt_powd_snf(t,
           3.0)) + 5.0 * a21 * rt_powd_snf(t, 4.0);
  *acc = (6.0 * coeff_idx_0 * t + 12.0 * maxval * (t * t)) + 20.0 * a21 *
    rt_powd_snf(t, 3.0);
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static real_T sg_IK_xnrm2(int32_T n, const real_T x[30], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (int32_T k = ix0; k <= kend; k++) {
    real_T absxk;
    absxk = std::abs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xscal(int32_T n, real_T a, real_T x[30], int32_T ix0)
{
  int32_T b;
  b = (ix0 + n) - 1;
  for (int32_T k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static real_T sg_IK_xnrm2_f(int32_T n, const real_T x[5], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (int32_T k = ix0; k <= kend; k++) {
    real_T absxk;
    absxk = std::abs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * std::sqrt(y);
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xscal_e(int32_T n, real_T a, real_T x[5], int32_T ix0)
{
  int32_T b;
  b = (ix0 + n) - 1;
  for (int32_T k = ix0; k <= b; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xaxpy_gf(int32_T n, real_T a, const real_T x[6], int32_T ix0,
  real_T y[30], int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T ix;
    int32_T iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (int32_T k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xaxpy_g(int32_T n, real_T a, const real_T x[30], int32_T ix0,
  real_T y[6], int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T ix;
    int32_T iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (int32_T k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static real_T sg_IK_xdotc(int32_T n, const real_T x[30], int32_T ix0, const
  real_T y[30], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (int32_T k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[30], int32_T
  iy0)
{
  if (!(a == 0.0)) {
    int32_T ix;
    int32_T iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (int32_T k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static real_T sg_IK_xdotc_p(int32_T n, const real_T x[25], int32_T ix0, const
  real_T y[25], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  ix = ix0;
  iy = iy0;
  d = 0.0;
  for (int32_T k = 0; k < n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xaxpy_gf2(int32_T n, real_T a, int32_T ix0, real_T y[25],
  int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T ix;
    int32_T iy;
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (int32_T k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xscal_eu(real_T a, real_T x[30], int32_T ix0)
{
  for (int32_T k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xscal_euh(real_T a, real_T x[25], int32_T ix0)
{
  for (int32_T k = ix0; k <= ix0 + 4; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xswap(real_T x[25], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (int32_T k = 0; k < 5; k++) {
    real_T temp;
    temp = x[ix + k];
    x[ix + k] = x[iy + k];
    x[iy + k] = temp;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xswap_o(real_T x[30], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (int32_T k = 0; k < 6; k++) {
    real_T temp;
    temp = x[ix + k];
    x[ix + k] = x[iy + k];
    x[iy + k] = temp;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = std::abs(*a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xrot(real_T x[25], int32_T ix0, int32_T iy0, real_T c, real_T
  s)
{
  int32_T ix;
  int32_T iy;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (int32_T k = 0; k < 5; k++) {
    real_T temp;
    temp = x[ix + k] * c + x[iy + k] * s;
    x[iy + k] = x[iy + k] * c - x[ix + k] * s;
    x[ix + k] = temp;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_xrot_l(real_T x[30], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  int32_T ix;
  int32_T iy;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (int32_T k = 0; k < 6; k++) {
    real_T temp;
    temp = x[ix + k] * c + x[iy + k] * s;
    x[iy + k] = x[iy + k] * c - x[ix + k] * s;
    x[ix + k] = temp;
  }
}

/* Function for MATLAB Function: '<S5>/IVK_solver' */
static void sg_IK_svd(const real_T A[30], real_T U[30], real_T s[5], real_T V[25])
{
  real_T b_A[30];
  real_T Vf[25];
  real_T work[6];
  real_T b_s[5];
  real_T e[5];
  real_T nrm;
  real_T rt;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T i;
  int32_T qjj;
  int32_T qp1jj;
  int32_T qp1q;
  int32_T qq;
  std::memcpy(&b_A[0], &A[0], 30U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    b_s[i] = 0.0;
    e[i] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    work[i] = 0.0;
  }

  for (i = 0; i < 30; i++) {
    U[i] = 0.0;
  }

  for (i = 0; i < 25; i++) {
    Vf[i] = 0.0;
  }

  for (i = 0; i < 5; i++) {
    boolean_T apply_transform;
    qq = 6 * i + i;
    apply_transform = false;
    nrm = sg_IK_xnrm2(6 - i, b_A, qq + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq] < 0.0) {
        b_s[i] = -nrm;
      } else {
        b_s[i] = nrm;
      }

      if (std::abs(b_s[i]) >= 1.0020841800044864E-292) {
        sg_IK_xscal(6 - i, 1.0 / b_s[i], b_A, qq + 1);
      } else {
        qp1q = (qq - i) + 6;
        for (qjj = qq; qjj < qp1q; qjj++) {
          b_A[qjj] /= b_s[i];
        }
      }

      b_A[qq]++;
      b_s[i] = -b_s[i];
    } else {
      b_s[i] = 0.0;
    }

    for (qp1q = i + 1; qp1q + 1 < 6; qp1q++) {
      qjj = 6 * qp1q + i;
      if (apply_transform) {
        sg_IK_xaxpy(6 - i, -(sg_IK_xdotc(6 - i, b_A, qq + 1, b_A, qjj + 1) /
                             b_A[i + 6 * i]), qq + 1, b_A, qjj + 1);
      }

      e[qp1q] = b_A[qjj];
    }

    for (qq = i; qq + 1 < 7; qq++) {
      U[qq + 6 * i] = b_A[6 * i + qq];
    }

    if (i + 1 <= 3) {
      nrm = sg_IK_xnrm2_f(4 - i, e, i + 2);
      if (nrm == 0.0) {
        e[i] = 0.0;
      } else {
        if (e[i + 1] < 0.0) {
          e[i] = -nrm;
        } else {
          e[i] = nrm;
        }

        nrm = e[i];
        if (std::abs(e[i]) >= 1.0020841800044864E-292) {
          sg_IK_xscal_e(4 - i, 1.0 / e[i], e, i + 2);
        } else {
          for (qq = i + 1; qq < 5; qq++) {
            e[qq] /= nrm;
          }
        }

        e[i + 1]++;
        e[i] = -e[i];
        for (qq = i + 1; qq + 1 < 7; qq++) {
          work[qq] = 0.0;
        }

        for (qq = i + 1; qq + 1 < 6; qq++) {
          sg_IK_xaxpy_g(5 - i, e[qq], b_A, (i + 6 * qq) + 2, work, i + 2);
        }

        for (qq = i + 1; qq + 1 < 6; qq++) {
          sg_IK_xaxpy_gf(5 - i, -e[qq] / e[i + 1], work, i + 2, b_A, (i + 6 * qq)
                         + 2);
        }
      }

      for (qq = i + 1; qq + 1 < 6; qq++) {
        Vf[qq + 5 * i] = e[qq];
      }
    }
  }

  i = 3;
  e[3] = b_A[27];
  e[4] = 0.0;
  for (qp1q = 4; qp1q >= 0; qp1q--) {
    qq = 6 * qp1q + qp1q;
    if (b_s[qp1q] != 0.0) {
      for (qp1jj = qp1q + 1; qp1jj + 1 < 6; qp1jj++) {
        qjj = (6 * qp1jj + qp1q) + 1;
        sg_IK_xaxpy(6 - qp1q, -(sg_IK_xdotc(6 - qp1q, U, qq + 1, U, qjj) / U[qq]),
                    qq + 1, U, qjj);
      }

      for (qjj = qp1q; qjj + 1 < 7; qjj++) {
        U[qjj + 6 * qp1q] = -U[6 * qp1q + qjj];
      }

      U[qq]++;
      for (qq = 0; qq < qp1q; qq++) {
        U[qq + 6 * qp1q] = 0.0;
      }
    } else {
      for (qjj = 0; qjj < 6; qjj++) {
        U[qjj + 6 * qp1q] = 0.0;
      }

      U[qq] = 1.0;
    }
  }

  for (qq = 4; qq >= 0; qq--) {
    if ((qq + 1 <= 3) && (e[qq] != 0.0)) {
      qp1q = (5 * qq + qq) + 2;
      for (qjj = qq + 1; qjj + 1 < 6; qjj++) {
        qp1jj = (5 * qjj + qq) + 2;
        sg_IK_xaxpy_gf2(4 - qq, -(sg_IK_xdotc_p(4 - qq, Vf, qp1q, Vf, qp1jj) /
          Vf[qp1q - 1]), qp1q, Vf, qp1jj);
      }
    }

    for (qp1q = 0; qp1q < 5; qp1q++) {
      Vf[qp1q + 5 * qq] = 0.0;
    }

    Vf[qq + 5 * qq] = 1.0;
  }

  for (qq = 0; qq < 5; qq++) {
    ztest = e[qq];
    if (b_s[qq] != 0.0) {
      rt = std::abs(b_s[qq]);
      nrm = b_s[qq] / rt;
      b_s[qq] = rt;
      if (qq + 1 < 5) {
        ztest /= nrm;
      }

      sg_IK_xscal_eu(nrm, U, 6 * qq + 1);
    }

    if ((qq + 1 < 5) && (ztest != 0.0)) {
      rt = std::abs(ztest);
      nrm = rt / ztest;
      ztest = rt;
      b_s[qq + 1] *= nrm;
      sg_IK_xscal_euh(nrm, Vf, 5 * (qq + 1) + 1);
    }

    e[qq] = ztest;
  }

  qq = 0;
  nrm = 0.0;
  for (qp1q = 0; qp1q < 5; qp1q++) {
    ztest = std::abs(b_s[qp1q]);
    rt = std::abs(e[qp1q]);
    if ((ztest >= rt) || rtIsNaN(rt)) {
      rt = ztest;
    }

    if ((!(nrm >= rt)) && (!rtIsNaN(rt))) {
      nrm = rt;
    }
  }

  while ((i + 2 > 0) && (qq < 75)) {
    qp1jj = i + 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      qp1q = qp1jj;
      if (qp1jj == 0) {
        exitg1 = 1;
      } else {
        rt = std::abs(e[qp1jj - 1]);
        if ((rt <= (std::abs(b_s[qp1jj - 1]) + std::abs(b_s[qp1jj])) *
             2.2204460492503131E-16) || ((rt <= 1.0020841800044864E-292) || ((qq
               > 20) && (rt <= 2.2204460492503131E-16 * nrm)))) {
          e[qp1jj - 1] = 0.0;
          exitg1 = 1;
        } else {
          qp1jj--;
        }
      }
    } while (exitg1 == 0);

    if (i + 1 == qp1jj) {
      qp1jj = 4;
    } else {
      int32_T j_ii;
      boolean_T exitg2;
      qjj = i + 2;
      j_ii = i + 2;
      exitg2 = false;
      while ((!exitg2) && (j_ii >= qp1jj)) {
        qjj = j_ii;
        if (j_ii == qp1jj) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (j_ii < i + 2) {
            rt = std::abs(e[j_ii - 1]);
          }

          if (j_ii > qp1jj + 1) {
            rt += std::abs(e[j_ii - 2]);
          }

          ztest = std::abs(b_s[j_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[j_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            j_ii--;
          }
        }
      }

      if (qjj == qp1jj) {
        qp1jj = 3;
      } else if (i + 2 == qjj) {
        qp1jj = 1;
      } else {
        qp1jj = 2;
        qp1q = qjj;
      }
    }

    switch (qp1jj) {
     case 1:
      rt = e[i];
      e[i] = 0.0;
      for (qjj = i; qjj + 1 >= qp1q + 1; qjj--) {
        sg_IK_xrotg(&b_s[qjj], &rt, &ztest, &sqds);
        if (qjj + 1 > qp1q + 1) {
          rt = e[qjj - 1] * -sqds;
          e[qjj - 1] *= ztest;
        }

        sg_IK_xrot(Vf, 5 * qjj + 1, 5 * (i + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[qp1q - 1];
      e[qp1q - 1] = 0.0;
      for (qjj = qp1q; qjj < i + 2; qjj++) {
        sg_IK_xrotg(&b_s[qjj], &rt, &ztest, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        sg_IK_xrot_l(U, 6 * qjj + 1, 6 * (qp1q - 1) + 1, ztest, sqds);
      }
      break;

     case 3:
      {
        real_T emm1;
        real_T shift;
        ztest = std::abs(b_s[i + 1]);
        rt = std::abs(b_s[i]);
        if ((ztest >= rt) || rtIsNaN(rt)) {
          rt = ztest;
        }

        ztest = std::abs(e[i]);
        if ((rt >= ztest) || rtIsNaN(ztest)) {
          ztest = rt;
        }

        rt = std::abs(b_s[qp1q]);
        if ((ztest >= rt) || rtIsNaN(rt)) {
          rt = ztest;
        }

        ztest = std::abs(e[qp1q]);
        if ((rt >= ztest) || rtIsNaN(ztest)) {
          ztest = rt;
        }

        rt = b_s[i + 1] / ztest;
        smm1 = b_s[i] / ztest;
        emm1 = e[i] / ztest;
        sqds = b_s[qp1q] / ztest;
        smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
        emm1 *= rt;
        emm1 *= emm1;
        if ((smm1 != 0.0) || (emm1 != 0.0)) {
          shift = std::sqrt(smm1 * smm1 + emm1);
          if (smm1 < 0.0) {
            shift = -shift;
          }

          shift = emm1 / (smm1 + shift);
        } else {
          shift = 0.0;
        }

        rt = (sqds + rt) * (sqds - rt) + shift;
        ztest = e[qp1q] / ztest * sqds;
        for (qjj = qp1q + 1; qjj <= i + 1; qjj++) {
          sg_IK_xrotg(&rt, &ztest, &sqds, &smm1);
          if (qjj > qp1q + 1) {
            e[qjj - 2] = rt;
          }

          rt = b_s[qjj - 1] * sqds + e[qjj - 1] * smm1;
          e[qjj - 1] = e[qjj - 1] * sqds - b_s[qjj - 1] * smm1;
          ztest = smm1 * b_s[qjj];
          b_s[qjj] *= sqds;
          sg_IK_xrot(Vf, 5 * (qjj - 1) + 1, 5 * qjj + 1, sqds, smm1);
          b_s[qjj - 1] = rt;
          sg_IK_xrotg(&b_s[qjj - 1], &ztest, &sqds, &smm1);
          rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
          b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
          ztest = smm1 * e[qjj];
          e[qjj] *= sqds;
          sg_IK_xrot_l(U, 6 * (qjj - 1) + 1, 6 * qjj + 1, sqds, smm1);
        }

        e[i] = rt;
        qq++;
      }
      break;

     default:
      if (b_s[qp1q] < 0.0) {
        b_s[qp1q] = -b_s[qp1q];
        sg_IK_xscal_euh(-1.0, Vf, 5 * qp1q + 1);
      }

      qq = qp1q + 1;
      while ((qp1q + 1 < 5) && (b_s[qp1q] < b_s[qq])) {
        rt = b_s[qp1q];
        b_s[qp1q] = b_s[qq];
        b_s[qq] = rt;
        sg_IK_xswap(Vf, 5 * qp1q + 1, 5 * (qp1q + 1) + 1);
        sg_IK_xswap_o(U, 6 * qp1q + 1, 6 * (qp1q + 1) + 1);
        qp1q = qq;
        qq++;
      }

      qq = 0;
      i--;
      break;
    }
  }

  for (i = 0; i < 5; i++) {
    s[i] = b_s[i];
    for (qq = 0; qq < 5; qq++) {
      V[qq + 5 * i] = Vf[5 * i + qq];
    }
  }
}

/* Model step function */
void sg_IK_step(void)
{
  b_dsp_FIRFilter_0_sg_IK_T *obj_3;
  b_dspcodegen_FIRFilter_sg_IK_T *obj_0;
  b_dspcodegen_FIRFilter_sg_IK_T *obj_1;
  b_dspcodegen_FIRFilter_sg_IK_T *obj_2;
  dsp_LowpassFilter_sg_IK_T *obj;
  real_T T_1[36];
  real_T A[30];
  real_T Jb_pinv[30];
  real_T U[30];
  real_T b_V[25];
  real_T T[16];
  real_T T_0[16];
  real_T T_w_c[16];
  real_T a[16];
  real_T g_a[16];
  real_T R_cam[9];
  real_T R_pBody[9];
  real_T R_pBody_0[9];
  real_T b_a_0[9];
  real_T b_omgmat[9];
  real_T b_omgmat_0[9];
  real_T omgmat[9];
  real_T T_2[6];
  real_T V[6];
  real_T s[5];
  real_T T_w_c_0[4];
  real_T matrix[4];
  real_T omgtheta[3];
  real_T a2;
  real_T a3;
  real_T a__6;
  real_T c_a2;
  real_T c_a3;
  real_T cy;
  real_T local_tf;
  real_T x_pos;
  real_T x_vel;
  real_T yaw;
  int32_T ar;
  int32_T c;
  int32_T i;
  int32_T ib;
  int32_T idx;
  int32_T vcol;
  int8_T b_I[9];
  int8_T b_a[9];
  boolean_T bClawInFrame;
  boolean_T wasTunablePropsChanged;
  static const real_T g_a_0[16] = { -0.0033201733081971163, 0.99999438683469843,
    0.00045027580353880909, 0.0, 0.99999429549546315, 0.0033198927854635185,
    0.00062232501604574933, 0.0, 0.0006208266554409256, 0.00045233946184574324,
    -0.9999997049815943, 0.0, -2.9696616227022652, 1.976311036084776,
    2.6628450155926142, 1.0 };

  static const real_T b_b[16] = { -0.49716724243009747, 0.86764746505320345,
    0.0035509774996006884, 0.0, 0.86764051357801664, 0.49717836120759562,
    -0.0036900331983521608, 0.0, -0.004967117124448933, 0.0012464083117572659,
    -0.999986887020921, 0.0, -1.0820240997479491, 1.536041691521612,
    -1.0244614487807751, 1.0 };

  static const real_T g[3] = { -0.1, -0.03, -0.5 };

  static const real_T a_0[16] = { -6.123233995736766E-17, -1.0,
    7.498798913309288E-33, 0.0, -1.0, 6.123233995736766E-17,
    1.2246467991473532E-16, 0.0, -1.2246467991473532E-16, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.0, 1.0 };

  static const real_T g_a_1[16] = { -0.0033201733081971163, 0.99999438683469843,
    0.00045027580353880909, 0.0, 0.99999429549546315, 0.0033198927854635185,
    0.00062232501604574933, 0.0, 0.0006208266554409256, 0.00045233946184574324,
    -0.9999997049815943, 0.0, -2.9696616227022652, 1.976311036084776,
    3.3128450155926141, 1.0 };

  static const real_T c_b[16] = { -0.49716724243009747, 0.86764746505320345,
    0.0035509774996006884, 0.0, 0.86764051357801664, 0.49717836120759562,
    -0.0036900331983521608, 0.0, -0.004967117124448933, 0.0012464083117572659,
    -0.999986887020921, 0.0, -1.0820240997479491, 1.536041691521612, -0.3, 1.0 };

  static const real_T g_0[3] = { -1.5707963267948966, -0.78539816339744828,
    -1.9198621771937625 };

  static const real_T h[3] = { 1.6580627893946132, 0.52359877559829882,
    -0.78539816339744828 };

  int32_T T_w_c_size[3];
  int32_T T_w_c_size_0[3];
  int32_T T_w_c_size_1[3];
  int32_T tmp_size[3];
  boolean_T exitg1;
  boolean_T guard1 = false;

  /* Delay: '<S3>/Delay' */
  sg_IK_B.Delay = sg_IK_DW.Delay_DSTATE;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  sg_IK_B.Add = sg_IK_B.Delay + sg_IK_cal->Constant1_Value_o;

  /* Constant: '<S1>/controlMode' */
  sg_IK_B.controlMode = sg_IK_cal->controlMode;

  /* S-Function (slrealtimeUDPReceive): '<S2>/UDP Receive' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = reinterpret_cast<slrealtime::ip::
        udp::Socket*>(sg_IK_DW.UDPReceive_PWORK[0]);
      char *buffer = (char *)sg_IK_DW.UDPReceive_PWORK[1];
      memset(buffer,0,304);
      void *dataPort = &sg_IK_B.UDPReceive_o1[0];
      int_T numBytesAvail = (int_T)(udpSock->bytesToRead());
      if (numBytesAvail > 0) {
        uint8_t* fmAddArg = (uint8_t *)sg_IK_cal->UDPReceive_fmAddress;
        size_t num_bytesRcvd = (size_t)(udpSock->receive(buffer,( numBytesAvail<
          65504 )? numBytesAvail:65504, !1,fmAddArg));
        if (num_bytesRcvd == 0) {
          sg_IK_B.UDPReceive_o2 = 0;
        } else {
          sg_IK_B.UDPReceive_o2 = (double)num_bytesRcvd;
          memcpy(dataPort,(void*)buffer,304);
        }
      } else {
        sg_IK_B.UDPReceive_o2 = 0;
      }
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_IK_M, eMsg.c_str());
      rtmSetStopRequested(sg_IK_M, 1);
      ;
    }
  }

  /* S-Function (slrealtimebytepacking): '<S2>/Byte Unpacking' */

  /* Byte Unpacking: <S2>/Byte Unpacking */
  (void)memcpy((uint8_T*)&sg_IK_B.eMode, (uint8_T*)&sg_IK_B.UDPReceive_o1[0] + 0,
               4);
  (void)memcpy((uint8_T*)&sg_IK_B.PLC_time, (uint8_T*)&sg_IK_B.UDPReceive_o1[0]
               + 4, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.Comau_theta[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 8, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Comau_theta_vel[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 32, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Winch, (uint8_T*)&sg_IK_B.UDPReceive_o1[0] +
               56, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.Winch_vel, (uint8_T*)&sg_IK_B.UDPReceive_o1[0]
               + 60, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.Em8000_transpos_and_rpy[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 64, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em8000_transvel_and_rpyvel[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 88, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em8000_tranacc_and_rpyacc[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 112, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em8000_MRU_transpos_and_rpy[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 136, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em8000_MRU_transvel_and_rpyvel[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 160, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em1500_transpos_and_rpy[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 184, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em1500_transvel_and_rpyvel[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 208, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em1500_tranacc_and_rpyacc[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 232, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em1500_MRU_transpos_and_rpy[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 256, 24);
  (void)memcpy((uint8_T*)&sg_IK_B.Em1500_MRU_transvel_and_rpyvel[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1[0] + 280, 24);
  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion4' */
    sg_IK_B.DataTypeConversion4[i] = sg_IK_B.Em8000_transpos_and_rpy[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion5' */
    sg_IK_B.DataTypeConversion5[i] = sg_IK_B.Em8000_transvel_and_rpyvel[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion14' */
    sg_IK_B.DataTypeConversion14[i] = sg_IK_B.Comau_theta[i];
  }

  /* Sum: '<S159>/Sum' incorporates:
   *  Constant: '<S159>/Constant8'
   */
  sg_IK_B.Sum = sg_IK_B.DataTypeConversion14[2] + sg_IK_cal->Constant8_Value;

  /* Sum: '<S159>/Sum3' */
  sg_IK_B.Sum3 = sg_IK_B.Sum + sg_IK_B.DataTypeConversion14[1];

  /* Constant: '<S159>/Constant' */
  sg_IK_B.Constant = sg_IK_cal->Constant_Value;

  /* Constant: '<S159>/Constant1' */
  sg_IK_B.Constant1 = sg_IK_cal->Constant1_Value;

  /* SignalConversion generated from: '<S161>/ SFunction ' incorporates:
   *  MATLAB Function: '<S157>/FK_solver'
   */
  sg_IK_B.TmpSignalConversionAtSFunctio_a[0] = sg_IK_B.DataTypeConversion14[0];
  sg_IK_B.TmpSignalConversionAtSFunctio_a[1] = sg_IK_B.DataTypeConversion14[1];
  sg_IK_B.TmpSignalConversionAtSFunctio_a[2] = sg_IK_B.Sum3;
  sg_IK_B.TmpSignalConversionAtSFunctio_a[3] = sg_IK_B.Constant;
  sg_IK_B.TmpSignalConversionAtSFunctio_a[4] = sg_IK_B.Constant1;

  /* MATLAB Function: '<S157>/FK_solver' incorporates:
   *  Constant: '<S157>/Constant3'
   *  Constant: '<S157>/Constant4'
   */
  std::memcpy(&sg_IK_B.T_b_ee[0], &sg_IK_cal->M[0], sizeof(real_T) << 4U);

  /* MATLAB Function 'Controller/Inverse velocity and forward kinematics/Forward kinematics/FK_solver': '<S161>:1' */
  /* '<S161>:1:33' */
  /* '<S161>:1:31' */
  /* '<S161>:1:37' */
  /* '<S161>:1:4' */
  T_w_c[0] = 0.0;
  T_w_c[5] = 0.0;
  T_w_c[10] = 0.0;
  T_w_c[3] = 0.0;
  T_w_c[7] = 0.0;
  T_w_c[11] = 0.0;
  T_w_c[15] = 0.0;
  for (i = 0; i < 5; i++) {
    ar = 4 - i;
    local_tf = sg_IK_B.TmpSignalConversionAtSFunctio_a[4 - i];
    for (idx = 0; idx < 6; idx++) {
      V[idx] = sg_IK_cal->SList[6 * ar + idx] * local_tf;
    }

    T_w_c[4] = -V[2];
    T_w_c[8] = V[1];
    T_w_c[1] = V[2];
    T_w_c[9] = -V[0];
    T_w_c[2] = -V[1];
    T_w_c[6] = V[0];
    T_w_c[12] = V[3];
    T_w_c[13] = V[4];
    T_w_c[14] = V[5];
    omgtheta[0] = T_w_c[6];
    omgtheta[1] = T_w_c[8];
    omgtheta[2] = T_w_c[1];
    if (std::abs(sg_IK_norm(omgtheta)) < 1.0E-6) {
      for (ar = 0; ar < 9; ar++) {
        b_I[ar] = 0;
      }

      b_I[0] = 1;
      b_I[4] = 1;
      b_I[8] = 1;
      for (ar = 0; ar < 3; ar++) {
        a[ar << 2] = b_I[3 * ar];
        a[(ar << 2) + 1] = b_I[3 * ar + 1];
        a[(ar << 2) + 2] = b_I[3 * ar + 2];
        a[ar + 12] = T_w_c[ar + 12];
      }

      a[3] = 0.0;
      a[7] = 0.0;
      a[11] = 0.0;
      a[15] = 1.0;
    } else {
      cy = sg_IK_norm(omgtheta);
      for (ar = 0; ar < 3; ar++) {
        omgmat[3 * ar] = T_w_c[ar << 2] / cy;
        omgmat[3 * ar + 1] = T_w_c[(ar << 2) + 1] / cy;
        omgmat[3 * ar + 2] = T_w_c[(ar << 2) + 2] / cy;
      }

      for (ar = 0; ar < 9; ar++) {
        b_a[ar] = 0;
      }

      b_a[0] = 1;
      b_a[4] = 1;
      b_a[8] = 1;
      x_pos = 1.0 - std::cos(cy);
      local_tf = cy - std::sin(cy);
      omgtheta[0] = T_w_c[6];
      omgtheta[1] = T_w_c[8];
      omgtheta[2] = T_w_c[1];
      if (std::abs(sg_IK_norm(omgtheta)) < 1.0E-6) {
        for (ar = 0; ar < 9; ar++) {
          R_cam[ar] = 0.0;
        }

        R_cam[0] = 1.0;
        R_cam[4] = 1.0;
        R_cam[8] = 1.0;
      } else {
        a2 = sg_IK_norm(omgtheta);
        for (ar = 0; ar < 3; ar++) {
          b_omgmat[3 * ar] = T_w_c[ar << 2] / a2;
          b_omgmat[3 * ar + 1] = T_w_c[(ar << 2) + 1] / a2;
          b_omgmat[3 * ar + 2] = T_w_c[(ar << 2) + 2] / a2;
        }

        x_vel = std::sin(a2);
        a2 = 1.0 - std::cos(a2);
        for (ar = 0; ar < 9; ar++) {
          b_I[ar] = 0;
        }

        for (idx = 0; idx < 3; idx++) {
          b_I[idx + 3 * idx] = 1;
          for (ar = 0; ar < 3; ar++) {
            b_omgmat_0[idx + 3 * ar] = 0.0;
            yaw = b_omgmat_0[3 * ar + idx];
            yaw += b_omgmat[3 * ar] * b_omgmat[idx];
            b_omgmat_0[idx + 3 * ar] = yaw;
            yaw = b_omgmat_0[3 * ar + idx];
            yaw += b_omgmat[3 * ar + 1] * b_omgmat[idx + 3];
            b_omgmat_0[idx + 3 * ar] = yaw;
            yaw = b_omgmat_0[3 * ar + idx];
            yaw += b_omgmat[3 * ar + 2] * b_omgmat[idx + 6];
            b_omgmat_0[idx + 3 * ar] = yaw;
          }
        }

        for (ar = 0; ar < 9; ar++) {
          R_cam[ar] = (x_vel * b_omgmat[ar] + static_cast<real_T>(b_I[ar])) + a2
            * b_omgmat_0[ar];
        }
      }

      for (ar = 0; ar < 3; ar++) {
        for (idx = 0; idx < 3; idx++) {
          b_omgmat_0[ar + 3 * idx] = 0.0;
          a2 = b_omgmat_0[3 * idx + ar];
          a2 += omgmat[3 * idx] * omgmat[ar];
          b_omgmat_0[ar + 3 * idx] = a2;
          a2 = b_omgmat_0[3 * idx + ar];
          a2 += omgmat[3 * idx + 1] * omgmat[ar + 3];
          b_omgmat_0[ar + 3 * idx] = a2;
          a2 = b_omgmat_0[3 * idx + ar];
          a2 += omgmat[3 * idx + 2] * omgmat[ar + 6];
          b_omgmat_0[ar + 3 * idx] = a2;
        }
      }

      for (ar = 0; ar < 9; ar++) {
        b_a_0[ar] = (static_cast<real_T>(b_a[ar]) * cy + x_pos * omgmat[ar]) +
          local_tf * b_omgmat_0[ar];
      }

      for (ar = 0; ar < 3; ar++) {
        local_tf = b_a_0[ar] * T_w_c[12];
        a[ar << 2] = R_cam[3 * ar];
        local_tf += b_a_0[ar + 3] * T_w_c[13];
        a[(ar << 2) + 1] = R_cam[3 * ar + 1];
        local_tf += b_a_0[ar + 6] * T_w_c[14];
        a[(ar << 2) + 2] = R_cam[3 * ar + 2];
        x_pos = local_tf / cy;
        a[ar + 12] = x_pos;
      }

      a[3] = 0.0;
      a[7] = 0.0;
      a[11] = 0.0;
      a[15] = 1.0;
    }

    for (ar = 0; ar < 4; ar++) {
      for (idx = 0; idx < 4; idx++) {
        T[ar + (idx << 2)] = 0.0;
        cy = T[(idx << 2) + ar];
        cy += sg_IK_B.T_b_ee[idx << 2] * a[ar];
        T[ar + (idx << 2)] = cy;
        cy = T[(idx << 2) + ar];
        cy += sg_IK_B.T_b_ee[(idx << 2) + 1] * a[ar + 4];
        T[ar + (idx << 2)] = cy;
        cy = T[(idx << 2) + ar];
        cy += sg_IK_B.T_b_ee[(idx << 2) + 2] * a[ar + 8];
        T[ar + (idx << 2)] = cy;
        cy = T[(idx << 2) + ar];
        cy += sg_IK_B.T_b_ee[(idx << 2) + 3] * a[ar + 12];
        T[ar + (idx << 2)] = cy;
      }
    }

    std::memcpy(&sg_IK_B.T_b_ee[0], &T[0], sizeof(real_T) << 4U);
  }

  /* '<S161>:1:6' */
  sg_IK_B.Endeff_local_xyz[0] = sg_IK_B.T_b_ee[12];
  sg_IK_B.Endeff_local_xyz[1] = sg_IK_B.T_b_ee[13];
  sg_IK_B.Endeff_local_xyz[2] = sg_IK_B.T_b_ee[14];

  /* '<S161>:1:8' */
  /* '<S161>:1:11' */
  cy = sg_IK_B.DataTypeConversion4[3];
  x_pos = sg_IK_B.DataTypeConversion4[4];
  local_tf = sg_IK_B.DataTypeConversion4[5];

  /* '<S161>:1:27' */
  x_vel = cy;
  a3 = x_vel;
  a3 = std::cos(a3);
  x_vel = std::sin(x_vel);
  cy = x_vel;
  omgtheta[0] = a3;
  x_vel = x_pos;
  a3 = x_vel;
  a3 = std::cos(a3);
  x_vel = std::sin(x_vel);
  x_pos = x_vel;
  omgtheta[1] = a3;
  x_vel = local_tf;
  a3 = x_vel;
  a3 = std::cos(a3);
  x_vel = std::sin(x_vel);
  local_tf = x_vel;
  omgtheta[2] = a3;
  R_pBody[0] = omgtheta[1] * omgtheta[2];
  R_pBody[3] = -omgtheta[1] * local_tf;
  R_pBody[6] = x_pos;
  R_pBody[1] = cy * omgtheta[2] * x_pos + omgtheta[0] * local_tf;
  R_pBody[4] = omgtheta[0] * omgtheta[2] - cy * x_pos * local_tf;
  R_pBody[7] = -omgtheta[1] * cy;
  R_pBody[2] = cy * local_tf - omgtheta[0] * omgtheta[2] * x_pos;
  R_pBody[5] = omgtheta[0] * x_pos * local_tf + cy * omgtheta[2];
  R_pBody[8] = omgtheta[0] * omgtheta[1];

  /* '<S161>:1:31' */
  /* '<S161>:1:33' */
  /* '<S161>:1:37' */
  /* '<S161>:1:39' */
  for (ar = 0; ar < 3; ar++) {
    T_w_c[ar << 2] = R_pBody[3 * ar];
    T_w_c[(ar << 2) + 1] = R_pBody[3 * ar + 1];
    T_w_c[(ar << 2) + 2] = R_pBody[3 * ar + 2];
  }

  T_w_c[12] = sg_IK_B.DataTypeConversion4[0];
  T_w_c[13] = sg_IK_B.DataTypeConversion4[1];
  T_w_c[14] = sg_IK_B.DataTypeConversion4[2];
  T_w_c[3] = 0.0;
  T_w_c[7] = 0.0;
  T_w_c[11] = 0.0;
  T_w_c[15] = 1.0;
  for (ar = 0; ar < 4; ar++) {
    for (idx = 0; idx < 4; idx++) {
      T[ar + (idx << 2)] = 0.0;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[idx << 2] * g_a_0[ar];
      T[ar + (idx << 2)] = cy;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[(idx << 2) + 1] * g_a_0[ar + 4];
      T[ar + (idx << 2)] = cy;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[(idx << 2) + 2] * g_a_0[ar + 8];
      T[ar + (idx << 2)] = cy;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[(idx << 2) + 3] * g_a_0[ar + 12];
      T[ar + (idx << 2)] = cy;
    }

    for (idx = 0; idx < 4; idx++) {
      g_a[ar + (idx << 2)] = 0.0;
      cy = g_a[(idx << 2) + ar];
      cy += b_b[idx << 2] * T[ar];
      g_a[ar + (idx << 2)] = cy;
      cy = g_a[(idx << 2) + ar];
      cy += b_b[(idx << 2) + 1] * T[ar + 4];
      g_a[ar + (idx << 2)] = cy;
      cy = g_a[(idx << 2) + ar];
      cy += b_b[(idx << 2) + 2] * T[ar + 8];
      g_a[ar + (idx << 2)] = cy;
      cy = g_a[(idx << 2) + ar];
      cy += b_b[(idx << 2) + 3] * T[ar + 12];
      g_a[ar + (idx << 2)] = cy;
    }

    for (idx = 0; idx < 4; idx++) {
      sg_IK_B.T_w_ee[ar + (idx << 2)] = 0.0;
      sg_IK_B.T_w_ee[ar + (idx << 2)] += sg_IK_B.T_b_ee[idx << 2] * g_a[ar];
      sg_IK_B.T_w_ee[ar + (idx << 2)] += sg_IK_B.T_b_ee[(idx << 2) + 1] * g_a[ar
        + 4];
      sg_IK_B.T_w_ee[ar + (idx << 2)] += sg_IK_B.T_b_ee[(idx << 2) + 2] * g_a[ar
        + 8];
      sg_IK_B.T_w_ee[ar + (idx << 2)] += sg_IK_B.T_b_ee[(idx << 2) + 3] * g_a[ar
        + 12];
    }
  }

  /* '<S161>:1:41' */
  sg_IK_B.Endeff_world_xyz[0] = sg_IK_B.T_w_ee[12];
  sg_IK_B.Endeff_world_xyz[1] = sg_IK_B.T_w_ee[13];
  sg_IK_B.Endeff_world_xyz[2] = sg_IK_B.T_w_ee[14];

  /* Constant: '<S163>/Constant' */
  sg_IK_B.Operation_Mode = sg_IK_cal->Operation_Mode;

  /* Constant: '<S6>/Constant' */
  sg_IK_B.Constant_f = sg_IK_cal->State_Mode_Selector;

  /* Constant: '<S6>/Constant4' */
  sg_IK_B.MS_Switch = sg_IK_cal->Manual_State_Switch;

  /* Constant: '<S6>/enable_65cm_offset_Em8000' */
  sg_IK_B.enable_65cm_offset_Em8000 = sg_IK_cal->enable_65cm_offset_Em8000_Value;

  /* S-Function (slrealtimeUDPReceive): '<S8>/UDP Receive' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = reinterpret_cast<slrealtime::ip::
        udp::Socket*>(sg_IK_DW.UDPReceive_PWORK_c[0]);
      char *buffer = (char *)sg_IK_DW.UDPReceive_PWORK_c[1];
      memset(buffer,0,29);
      void *dataPort = &sg_IK_B.UDPReceive_o1_i[0];
      int_T numBytesAvail = (int_T)(udpSock->bytesToRead());
      if (numBytesAvail > 0) {
        uint8_t* fmAddArg = (uint8_t *)sg_IK_cal->UDPReceive_fmAddress_o;
        size_t num_bytesRcvd = (size_t)(udpSock->receive(buffer,( numBytesAvail<
          65504 )? numBytesAvail:65504, !1,fmAddArg));
        if (num_bytesRcvd == 0) {
          sg_IK_B.UDPReceive_o2_c = 0;
        } else {
          sg_IK_B.UDPReceive_o2_c = (double)num_bytesRcvd;
          memcpy(dataPort,(void*)buffer,29);
        }
      } else {
        sg_IK_B.UDPReceive_o2_c = 0;
      }
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_IK_M, eMsg.c_str());
      rtmSetStopRequested(sg_IK_M, 1);
      ;
    }
  }

  /* S-Function (slrealtimebytepacking): '<S8>/Byte_Unpacking' */

  /* Byte Unpacking: <S8>/Byte_Unpacking */
  (void)memcpy((uint8_T*)&sg_IK_B.UDP_camera_detection[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1_i[0] + 0, 12);
  (void)memcpy((uint8_T*)&sg_IK_B.Byte_Unpacking_o2, (uint8_T*)
               &sg_IK_B.UDPReceive_o1_i[0] + 12, 1);
  (void)memcpy((uint8_T*)&sg_IK_B.UDP_camera_IMU[0], (uint8_T*)
               &sg_IK_B.UDPReceive_o1_i[0] + 13, 16);
  for (i = 0; i < 6; i++) {
    /* Gain: '<S8>/Gain' */
    sg_IK_B.Gain_k[i] = sg_IK_cal->Gain_Gain_l * sg_IK_B.UDP_camera_detection[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S8>/Cast To Double' incorporates:
     *  Gain: '<S8>/Gain'
     */
    sg_IK_B.CastToDouble[i] = static_cast<real_T>(sg_IK_B.Gain_k[i]) *
      5.9604644775390625E-8;
  }

  /* DataTypeConversion: '<S8>/Cast To Double1' */
  sg_IK_B.CastToDouble1[0] = sg_IK_B.UDP_camera_IMU[0];
  sg_IK_B.CastToDouble1[1] = sg_IK_B.UDP_camera_IMU[1];
  sg_IK_B.CastToDouble1[2] = sg_IK_B.UDP_camera_IMU[2];
  sg_IK_B.CastToDouble1[3] = sg_IK_B.UDP_camera_IMU[3];

  /* MATLAB Function: '<S8>/Camera_transform' */
  /* MATLAB Function 'Controller/UDP_Camera/Camera_transform': '<S167>:1' */
  /* '<S167>:1:55' */
  /* '<S167>:1:22' */
  /* '<S167>:1:35' */
  /* '<S167>:1:3' */
  /* '<S167>:1:4' */
  /* '<S167>:1:7' */
  /* '<S167>:1:11' */
  /* '<S167>:1:12' */
  local_tf = sg_IK_B.CastToDouble1[3];
  x_vel = sg_IK_B.CastToDouble1[0];
  a3 = sg_IK_B.CastToDouble1[1];
  yaw = sg_IK_B.CastToDouble1[2];
  matrix[0] = local_tf;
  matrix[1] = x_vel + 0.0160522;
  matrix[2] = a3 + 0.080932;
  matrix[3] = yaw + 0.0632324;

  /* '<S167>:1:14' */
  yaw = matrix[0];
  cy = yaw * yaw;
  yaw = matrix[1];
  x_pos = yaw * yaw;
  yaw = matrix[2];
  local_tf = yaw * yaw;
  yaw = matrix[3];
  x_vel = yaw * yaw;
  yaw = cy;
  yaw += x_pos;
  yaw += local_tf;
  yaw += x_vel;
  yaw = 1.0 / std::sqrt(yaw);
  cy = matrix[0] * yaw;
  x_pos = matrix[1] * yaw;
  local_tf = matrix[2] * yaw;
  x_vel = matrix[3] * yaw;
  R_cam[0] = 1.0 - (local_tf * local_tf + x_vel * x_vel) * 2.0;
  R_cam[1] = (x_pos * local_tf - cy * x_vel) * 2.0;
  R_cam[2] = (x_pos * x_vel + cy * local_tf) * 2.0;
  R_cam[3] = (x_pos * local_tf + cy * x_vel) * 2.0;
  R_cam[4] = 1.0 - (x_pos * x_pos + x_vel * x_vel) * 2.0;
  R_cam[5] = (local_tf * x_vel - cy * x_pos) * 2.0;
  R_cam[6] = (x_pos * x_vel - cy * local_tf) * 2.0;
  R_cam[7] = (local_tf * x_vel + cy * x_pos) * 2.0;
  R_cam[8] = 1.0 - (x_pos * x_pos + local_tf * local_tf) * 2.0;
  std::memcpy(&omgmat[0], &R_cam[0], 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    int8_T subsa_idx_1;
    subsa_idx_1 = static_cast<int8_T>(i + 1);
    R_cam[subsa_idx_1 - 1] = omgmat[(subsa_idx_1 - 1) * 3];
    subsa_idx_1 = static_cast<int8_T>(i + 1);
    R_cam[subsa_idx_1 + 2] = omgmat[(subsa_idx_1 - 1) * 3 + 1];
    subsa_idx_1 = static_cast<int8_T>(i + 1);
    R_cam[subsa_idx_1 + 5] = omgmat[(subsa_idx_1 - 1) * 3 + 2];
  }

  /* '<S167>:1:22' */
  /* '<S167>:1:28' */
  /* '<S167>:1:30' */
  /* '<S167>:1:31' */
  yaw = rt_atan2d_snf(sg_IK_B.T_w_ee[1], sg_IK_B.T_w_ee[0]);

  /* '<S167>:1:33' */
  /* '<S167>:1:37' */
  /* '<S167>:1:41' */
  local_tf = std::cos(yaw);
  x_vel = std::sin(yaw);
  a3 = std::sin(yaw);
  yaw = std::cos(yaw);
  a[0] = local_tf;
  a[4] = -x_vel;
  a[8] = 0.0;
  a[1] = a3;
  a[5] = yaw;
  a[9] = 0.0;
  a[2] = 0.0;
  a[12] = sg_IK_B.T_w_ee[12];
  a[6] = 0.0;
  a[13] = sg_IK_B.T_w_ee[13];
  a[10] = 1.0;
  a[14] = sg_IK_B.T_w_ee[14];
  a[3] = 0.0;
  a[7] = 0.0;
  a[11] = 0.0;
  a[15] = 1.0;
  for (ar = 0; ar < 3; ar++) {
    T[ar << 2] = R_cam[3 * ar];
    T[(ar << 2) + 1] = R_cam[3 * ar + 1];
    T[(ar << 2) + 2] = R_cam[3 * ar + 2];
    T[ar + 12] = g[ar];
  }

  T[3] = 0.0;
  T[7] = 0.0;
  T[11] = 0.0;
  T[15] = 1.0;
  for (ar = 0; ar < 4; ar++) {
    for (idx = 0; idx < 4; idx++) {
      T_w_c[idx + (ar << 2)] = 0.0;
      yaw = T_w_c[(ar << 2) + idx];
      yaw += T[ar << 2] * a[idx];
      T_w_c[idx + (ar << 2)] = yaw;
      yaw = T_w_c[(ar << 2) + idx];
      yaw += T[(ar << 2) + 1] * a[idx + 4];
      T_w_c[idx + (ar << 2)] = yaw;
      yaw = T_w_c[(ar << 2) + idx];
      yaw += T[(ar << 2) + 2] * a[idx + 8];
      T_w_c[idx + (ar << 2)] = yaw;
      yaw = T_w_c[(ar << 2) + idx];
      yaw += T[(ar << 2) + 3] * a[idx + 12];
      T_w_c[idx + (ar << 2)] = yaw;
    }
  }

  /* '<S167>:1:44' */
  /* '<S167>:1:45' */
  /* '<S167>:1:46' */
  yaw = T_w_c[10] * T_w_c[10] + T_w_c[9] * T_w_c[9];
  cy = std::sqrt(yaw);
  local_tf = rt_atan2d_snf(T_w_c[4], T_w_c[0]);
  x_vel = rt_atan2d_snf(-T_w_c[8], cy);
  a3 = rt_atan2d_snf(T_w_c[9], T_w_c[10]);
  sg_IK_B.Camera_space_frame_EUL[0] = local_tf;
  sg_IK_B.Camera_space_frame_EUL[1] = x_vel;
  sg_IK_B.Camera_space_frame_EUL[2] = a3;
  if (yaw < 2.2204460492503131E-15) {
    T_w_c_size[0] = 1;
    T_w_c_size[1] = 1;
    T_w_c_size[2] = 1;
    T_w_c_size_0[0] = 1;
    T_w_c_size_0[1] = 1;
    T_w_c_size_0[2] = 1;
    T_w_c_size_1[0] = 1;
    T_w_c_size_1[1] = 1;
    T_w_c_size_1[2] = 1;
    local_tf = -T_w_c[1];
    x_pos = T_w_c[5];
    a2 = -T_w_c[8];
    sg_IK_atan2(&local_tf, T_w_c_size, &x_pos, T_w_c_size_0, &c_a2, tmp_size);
    T_w_c_size[0] = 1;
    T_w_c_size[1] = 1;
    T_w_c_size[2] = 1;
    local_tf = cy;
    sg_IK_atan2(&a2, T_w_c_size_1, &local_tf, T_w_c_size, &x_pos, T_w_c_size_0);
    i = tmp_size[2];
    if (0 <= i - 1) {
      sg_IK_B.Camera_space_frame_EUL[0] = c_a2;
    }

    i = T_w_c_size_0[2];
    if (0 <= i - 1) {
      sg_IK_B.Camera_space_frame_EUL[1] = x_pos;
    }

    sg_IK_B.Camera_space_frame_EUL[2] = 0.0;
  }

  sg_IK_B.Camera_space_frame_EUL[0] = -sg_IK_B.Camera_space_frame_EUL[0];
  sg_IK_B.Camera_space_frame_EUL[1] = -sg_IK_B.Camera_space_frame_EUL[1];
  sg_IK_B.Camera_space_frame_EUL[2] = -sg_IK_B.Camera_space_frame_EUL[2];
  yaw = sg_IK_B.Camera_space_frame_EUL[2];
  x_pos = sg_IK_B.Camera_space_frame_EUL[0];
  sg_IK_B.Camera_space_frame_EUL[0] = yaw;
  sg_IK_B.Camera_space_frame_EUL[2] = x_pos;

  /* '<S167>:1:54' */
  /* '<S167>:1:55' */
  /* '<S167>:1:58' */
  /* '<S167>:1:59' */
  /* '<S167>:1:60' */
  yaw = sg_IK_B.CastToDouble[0];
  x_pos = sg_IK_B.CastToDouble[1];
  local_tf = sg_IK_B.CastToDouble[2];
  for (ar = 0; ar < 4; ar++) {
    cy = a_0[ar] * yaw;
    cy += a_0[ar + 4] * x_pos;
    cy += a_0[ar + 8] * local_tf;
    cy += a_0[ar + 12];
    matrix[ar] = cy;
  }

  for (ar = 0; ar < 4; ar++) {
    yaw = T_w_c[ar] * matrix[0];
    yaw += T_w_c[ar + 4] * matrix[1];
    yaw += T_w_c[ar + 8] * matrix[2];
    yaw += T_w_c[ar + 12] * matrix[3];
    T_w_c_0[ar] = yaw;
  }

  sg_IK_B.p_Ball_space[0] = T_w_c_0[0];
  sg_IK_B.p_Ball_space[1] = T_w_c_0[1];
  sg_IK_B.p_Ball_space[2] = T_w_c_0[2];

  /* '<S167>:1:61' */
  yaw = sg_IK_B.CastToDouble[3];
  x_pos = sg_IK_B.CastToDouble[4];
  local_tf = sg_IK_B.CastToDouble[5];
  for (ar = 0; ar < 4; ar++) {
    cy = a_0[ar] * yaw;
    cy += a_0[ar + 4] * x_pos;
    cy += a_0[ar + 8] * local_tf;
    cy += a_0[ar + 12];
    matrix[ar] = cy;
  }

  for (ar = 0; ar < 4; ar++) {
    yaw = T_w_c[ar] * matrix[0];
    yaw += T_w_c[ar + 4] * matrix[1];
    yaw += T_w_c[ar + 8] * matrix[2];
    yaw += T_w_c[ar + 12] * matrix[3];
    T_w_c_0[ar] = yaw;
  }

  sg_IK_B.p_Claw_space[0] = T_w_c_0[0];
  sg_IK_B.p_Claw_space[1] = T_w_c_0[1];
  sg_IK_B.p_Claw_space[2] = T_w_c_0[2];
  if (!sg_IK_DW.p_Ball_space_persistent_not_emp) {
    /* '<S167>:1:65' */
    /* '<S167>:1:66' */
    sg_IK_DW.p_Ball_space_persistent[0] = sg_IK_B.p_Ball_space[0];
    sg_IK_DW.p_Ball_space_persistent[1] = sg_IK_B.p_Ball_space[1];
    sg_IK_DW.p_Ball_space_persistent[2] = sg_IK_B.p_Ball_space[2];
    sg_IK_DW.p_Ball_space_persistent_not_emp = true;
  }

  if (!sg_IK_DW.p_Claw_space_persistent_not_emp) {
    /* '<S167>:1:68' */
    /* '<S167>:1:69' */
    sg_IK_DW.p_Claw_space_persistent[0] = sg_IK_B.p_Claw_space[0];
    sg_IK_DW.p_Claw_space_persistent[1] = sg_IK_B.p_Claw_space[1];
    sg_IK_DW.p_Claw_space_persistent[2] = sg_IK_B.p_Claw_space[2];
    sg_IK_DW.p_Claw_space_persistent_not_emp = true;
  }

  /* '<S167>:1:74' */
  wasTunablePropsChanged = true;

  /* '<S167>:1:75' */
  bClawInFrame = true;

  /* '<S167>:1:76' */
  if (std::abs(sg_IK_B.CastToDouble[0]) >= 20.0) {
    /* '<S167>:1:77' */
    /* '<S167>:1:78' */
    wasTunablePropsChanged = false;
  }

  if (std::abs(sg_IK_B.CastToDouble[3]) >= 20.0) {
    /* '<S167>:1:80' */
    /* '<S167>:1:81' */
    bClawInFrame = false;
  }

  /* '<S167>:1:76' */
  if (std::abs(sg_IK_B.CastToDouble[1]) >= 20.0) {
    /* '<S167>:1:77' */
    /* '<S167>:1:78' */
    wasTunablePropsChanged = false;
  }

  if (std::abs(sg_IK_B.CastToDouble[4]) >= 20.0) {
    /* '<S167>:1:80' */
    /* '<S167>:1:81' */
    bClawInFrame = false;
  }

  /* '<S167>:1:76' */
  if (std::abs(sg_IK_B.CastToDouble[2]) >= 20.0) {
    /* '<S167>:1:77' */
    /* '<S167>:1:78' */
    wasTunablePropsChanged = false;
  }

  if (std::abs(sg_IK_B.CastToDouble[5]) >= 20.0) {
    /* '<S167>:1:80' */
    /* '<S167>:1:81' */
    bClawInFrame = false;
  }

  if (wasTunablePropsChanged) {
    /* '<S167>:1:86' */
    /* '<S167>:1:87' */
    sg_IK_DW.p_Ball_space_persistent[0] = sg_IK_B.p_Ball_space[0];
    sg_IK_DW.p_Ball_space_persistent[1] = sg_IK_B.p_Ball_space[1];
    sg_IK_DW.p_Ball_space_persistent[2] = sg_IK_B.p_Ball_space[2];
  } else {
    /* '<S167>:1:89' */
    sg_IK_B.p_Ball_space[0] = sg_IK_DW.p_Ball_space_persistent[0];
    sg_IK_B.p_Ball_space[1] = sg_IK_DW.p_Ball_space_persistent[1];
    sg_IK_B.p_Ball_space[2] = sg_IK_DW.p_Ball_space_persistent[2];
  }

  if (bClawInFrame) {
    /* '<S167>:1:92' */
    /* '<S167>:1:93' */
    sg_IK_DW.p_Claw_space_persistent[0] = sg_IK_B.p_Claw_space[0];
    sg_IK_DW.p_Claw_space_persistent[1] = sg_IK_B.p_Claw_space[1];
    sg_IK_DW.p_Claw_space_persistent[2] = sg_IK_B.p_Claw_space[2];
  } else {
    /* '<S167>:1:95' */
    sg_IK_B.p_Claw_space[0] = sg_IK_DW.p_Claw_space_persistent[0];
    sg_IK_B.p_Claw_space[1] = sg_IK_DW.p_Claw_space_persistent[1];
    sg_IK_B.p_Claw_space[2] = sg_IK_DW.p_Claw_space_persistent[2];
  }

  sg_IK_B.Camera_space_frame_XYZ[0] = T_w_c[12];
  sg_IK_B.Camera_space_frame_XYZ[1] = T_w_c[13];
  sg_IK_B.Camera_space_frame_XYZ[2] = T_w_c[14];
  sg_IK_B.bBall_InFrame = wasTunablePropsChanged;

  /* End of MATLAB Function: '<S8>/Camera_transform' */

  /* MATLAB Function: '<S6>/is_Em8000_settled' */
  /* MATLAB Function 'Controller/State Machine and Operation mode selecotr/is_Em8000_settled': '<S165>:1' */
  /* '<S165>:1:2' */
  if ((sg_IK_B.DataTypeConversion4[2] >= 0.99) && (sg_IK_B.DataTypeConversion4[2]
       <= 1.01)) {
    /* '<S165>:1:6' */
    /* '<S165>:1:7' */
    sg_IK_B.Em8000_settled_flag = true;
  } else {
    /* '<S165>:1:9' */
    sg_IK_B.Em8000_settled_flag = false;
  }

  /* End of MATLAB Function: '<S6>/is_Em8000_settled' */

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  sg_IK_B.DataTypeConversion2 = sg_IK_B.Winch;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/Winch_Correction_And_ClawLenght'
   */
  sg_IK_B.Pos = sg_IK_B.DataTypeConversion2 +
    sg_IK_cal->Winch_Correction_And_ClawLenght;

  /* MATLAB Function: '<S6>/Winch_Local_to_Global' */
  /* MATLAB Function 'Controller/State Machine and Operation mode selecotr/Winch_Local_to_Global': '<S164>:1' */
  /* '<S164>:1:4' */
  /* '<S164>:1:5' */
  sg_IK_B.Winch_Global_Pos_Z_h = sg_IK_B.Endeff_world_xyz[2] - (sg_IK_B.Pos -
    0.202);

  /* Memory: '<S7>/Memory2' */
  sg_IK_B.Memory2 = sg_IK_DW.Memory2_PreviousInput;

  /* Chart: '<S6>/Chart' */
  if (sg_IK_DW.temporalCounter_i1 < 8191U) {
    sg_IK_DW.temporalCounter_i1 = static_cast<uint16_T>
      (sg_IK_DW.temporalCounter_i1 + 1U);
  }

  if (sg_IK_DW.temporalCounter_i2 < 1023U) {
    sg_IK_DW.temporalCounter_i2 = static_cast<uint16_T>
      (sg_IK_DW.temporalCounter_i2 + 1U);
  }

  /* Gateway: Controller/State Machine and Operation mode selecotr/Chart */
  sg_IK_DW.sfEvent = -1;

  /* During: Controller/State Machine and Operation mode selecotr/Chart */
  if (sg_IK_DW.is_active_c9_sg_IK == 0U) {
    /* Entry: Controller/State Machine and Operation mode selecotr/Chart */
    sg_IK_DW.is_active_c9_sg_IK = 1U;

    /* Entry Internal: Controller/State Machine and Operation mode selecotr/Chart */
    /* Transition: '<S162>:124' */
    sg_IK_DW.is_c9_sg_IK = sg_IK_IN_Mode_selector_state;

    /* Entry 'Mode_selector_state': '<S162>:119' */
    if (sg_IK_B.Constant_f == 1.0) {
      sg_IK_DW.Hook_state_switch = 1.0;
      sg_IK_DW.Mode = 1.0;
    } else {
      sg_IK_DW.Mode = 2.0;
    }
  } else {
    switch (sg_IK_DW.is_c9_sg_IK) {
     case sg_IN_Autonomous_Operation_Mode:
      sg_IK_Autonomous_Operation_Mode();
      break;

     case sg__IN_Manual_State_Switch_Mode:
      /* During 'Manual_State_Switch_Mode': '<S162>:121' */
      switch (sg_IK_DW.is_Manual_State_Switch_Mode) {
       case sg_IK_IN_Go_home:
        /* During 'Go_home': '<S162>:16' */
        if (sg_IK_B.MS_Switch == 0.0) {
          /* Transition: '<S162>:31' */
          sg_IK_DW.is_Manual_State_Switch_Mode = sg__IN_Stay_in_current_position;

          /* Entry 'Stay_in_current_position': '<S162>:12' */
          sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_method = 1.0;
          sg_IK_B.v_max = 0.0;
          sg_IK_B.new_command++;
          sg_IK_B.FF_Flag = 0.0;
          sg_IK_B.Winch_PosRef_e = 10.0;
          sg_IK_B.Winch_Mode_selector = 1.0;
        } else if (sg_IK_B.MS_Switch == 2.0) {
          /* Transition: '<S162>:35' */
          sg_IK_DW.is_Manual_State_Switch_Mode = IN_Move_to_above_platform_PickU;
          enter_atomic_Move_to_above_plat();
        } else if (sg_IK_B.MS_Switch == 4.0) {
          /* Transition: '<S162>:137' */
          sg_IK_DW.is_Manual_State_Switch_Mode = IN_Lower_payload_Onto_platform;

          /* Entry 'Lower_payload_Onto_platform': '<S162>:126' */
          /* Entry Internal 'Lower_payload_Onto_platform': '<S162>:126' */
          /* Transition: '<S162>:135' */
          sg_IK_DW.is_Lower_payload_Onto_platform =
            IN_Move_above_platform_While_lo;
          sg_IK_DW.temporalCounter_i1 = 0U;

          /* Entry 'Move_above_platform_While_lowering_payload': '<S162>:134' */
          if (sg_IK_B.Em8000_settled_flag &&
              (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0))) {
            sg_IK_DW.Em8000_settled_offset = 1.0;
          } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
            sg_IK_DW.Em8000_settled_offset = 0.65;
          } else {
            sg_IK_DW.Em8000_settled_offset = 0.0;
          }

          sg_IK_DW.Sub_stage_switch2 = 0.0;
          sg_IK_DW.X_Platform = 0.41;
          sg_IK_DW.Y_Platform = -1.34;
          sg_IK_DW.Z_Platform = 5.67 - sg_IK_DW.Em8000_settled_offset;
          sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_Platform;
          sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_Platform;
          sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_Platform;
          sg_IK_B.Traj_method = 2.0;
          sg_IK_B.v_max = 0.12;
          sg_IK_B.new_command++;
          sg_IK_B.Winch_Mode_selector = 2.0;
          sg_IK_B.Winch_PosRef_e = 2.6;
          sg_IK_B.Winch_NewCmd++;
          sg_IK_B.FF_Flag = 1.0;
        }
        break;

       case sg_IK_IN_Hook_Ball:
        sg_IK_Hook_Ball();
        break;

       case IN_Lower_payload_Onto_platform:
        /* During 'Lower_payload_Onto_platform': '<S162>:126' */
        if (sg_IK_B.MS_Switch == 1.0) {
          /* Transition: '<S162>:138' */
          /* Exit Internal 'Lower_payload_Onto_platform': '<S162>:126' */
          sg_IK_DW.is_Lower_payload_Onto_platform = 0U;
          sg_IK_DW.is_Manual_State_Switch_Mode = sg_IK_IN_Go_home;
          sg_IK_enter_atomic_Go_home();
        } else if (sg_IK_B.MS_Switch == 0.0) {
          /* Transition: '<S162>:182' */
          /* Exit Internal 'Lower_payload_Onto_platform': '<S162>:126' */
          sg_IK_DW.is_Lower_payload_Onto_platform = 0U;
          sg_IK_DW.is_Manual_State_Switch_Mode = sg__IN_Stay_in_current_position;

          /* Entry 'Stay_in_current_position': '<S162>:12' */
          sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_method = 1.0;
          sg_IK_B.v_max = 0.0;
          sg_IK_B.new_command++;
          sg_IK_B.FF_Flag = 0.0;
          sg_IK_B.Winch_PosRef_e = 10.0;
          sg_IK_B.Winch_Mode_selector = 1.0;
        } else {
          switch (sg_IK_DW.is_Lower_payload_Onto_platform) {
           case sg_IK_IN_Lower_winch_To_unhook:
            /* During 'Lower_winch_To_unhook': '<S162>:139' */
            if (sg_IK_DW.temporalCounter_i1 >= 7000U) {
              /* Transition: '<S162>:142' */
              sg_IK_DW.is_Lower_payload_Onto_platform =
                sg_IK_IN_Move_to_side_unhook;

              /* Entry 'Move_to_side_unhook': '<S162>:141' */
              if (sg_IK_B.Em8000_settled_flag &&
                  (!(sg_IK_B.enable_65cm_offset_Em8000 != 0.0))) {
                sg_IK_DW.Em8000_settled_offset = 1.0;
              } else if (sg_IK_B.enable_65cm_offset_Em8000 != 0.0) {
                sg_IK_DW.Em8000_settled_offset = 0.65;
              } else {
                sg_IK_DW.Em8000_settled_offset = 0.0;
              }

              sg_IK_DW.X_Unhook = 0.0;
              sg_IK_DW.Y_Unhook = -1.62;
              sg_IK_DW.Z_Unhook = 5.62 - sg_IK_DW.Em8000_settled_offset;
              sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
              sg_IK_B.Traj_points_XYZ[1] = sg_IK_DW.X_Unhook;
              sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
              sg_IK_B.Traj_points_XYZ[3] = sg_IK_DW.Y_Unhook;
              sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
              sg_IK_B.Traj_points_XYZ[5] = sg_IK_DW.Z_Unhook;
              sg_IK_B.Traj_method = 2.0;
              sg_IK_B.v_max = 0.07;
              sg_IK_B.new_command++;
              sg_IK_B.Winch_PosRef_e = 2.6;
              sg_IK_B.Winch_NewCmd++;
              sg_IK_B.FF_Flag = 1.0;
            }
            break;

           case IN_Move_above_platform_While_lo:
            /* During 'Move_above_platform_While_lowering_payload': '<S162>:134' */
            wasTunablePropsChanged = ((sg_IK_DW.Sub_stage_switch2 == 1.0) &&
              (sg_IK_DW.temporalCounter_i1 >= 3000U));
            if (wasTunablePropsChanged) {
              /* Transition: '<S162>:140' */
              sg_IK_DW.is_Lower_payload_Onto_platform =
                sg_IK_IN_Lower_winch_To_unhook;
              sg_IK_DW.temporalCounter_i1 = 0U;

              /* Entry 'Lower_winch_To_unhook': '<S162>:139' */
              sg_IK_B.Winch_PosRef_e = 2.6;
              sg_IK_B.Winch_NewCmd++;
            } else if (!sg_IK_B.Memory2) {
              sg_IK_DW.Sub_stage_switch2 = 1.0;
            }
            break;

           default:
            /* During 'Move_to_side_unhook': '<S162>:141' */
            break;
          }
        }
        break;

       case IN_Move_to_above_platform_PickU:
        /* During 'Move_to_above_platform_PickUp': '<S162>:32' */
        if (sg_IK_B.MS_Switch == 0.0) {
          /* Transition: '<S162>:33' */
          sg_IK_DW.is_Manual_State_Switch_Mode = sg__IN_Stay_in_current_position;

          /* Entry 'Stay_in_current_position': '<S162>:12' */
          sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
          sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
          sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
          sg_IK_B.Traj_method = 1.0;
          sg_IK_B.v_max = 0.0;
          sg_IK_B.new_command++;
          sg_IK_B.FF_Flag = 0.0;
          sg_IK_B.Winch_PosRef_e = 10.0;
          sg_IK_B.Winch_Mode_selector = 1.0;
        } else if (sg_IK_B.MS_Switch == 1.0) {
          /* Transition: '<S162>:34' */
          sg_IK_DW.is_Manual_State_Switch_Mode = sg_IK_IN_Go_home;
          sg_IK_enter_atomic_Go_home();
        } else if (sg_IK_B.MS_Switch == 3.0) {
          /* Transition: '<S162>:45' */
          sg_IK_DW.is_Manual_State_Switch_Mode = sg_IK_IN_Hook_Ball;

          /* Entry Internal 'Hook_Ball': '<S162>:43' */
          /* Transition: '<S162>:51' */
          sg_IK_DW.is_Hook_Ball = sg_IK_IN_Ball_In_Frame;

          /* Entry 'Ball_In_Frame': '<S162>:50' */
          if (sg_IK_B.bBall_InFrame) {
            sg_IK_DW.Sub_stage_switch = 1.0;
          } else {
            sg_IK_DW.Sub_stage_switch = 0.0;
            sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
            sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
            sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
            sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
            sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
            sg_IK_B.v_max = 0.0;
            sg_IK_B.new_command++;
          }
        } else {
          sg_IK_B.Winch_PosRef_e = 3.2;
        }
        break;

       default:
        /* During 'Stay_in_current_position': '<S162>:12' */
        if (sg_IK_B.MS_Switch == 1.0) {
          /* Transition: '<S162>:30' */
          sg_IK_DW.is_Manual_State_Switch_Mode = sg_IK_IN_Go_home;
          sg_IK_enter_atomic_Go_home();
        } else if (sg_IK_B.MS_Switch == 2.0) {
          /* Transition: '<S162>:36' */
          sg_IK_DW.is_Manual_State_Switch_Mode = IN_Move_to_above_platform_PickU;
          enter_atomic_Move_to_above_plat();
        }
        break;
      }
      break;

     default:
      /* During 'Mode_selector_state': '<S162>:119' */
      if (sg_IK_DW.Mode == 2.0) {
        /* Transition: '<S162>:120' */
        sg_IK_DW.is_c9_sg_IK = sg__IN_Manual_State_Switch_Mode;

        /* Entry Internal 'Manual_State_Switch_Mode': '<S162>:121' */
        /* Transition: '<S162>:13' */
        sg_IK_DW.is_Manual_State_Switch_Mode = sg__IN_Stay_in_current_position;

        /* Entry 'Stay_in_current_position': '<S162>:12' */
        sg_IK_B.Traj_points_XYZ[0] = sg_IK_B.Endeff_world_xyz[0];
        sg_IK_B.Traj_points_XYZ[1] = sg_IK_B.Endeff_world_xyz[0];
        sg_IK_B.Traj_points_XYZ[2] = sg_IK_B.Endeff_world_xyz[1];
        sg_IK_B.Traj_points_XYZ[3] = sg_IK_B.Endeff_world_xyz[1];
        sg_IK_B.Traj_points_XYZ[4] = sg_IK_B.Endeff_world_xyz[2];
        sg_IK_B.Traj_points_XYZ[5] = sg_IK_B.Endeff_world_xyz[2];
        sg_IK_B.Traj_method = 1.0;
        sg_IK_B.v_max = 0.0;
        sg_IK_B.new_command++;
        sg_IK_B.FF_Flag = 0.0;
        sg_IK_B.Winch_PosRef_e = 10.0;
        sg_IK_B.Winch_Mode_selector = 1.0;
      } else if (sg_IK_DW.Mode == 1.0) {
        /* Transition: '<S162>:180' */
        sg_IK_DW.is_c9_sg_IK = sg_IN_Autonomous_Operation_Mode;

        /* Entry Internal 'Autonomous_Operation_Mode': '<S162>:170' */
        /* Transition: '<S162>:385' */
        sg_IK_DW.is_Autonomous_Operation_Mode = sg_IK_IN_Go_home;
        sg_IK_DW.temporalCounter_i1 = 0U;
        sg_IK_enter_atomic_Go_home_m();
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Constant: '<S157>/Constant7' */
  sg_IK_B.Constant7 = sg_IK_cal->x_coordinate_traj;

  /* Constant: '<S157>/Constant5' */
  sg_IK_B.Constant5 = sg_IK_cal->y_coordinate_traj;

  /* Constant: '<S157>/Constant6' */
  sg_IK_B.Constant6 = sg_IK_cal->z_coordinate_traj;

  /* MultiPortSwitch: '<S163>/Multiport Switch' incorporates:
   *  MultiPortSwitch: '<S163>/Multiport Switch1'
   *  MultiPortSwitch: '<S163>/Multiport Switch2'
   *  MultiPortSwitch: '<S163>/Multiport Switch3'
   */
  if (static_cast<int32_T>(sg_IK_B.Operation_Mode) == 1) {
    /* MultiPortSwitch: '<S163>/Multiport Switch' */
    for (i = 0; i < 6; i++) {
      sg_IK_B.MultiportSwitch[i] = sg_IK_B.Traj_points_XYZ[i];
    }

    /* MultiPortSwitch: '<S163>/Multiport Switch1' */
    sg_IK_B.MultiportSwitch1 = sg_IK_B.new_command;

    /* MultiPortSwitch: '<S163>/Multiport Switch2' */
    sg_IK_B.MultiportSwitch2 = sg_IK_B.Traj_method;

    /* MultiPortSwitch: '<S163>/Multiport Switch3' */
    sg_IK_B.MultiportSwitch3 = sg_IK_B.v_max;
  } else {
    /* MultiPortSwitch: '<S163>/Multiport Switch' */
    sg_IK_B.MultiportSwitch[0] = sg_IK_B.Endeff_world_xyz[0];
    sg_IK_B.MultiportSwitch[1] = sg_IK_B.Constant7;
    sg_IK_B.MultiportSwitch[2] = sg_IK_B.Endeff_world_xyz[1];
    sg_IK_B.MultiportSwitch[3] = sg_IK_B.Constant5;
    sg_IK_B.MultiportSwitch[4] = sg_IK_B.Endeff_world_xyz[2];
    sg_IK_B.MultiportSwitch[5] = sg_IK_B.Constant6;

    /* MultiPortSwitch: '<S163>/Multiport Switch1' incorporates:
     *  Constant: '<S163>/Constant10'
     */
    sg_IK_B.MultiportSwitch1 = sg_IK_cal->new_command_traj;

    /* MultiPortSwitch: '<S163>/Multiport Switch2' incorporates:
     *  Constant: '<S163>/Constant9'
     */
    sg_IK_B.MultiportSwitch2 = sg_IK_cal->Traj_method;

    /* MultiPortSwitch: '<S163>/Multiport Switch3' incorporates:
     *  Constant: '<S163>/Constant3'
     */
    sg_IK_B.MultiportSwitch3 = sg_IK_cal->v_max;
  }

  /* End of MultiPortSwitch: '<S163>/Multiport Switch' */

  /* Clock: '<S7>/Clock' */
  sg_IK_B.Clock = sg_IK_M->Timing.t[0];

  /* Memory: '<S5>/Memory3' */
  sg_IK_B.Memory3 = sg_IK_DW.Memory3_PreviousInput;

  /* MATLAB Function: '<S7>/Trajectory_planner' */
  yaw = sg_IK_B.Clock;
  x_pos = sg_IK_B.MultiportSwitch3;

  /* MATLAB Function 'Controller/Trajectory planner/Trajectory_planner': '<S166>:1' */
  if (sg_IK_B.Memory3) {
    /* '<S166>:1:9' */
    /* '<S166>:1:10' */
    sg_IK_B.p[0] = sg_IK_B.MultiportSwitch[0];
    sg_IK_B.p[1] = sg_IK_B.MultiportSwitch[2];
    sg_IK_B.p[2] = sg_IK_B.MultiportSwitch[4];

    /* '<S166>:1:11' */
    sg_IK_B.p_vel[0] = 0.0;
    sg_IK_B.p_vel[1] = 0.0;
    sg_IK_B.p_vel[2] = 0.0;

    /* '<S166>:1:12' */
    sg_IK_B.Traj_Running = false;
  } else {
    if (!sg_IK_DW.abs_tf_not_empty) {
      /* '<S166>:1:21' */
      sg_IK_DW.abs_tf_not_empty = true;

      /* '<S166>:1:25' */
      sg_IK_DW.new_points_x[0] = sg_IK_B.MultiportSwitch[0];
      sg_IK_DW.new_points_x[1] = sg_IK_B.MultiportSwitch[1];

      /* '<S166>:1:26' */
      sg_IK_DW.new_points_y[0] = sg_IK_B.MultiportSwitch[2];
      sg_IK_DW.new_points_y[1] = sg_IK_B.MultiportSwitch[3];

      /* '<S166>:1:27' */
      sg_IK_DW.new_points_z[0] = sg_IK_B.MultiportSwitch[4];
      sg_IK_DW.new_points_z[1] = sg_IK_B.MultiportSwitch[5];
    }

    if (sg_IK_B.MultiportSwitch1 != sg_IK_DW.last_command_f) {
      /* '<S166>:1:31' */
      /* '<S166>:1:33' */
      sg_IK_DW.base_t = sg_IK_B.Clock;

      /* '<S166>:1:35' */
      sg_IK_DW.new_points_x[0] = sg_IK_B.MultiportSwitch[0];
      sg_IK_DW.new_points_x[1] = sg_IK_B.MultiportSwitch[1];

      /* '<S166>:1:36' */
      sg_IK_DW.new_points_y[0] = sg_IK_B.MultiportSwitch[2];
      sg_IK_DW.new_points_y[1] = sg_IK_B.MultiportSwitch[3];

      /* '<S166>:1:37' */
      sg_IK_DW.new_points_z[0] = sg_IK_B.MultiportSwitch[4];
      sg_IK_DW.new_points_z[1] = sg_IK_B.MultiportSwitch[5];

      /* '<S166>:1:42' */
      x_pos = sg_IK_B.MultiportSwitch3;
      if (!(x_pos >= 1.0E-6)) {
        x_pos = 1.0E-6;
      }

      /* '<S166>:1:45' */
      /* '<S166>:1:46' */
      /* '<S166>:1:47' */
      /* '<S166>:1:51' */
      local_tf = std::abs(sg_IK_DW.new_points_x[1] - sg_IK_DW.new_points_x[0]);
      x_vel = std::abs(sg_IK_DW.new_points_y[1] - sg_IK_DW.new_points_y[0]);
      a3 = std::abs(sg_IK_DW.new_points_z[1] - sg_IK_DW.new_points_z[0]);
      matrix[0] = local_tf / x_pos;
      matrix[1] = x_vel / x_pos;
      matrix[2] = a3 / x_pos;
      matrix[3] = 1.0E-6;
      local_tf = std::abs(sg_IK_DW.new_points_x[1] - sg_IK_DW.new_points_x[0]);
      x_vel = std::abs(sg_IK_DW.new_points_y[1] - sg_IK_DW.new_points_y[0]);
      a3 = std::abs(sg_IK_DW.new_points_z[1] - sg_IK_DW.new_points_z[0]);
      T_w_c_0[0] = local_tf / x_pos;
      T_w_c_0[1] = x_vel / x_pos;
      T_w_c_0[2] = a3 / x_pos;
      T_w_c_0[3] = 1.0E-6;
      if (!rtIsNaN(T_w_c_0[0])) {
        idx = 1;
      } else {
        idx = 0;
        i = 2;
        exitg1 = false;
        while ((!exitg1) && (i < 5)) {
          if (!rtIsNaN(T_w_c_0[i - 1])) {
            idx = i;
            exitg1 = true;
          } else {
            i++;
          }
        }
      }

      if (idx == 0) {
        cy = matrix[0];
      } else {
        cy = matrix[idx - 1];
        while (idx + 1 < 5) {
          if (cy < matrix[idx]) {
            cy = matrix[idx];
          }

          idx++;
        }
      }

      /* '<S166>:1:54' */
      sg_IK_DW.abs_tf = cy + sg_IK_B.Clock;

      /* '<S166>:1:56' */
      sg_IK_DW.last_command_f = sg_IK_B.MultiportSwitch1;
    }

    /* '<S166>:1:60' */
    cy = sg_IK_B.Clock - sg_IK_DW.base_t;

    /* '<S166>:1:61' */
    local_tf = sg_IK_DW.abs_tf - sg_IK_DW.base_t;
    if ((sg_IK_DW.abs_tf == 0.0) || (x_pos == 0.0)) {
      /* '<S166>:1:64' */
      /* '<S166>:1:65' */
      x_pos = sg_IK_DW.new_points_x[0];

      /* '<S166>:1:66' */
      a2 = sg_IK_DW.new_points_y[0];

      /* '<S166>:1:67' */
      c_a2 = sg_IK_DW.new_points_z[0];

      /* '<S166>:1:69' */
      x_vel = 0.0;

      /* '<S166>:1:70' */
      a3 = 0.0;

      /* '<S166>:1:71' */
      c_a3 = 0.0;
    } else if (sg_IK_B.MultiportSwitch2 == 1.0) {
      /* '<S166>:1:73' */
      /* '<S166>:1:74' */
      x_vel = cy;
      if (cy < 0.0) {
        x_vel = 0.0;
      } else if (cy > local_tf) {
        x_vel = local_tf;
      }

      a2 = (sg_IK_DW.new_points_x[1] - sg_IK_DW.new_points_x[0]) * 3.0 /
        (local_tf * local_tf) - 0.0 / local_tf;
      a3 = (sg_IK_DW.new_points_x[1] - sg_IK_DW.new_points_x[0]) * -2.0 /
        rt_powd_snf(local_tf, 3.0) + 0.0 / (local_tf * local_tf);
      x_pos = ((0.0 * x_vel + sg_IK_DW.new_points_x[0]) + x_vel * x_vel * a2) +
        a3 * rt_powd_snf(x_vel, 3.0);
      x_vel = 2.0 * a2 * x_vel + 3.0 * a3 * (x_vel * x_vel);

      /* '<S166>:1:74' */
      /* '<S166>:1:75' */
      a3 = cy;
      if (cy < 0.0) {
        a3 = 0.0;
      } else if (cy > local_tf) {
        a3 = local_tf;
      }

      c_a2 = (sg_IK_DW.new_points_y[1] - sg_IK_DW.new_points_y[0]) * 3.0 /
        (local_tf * local_tf) - 0.0 / local_tf;
      c_a3 = (sg_IK_DW.new_points_y[1] - sg_IK_DW.new_points_y[0]) * -2.0 /
        rt_powd_snf(local_tf, 3.0) + 0.0 / (local_tf * local_tf);
      a2 = ((0.0 * a3 + sg_IK_DW.new_points_y[0]) + a3 * a3 * c_a2) + c_a3 *
        rt_powd_snf(a3, 3.0);
      a3 = 2.0 * c_a2 * a3 + 3.0 * c_a3 * (a3 * a3);

      /* '<S166>:1:75' */
      /* '<S166>:1:76' */
      if (cy < 0.0) {
        cy = 0.0;
      } else if (cy > local_tf) {
        cy = local_tf;
      }

      c_a3 = (sg_IK_DW.new_points_z[1] - sg_IK_DW.new_points_z[0]) * 3.0 /
        (local_tf * local_tf) - 0.0 / local_tf;
      local_tf = (sg_IK_DW.new_points_z[1] - sg_IK_DW.new_points_z[0]) * -2.0 /
        rt_powd_snf(local_tf, 3.0) + 0.0 / (local_tf * local_tf);
      c_a2 = ((0.0 * cy + sg_IK_DW.new_points_z[0]) + cy * cy * c_a3) + local_tf
        * rt_powd_snf(cy, 3.0);
      c_a3 = 2.0 * c_a3 * cy + 3.0 * local_tf * (cy * cy);

      /* '<S166>:1:76' */
    } else if (sg_IK_B.MultiportSwitch2 == 2.0) {
      /* '<S166>:1:77' */
      /* '<S166>:1:78' */
      sg_IK_quinticTrajectoryPlanner(cy, local_tf, sg_IK_DW.new_points_x[0],
        sg_IK_DW.new_points_x[1], &x_pos, &x_vel, &a2);

      /* '<S166>:1:78' */
      /* '<S166>:1:79' */
      sg_IK_quinticTrajectoryPlanner(cy, local_tf, sg_IK_DW.new_points_y[0],
        sg_IK_DW.new_points_y[1], &a2, &a3, &c_a2);

      /* '<S166>:1:79' */
      /* '<S166>:1:80' */
      sg_IK_quinticTrajectoryPlanner(cy, local_tf, sg_IK_DW.new_points_z[0],
        sg_IK_DW.new_points_z[1], &c_a2, &c_a3, &a__6);

      /* '<S166>:1:80' */
    } else {
      /* '<S166>:1:82' */
      x_vel = cy;
      if (cy < 0.0) {
        x_vel = 0.0;
      } else if (cy > local_tf) {
        x_vel = local_tf;
      }

      a2 = (sg_IK_DW.new_points_x[1] - sg_IK_DW.new_points_x[0]) * 3.0 /
        (local_tf * local_tf) - 0.0 / local_tf;
      a3 = (sg_IK_DW.new_points_x[1] - sg_IK_DW.new_points_x[0]) * -2.0 /
        rt_powd_snf(local_tf, 3.0) + 0.0 / (local_tf * local_tf);
      x_pos = ((0.0 * x_vel + sg_IK_DW.new_points_x[0]) + x_vel * x_vel * a2) +
        a3 * rt_powd_snf(x_vel, 3.0);
      x_vel = 2.0 * a2 * x_vel + 3.0 * a3 * (x_vel * x_vel);

      /* '<S166>:1:82' */
      /* '<S166>:1:83' */
      a3 = cy;
      if (cy < 0.0) {
        a3 = 0.0;
      } else if (cy > local_tf) {
        a3 = local_tf;
      }

      c_a2 = (sg_IK_DW.new_points_y[1] - sg_IK_DW.new_points_y[0]) * 3.0 /
        (local_tf * local_tf) - 0.0 / local_tf;
      c_a3 = (sg_IK_DW.new_points_y[1] - sg_IK_DW.new_points_y[0]) * -2.0 /
        rt_powd_snf(local_tf, 3.0) + 0.0 / (local_tf * local_tf);
      a2 = ((0.0 * a3 + sg_IK_DW.new_points_y[0]) + a3 * a3 * c_a2) + c_a3 *
        rt_powd_snf(a3, 3.0);
      a3 = 2.0 * c_a2 * a3 + 3.0 * c_a3 * (a3 * a3);

      /* '<S166>:1:83' */
      /* '<S166>:1:84' */
      if (cy < 0.0) {
        cy = 0.0;
      } else if (cy > local_tf) {
        cy = local_tf;
      }

      c_a3 = (sg_IK_DW.new_points_z[1] - sg_IK_DW.new_points_z[0]) * 3.0 /
        (local_tf * local_tf) - 0.0 / local_tf;
      local_tf = (sg_IK_DW.new_points_z[1] - sg_IK_DW.new_points_z[0]) * -2.0 /
        rt_powd_snf(local_tf, 3.0) + 0.0 / (local_tf * local_tf);
      c_a2 = ((0.0 * cy + sg_IK_DW.new_points_z[0]) + cy * cy * c_a3) + local_tf
        * rt_powd_snf(cy, 3.0);
      c_a3 = 2.0 * c_a3 * cy + 3.0 * local_tf * (cy * cy);

      /* '<S166>:1:84' */
    }

    /* '<S166>:1:92' */
    sg_IK_B.p[0] = x_pos;

    /* '<S166>:1:93' */
    sg_IK_B.p[1] = a2;

    /* '<S166>:1:94' */
    sg_IK_B.p[2] = c_a2;

    /* '<S166>:1:96' */
    sg_IK_B.p_vel[0] = x_vel;

    /* '<S166>:1:97' */
    sg_IK_B.p_vel[1] = a3;

    /* '<S166>:1:98' */
    sg_IK_B.p_vel[2] = c_a3;

    /* '<S166>:1:100' */
    sg_IK_B.Traj_Running = (yaw <= sg_IK_DW.abs_tf + 0.1);
  }

  /* End of MATLAB Function: '<S7>/Trajectory_planner' */

  /* Sum: '<S4>/Sum' */
  sg_IK_B.Sum_f = sg_IK_B.p[0] - sg_IK_B.Endeff_world_xyz[0];

  /* Gain: '<S49>/Proportional Gain' */
  sg_IK_B.ProportionalGain = sg_IK_cal->DiscretePIDController_P * sg_IK_B.Sum_f;

  /* DiscreteIntegrator: '<S44>/Integrator' */
  sg_IK_B.Integrator = sg_IK_DW.Integrator_DSTATE;

  /* Sum: '<S53>/Sum' */
  sg_IK_B.Sum_a = sg_IK_B.ProportionalGain + sg_IK_B.Integrator;

  /* Saturate: '<S51>/Saturation' */
  yaw = sg_IK_B.Sum_a;
  cy = sg_IK_cal->DiscretePIDController_LowerSatu;
  x_pos = sg_IK_cal->DiscretePIDController_UpperSatu;
  if (yaw > x_pos) {
    /* Saturate: '<S51>/Saturation' */
    sg_IK_B.Saturation = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S51>/Saturation' */
    sg_IK_B.Saturation = cy;
  } else {
    /* Saturate: '<S51>/Saturation' */
    sg_IK_B.Saturation = yaw;
  }

  /* End of Saturate: '<S51>/Saturation' */

  /* Sum: '<S4>/Sum3' */
  sg_IK_B.Sum3_e = sg_IK_B.p_vel[0] + sg_IK_B.Saturation;

  /* Sum: '<S4>/Sum1' */
  sg_IK_B.Sum1 = sg_IK_B.p[1] - sg_IK_B.Endeff_world_xyz[1];

  /* Gain: '<S97>/Proportional Gain' */
  sg_IK_B.ProportionalGain_c = sg_IK_cal->DiscretePIDController1_P *
    sg_IK_B.Sum1;

  /* DiscreteIntegrator: '<S92>/Integrator' */
  sg_IK_B.Integrator_k = sg_IK_DW.Integrator_DSTATE_c;

  /* Sum: '<S101>/Sum' */
  sg_IK_B.Sum_d = sg_IK_B.ProportionalGain_c + sg_IK_B.Integrator_k;

  /* Saturate: '<S99>/Saturation' */
  yaw = sg_IK_B.Sum_d;
  cy = sg_IK_cal->DiscretePIDController1_LowerSat;
  x_pos = sg_IK_cal->DiscretePIDController1_UpperSat;
  if (yaw > x_pos) {
    /* Saturate: '<S99>/Saturation' */
    sg_IK_B.Saturation_k = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S99>/Saturation' */
    sg_IK_B.Saturation_k = cy;
  } else {
    /* Saturate: '<S99>/Saturation' */
    sg_IK_B.Saturation_k = yaw;
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* Sum: '<S4>/Sum4' */
  sg_IK_B.Sum4 = sg_IK_B.p_vel[1] + sg_IK_B.Saturation_k;

  /* Sum: '<S4>/Sum2' */
  sg_IK_B.Sum2 = sg_IK_B.p[2] - sg_IK_B.Endeff_world_xyz[2];

  /* Gain: '<S145>/Proportional Gain' */
  sg_IK_B.ProportionalGain_o = sg_IK_cal->DiscretePIDController2_P *
    sg_IK_B.Sum2;

  /* DiscreteIntegrator: '<S140>/Integrator' */
  sg_IK_B.Integrator_j = sg_IK_DW.Integrator_DSTATE_n;

  /* Sum: '<S149>/Sum' */
  sg_IK_B.Sum_k = sg_IK_B.ProportionalGain_o + sg_IK_B.Integrator_j;

  /* Saturate: '<S147>/Saturation' */
  yaw = sg_IK_B.Sum_k;
  cy = sg_IK_cal->DiscretePIDController2_LowerSat;
  x_pos = sg_IK_cal->DiscretePIDController2_UpperSat;
  if (yaw > x_pos) {
    /* Saturate: '<S147>/Saturation' */
    sg_IK_B.Saturation_e = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S147>/Saturation' */
    sg_IK_B.Saturation_e = cy;
  } else {
    /* Saturate: '<S147>/Saturation' */
    sg_IK_B.Saturation_e = yaw;
  }

  /* End of Saturate: '<S147>/Saturation' */

  /* Sum: '<S4>/Sum5' */
  sg_IK_B.Sum5 = sg_IK_B.p_vel[2] + sg_IK_B.Saturation_e;

  /* SignalConversion generated from: '<S158>/ SFunction ' incorporates:
   *  MATLAB Function: '<S5>/IVK_solver'
   */
  sg_IK_B.TmpSignalConversionAtSFunctionI[0] = sg_IK_B.Sum3_e;
  sg_IK_B.TmpSignalConversionAtSFunctionI[1] = sg_IK_B.Sum4;
  sg_IK_B.TmpSignalConversionAtSFunctionI[2] = sg_IK_B.Sum5;

  /* SignalConversion generated from: '<S158>/ SFunction ' incorporates:
   *  MATLAB Function: '<S5>/IVK_solver'
   */
  sg_IK_B.TmpSignalConversionAtSFunctio_h[0] = sg_IK_B.DataTypeConversion14[0];
  sg_IK_B.TmpSignalConversionAtSFunctio_h[1] = sg_IK_B.DataTypeConversion14[1];
  sg_IK_B.TmpSignalConversionAtSFunctio_h[2] = sg_IK_B.Sum3;
  sg_IK_B.TmpSignalConversionAtSFunctio_h[3] = sg_IK_B.Constant;
  sg_IK_B.TmpSignalConversionAtSFunctio_h[4] = sg_IK_B.Constant1;

  /* MATLAB Function: '<S5>/IVK_solver' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Ts'
   */
  yaw = *get_Ts();

  /* MATLAB Function 'Controller/Inverse velocity and forward kinematics/IVK_solver': '<S158>:1' */
  /* '<S158>:1:21' */
  /* '<S158>:1:20' */
  /* '<S158>:1:24' */
  /* '<S158>:1:54' */
  /* '<S158>:1:55' */
  /* '<S158>:1:6' */
  cy = sg_IK_B.DataTypeConversion4[3];
  x_pos = sg_IK_B.DataTypeConversion4[4];
  local_tf = sg_IK_B.DataTypeConversion4[5];

  /* '<S158>:1:18' */
  x_vel = cy;
  a3 = x_vel;
  a3 = std::cos(a3);
  x_vel = std::sin(x_vel);
  cy = x_vel;
  omgtheta[0] = a3;
  x_vel = x_pos;
  a3 = x_vel;
  a3 = std::cos(a3);
  x_vel = std::sin(x_vel);
  x_pos = x_vel;
  omgtheta[1] = a3;
  x_vel = local_tf;
  a3 = x_vel;
  a3 = std::cos(a3);
  x_vel = std::sin(x_vel);
  local_tf = x_vel;
  omgtheta[2] = a3;
  R_pBody_0[0] = omgtheta[1] * omgtheta[2];
  R_pBody_0[3] = -omgtheta[1] * local_tf;
  R_pBody_0[6] = x_pos;
  R_pBody_0[1] = cy * omgtheta[2] * x_pos + omgtheta[0] * local_tf;
  R_pBody_0[4] = omgtheta[0] * omgtheta[2] - cy * x_pos * local_tf;
  R_pBody_0[7] = -omgtheta[1] * cy;
  R_pBody_0[2] = cy * local_tf - omgtheta[0] * omgtheta[2] * x_pos;
  R_pBody_0[5] = omgtheta[0] * x_pos * local_tf + cy * omgtheta[2];
  R_pBody_0[8] = omgtheta[0] * omgtheta[1];

  /* '<S158>:1:20' */
  /* '<S158>:1:21' */
  /* '<S158>:1:24' */
  /* '<S158>:1:25' */
  for (ar = 0; ar < 3; ar++) {
    T_w_c[ar << 2] = R_pBody_0[3 * ar];
    T_w_c[(ar << 2) + 1] = R_pBody_0[3 * ar + 1];
    T_w_c[(ar << 2) + 2] = R_pBody_0[3 * ar + 2];
  }

  T_w_c[12] = sg_IK_B.DataTypeConversion4[0];
  T_w_c[13] = sg_IK_B.DataTypeConversion4[1];
  T_w_c[14] = sg_IK_B.DataTypeConversion4[2];
  T_w_c[3] = 0.0;
  T_w_c[7] = 0.0;
  T_w_c[11] = 0.0;
  T_w_c[15] = 1.0;
  for (ar = 0; ar < 4; ar++) {
    for (idx = 0; idx < 4; idx++) {
      T[ar + (idx << 2)] = 0.0;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[idx << 2] * g_a_1[ar];
      T[ar + (idx << 2)] = cy;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[(idx << 2) + 1] * g_a_1[ar + 4];
      T[ar + (idx << 2)] = cy;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[(idx << 2) + 2] * g_a_1[ar + 8];
      T[ar + (idx << 2)] = cy;
      cy = T[(idx << 2) + ar];
      cy += T_w_c[(idx << 2) + 3] * g_a_1[ar + 12];
      T[ar + (idx << 2)] = cy;
    }

    for (idx = 0; idx < 4; idx++) {
      g_a[ar + (idx << 2)] = 0.0;
      cy = g_a[(idx << 2) + ar];
      cy += c_b[idx << 2] * T[ar];
      g_a[ar + (idx << 2)] = cy;
      cy = g_a[(idx << 2) + ar];
      cy += c_b[(idx << 2) + 1] * T[ar + 4];
      g_a[ar + (idx << 2)] = cy;
      cy = g_a[(idx << 2) + ar];
      cy += c_b[(idx << 2) + 2] * T[ar + 8];
      g_a[ar + (idx << 2)] = cy;
      cy = g_a[(idx << 2) + ar];
      cy += c_b[(idx << 2) + 3] * T[ar + 12];
      g_a[ar + (idx << 2)] = cy;
    }

    for (idx = 0; idx < 4; idx++) {
      a[ar + (idx << 2)] = 0.0;
      cy = a[(idx << 2) + ar];
      cy += sg_IK_B.T_b_ee[idx << 2] * g_a[ar];
      a[ar + (idx << 2)] = cy;
      cy = a[(idx << 2) + ar];
      cy += sg_IK_B.T_b_ee[(idx << 2) + 1] * g_a[ar + 4];
      a[ar + (idx << 2)] = cy;
      cy = a[(idx << 2) + ar];
      cy += sg_IK_B.T_b_ee[(idx << 2) + 2] * g_a[ar + 8];
      a[ar + (idx << 2)] = cy;
      cy = a[(idx << 2) + ar];
      cy += sg_IK_B.T_b_ee[(idx << 2) + 3] * g_a[ar + 12];
      a[ar + (idx << 2)] = cy;
    }
  }

  /* '<S158>:1:29' */
  std::memcpy(&A[0], &sg_IK_cal->BList[0], 30U * sizeof(real_T));
  for (ar = 0; ar < 16; ar++) {
    T[ar] = 0.0;
  }

  T[0] = 1.0;
  T[5] = 1.0;
  T[10] = 1.0;
  T[15] = 1.0;
  T_w_c[0] = 0.0;
  T_w_c[5] = 0.0;
  T_w_c[10] = 0.0;
  T_w_c[3] = 0.0;
  T_w_c[7] = 0.0;
  T_w_c[11] = 0.0;
  T_w_c[15] = 0.0;
  b_omgmat[0] = 0.0;
  b_omgmat[4] = 0.0;
  b_omgmat[8] = 0.0;
  for (i = 0; i < 4; i++) {
    ar = 4 - i;
    local_tf = sg_IK_B.TmpSignalConversionAtSFunctio_h[4 - i];
    for (idx = 0; idx < 6; idx++) {
      V[idx] = -sg_IK_cal->BList[6 * ar + idx] * local_tf;
    }

    T_w_c[4] = -V[2];
    T_w_c[8] = V[1];
    T_w_c[1] = V[2];
    T_w_c[9] = -V[0];
    T_w_c[2] = -V[1];
    T_w_c[6] = V[0];
    T_w_c[12] = V[3];
    T_w_c[13] = V[4];
    T_w_c[14] = V[5];
    omgtheta[0] = T_w_c[6];
    omgtheta[1] = T_w_c[8];
    omgtheta[2] = T_w_c[1];
    if (std::abs(sg_IK_norm(omgtheta)) < 1.0E-6) {
      for (ar = 0; ar < 9; ar++) {
        b_I[ar] = 0;
      }

      b_I[0] = 1;
      b_I[4] = 1;
      b_I[8] = 1;
      for (ar = 0; ar < 3; ar++) {
        g_a[ar << 2] = b_I[3 * ar];
        g_a[(ar << 2) + 1] = b_I[3 * ar + 1];
        g_a[(ar << 2) + 2] = b_I[3 * ar + 2];
        g_a[ar + 12] = T_w_c[ar + 12];
      }

      g_a[3] = 0.0;
      g_a[7] = 0.0;
      g_a[11] = 0.0;
      g_a[15] = 1.0;
    } else {
      cy = sg_IK_norm(omgtheta);
      for (ar = 0; ar < 3; ar++) {
        R_pBody_0[3 * ar] = T_w_c[ar << 2] / cy;
        R_pBody_0[3 * ar + 1] = T_w_c[(ar << 2) + 1] / cy;
        R_pBody_0[3 * ar + 2] = T_w_c[(ar << 2) + 2] / cy;
      }

      for (ar = 0; ar < 9; ar++) {
        b_a[ar] = 0;
      }

      b_a[0] = 1;
      b_a[4] = 1;
      b_a[8] = 1;
      a3 = 1.0 - std::cos(cy);
      x_pos = cy - std::sin(cy);
      omgtheta[0] = T_w_c[6];
      omgtheta[1] = T_w_c[8];
      omgtheta[2] = T_w_c[1];
      if (std::abs(sg_IK_norm(omgtheta)) < 1.0E-6) {
        for (ar = 0; ar < 9; ar++) {
          R_cam[ar] = 0.0;
        }

        R_cam[0] = 1.0;
        R_cam[4] = 1.0;
        R_cam[8] = 1.0;
      } else {
        a2 = sg_IK_norm(omgtheta);
        for (ar = 0; ar < 3; ar++) {
          omgmat[3 * ar] = T_w_c[ar << 2] / a2;
          omgmat[3 * ar + 1] = T_w_c[(ar << 2) + 1] / a2;
          omgmat[3 * ar + 2] = T_w_c[(ar << 2) + 2] / a2;
        }

        local_tf = std::sin(a2);
        x_vel = 1.0 - std::cos(a2);
        for (ar = 0; ar < 9; ar++) {
          b_I[ar] = 0;
        }

        for (idx = 0; idx < 3; idx++) {
          b_I[idx + 3 * idx] = 1;
          for (ar = 0; ar < 3; ar++) {
            b_omgmat_0[idx + 3 * ar] = 0.0;
            a2 = b_omgmat_0[3 * ar + idx];
            a2 += omgmat[3 * ar] * omgmat[idx];
            b_omgmat_0[idx + 3 * ar] = a2;
            a2 = b_omgmat_0[3 * ar + idx];
            a2 += omgmat[3 * ar + 1] * omgmat[idx + 3];
            b_omgmat_0[idx + 3 * ar] = a2;
            a2 = b_omgmat_0[3 * ar + idx];
            a2 += omgmat[3 * ar + 2] * omgmat[idx + 6];
            b_omgmat_0[idx + 3 * ar] = a2;
          }
        }

        for (ar = 0; ar < 9; ar++) {
          R_cam[ar] = (local_tf * omgmat[ar] + static_cast<real_T>(b_I[ar])) +
            x_vel * b_omgmat_0[ar];
        }
      }

      for (ar = 0; ar < 3; ar++) {
        for (idx = 0; idx < 3; idx++) {
          R_pBody[ar + 3 * idx] = 0.0;
          local_tf = R_pBody[3 * idx + ar];
          local_tf += R_pBody_0[3 * idx] * R_pBody_0[ar];
          R_pBody[ar + 3 * idx] = local_tf;
          local_tf = R_pBody[3 * idx + ar];
          local_tf += R_pBody_0[3 * idx + 1] * R_pBody_0[ar + 3];
          R_pBody[ar + 3 * idx] = local_tf;
          local_tf = R_pBody[3 * idx + ar];
          local_tf += R_pBody_0[3 * idx + 2] * R_pBody_0[ar + 6];
          R_pBody[ar + 3 * idx] = local_tf;
        }
      }

      for (ar = 0; ar < 9; ar++) {
        b_a_0[ar] = (static_cast<real_T>(b_a[ar]) * cy + a3 * R_pBody_0[ar]) +
          x_pos * R_pBody[ar];
      }

      for (ar = 0; ar < 3; ar++) {
        local_tf = b_a_0[ar] * T_w_c[12];
        g_a[ar << 2] = R_cam[3 * ar];
        local_tf += b_a_0[ar + 3] * T_w_c[13];
        g_a[(ar << 2) + 1] = R_cam[3 * ar + 1];
        local_tf += b_a_0[ar + 6] * T_w_c[14];
        g_a[(ar << 2) + 2] = R_cam[3 * ar + 2];
        x_pos = local_tf / cy;
        g_a[ar + 12] = x_pos;
      }

      g_a[3] = 0.0;
      g_a[7] = 0.0;
      g_a[11] = 0.0;
      g_a[15] = 1.0;
    }

    for (ar = 0; ar < 4; ar++) {
      for (idx = 0; idx < 4; idx++) {
        T_0[ar + (idx << 2)] = 0.0;
        cy = T_0[(idx << 2) + ar];
        cy += g_a[idx << 2] * T[ar];
        T_0[ar + (idx << 2)] = cy;
        cy = T_0[(idx << 2) + ar];
        cy += g_a[(idx << 2) + 1] * T[ar + 4];
        T_0[ar + (idx << 2)] = cy;
        cy = T_0[(idx << 2) + ar];
        cy += g_a[(idx << 2) + 2] * T[ar + 8];
        T_0[ar + (idx << 2)] = cy;
        cy = T_0[(idx << 2) + ar];
        cy += g_a[(idx << 2) + 3] * T[ar + 12];
        T_0[ar + (idx << 2)] = cy;
      }
    }

    std::memcpy(&T[0], &T_0[0], sizeof(real_T) << 4U);
    b_omgmat[3] = -T[14];
    b_omgmat[6] = T[13];
    b_omgmat[1] = T[14];
    b_omgmat[7] = -T[12];
    b_omgmat[2] = -T[13];
    b_omgmat[5] = T[12];
    ar = 3 - i;
    for (idx = 0; idx < 3; idx++) {
      for (c = 0; c < 3; c++) {
        omgmat[idx + 3 * c] = 0.0;
        local_tf = omgmat[3 * c + idx];
        local_tf += T[c << 2] * b_omgmat[idx];
        omgmat[idx + 3 * c] = local_tf;
        local_tf = omgmat[3 * c + idx];
        local_tf += T[(c << 2) + 1] * b_omgmat[idx + 3];
        omgmat[idx + 3 * c] = local_tf;
        local_tf = omgmat[3 * c + idx];
        local_tf += T[(c << 2) + 2] * b_omgmat[idx + 6];
        omgmat[idx + 3 * c] = local_tf;
        T_1[c + 6 * idx] = T[(idx << 2) + c];
        T_1[c + 6 * (idx + 3)] = 0.0;
      }
    }

    for (idx = 0; idx < 3; idx++) {
      T_1[6 * idx + 3] = omgmat[3 * idx];
      T_1[6 * (idx + 3) + 3] = T[idx << 2];
      T_1[6 * idx + 4] = omgmat[3 * idx + 1];
      T_1[6 * (idx + 3) + 4] = T[(idx << 2) + 1];
      T_1[6 * idx + 5] = omgmat[3 * idx + 2];
      T_1[6 * (idx + 3) + 5] = T[(idx << 2) + 2];
    }

    idx = 3 - i;
    for (c = 0; c < 6; c++) {
      A[c + 6 * idx] = 0.0;
      for (ib = 0; ib < 6; ib++) {
        A[c + 6 * idx] += T_1[6 * ib + c] * sg_IK_cal->BList[6 * ar + ib];
      }
    }
  }

  /* '<S158>:1:30' */
  wasTunablePropsChanged = true;
  for (idx = 0; idx < 30; idx++) {
    cy = A[idx];
    Jb_pinv[idx] = 0.0;
    if (wasTunablePropsChanged && ((!rtIsInf(cy)) && (!rtIsNaN(cy)))) {
    } else {
      wasTunablePropsChanged = false;
    }
  }

  if (!wasTunablePropsChanged) {
    for (ar = 0; ar < 30; ar++) {
      Jb_pinv[ar] = (rtNaN);
    }
  } else {
    sg_IK_svd(A, U, s, b_V);
    cy = std::abs(s[0]);
    if ((!rtIsInf(cy)) && (!rtIsNaN(cy))) {
      if (cy <= 2.2250738585072014E-308) {
        cy = 4.94065645841247E-324;
      } else {
        frexp(cy, &vcol);
        cy = std::ldexp(1.0, vcol - 53);
      }
    } else {
      cy = (rtNaN);
    }

    cy *= 6.0;
    i = -1;
    idx = 0;
    while ((idx < 5) && (s[idx] > cy)) {
      i++;
      idx++;
    }

    if (i + 1 > 0) {
      vcol = 0;
      for (ar = 0; ar <= i; ar++) {
        a2 = 1.0 / s[ar];
        for (idx = vcol; idx < vcol + 5; idx++) {
          b_V[idx] *= a2;
        }

        vcol += 5;
      }

      for (vcol = 0; vcol <= 26; vcol += 5) {
        for (idx = vcol; idx < vcol + 5; idx++) {
          Jb_pinv[idx] = 0.0;
        }
      }

      idx = 0;
      for (vcol = 0; vcol <= 26; vcol += 5) {
        ar = -1;
        idx++;
        c = 6 * i + idx;
        for (ib = idx; ib <= c; ib += 6) {
          int32_T ia;
          ia = ar;
          for (int32_T b_ic = vcol; b_ic < vcol + 5; b_ic++) {
            ia++;
            Jb_pinv[b_ic] += U[ib - 1] * b_V[ia];
          }

          ar += 5;
        }
      }
    }
  }

  /* '<S158>:1:33' */
  /* '<S158>:1:46' */
  for (ar = 0; ar < 3; ar++) {
    R_pBody_0[3 * ar] = a[ar];
    R_pBody_0[3 * ar + 1] = a[ar + 4];
    R_pBody_0[3 * ar + 2] = a[ar + 8];
  }

  for (ar = 0; ar < 9; ar++) {
    R_pBody[ar] = -R_pBody_0[ar];
  }

  for (ar = 0; ar < 3; ar++) {
    local_tf = R_pBody[ar] * a[12];
    T[ar << 2] = R_pBody_0[3 * ar];
    local_tf += R_pBody[ar + 3] * a[13];
    T[(ar << 2) + 1] = R_pBody_0[3 * ar + 1];
    local_tf += R_pBody[ar + 6] * a[14];
    T[(ar << 2) + 2] = R_pBody_0[3 * ar + 2];
    T[ar + 12] = local_tf;
  }

  T[3] = 0.0;
  T[7] = 0.0;
  T[11] = 0.0;
  T[15] = 1.0;

  /* '<S158>:1:49' */
  b_omgmat[0] = 0.0;
  b_omgmat[3] = -T[14];
  b_omgmat[6] = T[13];
  b_omgmat[1] = T[14];
  b_omgmat[4] = 0.0;
  b_omgmat[7] = -T[12];
  b_omgmat[2] = -T[13];
  b_omgmat[5] = T[12];
  b_omgmat[8] = 0.0;
  for (ar = 0; ar < 3; ar++) {
    for (idx = 0; idx < 3; idx++) {
      omgmat[ar + 3 * idx] = 0.0;
      local_tf = omgmat[3 * idx + ar];
      local_tf += T[idx << 2] * b_omgmat[ar];
      omgmat[ar + 3 * idx] = local_tf;
      local_tf = omgmat[3 * idx + ar];
      local_tf += T[(idx << 2) + 1] * b_omgmat[ar + 3];
      omgmat[ar + 3 * idx] = local_tf;
      local_tf = omgmat[3 * idx + ar];
      local_tf += T[(idx << 2) + 2] * b_omgmat[ar + 6];
      omgmat[ar + 3 * idx] = local_tf;
      T_1[idx + 6 * ar] = T[(ar << 2) + idx];
      T_1[idx + 6 * (ar + 3)] = 0.0;
    }
  }

  for (ar = 0; ar < 3; ar++) {
    T_1[6 * ar + 3] = omgmat[3 * ar];
    T_1[6 * (ar + 3) + 3] = T[ar << 2];
    T_1[6 * ar + 4] = omgmat[3 * ar + 1];
    T_1[6 * (ar + 3) + 4] = T[(ar << 2) + 1];
    T_1[6 * ar + 5] = omgmat[3 * ar + 2];
    T_1[6 * (ar + 3) + 5] = T[(ar << 2) + 2];
  }

  V[0] = 0.0;
  V[1] = 0.0;
  V[2] = 0.0;
  V[3] = sg_IK_B.TmpSignalConversionAtSFunctionI[0];
  V[4] = sg_IK_B.TmpSignalConversionAtSFunctionI[1];
  V[5] = sg_IK_B.TmpSignalConversionAtSFunctionI[2];
  for (ar = 0; ar < 6; ar++) {
    T_2[ar] = 0.0;
  }

  for (idx = 0; idx < 6; idx++) {
    for (ar = 0; ar < 6; ar++) {
      cy = T_2[ar];
      cy += T_1[6 * idx + ar] * V[idx];
      T_2[ar] = cy;
    }
  }

  for (ar = 0; ar < 5; ar++) {
    sg_IK_B.thetaListDot[ar] = 0.0;
    for (idx = 0; idx < 6; idx++) {
      sg_IK_B.thetaListDot[ar] += Jb_pinv[5 * idx + ar] * T_2[idx];
    }
  }

  /* '<S158>:1:54' */
  /* '<S158>:1:55' */
  /* '<S158>:1:57' */
  b_omgmat[0] = 0.0;
  b_omgmat[3] = -T[14];
  b_omgmat[6] = T[13];
  b_omgmat[1] = T[14];
  b_omgmat[4] = 0.0;
  b_omgmat[7] = -T[12];
  b_omgmat[2] = -T[13];
  b_omgmat[5] = T[12];
  b_omgmat[8] = 0.0;
  for (ar = 0; ar < 3; ar++) {
    for (idx = 0; idx < 3; idx++) {
      omgmat[ar + 3 * idx] = 0.0;
      local_tf = omgmat[3 * idx + ar];
      local_tf += T[idx << 2] * b_omgmat[ar];
      omgmat[ar + 3 * idx] = local_tf;
      local_tf = omgmat[3 * idx + ar];
      local_tf += T[(idx << 2) + 1] * b_omgmat[ar + 3];
      omgmat[ar + 3 * idx] = local_tf;
      local_tf = omgmat[3 * idx + ar];
      local_tf += T[(idx << 2) + 2] * b_omgmat[ar + 6];
      omgmat[ar + 3 * idx] = local_tf;
      T_1[idx + 6 * ar] = T[(ar << 2) + idx];
      T_1[idx + 6 * (ar + 3)] = 0.0;
    }
  }

  for (ar = 0; ar < 3; ar++) {
    T_1[6 * ar + 3] = omgmat[3 * ar];
    T_1[6 * (ar + 3) + 3] = T[ar << 2];
    T_1[6 * ar + 4] = omgmat[3 * ar + 1];
    T_1[6 * (ar + 3) + 4] = T[(ar << 2) + 1];
    T_1[6 * ar + 5] = omgmat[3 * ar + 2];
    T_1[6 * (ar + 3) + 5] = T[(ar << 2) + 2];
  }

  V[0] = 0.0;
  V[1] = 0.0;
  V[2] = 0.0;
  V[3] = sg_IK_B.TmpSignalConversionAtSFunctionI[0];
  V[4] = sg_IK_B.TmpSignalConversionAtSFunctionI[1];
  V[5] = sg_IK_B.TmpSignalConversionAtSFunctionI[2];
  for (ar = 0; ar < 6; ar++) {
    T_2[ar] = 0.0;
  }

  for (idx = 0; idx < 6; idx++) {
    for (ar = 0; ar < 6; ar++) {
      cy = T_2[ar];
      cy += T_1[6 * idx + ar] * V[idx];
      T_2[ar] = cy;
    }
  }

  for (ar = 0; ar < 5; ar++) {
    s[ar] = 0.0;
    for (idx = 0; idx < 6; idx++) {
      cy = s[ar];
      cy += Jb_pinv[5 * idx + ar] * T_2[idx];
      s[ar] = cy;
    }
  }

  omgtheta[0] = s[0] * yaw + sg_IK_B.DataTypeConversion14[0];
  omgtheta[1] = s[1] * yaw + sg_IK_B.DataTypeConversion14[1];
  omgtheta[2] = s[2] * yaw + sg_IK_B.DataTypeConversion14[2];
  wasTunablePropsChanged = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    bClawInFrame = !(omgtheta[i] < g_0[i]);
    if (!bClawInFrame) {
      wasTunablePropsChanged = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  guard1 = false;
  if (wasTunablePropsChanged) {
    /* '<S158>:1:59' */
    guard1 = true;
  } else {
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      bClawInFrame = !(omgtheta[i] > h[i]);
      if (!bClawInFrame) {
        wasTunablePropsChanged = true;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (wasTunablePropsChanged) {
      /* '<S158>:1:59' */
      guard1 = true;
    } else {
      /* '<S158>:1:64' */
      sg_IK_B.Joint_LimitReached = false;
    }
  }

  if (guard1) {
    /* '<S158>:1:61' */
    for (i = 0; i < 5; i++) {
      sg_IK_B.thetaListDot[i] = 0.0;
    }

    /* '<S158>:1:62' */
    sg_IK_B.Joint_LimitReached = true;
  }

  /* MultiPortSwitch: '<S1>/SWITCH1' */
  if (static_cast<int32_T>(sg_IK_B.controlMode) == 1) {
    /* MultiPortSwitch: '<S1>/SWITCH1' */
    sg_IK_B.SWITCH1 = sg_IK_B.thetaListDot[0];
  } else {
    /* MultiPortSwitch: '<S1>/SWITCH1' incorporates:
     *  Constant: '<S1>/Zero_ref'
     */
    sg_IK_B.SWITCH1 = sg_IK_cal->Zero_ref_Value;
  }

  /* End of MultiPortSwitch: '<S1>/SWITCH1' */

  /* Saturate: '<S1>/Saturation2' */
  yaw = sg_IK_B.SWITCH1;
  cy = sg_IK_cal->Saturation2_LowerSat;
  x_pos = sg_IK_cal->Saturation2_UpperSat;
  if (yaw > x_pos) {
    /* Saturate: '<S1>/Saturation2' */
    sg_IK_B.Saturation2 = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S1>/Saturation2' */
    sg_IK_B.Saturation2 = cy;
  } else {
    /* Saturate: '<S1>/Saturation2' */
    sg_IK_B.Saturation2 = yaw;
  }

  /* End of Saturate: '<S1>/Saturation2' */

  /* DataTypeConversion: '<S1>/Cast To Single1' */
  sg_IK_B.CastToSingle1 = static_cast<real32_T>(sg_IK_B.Saturation2);

  /* MultiPortSwitch: '<S1>/SWITCH2' */
  if (static_cast<int32_T>(sg_IK_B.controlMode) == 1) {
    /* MultiPortSwitch: '<S1>/SWITCH2' */
    sg_IK_B.SWITCH2 = sg_IK_B.thetaListDot[1];
  } else {
    /* MultiPortSwitch: '<S1>/SWITCH2' incorporates:
     *  Constant: '<S1>/Zero_ref'
     */
    sg_IK_B.SWITCH2 = sg_IK_cal->Zero_ref_Value;
  }

  /* End of MultiPortSwitch: '<S1>/SWITCH2' */

  /* Saturate: '<S1>/Saturation3' */
  yaw = sg_IK_B.SWITCH2;
  cy = sg_IK_cal->Saturation3_LowerSat;
  x_pos = sg_IK_cal->Saturation3_UpperSat;
  if (yaw > x_pos) {
    /* Saturate: '<S1>/Saturation3' */
    sg_IK_B.Saturation3 = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S1>/Saturation3' */
    sg_IK_B.Saturation3 = cy;
  } else {
    /* Saturate: '<S1>/Saturation3' */
    sg_IK_B.Saturation3 = yaw;
  }

  /* End of Saturate: '<S1>/Saturation3' */

  /* DataTypeConversion: '<S1>/Cast To Single2' */
  sg_IK_B.CastToSingle2 = static_cast<real32_T>(sg_IK_B.Saturation3);

  /* MultiPortSwitch: '<S1>/SWITCH3' */
  if (static_cast<int32_T>(sg_IK_B.controlMode) == 1) {
    /* Sum: '<S160>/Sum2' */
    sg_IK_B.Sum2_h = sg_IK_B.thetaListDot[2] - sg_IK_B.thetaListDot[1];

    /* MultiPortSwitch: '<S1>/SWITCH3' */
    sg_IK_B.SWITCH3 = sg_IK_B.Sum2_h;
  } else {
    /* MultiPortSwitch: '<S1>/SWITCH3' incorporates:
     *  Constant: '<S1>/Zero_ref'
     */
    sg_IK_B.SWITCH3 = sg_IK_cal->Zero_ref_Value;
  }

  /* End of MultiPortSwitch: '<S1>/SWITCH3' */

  /* Saturate: '<S1>/Saturation4' */
  yaw = sg_IK_B.SWITCH3;
  cy = sg_IK_cal->Saturation4_LowerSat;
  x_pos = sg_IK_cal->Saturation4_UpperSat;
  if (yaw > x_pos) {
    /* Saturate: '<S1>/Saturation4' */
    sg_IK_B.Saturation4 = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S1>/Saturation4' */
    sg_IK_B.Saturation4 = cy;
  } else {
    /* Saturate: '<S1>/Saturation4' */
    sg_IK_B.Saturation4 = yaw;
  }

  /* End of Saturate: '<S1>/Saturation4' */

  /* DataTypeConversion: '<S1>/Cast To Single3' */
  sg_IK_B.CastToSingle3 = static_cast<real32_T>(sg_IK_B.Saturation4);

  /* MultiPortSwitch: '<S163>/Multiport Switch6' incorporates:
   *  MultiPortSwitch: '<S163>/Multiport Switch4'
   */
  if (static_cast<int32_T>(sg_IK_B.Operation_Mode) == 1) {
    /* MultiPortSwitch: '<S163>/Multiport Switch6' */
    sg_IK_B.MultiportSwitch6 = sg_IK_B.Winch_Mode_selector;

    /* MultiPortSwitch: '<S163>/Multiport Switch4' */
    sg_IK_B.MultiportSwitch4 = sg_IK_B.Winch_PosRef_e;
  } else {
    /* MultiPortSwitch: '<S163>/Multiport Switch6' incorporates:
     *  Constant: '<S163>/Constant4'
     */
    sg_IK_B.MultiportSwitch6 = sg_IK_cal->Constant4_Value;

    /* MultiPortSwitch: '<S163>/Multiport Switch4' incorporates:
     *  Constant: '<S163>/Constant1'
     */
    sg_IK_B.MultiportSwitch4 = sg_IK_cal->Winch_PosRef;
  }

  /* End of MultiPortSwitch: '<S163>/Multiport Switch6' */

  /* MATLABSystem: '<S168>/Lowpass Filter1' */
  yaw = sg_IK_B.MultiportSwitch4;
  obj = &sg_IK_DW.obj;
  wasTunablePropsChanged = false;
  obj_0 = obj->FilterObj;
  if (obj_0->isInitialized != 1) {
    obj_1 = obj_0;
    obj_2 = obj_1;
    obj_2->isSetupComplete = false;
    obj_2->isInitialized = 1;
    obj_2->isSetupComplete = true;
    obj_3 = &obj_1->cSFunObject;

    /* System object Initialization function: dsp.FIRFilter */
    for (ar = 0; ar < 762; ar++) {
      obj_3->W0_states[ar] = obj_3->P0_InitialStates;
    }
  }

  obj_3 = &obj_0->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  cy = 0.0;

  /* load input sample */
  for (ar = 0; ar < 762; ar++) {
    /* shift state */
    x_pos = yaw;
    yaw = obj_3->W0_states[ar];
    obj_3->W0_states[ar] = x_pos;

    /* compute one tap */
    x_pos *= obj_3->P1_Coefficients[ar];
    cy += x_pos;
  }

  /* compute last tap */
  x_pos = obj_3->P1_Coefficients[ar] * yaw;
  cy += x_pos;

  /* store output sample */
  yaw = cy;

  /* MATLABSystem: '<S168>/Lowpass Filter1' */
  sg_IK_B.Winch_PosRef = yaw;

  /* MATLAB Function: '<S168>/Winch_Local_to_Global' */
  /* MATLAB Function 'Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/Winch_Local_to_Global': '<S172>:1' */
  /* '<S172>:1:4' */
  /* '<S172>:1:7' */
  sg_IK_B.Winch_Global_Pos_Z = sg_IK_B.Endeff_world_xyz[2] - (sg_IK_B.Pos -
    0.202);

  /* Sum: '<S168>/Sum' */
  sg_IK_B.Winch_e = sg_IK_B.Winch_PosRef - sg_IK_B.Winch_Global_Pos_Z;

  /* Gain: '<S209>/Proportional Gain' */
  sg_IK_B.ProportionalGain_b = sg_IK_cal->DiscretePIDController_P_h *
    sg_IK_B.Winch_e;

  /* DiscreteIntegrator: '<S204>/Integrator' */
  sg_IK_B.Integrator_e = sg_IK_DW.Integrator_DSTATE_j;

  /* Sum: '<S213>/Sum' */
  sg_IK_B.Sum_e = sg_IK_B.ProportionalGain_b + sg_IK_B.Integrator_e;
  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion10' */
    sg_IK_B.DataTypeConversion10[i] = sg_IK_B.Em1500_transvel_and_rpyvel[i];
  }

  /* MATLAB Function: '<S168>/FeedForward_Switch' */
  /* MATLAB Function 'Controller/Winch_Controller/Winch_Camera_Based_HeaveComp/FeedForward_Switch': '<S171>:1' */
  /* '<S171>:1:2' */
  if (sg_IK_B.FF_Flag != 0.0) {
    /* '<S171>:1:3' */
    /* '<S171>:1:4' */
    sg_IK_B.Vel_FF_n = static_cast<real32_T>(-sg_IK_B.DataTypeConversion10[2]);
  } else {
    /* '<S171>:1:6' */
    sg_IK_B.Vel_FF_n = 0.0F;
  }

  /* End of MATLAB Function: '<S168>/FeedForward_Switch' */

  /* Sum: '<S168>/Sum2' */
  sg_IK_B.Sum2_i = sg_IK_B.Sum_e + sg_IK_B.Vel_FF_n;

  /* Saturate: '<S168>/Saturation1' */
  yaw = sg_IK_B.Sum2_i;
  cy = sg_IK_cal->Saturation1_LowerSat_j;
  x_pos = sg_IK_cal->Saturation1_UpperSat_b;
  if (yaw > x_pos) {
    /* Saturate: '<S168>/Saturation1' */
    sg_IK_B.Saturation1 = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S168>/Saturation1' */
    sg_IK_B.Saturation1 = cy;
  } else {
    /* Saturate: '<S168>/Saturation1' */
    sg_IK_B.Saturation1 = yaw;
  }

  /* End of Saturate: '<S168>/Saturation1' */

  /* Gain: '<S168>/Gain' */
  sg_IK_B.Gain = sg_IK_cal->Gain_Gain_h * sg_IK_B.Saturation1;

  /* MultiPortSwitch: '<S163>/Multiport Switch5' */
  if (static_cast<int32_T>(sg_IK_B.Operation_Mode) == 1) {
    /* MultiPortSwitch: '<S163>/Multiport Switch5' */
    sg_IK_B.MultiportSwitch5 = sg_IK_B.Winch_NewCmd;
  } else {
    /* MultiPortSwitch: '<S163>/Multiport Switch5' incorporates:
     *  Constant: '<S163>/Constant2'
     */
    sg_IK_B.MultiportSwitch5 = sg_IK_cal->Winch_NewCmd;
  }

  /* End of MultiPortSwitch: '<S163>/Multiport Switch5' */

  /* MATLAB Function: '<S169>/Winch_Local_to_Global' */
  /* MATLAB Function 'Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Winch_Local_to_Global': '<S222>:1' */
  /* '<S222>:1:3' */
  /* '<S222>:1:5' */
  sg_IK_B.Winch_Global_Pos_Z_out = sg_IK_B.Endeff_world_xyz[2] - (sg_IK_B.Pos -
    0.202);

  /* Clock: '<S169>/Clock1' */
  sg_IK_B.Clock1 = sg_IK_M->Timing.t[0];
  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion9' */
    sg_IK_B.DataTypeConversion9[i] = sg_IK_B.Em1500_transpos_and_rpy[i];
  }

  /* MultiPortSwitch: '<S169>/Multiport Switch' incorporates:
   *  Constant: '<S169>/Constant1'
   */
  if (static_cast<int32_T>(sg_IK_cal->Operation_Mode) == 1) {
    /* MultiPortSwitch: '<S169>/Multiport Switch' */
    sg_IK_B.MultiportSwitch_f = sg_IK_B.FF_Flag;
  } else {
    /* MultiPortSwitch: '<S169>/Multiport Switch' incorporates:
     *  Constant: '<S169>/Constant'
     */
    sg_IK_B.MultiportSwitch_f = sg_IK_cal->Winch_EnableHeaveComp;
  }

  /* End of MultiPortSwitch: '<S169>/Multiport Switch' */

  /* MATLAB Function: '<S169>/Winch_Posref_ramp_generator' */
  /* MATLAB Function 'Controller/Winch_Controller/Winch_StewartFB_Based_HeaveComp/Winch_Posref_ramp_generator': '<S223>:1' */
  /* '<S223>:1:3' */
  /* '<S223>:1:4' */
  if ((sg_IK_B.DataTypeConversion9[2] >= 0.464) && (sg_IK_B.DataTypeConversion9
       [2] <= 0.468)) {
    /* '<S223>:1:9' */
    /* '<S223>:1:10' */
    wasTunablePropsChanged = true;
  } else {
    /* '<S223>:1:12' */
  }

  /* '<S223>:1:15' */
  if (!sg_IK_DW.first_run_not_empty) {
    /* '<S223>:1:24' */
    /* '<S223>:1:25' */
    sg_IK_DW.last_command = sg_IK_B.MultiportSwitch5;

    /* '<S223>:1:27' */
    sg_IK_DW.command_start_time = sg_IK_B.Clock1;

    /* '<S223>:1:31' */
    sg_IK_DW.target_idle_base_pos = sg_IK_B.Winch_Global_Pos_Z_out;

    /* '<S223>:1:32' */
    sg_IK_DW.command_start_pos = sg_IK_DW.target_idle_base_pos;

    /* '<S223>:1:33' */
    sg_IK_DW.current_target_pos = sg_IK_DW.target_idle_base_pos;
    sg_IK_DW.first_run_not_empty = true;
  }

  if (sg_IK_B.MultiportSwitch5 != sg_IK_DW.last_command) {
    /* '<S223>:1:41' */
    /* '<S223>:1:42' */
    sg_IK_DW.command_start_pos = sg_IK_B.Winch_Global_Pos_Z_out;

    /* '<S223>:1:43' */
    sg_IK_DW.current_target_pos = sg_IK_B.MultiportSwitch4;

    /* '<S223>:1:44' */
    yaw = sg_IK_DW.current_target_pos - sg_IK_DW.command_start_pos;
    if (std::abs(yaw) > 1.0E-6) {
      /* '<S223>:1:48' */
      /* '<S223>:1:49' */
      sg_IK_DW.is_moving = true;

      /* '<S223>:1:50' */
      sg_IK_DW.command_start_time = sg_IK_B.Clock1;

      /* '<S223>:1:51' */
      /* '<S223>:1:52' */
      if (yaw < 0.0) {
        cy = -1.0;
      } else if (yaw > 0.0) {
        cy = 1.0;
      } else if (yaw == 0.0) {
        cy = 0.0;
      } else {
        cy = (rtNaN);
      }

      sg_IK_DW.actual_move_vel = cy * 0.05;

      /* '<S223>:1:53' */
      sg_IK_DW.T_move = std::abs(yaw) / 0.05;
    } else {
      /* '<S223>:1:56' */
      sg_IK_DW.is_moving = false;

      /* '<S223>:1:57' */
      sg_IK_DW.T_move = 0.0;

      /* '<S223>:1:58' */
      sg_IK_DW.actual_move_vel = 0.0;
      if (std::abs(yaw) <= 1.0E-6) {
        /* '<S223>:1:60' */
        /* '<S223>:1:61' */
        sg_IK_DW.target_idle_base_pos = sg_IK_DW.current_target_pos;
      }
    }

    /* '<S223>:1:64' */
    sg_IK_DW.last_command = sg_IK_B.MultiportSwitch5;
  }

  /* '<S223>:1:69' */
  cy = sg_IK_DW.target_idle_base_pos;

  /* '<S223>:1:70' */
  yaw = 0.0;
  if (sg_IK_DW.is_moving) {
    /* '<S223>:1:73' */
    /* '<S223>:1:74' */
    cy = sg_IK_B.Clock1 - sg_IK_DW.command_start_time;
    if ((cy < sg_IK_DW.T_move) && (sg_IK_DW.T_move > 0.0)) {
      /* '<S223>:1:77' */
      /* '<S223>:1:79' */
      cy = sg_IK_DW.actual_move_vel * cy + sg_IK_DW.command_start_pos;

      /* '<S223>:1:80' */
      yaw = sg_IK_DW.actual_move_vel;
    } else {
      /* '<S223>:1:83' */
      cy = sg_IK_DW.current_target_pos;

      /* '<S223>:1:84' */
      /* '<S223>:1:85' */
      sg_IK_DW.target_idle_base_pos = sg_IK_DW.current_target_pos;

      /* '<S223>:1:86' */
      sg_IK_DW.is_moving = false;

      /* '<S223>:1:87' */
      sg_IK_DW.actual_move_vel = 0.0;

      /* '<S223>:1:88' */
      sg_IK_DW.T_move = 0.0;
    }
  }

  if ((sg_IK_B.MultiportSwitch_f != 0.0) && (!wasTunablePropsChanged)) {
    /* '<S223>:1:93' */
    /* '<S223>:1:95' */
    sg_IK_B.PosRef = cy - sg_IK_B.DataTypeConversion9[2];

    /* '<S223>:1:97' */
    sg_IK_B.Vel_FF = yaw - sg_IK_B.DataTypeConversion10[2];
  } else {
    /* '<S223>:1:99' */
    sg_IK_B.PosRef = cy;

    /* '<S223>:1:100' */
    sg_IK_B.Vel_FF = yaw;
  }

  /* End of MATLAB Function: '<S169>/Winch_Posref_ramp_generator' */

  /* Sum: '<S169>/Sum' */
  sg_IK_B.Winch_e_f = sg_IK_B.PosRef - sg_IK_B.Winch_Global_Pos_Z_out;

  /* Gain: '<S260>/Proportional Gain' */
  sg_IK_B.ProportionalGain_a = sg_IK_cal->DiscretePIDController_P_l *
    sg_IK_B.Winch_e_f;

  /* DiscreteIntegrator: '<S255>/Integrator' */
  sg_IK_B.Integrator_o = sg_IK_DW.Integrator_DSTATE_cl;

  /* Sum: '<S264>/Sum' */
  sg_IK_B.Sum_o = sg_IK_B.ProportionalGain_a + sg_IK_B.Integrator_o;

  /* MultiPortSwitch: '<S9>/Multiport Switch1' */
  if (static_cast<int32_T>(sg_IK_B.MultiportSwitch6) == 1) {
    /* MultiPortSwitch: '<S9>/Multiport Switch1' */
    sg_IK_B.MultiportSwitch1_a = sg_IK_B.Gain;
  } else {
    /* Sum: '<S169>/Sum2' */
    sg_IK_B.Sum2_j = sg_IK_B.Sum_o + sg_IK_B.Vel_FF;

    /* Saturate: '<S169>/Saturation1' */
    yaw = sg_IK_B.Sum2_j;
    cy = sg_IK_cal->Saturation1_LowerSat;
    x_pos = sg_IK_cal->Saturation1_UpperSat;
    if (yaw > x_pos) {
      /* Saturate: '<S169>/Saturation1' */
      sg_IK_B.Saturation1_k = x_pos;
    } else if (yaw < cy) {
      /* Saturate: '<S169>/Saturation1' */
      sg_IK_B.Saturation1_k = cy;
    } else {
      /* Saturate: '<S169>/Saturation1' */
      sg_IK_B.Saturation1_k = yaw;
    }

    /* End of Saturate: '<S169>/Saturation1' */

    /* Gain: '<S169>/Gain' */
    sg_IK_B.Gain_f = sg_IK_cal->Gain_Gain * sg_IK_B.Saturation1_k;

    /* MultiPortSwitch: '<S9>/Multiport Switch1' */
    sg_IK_B.MultiportSwitch1_a = sg_IK_B.Gain_f;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch1' */

  /* MultiPortSwitch: '<S1>/SWITCH4' */
  if (static_cast<int32_T>(sg_IK_B.controlMode) == 1) {
    /* MultiPortSwitch: '<S1>/SWITCH4' */
    sg_IK_B.SWITCH4 = sg_IK_B.MultiportSwitch1_a;
  } else {
    /* MultiPortSwitch: '<S1>/SWITCH4' incorporates:
     *  Constant: '<S1>/Zero_ref'
     */
    sg_IK_B.SWITCH4 = sg_IK_cal->Zero_ref_Value;
  }

  /* End of MultiPortSwitch: '<S1>/SWITCH4' */

  /* Saturate: '<S1>/Saturation1' */
  yaw = sg_IK_B.SWITCH4;
  cy = sg_IK_cal->Saturation1_LowerSat_e;
  x_pos = sg_IK_cal->Saturation1_UpperSat_a;
  if (yaw > x_pos) {
    /* Saturate: '<S1>/Saturation1' */
    sg_IK_B.Saturation1_a = x_pos;
  } else if (yaw < cy) {
    /* Saturate: '<S1>/Saturation1' */
    sg_IK_B.Saturation1_a = cy;
  } else {
    /* Saturate: '<S1>/Saturation1' */
    sg_IK_B.Saturation1_a = yaw;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DataTypeConversion: '<S1>/Cast To Single' */
  sg_IK_B.CastToSingle = static_cast<real32_T>(sg_IK_B.Saturation1_a);

  /* S-Function (slrealtimebytepacking): '<S3>/Byte Packing' incorporates:
   *  Inport: '<Root>/Input1'
   *  Inport: '<Root>/Input2'
   *  Inport: '<Root>/Input3'
   */

  /* Byte Packing: <S3>/Byte Packing */
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 0, (uint8_T*)&sg_IK_U.Input1
               [0], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 4, (uint8_T*)&sg_IK_B.Add, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 8, (uint8_T*)&sg_IK_U.Input1
               [2], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 12, (uint8_T*)
               &sg_IK_U.Input2[0], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 16, (uint8_T*)
               &sg_IK_U.Input2[1], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 20, (uint8_T*)
               &sg_IK_U.Input2[2], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 24, (uint8_T*)
               &sg_IK_U.Input2[3], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 28, (uint8_T*)
               &sg_IK_U.Input2[4], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 32, (uint8_T*)
               &sg_IK_U.Input2[5], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 36, (uint8_T*)
               &sg_IK_U.Input2[6], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 40, (uint8_T*)
               &sg_IK_U.Input2[7], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 44, (uint8_T*)
               &sg_IK_U.Input2[8], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 48, (uint8_T*)
               &sg_IK_U.Input2[9], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 52, (uint8_T*)
               &sg_IK_U.Input2[10], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 56, (uint8_T*)
               &sg_IK_U.Input2[11], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 60, (uint8_T*)
               &sg_IK_U.Input2[12], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 64, (uint8_T*)
               &sg_IK_U.Input2[13], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 68, (uint8_T*)
               &sg_IK_U.Input2[14], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 72, (uint8_T*)
               &sg_IK_U.Input2[15], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 76, (uint8_T*)
               &sg_IK_U.Input2[16], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 80, (uint8_T*)
               &sg_IK_U.Input2[17], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 84, (uint8_T*)
               &sg_IK_U.Input2[18], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 88, (uint8_T*)
               &sg_IK_U.Input2[19], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 92, (uint8_T*)
               &sg_IK_U.Input2[20], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 96, (uint8_T*)
               &sg_IK_U.Input2[21], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 100, (uint8_T*)
               &sg_IK_U.Input2[22], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 104, (uint8_T*)
               &sg_IK_U.Input2[23], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 108, (uint8_T*)
               &sg_IK_B.CastToSingle1, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 112, (uint8_T*)
               &sg_IK_B.CastToSingle2, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 116, (uint8_T*)
               &sg_IK_B.CastToSingle3, 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 120, (uint8_T*)
               &sg_IK_U.Input3[0], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 124, (uint8_T*)
               &sg_IK_U.Input3[1], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 128, (uint8_T*)
               &sg_IK_U.Input3[2], 4);
  (void)memcpy((uint8_T*)&sg_IK_B.BytePacking[0] + 132, (uint8_T*)
               &sg_IK_B.CastToSingle, 4);

  /* S-Function (slrealtimeUDPSend): '<S3>/UDP Send' */
  {
    try {
      slrealtime::ip::udp::Socket *udpSock = reinterpret_cast<slrealtime::ip::
        udp::Socket*>(sg_IK_DW.UDPSend_PWORK);
      uint8_t *remoteAddress = (uint8_t *)sg_IK_cal->UDPSend_toAddress;
      uint16_t *remotePort = (uint16_t *)&sg_IK_cal->UDPSend_toPort;
      udpSock->resetRemoteEndpoint(remoteAddress, remotePort);
      int dataLen = sg_IK_ConstB.Width;
      dataLen = (dataLen <= sg_IK_DW.UDPSend_IWORK[0]) ? dataLen :
        sg_IK_DW.UDPSend_IWORK[0];
      dataLen = (dataLen <= -1) ? 0 : dataLen;
      void *dataPort = &sg_IK_B.BytePacking[0];
      size_t numBytesSend = udpSock->send((const char*)dataPort,dataLen);
    } catch (std::exception& e) {
      std::string tmp = std::string(e.what());
      static std::string eMsg = tmp;
      rtmSetErrorStatus(sg_IK_M, eMsg.c_str());
      rtmSetStopRequested(sg_IK_M, 1);
      ;
    }
  }

  /* Gain: '<S41>/Integral Gain' */
  sg_IK_B.IntegralGain = sg_IK_cal->DiscretePIDController_I * sg_IK_B.Sum_f;

  /* Gain: '<S89>/Integral Gain' */
  sg_IK_B.IntegralGain_p = sg_IK_cal->DiscretePIDController1_I * sg_IK_B.Sum1;

  /* Gain: '<S137>/Integral Gain' */
  sg_IK_B.IntegralGain_f = sg_IK_cal->DiscretePIDController2_I * sg_IK_B.Sum2;

  /* SignalConversion generated from: '<S5>/Theta3 = (Theta3*+90deg) + Theta2' */
  sg_IK_B.theta0[0] = sg_IK_B.DataTypeConversion14[0];
  sg_IK_B.theta0[1] = sg_IK_B.DataTypeConversion14[1];
  sg_IK_B.theta0[2] = sg_IK_B.Sum3;
  sg_IK_B.theta0[3] = sg_IK_B.Constant;
  sg_IK_B.theta0[4] = sg_IK_B.Constant1;

  /* SignalConversion generated from: '<S157>/Mux1' */
  sg_IK_B.x_IK[0] = sg_IK_B.Endeff_world_xyz[0];
  sg_IK_B.x_IK[1] = sg_IK_B.Constant7;

  /* SignalConversion generated from: '<S157>/Mux2' */
  sg_IK_B.y_IK[0] = sg_IK_B.Endeff_world_xyz[1];
  sg_IK_B.y_IK[1] = sg_IK_B.Constant5;

  /* SignalConversion generated from: '<S157>/Mux3' */
  sg_IK_B.z_IK[0] = sg_IK_B.Endeff_world_xyz[2];
  sg_IK_B.z_IK[1] = sg_IK_B.Constant6;

  /* DataTypeConversion: '<S8>/Boolean' */
  sg_IK_B.UDP_Hooked_flag = (sg_IK_B.Byte_Unpacking_o2 != 0);

  /* Gain: '<S201>/Integral Gain' */
  sg_IK_B.IntegralGain_l = sg_IK_cal->DiscretePIDController_I_c *
    sg_IK_B.Winch_e;

  /* Gain: '<S252>/Integral Gain' */
  sg_IK_B.IntegralGain_o = sg_IK_cal->DiscretePIDController_I_f *
    sg_IK_B.Winch_e_f;

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  sg_IK_B.Vel = sg_IK_B.Winch_vel;
  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    sg_IK_B.DataTypeConversion1[i] = sg_IK_B.Comau_theta_vel[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion6' */
    sg_IK_B.DataTypeConversion6[i] = sg_IK_B.Em8000_tranacc_and_rpyacc[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion7' */
    sg_IK_B.DataTypeConversion7[i] = sg_IK_B.Em8000_MRU_transpos_and_rpy[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion8' */
    sg_IK_B.DataTypeConversion8[i] = sg_IK_B.Em8000_MRU_transvel_and_rpyvel[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion11' */
    sg_IK_B.DataTypeConversion11[i] = sg_IK_B.Em1500_tranacc_and_rpyacc[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion12' */
    sg_IK_B.DataTypeConversion12[i] = sg_IK_B.Em1500_MRU_transpos_and_rpy[i];
  }

  for (i = 0; i < 6; i++) {
    /* DataTypeConversion: '<S2>/Data Type Conversion13' */
    sg_IK_B.DataTypeConversion13[i] = sg_IK_B.Em1500_MRU_transvel_and_rpyvel[i];
  }

  /* Update for Delay: '<S3>/Delay' */
  sg_IK_DW.Delay_DSTATE = sg_IK_B.Add;

  /* Update for Memory: '<S7>/Memory2' */
  sg_IK_DW.Memory2_PreviousInput = sg_IK_B.Traj_Running;

  /* Update for Memory: '<S5>/Memory3' */
  sg_IK_DW.Memory3_PreviousInput = sg_IK_B.Joint_LimitReached;

  /* Update for DiscreteIntegrator: '<S44>/Integrator' */
  sg_IK_DW.Integrator_DSTATE += sg_IK_cal->Integrator_gainval *
    sg_IK_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S92>/Integrator' */
  sg_IK_DW.Integrator_DSTATE_c += sg_IK_cal->Integrator_gainval_i *
    sg_IK_B.IntegralGain_p;

  /* Update for DiscreteIntegrator: '<S140>/Integrator' */
  sg_IK_DW.Integrator_DSTATE_n += sg_IK_cal->Integrator_gainval_h *
    sg_IK_B.IntegralGain_f;

  /* Update for DiscreteIntegrator: '<S204>/Integrator' */
  sg_IK_DW.Integrator_DSTATE_j += sg_IK_cal->Integrator_gainval_hf *
    sg_IK_B.IntegralGain_l;

  /* Update for DiscreteIntegrator: '<S255>/Integrator' */
  sg_IK_DW.Integrator_DSTATE_cl += sg_IK_cal->Integrator_gainval_j *
    sg_IK_B.IntegralGain_o;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sg_IK_M->Timing.clockTick0)) {
    ++sg_IK_M->Timing.clockTickH0;
  }

  sg_IK_M->Timing.t[0] = sg_IK_M->Timing.clockTick0 * sg_IK_M->Timing.stepSize0
    + sg_IK_M->Timing.clockTickH0 * sg_IK_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    sg_IK_M->Timing.clockTick1++;
    if (!sg_IK_M->Timing.clockTick1) {
      sg_IK_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void sg_IK_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sg_IK_M->solverInfo, &sg_IK_M->Timing.simTimeStep);
    rtsiSetTPtr(&sg_IK_M->solverInfo, &rtmGetTPtr(sg_IK_M));
    rtsiSetStepSizePtr(&sg_IK_M->solverInfo, &sg_IK_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sg_IK_M->solverInfo, (&rtmGetErrorStatus(sg_IK_M)));
    rtsiSetRTModelPtr(&sg_IK_M->solverInfo, sg_IK_M);
  }

  rtsiSetSimTimeStep(&sg_IK_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&sg_IK_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(sg_IK_M, &sg_IK_M->Timing.tArray[0]);
  sg_IK_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&sg_IK_B)), 0,
                     sizeof(B_sg_IK_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion4[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion5[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion14[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.CastToDouble[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.MultiportSwitch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion10[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion9[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      sg_IK_B.theta0[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion6[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion7[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion8[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion11[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion12[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.DataTypeConversion13[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Traj_points_XYZ[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      sg_IK_B.TmpSignalConversionAtSFunctio_h[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      sg_IK_B.thetaListDot[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      sg_IK_B.TmpSignalConversionAtSFunctio_a[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      sg_IK_B.T_w_ee[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      sg_IK_B.T_b_ee[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Comau_theta[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Comau_theta_vel[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em8000_transpos_and_rpy[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em8000_transvel_and_rpyvel[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em8000_tranacc_and_rpyacc[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em8000_MRU_transpos_and_rpy[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em8000_MRU_transvel_and_rpyvel[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em1500_transpos_and_rpy[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em1500_transvel_and_rpyvel[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em1500_tranacc_and_rpyacc[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em1500_MRU_transpos_and_rpy[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      sg_IK_B.Em1500_MRU_transvel_and_rpyvel[i] = 0.0F;
    }

    sg_IK_B.controlMode = 0.0;
    sg_IK_B.UDPReceive_o2 = 0.0;
    sg_IK_B.Sum = 0.0;
    sg_IK_B.Sum3 = 0.0;
    sg_IK_B.Constant = 0.0;
    sg_IK_B.Constant1 = 0.0;
    sg_IK_B.Operation_Mode = 0.0;
    sg_IK_B.Constant_f = 0.0;
    sg_IK_B.MS_Switch = 0.0;
    sg_IK_B.enable_65cm_offset_Em8000 = 0.0;
    sg_IK_B.UDPReceive_o2_c = 0.0;
    sg_IK_B.CastToDouble1[0] = 0.0;
    sg_IK_B.CastToDouble1[1] = 0.0;
    sg_IK_B.CastToDouble1[2] = 0.0;
    sg_IK_B.CastToDouble1[3] = 0.0;
    sg_IK_B.DataTypeConversion2 = 0.0;
    sg_IK_B.Pos = 0.0;
    sg_IK_B.Constant7 = 0.0;
    sg_IK_B.Constant5 = 0.0;
    sg_IK_B.Constant6 = 0.0;
    sg_IK_B.Clock = 0.0;
    sg_IK_B.MultiportSwitch1 = 0.0;
    sg_IK_B.MultiportSwitch2 = 0.0;
    sg_IK_B.MultiportSwitch3 = 0.0;
    sg_IK_B.Sum_f = 0.0;
    sg_IK_B.ProportionalGain = 0.0;
    sg_IK_B.Integrator = 0.0;
    sg_IK_B.Sum_a = 0.0;
    sg_IK_B.Saturation = 0.0;
    sg_IK_B.Sum3_e = 0.0;
    sg_IK_B.Sum1 = 0.0;
    sg_IK_B.ProportionalGain_c = 0.0;
    sg_IK_B.Integrator_k = 0.0;
    sg_IK_B.Sum_d = 0.0;
    sg_IK_B.Saturation_k = 0.0;
    sg_IK_B.Sum4 = 0.0;
    sg_IK_B.Sum2 = 0.0;
    sg_IK_B.ProportionalGain_o = 0.0;
    sg_IK_B.Integrator_j = 0.0;
    sg_IK_B.Sum_k = 0.0;
    sg_IK_B.Saturation_e = 0.0;
    sg_IK_B.Sum5 = 0.0;
    sg_IK_B.SWITCH1 = 0.0;
    sg_IK_B.Saturation2 = 0.0;
    sg_IK_B.SWITCH2 = 0.0;
    sg_IK_B.Saturation3 = 0.0;
    sg_IK_B.SWITCH3 = 0.0;
    sg_IK_B.Saturation4 = 0.0;
    sg_IK_B.MultiportSwitch6 = 0.0;
    sg_IK_B.MultiportSwitch4 = 0.0;
    sg_IK_B.Winch_e = 0.0;
    sg_IK_B.ProportionalGain_b = 0.0;
    sg_IK_B.Integrator_e = 0.0;
    sg_IK_B.Sum_e = 0.0;
    sg_IK_B.Sum2_i = 0.0;
    sg_IK_B.Saturation1 = 0.0;
    sg_IK_B.Gain = 0.0;
    sg_IK_B.MultiportSwitch5 = 0.0;
    sg_IK_B.Clock1 = 0.0;
    sg_IK_B.MultiportSwitch_f = 0.0;
    sg_IK_B.Winch_e_f = 0.0;
    sg_IK_B.ProportionalGain_a = 0.0;
    sg_IK_B.Integrator_o = 0.0;
    sg_IK_B.Sum_o = 0.0;
    sg_IK_B.MultiportSwitch1_a = 0.0;
    sg_IK_B.SWITCH4 = 0.0;
    sg_IK_B.Saturation1_a = 0.0;
    sg_IK_B.IntegralGain = 0.0;
    sg_IK_B.IntegralGain_p = 0.0;
    sg_IK_B.IntegralGain_f = 0.0;
    sg_IK_B.x_IK[0] = 0.0;
    sg_IK_B.x_IK[1] = 0.0;
    sg_IK_B.y_IK[0] = 0.0;
    sg_IK_B.y_IK[1] = 0.0;
    sg_IK_B.z_IK[0] = 0.0;
    sg_IK_B.z_IK[1] = 0.0;
    sg_IK_B.IntegralGain_l = 0.0;
    sg_IK_B.IntegralGain_o = 0.0;
    sg_IK_B.Vel = 0.0;
    sg_IK_B.PosRef = 0.0;
    sg_IK_B.Vel_FF = 0.0;
    sg_IK_B.Winch_Global_Pos_Z_out = 0.0;
    sg_IK_B.Winch_Global_Pos_Z = 0.0;
    sg_IK_B.Winch_PosRef = 0.0;
    sg_IK_B.Sum2_j = 0.0;
    sg_IK_B.Saturation1_k = 0.0;
    sg_IK_B.Gain_f = 0.0;
    sg_IK_B.p_Ball_space[0] = 0.0;
    sg_IK_B.p_Ball_space[1] = 0.0;
    sg_IK_B.p_Ball_space[2] = 0.0;
    sg_IK_B.p_Claw_space[0] = 0.0;
    sg_IK_B.p_Claw_space[1] = 0.0;
    sg_IK_B.p_Claw_space[2] = 0.0;
    sg_IK_B.Camera_space_frame_XYZ[0] = 0.0;
    sg_IK_B.Camera_space_frame_XYZ[1] = 0.0;
    sg_IK_B.Camera_space_frame_XYZ[2] = 0.0;
    sg_IK_B.Camera_space_frame_EUL[0] = 0.0;
    sg_IK_B.Camera_space_frame_EUL[1] = 0.0;
    sg_IK_B.Camera_space_frame_EUL[2] = 0.0;
    sg_IK_B.p[0] = 0.0;
    sg_IK_B.p[1] = 0.0;
    sg_IK_B.p[2] = 0.0;
    sg_IK_B.p_vel[0] = 0.0;
    sg_IK_B.p_vel[1] = 0.0;
    sg_IK_B.p_vel[2] = 0.0;
    sg_IK_B.Sum2_h = 0.0;
    sg_IK_B.Winch_Global_Pos_Z_h = 0.0;
    sg_IK_B.new_command = 0.0;
    sg_IK_B.Traj_method = 0.0;
    sg_IK_B.v_max = 0.0;
    sg_IK_B.Winch_NewCmd = 0.0;
    sg_IK_B.Winch_PosRef_e = 0.0;
    sg_IK_B.Winch_Mode_selector = 0.0;
    sg_IK_B.FF_Flag = 0.0;
    sg_IK_B.TmpSignalConversionAtSFunctionI[0] = 0.0;
    sg_IK_B.TmpSignalConversionAtSFunctionI[1] = 0.0;
    sg_IK_B.TmpSignalConversionAtSFunctionI[2] = 0.0;
    sg_IK_B.Endeff_local_xyz[0] = 0.0;
    sg_IK_B.Endeff_local_xyz[1] = 0.0;
    sg_IK_B.Endeff_local_xyz[2] = 0.0;
    sg_IK_B.Endeff_world_xyz[0] = 0.0;
    sg_IK_B.Endeff_world_xyz[1] = 0.0;
    sg_IK_B.Endeff_world_xyz[2] = 0.0;
    sg_IK_B.PLC_time = 0.0F;
    sg_IK_B.Winch = 0.0F;
    sg_IK_B.Winch_vel = 0.0F;
    sg_IK_B.UDP_camera_IMU[0] = 0.0F;
    sg_IK_B.UDP_camera_IMU[1] = 0.0F;
    sg_IK_B.UDP_camera_IMU[2] = 0.0F;
    sg_IK_B.UDP_camera_IMU[3] = 0.0F;
    sg_IK_B.CastToSingle1 = 0.0F;
    sg_IK_B.CastToSingle2 = 0.0F;
    sg_IK_B.CastToSingle3 = 0.0F;
    sg_IK_B.CastToSingle = 0.0F;
    sg_IK_B.Vel_FF_n = 0.0F;
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&sg_IK_DW), 0,
                     sizeof(DW_sg_IK_T));
  sg_IK_DW.Integrator_DSTATE = 0.0;
  sg_IK_DW.Integrator_DSTATE_c = 0.0;
  sg_IK_DW.Integrator_DSTATE_n = 0.0;
  sg_IK_DW.Integrator_DSTATE_j = 0.0;
  sg_IK_DW.Integrator_DSTATE_cl = 0.0;
  sg_IK_DW.Sum2_DWORK1 = 0.0;
  sg_IK_DW.last_command = 0.0;
  sg_IK_DW.command_start_time = 0.0;
  sg_IK_DW.command_start_pos = 0.0;
  sg_IK_DW.current_target_pos = 0.0;
  sg_IK_DW.T_move = 0.0;
  sg_IK_DW.actual_move_vel = 0.0;
  sg_IK_DW.target_idle_base_pos = 0.0;
  sg_IK_DW.p_Ball_space_persistent[0] = 0.0;
  sg_IK_DW.p_Ball_space_persistent[1] = 0.0;
  sg_IK_DW.p_Ball_space_persistent[2] = 0.0;
  sg_IK_DW.p_Claw_space_persistent[0] = 0.0;
  sg_IK_DW.p_Claw_space_persistent[1] = 0.0;
  sg_IK_DW.p_Claw_space_persistent[2] = 0.0;
  sg_IK_DW.abs_tf = 0.0;
  sg_IK_DW.base_t = 0.0;
  sg_IK_DW.last_command_f = 0.0;
  sg_IK_DW.new_points_x[0] = 0.0;
  sg_IK_DW.new_points_x[1] = 0.0;
  sg_IK_DW.new_points_y[0] = 0.0;
  sg_IK_DW.new_points_y[1] = 0.0;
  sg_IK_DW.new_points_z[0] = 0.0;
  sg_IK_DW.new_points_z[1] = 0.0;
  sg_IK_DW.Z_home = 0.0;
  sg_IK_DW.X_home = 0.0;
  sg_IK_DW.Y_home = 0.0;
  sg_IK_DW.X_Platform = 0.0;
  sg_IK_DW.Z_Platform = 0.0;
  sg_IK_DW.Y_Platform = 0.0;
  sg_IK_DW.Z_Offset = 0.0;
  sg_IK_DW.r_Offset = 0.0;
  sg_IK_DW.Target_Pos_Y = 0.0;
  sg_IK_DW.Target_Pos_X = 0.0;
  sg_IK_DW.Target_Pos_Z = 0.0;
  sg_IK_DW.unit_delta[0] = 0.0;
  sg_IK_DW.unit_delta[1] = 0.0;
  sg_IK_DW.Sub_stage_switch = 0.0;
  sg_IK_DW.Z_Up = 0.0;
  sg_IK_DW.norm_delta = 0.0;
  sg_IK_DW.delta_xy[0] = 0.0;
  sg_IK_DW.delta_xy[1] = 0.0;
  sg_IK_DW.Mode = 0.0;
  sg_IK_DW.Sub_stage_switch2 = 0.0;
  sg_IK_DW.X_Unhook = 0.0;
  sg_IK_DW.Y_Unhook = 0.0;
  sg_IK_DW.Z_Unhook = 0.0;
  sg_IK_DW.Em8000_settled_offset = 0.0;
  sg_IK_DW.Hook_state_switch = 0.0;
  sg_IK_DW.AutoSwitch = 0.0;

  /* external inputs */
  (void)std::memset(&sg_IK_U, 0, sizeof(ExtU_sg_IK_T));
  for (int32_T i = 0; i < 24; i++) {
    sg_IK_U.Input2[i] = 0.0F;
  }

  sg_IK_U.Input3[0] = 0.0F;
  sg_IK_U.Input3[1] = 0.0F;
  sg_IK_U.Input3[2] = 0.0F;

  {
    b_dsp_FIRFilter_0_sg_IK_T *b_obj_0;
    b_dspcodegen_FIRFilter_sg_IK_T *FIR;
    b_dspcodegen_FIRFilter_sg_IK_T *obj_1;
    dsp_LowpassFilter_sg_IK_T *b_obj;
    dsp_LowpassFilter_sg_IK_T *obj;
    dsp_LowpassFilter_sg_IK_T *obj_0;
    boolean_T wasTunablePropsChanged;
    static const real_T tmp[763] = { -0.0050437708092586934,
      -8.1025577916233035E-5, -8.149585722547156E-5, -8.2154750224938311E-5,
      -8.2531753943562461E-5, -8.3104016291767044E-5, -8.3403735248531438E-5,
      -8.3880175652279739E-5, -8.4090511462204948E-5, -8.4480897274178939E-5,
      -8.459428769269944E-5, -8.4897380601740578E-5, -8.4918431930544787E-5,
      -8.5124589512467874E-5, -8.5051617317500052E-5, -8.5153034953901389E-5,
      -8.4978290009126521E-5, -8.4981646624645042E-5, -8.47006619892971E-5,
      -8.4607801137862374E-5, -8.4234448244652462E-5, -8.396474143294119E-5,
      -8.3628291972757759E-5, -8.3206072365657374E-5, -8.2579555603670747E-5,
      -8.2187319520770022E-5, -8.1507048540415777E-5, -8.0988275810455425E-5,
      -8.0180493944900669E-5, -7.9512873425070313E-5, -7.8571488766873468E-5,
      -7.7803457502596165E-5, -7.6752789828264979E-5, -7.5885420650684312E-5,
      -7.4730071267125E-5, -7.3743858875902611E-5, -7.246788933904194E-5,
      -7.1351858435640946E-5, -6.9943494644011139E-5, -6.8703068533123129E-5,
      -6.7164999921398553E-5, -6.5797255766840453E-5, -6.4142875440302414E-5,
      -6.26156295894401E-5, -6.08531983107997E-5, -5.9214811567742113E-5,
      -5.7291000308242382E-5, -5.5559723581299425E-5, -5.3522018337569012E-5,
      -5.1624893885973039E-5, -4.9473918025866445E-5, -4.7434642991801039E-5,
      -4.5114706098872713E-5, -4.2952664942427669E-5, -4.04821341796579E-5,
      -3.8168581593206095E-5, -3.5546593426183574E-5, -3.3072130913102425E-5,
      -3.0295354778862081E-5, -2.7670670586705821E-5, -2.4741157184352867E-5,
      -2.1969332129057634E-5, -1.8882282720309549E-5, -1.5937678968077934E-5,
      -1.2678320601500263E-5, -9.5294709216581953E-6, -6.0788568273754818E-6,
      -2.7650498529127117E-6, 8.5694124597318634E-7, 4.3066036583253182E-6,
      8.09986060735029E-6, 1.1902049477518847E-5, 1.5826550544267216E-5,
      1.973793251469457E-5, 2.3953880010134549E-5, 2.8033349473783294E-5,
      3.2450243732253634E-5, 3.6736828169361839E-5, 4.1350398325651762E-5,
      4.5836487398904825E-5, 5.0641681782282396E-5, 5.53026491727296E-5,
      6.0277473217822233E-5, 6.50883096267038E-5, 7.0193515076556721E-5,
      7.5115413128971464E-5, 8.0283104337912689E-5, 8.5224833209832817E-5,
      9.0337205624727571E-5, 9.50918780112127E-5, 9.9824561765552965E-5,
      0.00010370877160050783, 0.00010540227617771253, 0.00012284100279570049,
      0.00012444545585863913, 0.0001298872481015343, 0.0001359614480759832,
      0.00014194846319910505, 0.00014830668038371672, 0.00015453394926114532,
      0.00016109809108599303, 0.00016752506277854969, 0.00017429218966856963,
      0.00018090928701378048, 0.00018787501263562359, 0.00019469115678554582,
      0.00020185302075605567, 0.000208873225764486, 0.0002162297269228374,
      0.00022344425630782088, 0.00023100119017666204, 0.00023840575702960422,
      0.00024616326024952113, 0.00025380493089988934, 0.00026160767214767825,
      0.00026963735908408742, 0.00027773208602889781, 0.00028566878578295058,
      0.00029400270195818669, 0.0003022201368294124, 0.0003107901980784102,
      0.00031923247736387518, 0.00032798630514144385, 0.00033659337417314662,
      0.00034553475681576846, 0.00035432567243120046, 0.00036346786530205816,
      0.00037247167895924482, 0.00038182396078708189, 0.00039104308388587317,
      0.00040060413191104062, 0.000410023558361131, 0.00041979010402479471,
      0.00042940737788177739, 0.00043936795889121483, 0.000449204890649944,
      0.00045931869498231433, 0.00046935086997552337, 0.00047968450758413973,
      0.00048985346283017322, 0.00050038686524108116, 0.00051077845500201321,
      0.00052147898172507669, 0.00053207777019100607, 0.00054297751722826612,
      0.00055373555083423648, 0.00056483436879551925, 0.0005757790722847343,
      0.000587061945966068, 0.00059819170911727172, 0.00060964515708507153,
      0.00062094257955136239, 0.00063256561424054588, 0.000644029912033792,
      0.000655833486369925, 0.00066748389125368421, 0.0006794672865267625,
      0.00069131356951969794, 0.00070345628259443915, 0.00071545191096428445,
      0.00072776678922121954, 0.0007399204920388073, 0.0007524528017473891,
      0.00076487398630542807, 0.00077746454987246349, 0.00079005254424296338,
      0.00080291196262516872, 0.00081562201687382136, 0.00082867356525943348,
      0.00084156551453499866, 0.000854785422499976, 0.00086784667486472815,
      0.000881220976280535, 0.00089442301290491139, 0.00090793468130560232,
      0.00092125536510916193, 0.000934874928968438, 0.00094829056932184408,
      0.00096197748884733971, 0.00097545892864538966, 0.00098919697951147271,
      0.0010027304373964631, 0.0010165811696573087, 0.0010303290715014308,
      0.0010447379251848719, 0.0010612698281963952, 0.0010731127075302425,
      0.0010876126640901409, 0.0011021141405975197, 0.001116381775114147,
      0.0011309607827949928, 0.0011453447290432029, 0.001160028303626981,
      0.0011745257890643803, 0.0011893237630069544, 0.0012039252323219889,
      0.0012188371690057343, 0.0012335461036580865, 0.0012485612455476083,
      0.0012633752589183468, 0.0012784815621405619, 0.0012933896697064685,
      0.0013085903697046587, 0.0013235818706627794, 0.0013388772103213836,
      0.0013539607338883606, 0.0013692291681851609, 0.0013846783830900305,
      0.0013998810477991689, 0.00141506169198986, 0.0014306202368343601,
      0.0014459642722567021, 0.0014615727927753514, 0.0014769455386590175,
      0.0014925554132307556, 0.0015079481877660144, 0.0015236119726023609,
      0.0015390561164153591, 0.0015547887780375852, 0.0015703000239954479,
      0.0015860881355959392, 0.001601652870585536, 0.0016174802433988949,
      0.0016330777145836164, 0.0016489399472021033, 0.0016645598606795074,
      0.0016804439494470457, 0.0016960924324999765, 0.0017119480397346867,
      0.0017276415331830943, 0.0017435187938981422, 0.0017591641858433122,
      0.0017750951311081254, 0.0017907699737106989, 0.0018066791452680531,
      0.0018223723472667065, 0.0018382691433403938, 0.0018539348090537643,
      0.0018698445616787119, 0.0018854927887314182, 0.0019013818309492174,
      0.0019170027985407623, 0.0019328491955579597, 0.0019484305167419391,
      0.0019642385395774215, 0.0019797800856572465, 0.0019955574479649566,
      0.0020110602946615086, 0.0020267881477355047, 0.0020422453243683345,
      0.0020578899853724657, 0.0020732837227126267, 0.0020888878049560734,
      0.0021042232667161649, 0.0021198103354738555, 0.0021350981641010745,
      0.0021505138751249267, 0.0021657946190034852, 0.0021811956551150502,
      0.0021963395703205484, 0.0022117013572280787, 0.002226766316875327,
      0.0022420369878215448, 0.0022570092286885641, 0.0022721690232287237,
      0.0022870231104376278, 0.0023020616142071853, 0.0023167779896491048,
      0.0023316758348744609, 0.0023462439106034126, 0.0023609849921596157,
      0.0023754172422029711, 0.0023900293762520093, 0.0024043708844549215,
      0.002418963116683348, 0.0024333389001977412, 0.0024480620277197657,
      0.0024626276897302193, 0.0024755266204835461, 0.0024901269071326876,
      0.0025042280068586359, 0.0025180115603621943, 0.0025319831260277544,
      0.0025456148310964363, 0.0025594152908921474, 0.00257288675993601,
      0.0025865207252355965, 0.00259981873335774, 0.0026132876496241888,
      0.0026264083683852314, 0.0026396974314796071, 0.0026526369147397712,
      0.0026657327717382598, 0.0026784865483479854, 0.002691391823609445,
      0.0027039468340190496, 0.0027166624005335051, 0.0027290100410798991,
      0.0027414790082959974, 0.0027538994593503357, 0.0027657158845242722,
      0.0027777928324325915, 0.0027899981923757617, 0.0028017525976556817,
      0.0028135956533395768, 0.0028250446641761, 0.002836610151735908,
      0.002847835178136564, 0.002859201502696316, 0.0028702146166542245,
      0.0028813763524441331, 0.002892166175898036, 0.0029030891363077235,
      0.0029136355488100121, 0.0029243004760724613, 0.0029345884413582578,
      0.0029449948746998571, 0.0029550127892550072, 0.0029651537543146558,
      0.0029749043057399867, 0.0029847469318736259, 0.0029942819670555044,
      0.0030038358659696725, 0.0030130628812017981, 0.0030224273927022542,
      0.0030313780044239846, 0.0030404379579743847, 0.0030491282041269505,
      0.0030578945295682632, 0.0030663033644142846, 0.0030748127666546019,
      0.00308292076492533, 0.0030911338397610812, 0.0030989382140227222,
      0.0031068408778572015, 0.0031143457003333865, 0.0031219488833248077,
      0.0031291536358463274, 0.0031364598637679988, 0.0031433531652760444,
      0.0031503425233081555, 0.0031569219970232483, 0.0031635758062563816,
      0.0031698610959028767, 0.0031762227335088325, 0.0031821917355468452,
      0.0031882670347075474, 0.00319389878514545, 0.0031996055126496752,
      0.0032050143857881141, 0.0032104082239892864, 0.0032154480887677393,
      0.0032205739816936804, 0.0032252772262700551, 0.0032300698333354509,
      0.0032344402809505375, 0.0032388870322345061, 0.0032429147322529661,
      0.00324701754473271, 0.0032506923150008304, 0.0032544491927961358,
      0.0032577778802486243, 0.0032611966495320554, 0.003264214493403026,
      0.0032673274217957619, 0.0032700703376387229, 0.0032729249784881373,
      0.0032753732464287713, 0.0032778848315153618, 0.00327981205846902,
      0.003281298692116851, 0.0032836225992695081, 0.003285208021407362,
      0.0032865262004426752, 0.0032879401645022495, 0.0032889187360449143,
      0.0032899831469625621, 0.0032906275672941404, 0.0032913491684221489,
      0.0032916515336571888, 0.0032920383225191886, 0.0032919938960883095,
      0.0032920383225191886, 0.0032916515336571888, 0.0032913491684221489,
      0.0032906275672941404, 0.0032899831469625621, 0.0032889187360449143,
      0.0032879401645022495, 0.0032865262004426752, 0.003285208021407362,
      0.0032836225992695081, 0.003281298692116851, 0.00327981205846902,
      0.0032778848315153618, 0.0032753732464287713, 0.0032729249784881373,
      0.0032700703376387229, 0.0032673274217957619, 0.003264214493403026,
      0.0032611966495320554, 0.0032577778802486243, 0.0032544491927961358,
      0.0032506923150008304, 0.00324701754473271, 0.0032429147322529661,
      0.0032388870322345061, 0.0032344402809505375, 0.0032300698333354509,
      0.0032252772262700551, 0.0032205739816936804, 0.0032154480887677393,
      0.0032104082239892864, 0.0032050143857881141, 0.0031996055126496752,
      0.00319389878514545, 0.0031882670347075474, 0.0031821917355468452,
      0.0031762227335088325, 0.0031698610959028767, 0.0031635758062563816,
      0.0031569219970232483, 0.0031503425233081555, 0.0031433531652760444,
      0.0031364598637679988, 0.0031291536358463274, 0.0031219488833248077,
      0.0031143457003333865, 0.0031068408778572015, 0.0030989382140227222,
      0.0030911338397610812, 0.00308292076492533, 0.0030748127666546019,
      0.0030663033644142846, 0.0030578945295682632, 0.0030491282041269505,
      0.0030404379579743847, 0.0030313780044239846, 0.0030224273927022542,
      0.0030130628812017981, 0.0030038358659696725, 0.0029942819670555044,
      0.0029847469318736259, 0.0029749043057399867, 0.0029651537543146558,
      0.0029550127892550072, 0.0029449948746998571, 0.0029345884413582578,
      0.0029243004760724613, 0.0029136355488100121, 0.0029030891363077235,
      0.002892166175898036, 0.0028813763524441331, 0.0028702146166542245,
      0.002859201502696316, 0.002847835178136564, 0.002836610151735908,
      0.0028250446641761, 0.0028135956533395768, 0.0028017525976556817,
      0.0027899981923757617, 0.0027777928324325915, 0.0027657158845242722,
      0.0027538994593503357, 0.0027414790082959974, 0.0027290100410798991,
      0.0027166624005335051, 0.0027039468340190496, 0.002691391823609445,
      0.0026784865483479854, 0.0026657327717382598, 0.0026526369147397712,
      0.0026396974314796071, 0.0026264083683852314, 0.0026132876496241888,
      0.00259981873335774, 0.0025865207252355965, 0.00257288675993601,
      0.0025594152908921474, 0.0025456148310964363, 0.0025319831260277544,
      0.0025180115603621943, 0.0025042280068586359, 0.0024901269071326876,
      0.0024755266204835461, 0.0024626276897302193, 0.0024480620277197657,
      0.0024333389001977412, 0.002418963116683348, 0.0024043708844549215,
      0.0023900293762520093, 0.0023754172422029711, 0.0023609849921596157,
      0.0023462439106034126, 0.0023316758348744609, 0.0023167779896491048,
      0.0023020616142071853, 0.0022870231104376278, 0.0022721690232287237,
      0.0022570092286885641, 0.0022420369878215448, 0.002226766316875327,
      0.0022117013572280787, 0.0021963395703205484, 0.0021811956551150502,
      0.0021657946190034852, 0.0021505138751249267, 0.0021350981641010745,
      0.0021198103354738555, 0.0021042232667161649, 0.0020888878049560734,
      0.0020732837227126267, 0.0020578899853724657, 0.0020422453243683345,
      0.0020267881477355047, 0.0020110602946615086, 0.0019955574479649566,
      0.0019797800856572465, 0.0019642385395774215, 0.0019484305167419391,
      0.0019328491955579597, 0.0019170027985407623, 0.0019013818309492174,
      0.0018854927887314182, 0.0018698445616787119, 0.0018539348090537643,
      0.0018382691433403938, 0.0018223723472667065, 0.0018066791452680531,
      0.0017907699737106989, 0.0017750951311081254, 0.0017591641858433122,
      0.0017435187938981422, 0.0017276415331830943, 0.0017119480397346867,
      0.0016960924324999765, 0.0016804439494470457, 0.0016645598606795074,
      0.0016489399472021033, 0.0016330777145836164, 0.0016174802433988949,
      0.001601652870585536, 0.0015860881355959392, 0.0015703000239954479,
      0.0015547887780375852, 0.0015390561164153591, 0.0015236119726023609,
      0.0015079481877660144, 0.0014925554132307556, 0.0014769455386590175,
      0.0014615727927753514, 0.0014459642722567021, 0.0014306202368343601,
      0.00141506169198986, 0.0013998810477991689, 0.0013846783830900305,
      0.0013692291681851609, 0.0013539607338883606, 0.0013388772103213836,
      0.0013235818706627794, 0.0013085903697046587, 0.0012933896697064685,
      0.0012784815621405619, 0.0012633752589183468, 0.0012485612455476083,
      0.0012335461036580865, 0.0012188371690057343, 0.0012039252323219889,
      0.0011893237630069544, 0.0011745257890643803, 0.001160028303626981,
      0.0011453447290432029, 0.0011309607827949928, 0.001116381775114147,
      0.0011021141405975197, 0.0010876126640901409, 0.0010731127075302425,
      0.0010612698281963952, 0.0010447379251848719, 0.0010303290715014308,
      0.0010165811696573087, 0.0010027304373964631, 0.00098919697951147271,
      0.00097545892864538966, 0.00096197748884733971, 0.00094829056932184408,
      0.000934874928968438, 0.00092125536510916193, 0.00090793468130560232,
      0.00089442301290491139, 0.000881220976280535, 0.00086784667486472815,
      0.000854785422499976, 0.00084156551453499866, 0.00082867356525943348,
      0.00081562201687382136, 0.00080291196262516872, 0.00079005254424296338,
      0.00077746454987246349, 0.00076487398630542807, 0.0007524528017473891,
      0.0007399204920388073, 0.00072776678922121954, 0.00071545191096428445,
      0.00070345628259443915, 0.00069131356951969794, 0.0006794672865267625,
      0.00066748389125368421, 0.000655833486369925, 0.000644029912033792,
      0.00063256561424054588, 0.00062094257955136239, 0.00060964515708507153,
      0.00059819170911727172, 0.000587061945966068, 0.0005757790722847343,
      0.00056483436879551925, 0.00055373555083423648, 0.00054297751722826612,
      0.00053207777019100607, 0.00052147898172507669, 0.00051077845500201321,
      0.00050038686524108116, 0.00048985346283017322, 0.00047968450758413973,
      0.00046935086997552337, 0.00045931869498231433, 0.000449204890649944,
      0.00043936795889121483, 0.00042940737788177739, 0.00041979010402479471,
      0.000410023558361131, 0.00040060413191104062, 0.00039104308388587317,
      0.00038182396078708189, 0.00037247167895924482, 0.00036346786530205816,
      0.00035432567243120046, 0.00034553475681576846, 0.00033659337417314662,
      0.00032798630514144385, 0.00031923247736387518, 0.0003107901980784102,
      0.0003022201368294124, 0.00029400270195818669, 0.00028566878578295058,
      0.00027773208602889781, 0.00026963735908408742, 0.00026160767214767825,
      0.00025380493089988934, 0.00024616326024952113, 0.00023840575702960422,
      0.00023100119017666204, 0.00022344425630782088, 0.0002162297269228374,
      0.000208873225764486, 0.00020185302075605567, 0.00019469115678554582,
      0.00018787501263562359, 0.00018090928701378048, 0.00017429218966856963,
      0.00016752506277854969, 0.00016109809108599303, 0.00015453394926114532,
      0.00014830668038371672, 0.00014194846319910505, 0.0001359614480759832,
      0.0001298872481015343, 0.00012444545585863913, 0.00012284100279570049,
      0.00010540227617771253, 0.00010370877160050783, 9.9824561765552965E-5,
      9.50918780112127E-5, 9.0337205624727571E-5, 8.5224833209832817E-5,
      8.0283104337912689E-5, 7.5115413128971464E-5, 7.0193515076556721E-5,
      6.50883096267038E-5, 6.0277473217822233E-5, 5.53026491727296E-5,
      5.0641681782282396E-5, 4.5836487398904825E-5, 4.1350398325651762E-5,
      3.6736828169361839E-5, 3.2450243732253634E-5, 2.8033349473783294E-5,
      2.3953880010134549E-5, 1.973793251469457E-5, 1.5826550544267216E-5,
      1.1902049477518847E-5, 8.09986060735029E-6, 4.3066036583253182E-6,
      8.5694124597318634E-7, -2.7650498529127117E-6, -6.0788568273754818E-6,
      -9.5294709216581953E-6, -1.2678320601500263E-5, -1.5937678968077934E-5,
      -1.8882282720309549E-5, -2.1969332129057634E-5, -2.4741157184352867E-5,
      -2.7670670586705821E-5, -3.0295354778862081E-5, -3.3072130913102425E-5,
      -3.5546593426183574E-5, -3.8168581593206095E-5, -4.04821341796579E-5,
      -4.2952664942427669E-5, -4.5114706098872713E-5, -4.7434642991801039E-5,
      -4.9473918025866445E-5, -5.1624893885973039E-5, -5.3522018337569012E-5,
      -5.5559723581299425E-5, -5.7291000308242382E-5, -5.9214811567742113E-5,
      -6.08531983107997E-5, -6.26156295894401E-5, -6.4142875440302414E-5,
      -6.5797255766840453E-5, -6.7164999921398553E-5, -6.8703068533123129E-5,
      -6.9943494644011139E-5, -7.1351858435640946E-5, -7.246788933904194E-5,
      -7.3743858875902611E-5, -7.4730071267125E-5, -7.5885420650684312E-5,
      -7.6752789828264979E-5, -7.7803457502596165E-5, -7.8571488766873468E-5,
      -7.9512873425070313E-5, -8.0180493944900669E-5, -8.0988275810455425E-5,
      -8.1507048540415777E-5, -8.2187319520770022E-5, -8.2579555603670747E-5,
      -8.3206072365657374E-5, -8.3628291972757759E-5, -8.396474143294119E-5,
      -8.4234448244652462E-5, -8.4607801137862374E-5, -8.47006619892971E-5,
      -8.4981646624645042E-5, -8.4978290009126521E-5, -8.5153034953901389E-5,
      -8.5051617317500052E-5, -8.5124589512467874E-5, -8.4918431930544787E-5,
      -8.4897380601740578E-5, -8.459428769269944E-5, -8.4480897274178939E-5,
      -8.4090511462204948E-5, -8.3880175652279739E-5, -8.3403735248531438E-5,
      -8.3104016291767044E-5, -8.2531753943562461E-5, -8.2154750224938311E-5,
      -8.149585722547156E-5, -8.1025577916233035E-5, -0.0050437708092586934 };

    const real_T *val;

    /* Start for S-Function (slrealtimeUDPReceive): '<S2>/UDP Receive' */
    {
      try {
        uint8_t *tempAddr = nullptr;
        uint8_t *tempInterface = nullptr;
        slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",50060U);
        if (tempAddr)
          delete tempAddr;
        if (tempInterface)
          delete tempInterface;
        sg_IK_DW.UDPReceive_IWORK = 304;
        sg_IK_DW.UDPReceive_PWORK[0] = reinterpret_cast<void*>(udpSock);
        char *buffer = (char *)calloc(65504,sizeof(char));
        sg_IK_DW.UDPReceive_PWORK[1] = (void*)buffer;
      } catch (std::exception& e) {
        std::string tmp = std::string(e.what());
        static std::string eMsg = tmp;
        rtmSetErrorStatus(sg_IK_M, eMsg.c_str());
        rtmSetStopRequested(sg_IK_M, 1);
        ;
      }
    }

    /* Start for Constant: '<S6>/Constant' */
    sg_IK_B.Constant_f = sg_IK_cal->State_Mode_Selector;

    /* Start for Constant: '<S6>/Constant4' */
    sg_IK_B.MS_Switch = sg_IK_cal->Manual_State_Switch;

    /* Start for Constant: '<S6>/enable_65cm_offset_Em8000' */
    sg_IK_B.enable_65cm_offset_Em8000 =
      sg_IK_cal->enable_65cm_offset_Em8000_Value;

    /* Start for S-Function (slrealtimeUDPReceive): '<S8>/UDP Receive' */
    {
      try {
        uint8_t *tempAddr = nullptr;
        uint8_t *tempInterface = nullptr;
        slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",5008U);
        if (tempAddr)
          delete tempAddr;
        if (tempInterface)
          delete tempInterface;
        sg_IK_DW.UDPReceive_IWORK_d = 29;
        sg_IK_DW.UDPReceive_PWORK_c[0] = reinterpret_cast<void*>(udpSock);
        char *buffer = (char *)calloc(65504,sizeof(char));
        sg_IK_DW.UDPReceive_PWORK_c[1] = (void*)buffer;
      } catch (std::exception& e) {
        std::string tmp = std::string(e.what());
        static std::string eMsg = tmp;
        rtmSetErrorStatus(sg_IK_M, eMsg.c_str());
        rtmSetStopRequested(sg_IK_M, 1);
        ;
      }
    }

    /* Start for MATLABSystem: '<S168>/Lowpass Filter1' */
    sg_IK_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    sg_IK_DW.obj.matlabCodegenIsDeleted = true;
    b_obj = &sg_IK_DW.obj;
    b_obj->TunablePropsChanged = false;
    b_obj->isInitialized = 0;
    b_obj->NumChannels = -1;
    b_obj->matlabCodegenIsDeleted = false;
    sg_IK_DW.objisempty = true;
    b_obj = &sg_IK_DW.obj;
    b_obj->isSetupComplete = false;
    b_obj->isInitialized = 1;
    obj = b_obj;
    wasTunablePropsChanged = obj->TunablePropsChanged;
    obj->TunablePropsChanged = wasTunablePropsChanged;
    obj = b_obj;
    obj_0 = obj;
    FIR = &obj->_pobj0;
    FIR->isInitialized = 0;
    FIR->isInitialized = 0;
    b_obj_0 = &FIR->cSFunObject;

    /* System object Constructor function: dsp.FIRFilter */
    b_obj_0->P0_InitialStates = 0.0;
    obj_1 = FIR;
    val = &tmp[0];
    b_obj_0 = &obj_1->cSFunObject;
    for (int32_T i = 0; i < 763; i++) {
      b_obj_0->P1_Coefficients[i] = val[i];
    }

    FIR->matlabCodegenIsDeleted = false;
    obj_0->FilterObj = FIR;
    obj->NumChannels = 1;
    b_obj->isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S168>/Lowpass Filter1' */

    /* Start for S-Function (slrealtimeUDPSend): '<S3>/UDP Send' */
    {
      try {
        slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",11000U);
        uint8_t *remoteAddress = (uint8_t *)sg_IK_cal->UDPSend_toAddress;
        uint16_t *remotePort = (uint16_t *)&sg_IK_cal->UDPSend_toPort;
        udpSock->setRemoteEndpoint(remoteAddress, remotePort[0]);
        sg_IK_DW.UDPSend_IWORK[0] = 136;
        sg_IK_DW.UDPSend_IWORK[1] = 11000U;
        sg_IK_DW.UDPSend_PWORK = reinterpret_cast<void*>(udpSock);
      } catch (std::exception& e) {
        std::string tmp = std::string(e.what());
        static std::string eMsg = tmp;
        rtmSetErrorStatus(sg_IK_M, eMsg.c_str());
        rtmSetStopRequested(sg_IK_M, 1);
        ;
      }
    }
  }

  {
    b_dsp_FIRFilter_0_sg_IK_T *obj_1;
    b_dspcodegen_FIRFilter_sg_IK_T *obj_0;
    dsp_LowpassFilter_sg_IK_T *obj;
    int32_T i;

    /* InitializeConditions for Delay: '<S3>/Delay' */
    sg_IK_DW.Delay_DSTATE = sg_IK_cal->Delay_InitialCondition;

    /* InitializeConditions for Memory: '<S7>/Memory2' */
    sg_IK_DW.Memory2_PreviousInput = sg_IK_cal->Memory2_InitialCondition;

    /* InitializeConditions for Memory: '<S5>/Memory3' */
    sg_IK_DW.Memory3_PreviousInput = sg_IK_cal->Memory3_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
    sg_IK_DW.Integrator_DSTATE = sg_IK_cal->DiscretePIDController_InitialCo;

    /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
    sg_IK_DW.Integrator_DSTATE_c = sg_IK_cal->DiscretePIDController1_InitialC;

    /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator' */
    sg_IK_DW.Integrator_DSTATE_n = sg_IK_cal->DiscretePIDController2_InitialC;

    /* InitializeConditions for DiscreteIntegrator: '<S204>/Integrator' */
    sg_IK_DW.Integrator_DSTATE_j = sg_IK_cal->DiscretePIDController_Initial_b;

    /* InitializeConditions for DiscreteIntegrator: '<S255>/Integrator' */
    sg_IK_DW.Integrator_DSTATE_cl = sg_IK_cal->DiscretePIDController_Initial_h;

    /* SystemInitialize for MATLAB Function: '<S8>/Camera_transform' */
    sg_IK_DW.p_Ball_space_persistent_not_emp = false;
    sg_IK_DW.p_Claw_space_persistent_not_emp = false;

    /* SystemInitialize for Chart: '<S6>/Chart' */
    sg_IK_DW.sfEvent = -1;
    sg_IK_DW.is_Autonomous_Operation_Mode = 0U;
    sg_IK_DW.is_Hook_Ball_o = 0U;
    sg_IK_DW.is_Lower_payload_Onto_platfor_p = 0U;
    sg_IK_DW.temporalCounter_i2 = 0U;
    sg_IK_DW.is_Manual_State_Switch_Mode = 0U;
    sg_IK_DW.is_Hook_Ball = 0U;
    sg_IK_DW.is_Lower_payload_Onto_platform = 0U;
    sg_IK_DW.temporalCounter_i1 = 0U;
    sg_IK_DW.is_active_c9_sg_IK = 0U;
    sg_IK_DW.is_c9_sg_IK = 0U;
    sg_IK_DW.Z_home = 0.0;
    sg_IK_DW.X_home = 0.0;
    sg_IK_DW.Y_home = 0.0;
    sg_IK_DW.X_Platform = 0.0;
    sg_IK_DW.Z_Platform = 0.0;
    sg_IK_DW.Y_Platform = 0.0;
    sg_IK_DW.Z_Offset = 0.0;
    sg_IK_DW.r_Offset = 0.0;
    sg_IK_DW.Target_Pos_Y = 0.0;
    sg_IK_DW.Target_Pos_X = 0.0;
    sg_IK_DW.Target_Pos_Z = 0.0;
    sg_IK_DW.Sub_stage_switch = 0.0;
    sg_IK_DW.Z_Up = 0.0;
    sg_IK_DW.norm_delta = 0.0;
    sg_IK_DW.unit_delta[0] = 0.0;
    sg_IK_DW.delta_xy[0] = 0.0;
    sg_IK_DW.unit_delta[1] = 0.0;
    sg_IK_DW.delta_xy[1] = 0.0;
    sg_IK_DW.Mode = 0.0;
    sg_IK_DW.Sub_stage_switch2 = 0.0;
    sg_IK_DW.X_Unhook = 0.0;
    sg_IK_DW.Y_Unhook = 0.0;
    sg_IK_DW.Z_Unhook = 0.0;
    sg_IK_DW.Em8000_settled_offset = 0.0;
    sg_IK_DW.Hook_state_switch = 0.0;
    sg_IK_DW.AutoSwitch = 0.0;
    for (i = 0; i < 6; i++) {
      sg_IK_B.Traj_points_XYZ[i] = 0.0;
    }

    sg_IK_B.new_command = 0.0;
    sg_IK_B.Traj_method = 0.0;
    sg_IK_B.v_max = 0.0;
    sg_IK_B.Winch_NewCmd = 0.0;
    sg_IK_B.Winch_PosRef_e = 0.0;
    sg_IK_B.Winch_Mode_selector = 0.0;
    sg_IK_B.FF_Flag = 0.0;

    /* End of SystemInitialize for Chart: '<S6>/Chart' */

    /* SystemInitialize for MATLAB Function: '<S7>/Trajectory_planner' */
    sg_IK_DW.abs_tf_not_empty = false;
    sg_IK_DW.abs_tf = 0.0;
    sg_IK_DW.base_t = 0.0;
    sg_IK_DW.last_command_f = 0.0;

    /* SystemInitialize for MATLAB Function: '<S169>/Winch_Posref_ramp_generator' */
    sg_IK_DW.first_run_not_empty = false;
    sg_IK_DW.is_moving = false;
    sg_IK_DW.T_move = 0.0;
    sg_IK_DW.actual_move_vel = 0.0;

    /* InitializeConditions for MATLABSystem: '<S168>/Lowpass Filter1' */
    obj = &sg_IK_DW.obj;
    obj_0 = obj->FilterObj;
    if (obj_0->isInitialized == 1) {
      obj_1 = &obj_0->cSFunObject;

      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 762; i++) {
        obj_1->W0_states[i] = obj_1->P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<S168>/Lowpass Filter1' */
  }
}

/* Model terminate function */
void sg_IK_terminate(void)
{
  b_dspcodegen_FIRFilter_sg_IK_T *obj_0;
  dsp_LowpassFilter_sg_IK_T *obj;

  /* Terminate for S-Function (slrealtimeUDPReceive): '<S2>/UDP Receive' */
  {
    slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",50060U);
    if (udpSock)
      delete udpSock;
    char *buffer = (char *)sg_IK_DW.UDPReceive_PWORK[1];
    if (buffer)
      free(buffer);
  }

  /* Terminate for S-Function (slrealtimeUDPReceive): '<S8>/UDP Receive' */
  {
    slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",5008U);
    if (udpSock)
      delete udpSock;
    char *buffer = (char *)sg_IK_DW.UDPReceive_PWORK_c[1];
    if (buffer)
      free(buffer);
  }

  /* Terminate for MATLABSystem: '<S168>/Lowpass Filter1' */
  obj = &sg_IK_DW.obj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if ((obj->isInitialized == 1) && obj->isSetupComplete) {
      obj_0 = obj->FilterObj;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      obj->NumChannels = -1;
    }
  }

  obj_0 = &sg_IK_DW.obj._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S168>/Lowpass Filter1' */

  /* Terminate for S-Function (slrealtimeUDPSend): '<S3>/UDP Send' */
  {
    slrealtime::ip::udp::Socket *udpSock = getUDPSocket("0.0.0.0",11000U);
    if (udpSock)
      delete udpSock;
  }
}
