#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE* prev, * next;
	char Alpabet;
}NODE, *NODEPTR, **NODE_DPTR;

NODEPTR getnode(char Alpabet)
{
	NODEPTR ptr = (NODEPTR)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->Alpabet = Alpabet;

	return ptr;
}

void initial(NODE_DPTR H, NODE_DPTR T)
{
	*H = getnode('0');
	*T = getnode(0);

	(*H)->next = *T;
	(*T)->prev = *H;

	(*H)->Alpabet = (*H)->Alpabet - 48;
}

void Add(NODEPTR H, int Rank, char Alpabet)
{
	NODEPTR ptr = H;
	NODEPTR newnode;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	newnode = getnode(Alpabet);

	newnode->prev = ptr->prev;
	newnode->next = ptr;
	(ptr->prev)->next = newnode;
	ptr->prev = newnode;

	H->Alpabet = H->Alpabet + 1;
}

void Delete(NODEPTR H, int Rank)
{
	NODEPTR ptr = H;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	(ptr->next)->prev = ptr->prev;
	(ptr->prev)->next = ptr->next;

	H->Alpabet = H->Alpabet - 1;

	free(ptr);
}

char Get(NODEPTR H, int Rank)
{
	NODEPTR ptr = H;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	return ptr->Alpabet;
}

void Print(NODEPTR H)
{
	NODEPTR ptr = H->next;

	for (int i = 0; i < H->Alpabet; i++)
	{
		printf("%c", ptr->Alpabet);

		ptr = ptr->next;
	}
}

int main()
{
	NODEPTR H, T;
	int N, Rank;
	char Operation, Alpabet;

	NODEPTR FreeMemory, tmp;

	initial(&H, &T);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%c", &Operation);

		if (Operation == 'A')
		{
			scanf("%d %c", &Rank, &Alpabet);

			if (Rank < 1 || Rank > H->Alpabet + 1)
				printf("invalid position\n");
			else
				Add(H, Rank, Alpabet);
		}
		else if (Operation == 'D')
		{
			scanf("%d", &Rank);

			if (Rank < 1 || Rank > H->Alpabet)
				printf("invalid position\n");
			else
				Delete(H, Rank);
		}
		else if (Operation == 'G')
		{
			scanf("%d", &Rank);

			if (Rank < 1 || Rank > H->Alpabet)
				printf("invalid position\n");
			else
				printf("%c\n", Get(H, Rank));
		}
		else if (Operation == 'P')
		{
			Print(H);

			printf("\n");
		}
	}

	FreeMemory = H;

	while (FreeMemory != NULL)
	{
		tmp = FreeMemory->next;

		free(FreeMemory);

		FreeMemory = tmp;
	}

	return 0;
}