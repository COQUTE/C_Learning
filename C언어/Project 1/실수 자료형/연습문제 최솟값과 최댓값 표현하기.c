#include<stdio.h>
#include<float.h>

int main()
{
	float num1 = FLT_MAX;
	double num2 = DBL_MIN;
	long double num3 = LDBL_MAX;

	printf("%.2f\n", num1);
	printf("%e\n", num2);
	printf("%Le\n", num3);

	return 0;
}