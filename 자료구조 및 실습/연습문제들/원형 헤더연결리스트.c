#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int element;
	struct NODE* next;
} NODE, *NODE_PTR, **NODE_DPTR;

NODE_PTR getnode(int element)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->element = element;
	ptr->next = NULL;

	return ptr;
}

void initial(NODE_DPTR H)
{
	NODE_PTR ptr = getnode(0);

	*H = ptr;
	(*H)->next = *H;
}

NODE_PTR MoveNode(NODE_PTR H, int Rank)
{
	NODE_PTR ptr = H;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	return ptr;
}

int size(NODE_PTR H)
{
	NODE_PTR ptr = H->next;
	int count = 0;

	while (ptr != H)
	{
		count++;
		ptr = ptr->next;
	}

	return count;
}

void add(NODE_PTR H, int Rank, int element)
{
	NODE_PTR ptr;
	NODE_PTR newnode;

	if (Rank < 1 || Rank > size(H) + 1)
	{
		printf("invalid position\n");

		return;
	}

	newnode = getnode(element);

	ptr = MoveNode(H, Rank - 1);

	newnode->next = ptr->next;
	ptr->next = newnode;
}

void Remove(NODE_PTR H, int Rank)
{
	NODE_PTR before, ptr;

	if (Rank < 1 || Rank > size(H))
	{
		printf("invalid position\n");

		return;
	}

	before = MoveNode(H, Rank - 1);

	ptr = before->next;

	before->next = ptr->next;
	
	free(ptr);
}

int get(NODE_PTR H, int Rank)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > size(H))
	{
		printf("invalid position\n");

		return;
	}

	ptr = MoveNode(H, Rank);

	printf("%d\n", ptr->element);

	return ptr->element;
}

void set(NODE_PTR H, int Rank, int element)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > size(H))
	{
		printf("invalid position\n");

		return;
	}

	ptr = MoveNode(H, Rank);

	ptr->element = element;
}

void print(NODE_PTR H)
{
	NODE_PTR ptr = H->next;

	while (ptr != H)
	{
		printf(" %d", ptr->element);

		ptr = ptr->next;
	}

	printf("\n");
}

void FreeMemory(NODE_PTR H)
{
	NODE_PTR ptr = H, tmp;
	int count = size(H);

	for (int i = 0; i <= count; i++)
	{
		tmp = ptr;
		ptr = ptr->next;

		free(tmp);
	}
}

int main()
{
	NODE_PTR H;
	char Type;
	int N, Rank, element;

	initial(&H);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%c", &Type);

		if (Type == 'A')
		{
			scanf("%d %d", &Rank, &element);

			add(H, Rank, element);
		}
		else if (Type == 'R')
		{
			scanf("%d", &Rank);

			Remove(H, Rank);
		}
		else if (Type == 'G')
		{
			scanf("%d", &Rank);

			element = get(H, Rank);
		}
		else if (Type == 'S')
		{
			scanf("%d %d", &Rank, &element);

			set(H, Rank, element);
		}
		else if (Type == 'P')
		{
			print(H);
		}
		else
			printf("invalid type\n");
	}

	return 0;
}