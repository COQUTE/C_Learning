#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ABC(int a[], int k)
{
	int max = a[k];
	int index = k;
	int tmp;

	for (int i = k; i < 10; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			index = i;
		}
	}

	if (index != k)
	{
		tmp = a[k];
		a[k] = a[index];
		a[index] = tmp;
	}
}

int main()
{
	int k[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &k[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		ABC(k, i);
	}

	for (int i = 0; i < 10; i++)
	{
		printf(" %d", k[i]);
	}

	printf("\n");

	return 0;
}