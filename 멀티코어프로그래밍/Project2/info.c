#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK_ERROR(err) \
    if(err != CL_SUCCESS) { \
        printf("[%s:%d] OpenCL error %d\n", __FILE__, __LINE__, err); \
        exit(EXIT_FAILURE); \
    }

int main()
{
    cl_uint num_platforms;
    cl_platform_id* platforms;
    cl_uint num_devices;
    cl_device_id* devices;
    char str[1024];
    cl_device_type device_type;
    size_t max_work_group_size;
    cl_uint max_clock_frequency;
    cl_ulong global_mem_size;
    cl_ulong local_mem_size;
    cl_ulong max_mem_alloc_size;
    cl_ulong max_compute_units;
    cl_command_queue_properties queue_properties;
    cl_uint p, d;
    cl_int err;

    err = clGetPlatformIDs(0, NULL, &num_platforms);
    CHECK_ERROR(err);

    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * num_platforms);
    err = clGetPlatformIDs(num_platforms, platforms, NULL);
    CHECK_ERROR(err);

    printf("Number of platforms: %u\n\n", num_platforms);
    for (p = 0; p < num_platforms; p++)
    {
        printf("platform: %u\n", p);

        err = clGetPlatformInfo(platforms[p], CL_PLATFORM_NAME, 1024, str, NULL);
        CHECK_ERROR(err);
        printf("- CL_PLATFORM_NAME\t:%s\n", str);

        err = clGetPlatformInfo(platforms[p], CL_PLATFORM_VENDOR, 1024, str, NULL);
        CHECK_ERROR(err);
        printf("- CL_PLATFORM_VENDOR\t:%s\n\n", str);

        err = clGetDeviceIDs(platforms[p], CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
        CHECK_ERROR(err);
        printf("Number of devices:\t%u\n\n", num_devices);

        devices = (cl_device_id*)malloc(sizeof(cl_device_id) * num_devices);
        err = clGetDeviceIDs(platforms[p], CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);
        CHECK_ERROR(err);

        for (d = 0; d < num_devices; d++)
        {
            printf("device: %u\n", d);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_TYPE, sizeof(cl_device_type), &device_type, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_TYPE\t:");
            if (device_type & CL_DEVICE_TYPE_CPU) printf(" CL_DEVICE_TYPE_CPU");
            if (device_type & CL_DEVICE_TYPE_GPU) printf(" CL_DEVICE_TYPE_GPU");
            if (device_type & CL_DEVICE_TYPE_ACCELERATOR) printf(" CL_DEVICE_TYPE_ACCELERATOR");
            if (device_type & CL_DEVICE_TYPE_DEFAULT) printf(" CL_DEVICE_TYPE_DEFAULT");
            if (device_type & CL_DEVICE_TYPE_CUSTOM) printf(" CL_DEVICE_TYPE_CUSTOM");
            printf("\n");

            err = clGetDeviceInfo(devices[d], CL_DEVICE_NAME, 1024, str, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_NAME\t: %s\n", str);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_VENDOR, 1024, str, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_VENDOR\t: %s\n", str);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_VERSION, 1024, str, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_VERSION\t: %s\n", str);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_ulong), &max_clock_frequency, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_MAX_CLOCK_FREQUENCY : %luMHz\n", max_clock_frequency);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_ulong), &max_compute_units, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_MAX_COMPUTE_UNITS : %lu\n", max_compute_units);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &max_work_group_size, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_MAX_WORK_GROUP_SIZE : %lu\n", max_work_group_size);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &global_mem_size, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_GLOBAL_MEM_SIZE : %lu\n", global_mem_size);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(cl_ulong), &local_mem_size, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_LOCAL_MEM_SIZE : %lu\n", local_mem_size);

            err = clGetDeviceInfo(devices[d], CL_DEVICE_QUEUE_PROPERTIES, sizeof(cl_ulong), &queue_properties, NULL);
            CHECK_ERROR(err);
            printf("- CL_DEVICE_QUEUE_PROPERTIES :");
            if (queue_properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) printf(" CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE");
            if (queue_properties & CL_QUEUE_PROFILING_ENABLE) printf(" CL_QUEUE_PROFILING_ENABLE");
            printf("\n");
        }

        free(devices);
    }

    free(platforms);

    printf("\nPlease enter any key to exit.\n");
    char c = getchar();

    return 0;
}