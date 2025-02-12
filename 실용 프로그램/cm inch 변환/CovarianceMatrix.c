#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Student {
	double height;	// 키,				X1
	double weight;	// 몸무게,			X2
	double GPA;		// 평균 학점,		X3
	double score;	// 선형대수점수,	X4
	double eph		// 시간당 소득,			X5
} Student;

int main() {
	Student* list;
	Student listAvg;

	list = (Student*)malloc(sizeof(Student) * 10);

	srand(time(NULL));

	listAvg.height = 0.0;
	listAvg.weight = 0.0;
	listAvg.GPA	 = 0.0;
	listAvg.score = 0.0;
	listAvg.eph = 0.0;

	for (int i = 0; i < 10; i++) {
		list[i].height = (double)(rand() % 2000 + 1400) / 10;
		listAvg.height += list[i].height;

		list[i].weight = (double)(rand() % 800 + 500) / 10;
		listAvg.weight += list[i].weight;

		list[i].GPA = (double)(rand() % 1000) / 10;
		listAvg.GPA += list[i].GPA;

		list[i].score = (double)(rand() % 1000) / 10;
		listAvg.score += list[i].score;

		list[i].eph = (double)(rand() % 10000) + 5000;
		listAvg.eph += list[i].eph;
	}

	listAvg.height = listAvg.height / 10;
	listAvg.weight = listAvg.weight / 10;
	listAvg.GPA = listAvg.GPA / 10;
	listAvg.score = listAvg.score / 10;
	listAvg.eph = listAvg.eph / 10;

	for (int i = 0; i < 10; i++) {
		list[i].height -= listAvg.height;
		list[i].weight -= listAvg.weight;
		list[i].GPA -= listAvg.GPA;
		list[i].score -= listAvg.score;
		list[i].eph -= listAvg.eph;
	}

	return 0;
}