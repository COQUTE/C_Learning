#include <stdio.h>

union Data {
	char c1;
	short num1;
	int num2;
};

int main()
{
	union Data d1;

	d1.num2 = 0x12345678;

	printf("0x%x\n", d1.num2);
	printf("0x%x\n", d1.num1);
	printf("0x%x\n", d1.c1);

	printf("%d\n", sizeof(d1));

	return 0;
}