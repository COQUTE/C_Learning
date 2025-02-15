#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Box {
	short candy;
	float snack;
	char doll[8];
};

int main()
{
	union Box* b1 = malloc(sizeof(union Box));

	printf("%d\n", sizeof(union Box));

	strcpy(b1->doll, "bear");

	printf("%d\n", b1->candy);
	printf("%f\n", b1->snack);
	printf("%s\n", b1->doll);

	free(b1);

	return 0;
}