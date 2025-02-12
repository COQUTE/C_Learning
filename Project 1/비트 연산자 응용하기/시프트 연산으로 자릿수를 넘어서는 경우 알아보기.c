#include <stdio.h>

int main()
{
	unsigned char num1 = 240;
	unsigned char num2 = 15;

	unsigned char num3, num4;

	num3 = num1 << 2;
	num4 = num2 >> 2;

	printf("%u\n", num3); // 192: 1100 0000: 맨 앞의 11이 사라져서 11000000이 됨
	printf("%u\n", num4); //   3: 0000 0011: 맨 뒤의 11이 사라져서 00000011이 됨

	return 0;
}