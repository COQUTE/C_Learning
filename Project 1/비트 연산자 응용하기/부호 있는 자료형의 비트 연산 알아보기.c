#include <stdio.h>

int main()
{
	unsigned char num1 = 131;
	char num2 = -125;

	unsigned char num3;
	char num4;

	num3 = num1 >> 5;
	num4 = num2 >> 5;

	printf("%u\n", num3); //  4: 0000 0100: 맨 뒤의 11은 사라지고 0000 0100이 됨
	printf("%u\n", num4); // -4: 1111 1100: 모자라는 공간은 부호 비트의 값인 1로 채워지므로 1111 1100이 됨

	return 0;
}