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
	NODE* ptr = (NODEPTR)malloc(sizeof(NODE));

	strcpy(ptr->name, name);
	ptr->score = score;
	ptr->next = NULL;

	return ptr;
}

void putnode(NODEPTR L)
{
	NODEPTR tmp;

	for (NODEPTR ptr = L; ptr != NULL;)
	{
		tmp = ptr->next;

		free(ptr);

		ptr = tmp;
	}
}

int main()
{
	NODEPTR L = NULL, newnode;
	NODEPTR ptr;

	char name[21];
	int score;

	while (1) {
		scanf("%s %d", name, &score);

		if (strcmp(name, "0") == 0)
			break;

		newnode = getnode(name, score);

		if (L == NULL)
			L = newnode;
		else
		{
			newnode->next = L;
			L = newnode;
		}
	}

	for (ptr = L; ptr != NULL; ptr = ptr->next)
	{
		printf("%s %d\n", ptr->name, ptr->score);
	}

	putnode(L); // L(헤드 노드) 이후 모든 노드의 메모리를 해제

	return 0;
}