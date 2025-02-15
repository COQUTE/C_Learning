#include<stdio.h>
#include<limits.h> // 자료형의 최댓값과 최솟값이 정의된 헤더 파일

int main()
{
	char num1 = CHAR_MIN; // char의 최솟값
	short num2 = SHRT_MIN; // short의 최솟값
	int num3 = INT_MIN; // int의 최솟값
	long num4 = LONG_MIN; // long의 최솟값
	long long num5 = LLONG_MIN; // long long의 최솟값

	printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);

	return 0;
}