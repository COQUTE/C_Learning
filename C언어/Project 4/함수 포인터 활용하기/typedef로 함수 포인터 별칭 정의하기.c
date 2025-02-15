#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

typedef int (*FP)(int, int);

struct Calc {
	FP fp;
};

void executer(FP fp)
{
	printf("%d\n", fp(70, 80));
}

int main()
{
	FP fp1;
	fp1 = add;
	printf("%d\n", fp1(10, 20));

	FP fp[10];
	fp[0] = add;
	printf("%d\n", fp[0](30, 40));

	struct Calc c;
	c.fp = add;
	printf("%d\n", c.fp(50, 60));

	executer(add);

	return 0;
}