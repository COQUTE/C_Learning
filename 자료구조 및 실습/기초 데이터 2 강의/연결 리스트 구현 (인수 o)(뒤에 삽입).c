#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char name[21];
	int score;
	struct NODE* next;
} NODE, *NODEPTR;

NODEPTR getnode(char name[], int score)
{
	NODEPTR ptr;
	ptr = (NODEPTR)malloc(sizeof(NODE));
	
	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->next = NULL;

	return ptr;
}

int main()
{
	NODEPTR L;
	NODEPTR last;
	NODEPTR newnode;

	char name[21];
	int score;

	scanf("%s %d", name, &score);

	newnode = getnode(name, score);
	L = newnode;

	last = L;

	while (strcmp(newnode->name, "0") != 0)
	{
		scanf("%s %d", name, &score);

		newnode = getnode(name, score);
		
		while (last->next != NULL)
			last = last->next;

		last->next = newnode;
	}

	for (NODEPTR ptr = L; ptr != NULL; ptr = ptr->next)
	{
		printf("학생 이름 : %s, 학점 : %d\n", ptr->name, ptr->score);
	}

	return 0;
}