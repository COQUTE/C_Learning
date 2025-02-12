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
    // 시간 측정 변수 선언
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    // 합 변수 선언
    int sum;

    // 벡터 크기
    int n = 16384;
    size_t bytes = sizeof(int) * n;

    // 호스트 input 벡터
    int* A;
    int* B;
    // 호스트 output 벡터
    int* C;

    // 디바이스 input 버퍼
    cl_mem buf_a;
    cl_mem buf_b;
    // 디바이스 output 버퍼
    cl_mem buf_c;

    // 플랫폼
    cl_platform_id platform;
    // 디바이스 ID
    cl_device_id device_id;
    // 콘텍스트
    cl_context context;
    // 커맨드 큐
    cl_command_queue queue;
    // 프로그램
    cl_program program;
    // 커널
    cl_kernel kernel;

    // 각 벡터 호스트 메모리 할당
    A = (int*)malloc(bytes);
    B = (int*)malloc(bytes);
    C = (int*)malloc(bytes);

    // 시간 측정 전 설정
    QueryPerformanceFrequency(&ticksPerSec);

    // rand() 사용 전 설정
    srand(time(NULL));

    // A, B 초기화
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        B[i] = rand() % 1000;
    }

    // CPU 계산 <시간 측정>
    QueryPerformanceCounter(&start);

    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i] + B[i];
    }
    printf("result: %d\n", sum);

    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("<CPU> time: %.12f ms\n\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 10000);

    // GPU 계산 <시간 측정>
    QueryPerformanceCounter(&start);

    // work-item, work-group 설정
    size_t globalSize, localSize;
    // err 변수 선언
    cl_int err;

    localSize = 64;
    // globalSize는 무조건 localSize로 나누어 떨어져야 하기 때문에 ceil() 올림 함수 사용
    globalSize = ceil(n / (float)localSize) * localSize;

    err = clGetPlatformIDs(1, &platform, NULL);
    CHECK_ERROR(err);

    // 디바이스 ID 가져오기
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
    CHECK_ERROR(err);

    // 콘텍스트 생성
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);
    CHECK_ERROR(err);

    // 커맨드 큐 생성
    queue = clCreateCommandQueueWithProperties(context, device_id, 0, &err);
    CHECK_ERROR(err);
    // queue = clCreateCommandQueueWithProperties(context, device_id, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE, &err);

    char* kernelSource;
    size_t kernelSourceSize;

    // 소스코드로 프로그램 객체 생성
    kernelSource = get_source_code("kernel.cl", &kernelSourceSize);
    program = clCreateProgramWithSource(context, 1, (const char**)&kernelSource, &kernelSourceSize, &err);
    CHECK_ERROR(err);

    // 프로그램 빌드
    err = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
    CHECK_ERROR(err);

    // 커널 객체 생성
    kernel = clCreateKernel(program, "vecAdd", &err);
    CHECK_ERROR(err);

    // 메모리 객체 생성 (읽기, 쓰기 옵션 선택)
    buf_a = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, &err);
    CHECK_ERROR(err);
    buf_b = clCreateBuffer(context, CL_MEM_READ_ONLY, bytes, NULL, &err);
    CHECK_ERROR(err);
    buf_c = clCreateBuffer(context, CL_MEM_WRITE_ONLY, bytes, NULL, &err);
    CHECK_ERROR(err);

    // 호스트 메모리에 있는 데이터를 디바이스 버퍼 메모리에 쓰기
    err = clEnqueueWriteBuffer(queue, buf_a, CL_TRUE, 0, bytes, A, 0, NULL, NULL);
    CHECK_ERROR(err);
    err = clEnqueueWriteBuffer(queue, buf_b, CL_TRUE, 0, bytes, B, 0, NULL, NULL);
    CHECK_ERROR(err);

    // 커널 코드에 인자 넘겨주기
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &buf_a);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 1, sizeof(cl_mem), &buf_b);
    CHECK_ERROR(err);
    err = clSetKernelArg(kernel, 2, sizeof(cl_mem), &buf_c);
    CHECK_ERROR(err);

    // 지정했던 work-item, work-group으로 커널 코드를 실행
    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);
    CHECK_ERROR(err);

    clFinish(queue);

    // 디바이스 버퍼 메모리 buf_c에 있을 합벡터를 호스트 메모리의 C로 가져옴
    err = clEnqueueReadBuffer(queue, buf_c, CL_TRUE, 0, bytes, C, 0, NULL, NULL);
    CHECK_ERROR(err);

    sum = 0;
    for (int i = 0; i < n; i++)
        sum += C[i];
    printf("result: %d\n", sum);

    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("<GPU> time: %.12f ms\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart * 10000);

    // OpenCL 자원들 해제
    clReleaseMemObject(buf_a);
    clReleaseMemObject(buf_b);
    clReleaseMemObject(buf_c);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    // 호스트 메모리 해제
    free(buf_a);
    free(buf_b);
    free(buf_c);

    return 0;
}