#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num1, num2;

	printf("정수를 두 개 입력하시오: ");
	scanf("%d %d", &num1, &num2);

	printf("%d %d\n", num1, num2);

	return 0;
}