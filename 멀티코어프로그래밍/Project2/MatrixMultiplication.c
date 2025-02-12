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

void seq_mat_mul(int ROW_A, int COL_B, int COL_A, float* A, float* B, float* C) {
    int i, j, k;
    float tmp;

    for (i = 0; i < ROW_A; i++) {
        for (j = 0; j < COL_B; j++) {
            tmp = 0.0;
            for (k = 0; k < COL_A; k++) {
                // C[i][j] += A[i][k] * B[k][j];
                *(C + (i * COL_B + j)) += *(A + (i * COL_A + k)) * *(B + (k * COL_B + j));
            }
        }
    }
}

int main() {
    // �ð� ���� ���� ����
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    // ��� ũ��
    unsigned int n = 1000;

    // ȣ��Ʈ input ���� & ȣ��Ʈ �޸� �Ҵ�
    unsigned int size_a = n * n;
    size_t bytes_size_a = sizeof(float) * size_a;
    float* A = (float*)malloc(bytes_size_a);

    unsigned int size_b = n * n;
    size_t bytes_size_b = sizeof(float) * size_b;
    float* B = (float*)malloc(bytes_size_b);

    // ȣ��Ʈ output ���� & ȣ��Ʈ �޸� �Ҵ�
    int size_c = n * n;
    size_t bytes_size_c = sizeof(float) * size_c;
    float* C = (float*)malloc(bytes_size_c);

    // rand() ��� �� ����
    srand(time(NULL));

    // ȣ��Ʈ �޸� A, B �ʱ�ȭ
    for (int i = 0; i < size_a; i++)
        A[i] = (float)(rand() % 10) / 10;
    for (int i = 0; i < size_b; i++)
        B[i] = (float)(rand() % 10) / 10;

    // �ð� ���� �� ����
    QueryPerformanceFrequency(&ticksPerSec);

    // CPU ��� <�ð� ����>
    QueryPerformanceCounter(&start);

    seq_mat_mul(n, n, n, A, B, C);

    // 1000 x 1000�� ��� �񱳰� ����� ������ ����
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %f", C[i * n + j]);
        }
        printf("\n");
    }

    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("<CPU> time: %.12f ms\n\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 10000);

    // GPU ��� <�ð� ����>
    QueryPerformanceCounter(&start);

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

    size_t globalSize[2] = { 1000, 1000 };
    size_t localSize[2] = { 8, 8 };
    cl_int err;

    // �÷��� ���� ��������
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

    // �ҽ��ڵ�� ���α׷� ��ü ����
    char* kernelSource;
    size_t kernelSourceSize;

    kernelSource = get_source_code("kernel.cl", &kernelSourceSize);
    program = clCreateProgramWithSource(context, 1, (const char**)&kernelSource, &kernelSourceSize, &err);
    CHECK_ERROR(err);

    // ���α׷� ����
    err = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    CHECK_ERROR(err);

    // Ŀ�� ��ü ����
    kernel = clCreateKernel(program, "matMul", &err);
    CHECK_ERROR(err);

    // �޸� ��ü ����
    buf_a = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes_size_a, NULL, &err);
    CHECK_ERROR(err);
    buf_b = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes_size_b, NULL, &err);
    CHECK_ERROR(err);
    buf_c = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes_size_c, NULL, &err);
    CHECK_ERROR(err);

    // ȣ��Ʈ �޸𸮿� �ִ� �����͸� ����̽� ���� �޸𸮿� ����
    err = clEnqueueWriteBuffer(queue, buf_a, CL_TRUE, 0, bytes_size_a, A, 0, NULL, NULL);
    CHECK_ERROR(err);
    err = clEnqueueWriteBuffer(queue, buf_b, CL_TRUE, 0, bytes_size_b, B, 0, NULL, NULL);
    CHECK_ERROR(err);

    int wA = n;
    int wB = n;

    // Ŀ�� �ڵ忡 ���� �Ѱ��ֱ�
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &buf_a);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &buf_b);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 2, sizeof(cl_mem), &buf_c);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 3, sizeof(int), &wA);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 4, sizeof(int), &wB);

    /*
    // Ŀ�� �ڵ� ���� �� host���� ���� �޾ƺ���
    float* buf_host = (float*)malloc(bytes_size_c);
    
    err = clEnqueueReadBuffer(queue, buf_a, CL_TRUE, 0, bytes_size_a, buf_host, 0, NULL, NULL);
    CHECK_ERROR(err);

    for (size_t i = 0; i < bytes_size_a; i++)
        printf("%f ", buf_host[i]);
    */

    // Ŀ�� �ڵ� ����
    err = clEnqueueNDRangeKernel(queue, kernel, 2, NULL, globalSize, localSize, 0, NULL, NULL);
    CHECK_ERROR(err);

    clFinish(queue);

    // buf_c���� ȣ��Ʈ �޸𸮷� ���� ������
    err = clEnqueueReadBuffer(queue, buf_c, CL_TRUE, 0, bytes_size_c, C, 0, NULL, NULL);
    CHECK_ERROR(err);

    // 1000 x 1000�� ��� �񱳰� ����� ������ ����
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %f", C[i * n + j]);
        }
        printf("\n");
    }

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