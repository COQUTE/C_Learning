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
	NODEPTR ptr = (NODEPTR)malloc(sizeof(NODE));

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
	NODEPTR L = NULL ,last = NULL;
	NODEPTR newnode;
	char name[21];
	int score;

	while (1)
	{
		scanf("%s %d", name, &score);

		if (strcmp(name, "0") == 0)
			break;

		newnode = getnode(name, score);

		if (L == NULL)
		{
			L = newnode;
			last = L;
		}
		else
		{
			while (last->next != NULL)
				last = last->next;

			last->next = newnode;
		}
	}

	for (NODEPTR ptr = L; ptr != NULL; ptr = ptr->next)
	{
		printf("%s %d\n", ptr->name, ptr->score);
	}

	putnode(L);

	return 0;
}