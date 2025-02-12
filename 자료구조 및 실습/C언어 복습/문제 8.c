#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	char name[8];
	int Korea;
	int English;
	int Math;
	float avg;
};

int main()
{
	int N;
	struct student* student;

	scanf("%d", &N);

	student = malloc(sizeof(struct student) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", student[i].name, &student[i].Korea, &student[i].English, &student[i].Math);

		student[i].avg = (float)(student[i].Korea + student[i].English + student[i].Math) / 3;
	}

	for (int i = 0; i < N; i++)
	{
		printf("%s %0.1f", student[i].name, student[i].avg);

		if (student[i].Korea >= 90 || student[i].English >= 90 || student[i].Math >= 90)
			printf(" GREAT");
		if (student[i].Korea < 70 || student[i].English < 70 || student[i].Math < 70)
			printf(" BAD");

		printf("\n");
	}

	free(student);

	return 0;
}