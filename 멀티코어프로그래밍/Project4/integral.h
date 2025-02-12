#pragma once

#ifndef __INTEGRAL__
#define __INTEGRAL__

#define CHECK_ERROR(err) \
    if (err != CL_SUCCESS) { \
        printf("[%s:%d] OpenCL error %d\n", __FILE__, __LINE__, err); \
        exit(EXIT_FAILURE); \
    }

#include <CL/cl.h>
#include <stdlib.h>

char* get_source_code(const char* file_name, size_t* len);
void build_error(cl_program program, cl_device_id device, cl_int err);
double f(double x);
double integral_seq(const int N);
double integral_opencl(const int N);

#endif