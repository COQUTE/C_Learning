#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char Name[21];
	int Score;
	struct NODE* next;
} NODE;

NODE* getnode()
{
	NODE* ptr;
	ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;

	return ptr;
}

int main()
{
	NODE* L = NULL;
	NODE* newnode;

	char Name[21];
	int Score;

	do {
		scanf("%s %d", Name, &Score);

		newnode = getnode();
		strcpy(newnode->Name, Name);
		newnode->Score = Score;
		newnode->next = L;
		L = newnode;
	} while (strcmp(L->Name, "0") != 0);

	for (NODE* ptr = L; ptr != NULL; ptr = ptr->next)
	{
		printf("학생 이름 : %s, 학점 : %d\n", ptr->Name, ptr->Score);
	}

	return 0;
}