#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	FILE* fp;
	int filter[3][3] = { { 1, 2, 1 }, { 0, 0, 0 }, { -1, -2, -1 } };
	unsigned char** input, ** output;
	int i, j;
	double val = 0;

	//Memory alloc
	input = (unsigned char**)malloc(sizeof(unsigned char*) * 512);
	for (i = 0; i < 512; i++)
		input[i] = (unsigned char*)malloc(sizeof(unsigned char) * 512);

	output = (unsigned char**)malloc(sizeof(unsigned char*) * 512);
	for (i = 0; i < 512; i++)
		output[i] = (unsigned char*)malloc(sizeof(unsigned char) * 512);

	//File read
	fp = fopen("lena.img", "rb");
	for (i = 0; i < 512; i++)
	{
		fread(input[i], sizeof(unsigned char), 512, fp);
	}
	fclose(fp);

	//High-pass filtering
	for (i = 1; i < 511; i++)
	{
		for (j = 1; j < 511; j++)
		{
			for (int s = -1; s <= 1; s++) {
				for (int t = -1; t <= 1; t++) {
					val += filter[s + 1][t + 1] * (double)input[i + s][j + t];
				}
			}

			if (val < 0)
				val = abs(val);

			output[i][j] = (unsigned char)val;

			val = 0;
		}
	}

	//File write
	fp = fopen("HPF.img", "wb");

	for (i = 0; i < 512; i++)
	{
		fwrite(output[i], sizeof(unsigned char), 512, fp);
	}
	fclose(fp);

	//Memory free
	for (i = 0; i < 512; i++)
		free(input[i]);
	free(input);

	for (i = 0; i < 512; i++)
		free(output[i]);
	free(output);
}