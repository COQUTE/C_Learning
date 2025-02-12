#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int element;
	struct NODE* next;
}NODE, *NODE_PTR, **NODE_DPTR;

NODE_PTR getnode(int element)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->element = element;
	ptr->next = NULL;

	return ptr;
}

void initial(NODE_DPTR L, int element)
{
	NODE_PTR ptr = getnode(element);

	*L = ptr;
}

int count(NODE_PTR L)
{
	NODE_PTR ptr = L;

	if (ptr == NULL)
		return 0;
	else
		return 1 + count(ptr->next);
}

void add(NODE_PTR L, int Rank, int element)
{
	NODE_PTR ptr = L;
	NODE_PTR newnode;

	if (Rank < 2 || Rank > count(L) + 1)
		printf("invalide position\n");
	else
	{
		newnode = getnode(element);

		for (int i = 0; i < Rank - 2; i++)
			ptr = ptr->next;

		newnode->next = ptr->next;
		ptr->next = newnode;
	}
}

int main()
{
	NODE_PTR L;
	int N, Rank, element;

	scanf("%d", &element);

	initial(&L, element);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &Rank, &element);

		add(L, Rank, element);
	}

	printf("%d\n", count(L));

	return 0;
}