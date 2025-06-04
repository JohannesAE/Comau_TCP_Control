/* Main generated for Simulink Real-Time model sg_IK */
#include <ModelInfo.hpp>
#include <utilities.hpp>
#include "rte_sg_IK_parameters.h"
#include "sg_IK.h"

/* Task descriptors */
slrealtime::TaskInfo task_1( 0u, std::bind(sg_IK_step), slrealtime::TaskInfo::PERIODIC, 0.001, 0, 40);

/* Executable base address for XCP */
#ifdef __linux__
extern char __executable_start;
static uintptr_t const base_address = reinterpret_cast<uintptr_t>(&__executable_start);
#else
/* Set 0 as placeholder, to be parsed later from /proc filesystem */
static uintptr_t const base_address = 0;
#endif

/* Model descriptor */
slrealtime::ModelInfo sg_IK_Info =
{
    "sg_IK",
    sg_IK_initialize,
    sg_IK_terminate,
    []()->char const*& { return sg_IK_M->errorStatus; },
    []()->unsigned char& { return sg_IK_M->Timing.stopRequestedFlag; },
    { task_1 },
    slrealtime::getSegmentVector()
};

int main(int argc, char *argv[]) {
    slrealtime::BaseAddress::set(base_address);
    return slrealtime::runModel(argc, argv, sg_IK_Info);
}
