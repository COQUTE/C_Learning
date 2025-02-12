#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char name[21];
	int score;
	struct NODE* next;
} NODE, *NODEPTR;

NODEPTR getnode()
{
	NODEPTR ptr = (NODEPTR)malloc(sizeof(NODE));

	ptr->next = NULL;

	return ptr;
}

int main()
{
	NODEPTR L = NULL;
	NODEPTR newnode;

	newnode = getnode();

	scanf("%s %d", newnode->name, &newnode->score);

	L = newnode;

	while (strcmp(newnode->name, "0") != 0)
	{
		newnode = getnode();

		scanf("%s %d", newnode->name, &newnode->score);

		newnode->next = L;
		L = newnode;
	}

	/* 뒤에 넣고 싶을 경우
	
	NODEPTR* last = L;
	
	while (strcmp(newnode->name, "0") != 0)
	{ 
		while (last->next != NULL)
			last = last->next;
		
		newnode = getnode();

		scanf("%s %d", newnode->name, &newnode->name);

		last->next = newnode;
	} */

	for (NODEPTR ptr = L; ptr != NULL; ptr = ptr->next)
	{
		printf("%s %d\n", ptr->name, ptr->score);
	}

	return 0;
}