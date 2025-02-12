#define _CRT_SECURE_NO_WARNINGS

#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define CHECK_ERROR(err) \
    if(err != CL_SUCCESS) { \
        printf("[%s:%d] OpenCL error %d\n", __FILE__, __LINE__, err); \
        exit(EXIT_FAILURE); \
    }

char* get_source_code(const char* file_name, size_t * len) {
    char* source_code;
    char buf[2] = "\0";
    int cnt = 0;
    size_t length;
    FILE* file = fopen(file_name, "r");
    
    if (file == NULL) {
        printf("[%s:%d] Failed to open %s\n", __FILE__, __LINE__, file_name);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    length = (size_t)ftell(file);
    rewind(file);

    source_code = (char*)malloc(length + 1);
    fread(source_code, length, 1, file);

    for (int i = 0; i < length; i++) {
        buf[0] = source_code[i];
        if (buf[0] == '\n') cnt++;
    }

    source_code[length - cnt] = '\0';
    fclose(file);
    *len = length - cnt;
    
    return source_code;
}

int main() {
    // �ð� ���� ���� ����
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    // �� ���� ����
    int sum;

    // ���� ũ��
    int n = 16384;
    size_t bytes = sizeof(int) * n;

    // ȣ��Ʈ input ����
    int* A;
    int* B;
    // ȣ��Ʈ output ����
    int* C;

    // ����̽� input ����
    cl_mem buf_a;
    cl_mem buf_b;
    // ����̽� output ����
    cl_mem buf_c;

    // �÷���
    cl_platform_id platform;
    // ����̽� ID
    cl_device_id device_id;
    // ���ؽ�Ʈ
    cl_context context;
    // Ŀ�ǵ� ť
    cl_command_queue queue;
    // ���α׷�
    cl_program program;
    // Ŀ��
    cl_kernel kernel;

    // �� ���� ȣ��Ʈ �޸� �Ҵ�
    A = (int*)malloc(bytes);
    B = (int*)malloc(bytes);
    C = (int*)malloc(bytes);

    // �ð� ���� �� ����
    QueryPerformanceFrequency(&ticksPerSec);

    // rand() ��� �� ����
    srand(time(NULL));

    // A, B �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 1000;
    }

    // CPU ��� <�ð� ����>
    QueryPerformanceCounter(&start);

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i] + B[i];
    }
    printf("result: %d\n", sum);

    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("<CPU> time: %.12f ms\n\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 10000);

    // GPU ��� <�ð� ����>
    QueryPerformanceCounter(&start);

    // work-item, work-group ����
    size_t globalSize, localSize;
    // err ���� ����
    cl_int err;

    localSize = 64;
    // globalSize�� ������ localSize�� ������ �������� �ϱ� ������ ceil() �ø� �Լ� ���
    globalSize = ceil(n / (float)localSize) * localSize;

    err = clGetPlatformIDs(1, &platform, NULL);
    CHECK_ERROR(err);

    // ����̽� ID ��������
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
    CHECK_ERROR(err);

    // ���ؽ�Ʈ ����
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);
    CHECK_ERROR(err);

    // Ŀ�ǵ� ť ����
    queue = clCreateCommandQueueWithProperties(context, device_id, 0, &err);
    CHECK_ERROR(err);
    // queue = clCreateCommandQueueWithProperties(context, device_id, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err);

    char* kernelSource;
    size_t kernelSourceSize;

    // �ҽ��ڵ�� ���α׷� ��ü ����
    kernelSource = get_source_code("kernel.cl", &kernelSourceSize);
    program = clCreateProgramWithSource(context, 1, (const char**)&kernelSource, &kernelSourceSize, &err);
    CHECK_ERROR(err);

    // ���α׷� ����
    err = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    CHECK_ERROR(err);

    // Ŀ�� ��ü ����
    kernel = clCreateKernel(program, "vecAdd", &err);
    CHECK_ERROR(err);

    // �޸� ��ü ���� (�б�, ���� �ɼ� ����)
    buf_a = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, &err);
    CHECK_ERROR(err);
    buf_b = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, &err);
    CHECK_ERROR(err);
    buf_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY, bytes, NULL, &err);
    CHECK_ERROR(err);

    // ȣ��Ʈ �޸𸮿� �ִ� �����͸� ����̽� ���� �޸𸮿� ����
    err = clEnqueueWriteBuffer(queue, buf_a, CL_TRUE, 0, bytes, A, 0, NULL, NULL);
    CHECK_ERROR(err);
    err = clEnqueueWriteBuffer(queue, buf_b, CL_TRUE, 0, bytes, B, 0, NULL, NULL);
    CHECK_ERROR(err);

    // Ŀ�� �ڵ忡 ���� �Ѱ��ֱ�
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &buf_a);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &buf_b);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 2, sizeof(cl_mem), &buf_c);
    CHECK_ERROR(err);

    // �����ߴ� work-item, work-group���� Ŀ�� �ڵ带 ����
    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);
    CHECK_ERROR(err);

    clFinish(queue);

    // ����̽� ���� �޸� buf_c�� ���� �պ��͸� ȣ��Ʈ �޸��� C�� ������
    err = clEnqueueReadBuffer(queue, buf_c, CL_TRUE, 0, bytes, C, 0, NULL, NULL);
    CHECK_ERROR(err);

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += C[i];
    printf("result: %d\n", sum);

    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("<GPU> time: %.12f ms\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 10000);

    // OpenCL �ڿ��� ����
    clReleaseMemObject(buf_a);
    clReleaseMemObject(buf_b);
    clReleaseMemObject(buf_c);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    // ȣ��Ʈ �޸� ����
    free(buf_a);
    free(buf_b);
    free(buf_c);

    return 0;
}