#include "rte_sg_IK_parameters.h"
#include "sg_IK.h"
#include "sg_IK_cal.h"

RTE_Param_Service_T RTE_Param_Service = {
  0.001
};

RTE_Param_Service_T *RTE_Param_Service_ptr = &RTE_Param_Service;
real_T* get_Ts(void)
{
  return &RTE_Param_Service_ptr->Ts;
}

extern sg_IK_cal_type sg_IK_cal_impl;
extern RTE_Param_Service_T RTE_Param_Service;
namespace slrealtime
{
  /* Description of SEGMENTS */
  SegmentVector segmentInfo {
    { (void*)&RTE_Param_Service, (void**)&RTE_Param_Service_ptr, sizeof
      (RTE_Param_Service_T), 2 },

    { (void*)&sg_IK_cal_impl, (void**)&sg_IK_cal, sizeof(sg_IK_cal_type), 2 }
  };

  SegmentVector &getSegmentVector(void)
  {
    return segmentInfo;
  }
}                                      // slrealtime
