#include "integral.h"
#include <stdio.h>
#include <time.h>

char* get_source_code(const char* file_name, size_t* len) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("[%s:%d] Failed to open %s\n", __FILE__, __LINE__, file_name);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    size_t length = (size_t)ftell(file);
    rewind(file);

    char* source_code = (char*)malloc(length + 1);
    fread(source_code, length, 1, file);
    source_code[length] = '\0';
    fclose(file);
    *len = length;

    return source_code;
}

void build_error(cl_program program, cl_device_id device, cl_int err) {
    if (err == CL_BUILD_PROGRAM_FAILURE) {
        size_t log_size;
        char* log;

        err = clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
        CHECK_ERROR(err);

        log = (char*)malloc(log_size + 1);
        err = clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
        CHECK_ERROR(err);

        log[log_size] = '\0';
        printf("Compiler error:\n%s\n", log);
        free(log);
        exit(0);
    };
}

double f(double x) {
    return (3 * x * x + 2 * x + 1);
}

double integral_seq(const int N) {
    double dx = 1.0 / (double)N;
    double sum = 0.0f;

    clock_t start = clock();
    for (int i = 0; i < N; i++)
        sum += f(i * dx) * dx;
    printf("Integral_seq\tExecution time: %lfsec\n", (float)(clock() - start) / CLOCKS_PER_SEC);

    return sum;
}

double integral_opencl(const int N) {
    /*
     * 플랫폼 탐색부터 커널 생성까지의 코드를 작성해주세요.
     */

    

    clock_t start = clock();

    /*
     * 여기서부터 병렬 처리를 위한 나머지 호스트 코드를 작성하세요.
     */



    printf("Integral_opencl\tTotal Execution time: %lfsec\n", (float)(clock() - start) / CLOCKS_PER_SEC);
}