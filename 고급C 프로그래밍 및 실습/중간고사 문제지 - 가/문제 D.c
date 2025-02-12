#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct city {
	char name[21];
	float HighTmp;
	float LowTmp;
	float dif;
};

int input_city(struct city city[])
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s %f %f", city[i].name, &city[i].HighTmp, &city[i].LowTmp);
	}

	return N;
}

struct city find_largest(struct city city[], int SIZE)
{
	float largest;
	int flag = 0;

	for (int i = 0; i < SIZE; i++)
	{
		city[i].dif = city[i].HighTmp - city[i].LowTmp;
	}

	largest = city[0].dif;

	for (int i = 1; i < SIZE; i++)
	{
		if (largest <= city[i].dif)
		{
			flag = i;
			largest = city[i].dif;
		}
	}

	return city[flag];
}

int main()
{
	struct city city[10];
	int count;

	count = input_city(city);

	printf("%s %0.1f\n", find_largest(city, count).name, find_largest(city, count).dif);

	return 0;
}