#include<stdio.h>

int main()
{
	int num1 = 2;
	int num2 = 2;
	int num3;
	int num4;
	int num5;
	int num6;

	num3 = num1++; // num1의 값을 num3에 할당한 뒤 num1의 값을 1 증가시킴
	num4 = num2--; // num2의 값을 num4에 할당한 뒤 num2의 값을 1 감소시킴

	printf("%d %d\n", num3, num4);

	num1 = 2; // 1 증가된 num1의 값을 다시 2로 초기화
	num2 = 2; // 1 감소된 num2의 값을 다시 2로 초기화

	num5 = ++num1; // num1의 값을 1 증가시킨 뒤 num5에 할당
	num6 = --num2; // num2의 값을 1 감소시킨 뒤 num6에 할당

	printf("%d %d\n", num5, num6);

	return 0;
}