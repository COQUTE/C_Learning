#include<stdio.h>

int main()
{
	float num1 = 0.1f;
	double num2 = 3867.215820;
	long double num3 = 9.327513l; // long double은 값을 할당할 때 숫자 뒤에 l(엘 소문자)을 붙임

	// float와 double은 %f로 출력, long doubledms %Lf로 출력
	printf("%f %f %Lf\n", num1, num2, num3);

	return 0;
}