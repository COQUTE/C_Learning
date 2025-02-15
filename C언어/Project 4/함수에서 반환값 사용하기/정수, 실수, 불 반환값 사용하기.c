#include <stdio.h>
#include <stdbool.h>

float realNumber()
{
	return 1.234567f;
}

bool truth()
{
	return true;
}

int main()
{
	float num1;
	bool b1;

	num1 = realNumber();
	b1 = truth();

	printf("%f\n", num1);
	printf("%d\n", b1);

	return 0;
}