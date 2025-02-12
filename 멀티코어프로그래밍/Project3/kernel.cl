__kernel void imgRotate(__global float* dst_data, __global float* src_data, int width, int height, float sinTheta, float cosTheta) {
	float x0 = width / 2.0f;
	float y0 = height / 2.0f;

	int dst_x = get_global_id(0);
	int dst_y = get_global_id(1);

	float xOff = dst_x - x0;
	float yOff = dst_y - y0;

	int src_x = (int)(xOff * cosTheta + yOff * sinTheta + x0);
	int src_y = (int)(yOff * cosTheta - xOff * sinTheta + y0);

	if ((src_x >= 0) && (src_x < width) && (src_y >= 0) && src_y < height)
		dst_data[dst_y * width + dst_x] = src_data[src_y * width + src_x];
	else
		dst_data[dst_y + width + dst_x] = 0.0f;
}