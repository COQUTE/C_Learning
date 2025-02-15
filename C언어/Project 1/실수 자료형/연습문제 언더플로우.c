#include<stdio.h>
#include<float.h>

int main()
{
	float num1 = FLT_MIN;
	num1 = num1 / 100000000.0f;
	printf("%e\n", num1);

	return 0;
}