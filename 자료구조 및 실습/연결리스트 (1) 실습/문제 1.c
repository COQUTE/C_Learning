#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE *prev, *next;
	char Alpabet;
}NODE, *NODEPTR;

typedef struct H_T {
	NODEPTR H, T;
	int ListSize;
}H_T, *H_TPTR;

NODEPTR getnode(char Alpabet)
{
	NODEPTR ptr = (NODEPTR)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->Alpabet = Alpabet;

	return ptr;
}

H_TPTR initial()
{
	H_TPTR p;
	NODEPTR H, T;

	p = (H_TPTR)malloc(sizeof(H_T));

	H = getnode(0);
	T = getnode(0);

	H->next = T;
	T->prev = H;

	p->H = H;
	p->T = T;
	p->ListSize = 0;

	return p;
}

void Add(H_TPTR list, int Rank, char Alpabet)
{
	NODEPTR ptr = list->H;
	NODEPTR newnode;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	newnode = getnode(Alpabet);

	newnode->prev = ptr->prev;
	newnode->next = ptr;
	(ptr->prev)->next = newnode;
	ptr->prev = newnode;

	list->ListSize = list->ListSize + 1;
}

void Delete(H_TPTR list, int Rank)
{
	NODEPTR ptr = list->H;
	
	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	(ptr->next)->prev = ptr->prev;
	(ptr->prev)->next = ptr->next;

	free(ptr);

	list->ListSize = list->ListSize - 1;
}

char Get(H_TPTR list, int Rank)
{
	NODEPTR ptr = list->H;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	return ptr->Alpabet;
}

void Print(H_TPTR list)
{
	NODEPTR ptr = (list->H)->next;

	for (int i = 0; i < list->ListSize; i++)
	{
		printf("%c", ptr->Alpabet);

		ptr = ptr->next;
	}
}

int main()
{
	H_TPTR p;
	int N, Rank;
	char Operation, Alpabet;
	NODEPTR FreeMemory, tmp;

	p = initial();

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%c", &Operation);

		if (Operation == 'A')
		{
			scanf("%d %c", &Rank, &Alpabet);

			if (Rank < 1 || Rank > p->ListSize + 1)
				printf("invalid position\n");
			else
				Add(p, Rank, Alpabet);
		}
		else if (Operation == 'D')
		{
			scanf("%d", &Rank);

			if (Rank < 1 || Rank > p->ListSize)
				printf("invalid position\n");
			else
				Delete(p, Rank);
		}
		else if (Operation == 'G')
		{
			scanf("%d", &Rank);

			if (Rank < 1 || Rank > p->ListSize)
				printf("invalid position\n");
			else
				printf("%c\n", Get(p, Rank));
		}
		else if (Operation == 'P')
		{
			Print(p);

			printf("\n");
		}
	}

	FreeMemory = (p->H)->next;

	for (int i = 0; i < p->ListSize; i++)
	{
		tmp = FreeMemory->next;

		free(FreeMemory);

		FreeMemory = tmp;
	}

	free(p);

	return 0;
}