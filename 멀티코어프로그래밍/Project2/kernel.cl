__kernel void matMul(__global float* A, __global float* B, __global float* C, int N, int K) {
	int rowC = get_global_id(0);
	int colC = get_global_id(1);

	float sum = 0.0f;
	
	for (int i = 0; i < K; i++) {
		sum += A[rowC * K + i] * B[i * N + colC];
	}

	C[rowC * N + colC] = sum;
}