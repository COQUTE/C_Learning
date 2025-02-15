#include<stdio.h>

int main()
{
	char num1 = 128;
	unsigned char num2 = 256;
	
	printf("%d %u\n", num1, num2); // -128 0: 저장할 수 있는 범위를 넘어서므로 최솟값부터 다시 시작

	return 0;
}