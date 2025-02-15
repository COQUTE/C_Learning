#include <stdio.h>

int main()
{
	unsigned char num1 = 3;
	unsigned char num2 = 24;
	
	printf("%u\n", num1 << 3); // <<Àº 2ÀÇ °ÅµìÁ¦°öÀ» °öÇÏ±â
	printf("%u\n", num2 >> 2); // >>Àº 2ÀÇ °ÅµìÁ¦°öÀ» ³ª´©±â

	return 0;
}