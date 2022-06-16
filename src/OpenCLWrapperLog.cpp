#include "OpenCLWrapperLog.hpp"
#include <CL/cl.h>

bool OpenCLWrapper::InitializedSuccessfully()
{
    cl_device_id device_id;

    cl_uint dev_cnt = 0;
    clGetPlatformIDs(0, 0, &dev_cnt);

    cl_platform_id platform_ids[100];
    clGetPlatformIDs(dev_cnt, platform_ids, NULL);

    int gpu = 1;
    int err = clGetDeviceIDs(platform_ids[0], gpu ? CL_DEVICE_TYPE_GPU : CL_DEVICE_TYPE_CPU, 1, &device_id, nullptr);

    return (err == CL_SUCCESS);
}
