#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct student {
	int num;
	char s[10];
	int age;
};

void swap(struct student* std1, struct student* std2)
{
	int tmp;
	char string[10];
	
	tmp = std1->age;
	std1->age = std2->age;
	std2->age = tmp;

	strcpy(string, std1->s);
	strcpy(std1->s, std2->s);
	strcpy(std2->s, string);
}

int main()
{
	struct student s1, s2;

	scanf("%d %s %d", &s1.num, s1.s, &s1.age);
	scanf("%d %s %d", &s2.num, s2.s, &s2.age);

	swap(&s1, &s2);

	printf("%d %s %d\n", s1.num, s1.s, s1.age);
	printf("%d %s %d\n", s2.num, s2.s, s2.age);

	return 0;
}