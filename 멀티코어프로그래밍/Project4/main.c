#include "integral.h"
#include <stdio.h>

int main() {
    double ans_seq, ans_opencl;
    int N = 536870912;

    printf("Sequential version...\n");
    ans_seq = integral_seq(N);

    printf("\nOpenCL version...\n");
    ans_opencl = integral_opencl(N);

    if (fabs(ans_seq - ans_opencl) < 0.001)
        printf("\nSequential version == OpenCL version\n");
    else {
        printf("\nSequential version != OpenCL version\n");
        printf("%lf != %lf\n", ans_seq, ans_opencl);
    }

    return 0;
}