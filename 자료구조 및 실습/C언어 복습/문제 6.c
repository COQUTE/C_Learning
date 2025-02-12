#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	char name[10];
	int score;
};

int main()
{
	struct student student[5];
	float avg = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d", student[i].name, &student[i].score);
	}

	for (int i = 0; i < 5; i++)
	{
		avg += (float)student[i].score;
	}

	avg /= 5;

	for (int i = 0; i < 5; i++)
	{
		if ((float)student[i].score <= avg)
			printf("%s\n", student[i].name);
	}

	return 0;
}