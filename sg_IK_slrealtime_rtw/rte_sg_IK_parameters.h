#ifndef _RTE_SG_IK_PARAMETERS_H
#define _RTE_SG_IK_PARAMETERS_H
#include "rtwtypes.h"
#include "SegmentInfo.hpp"
#include "multiword_types.h"
#include "sg_IK_types.h"

struct RTE_Param_Service_T {
  real_T Ts;
};

extern RTE_Param_Service_T RTE_Param_Service;
extern RTE_Param_Service_T *RTE_Param_Service_ptr;
real_T* get_Ts(void);
namespace slrealtime
{
  SegmentVector &getSegmentVector(void);
}                                      // slrealtime

#endif
