#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void order(int* p1, int* p2, int* p3)
{
	int min, mid, max;

	if (*p1 > *p2)
	{
		if (*p1 > *p3) // p1 > p2 && p1 > p3
		{
			if (*p2 > * p3) // p1 > p2 > p3
			{
				min = *p1;
				mid = *p2;
				max = *p3;
			}
			else // p1 > p3 > p2
			{
				min = *p2;
				mid = *p3;
				max = *p1;
			}
		}
		else // p3 > p1 > p2
		{
			min = *p2;
			mid = *p1;
			max = *p3;
		}
	}
	else // p1 < p2
	{
		if (*p1 < * p3) // p1 < p2 && p1 < p3
		{
			if (*p2 < *p3) // p1 < p2 < p3
			{
				min = *p1;
				mid = *p2;
				max = *p3;
			}
			else // p1 < p3 < p2
			{
				min = *p1;
				mid = *p3;
				max = *p2;
			}
		}
		else // p3 < p1 < p2
		{
			min = *p3;
			mid = *p1;
			max = *p2;
		}
	}

	*p1 = min;
	*p2 = mid;
	*p3 = max;
}

int main()
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	order(&A, &B, &C);

	printf("%d %d %d\n", A, B, C);

	return 0;
}