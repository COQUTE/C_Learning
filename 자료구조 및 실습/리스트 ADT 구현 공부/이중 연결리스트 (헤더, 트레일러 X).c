#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	struct NODE *prev, *next;
	char str[11];
}NODE, *NODE_PTR, **NODE_DPTR;

void InvalidRank()
{
	printf("invaild position\n");
}

void InvalidType()
{
	printf("invaild type\n");
}

NODE_PTR getnode(char* str)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->prev = NULL;
	ptr->next = NULL;
	strcpy(ptr->str, str);

	return ptr;
}

void initial(NODE_DPTR L, int* NodeSize)
{
	*L = getnode("");

	(*NodeSize) = 1;
}

NODE_PTR MoveNode(NODE_PTR L, int Rank)
{
	NODE_PTR ptr = L;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	return ptr;
}

void add(NODE_DPTR L, int Rank, char* str, int* NodeSize)
{
	NODE_PTR ptr;
	NODE_PTR newnode;

	if (Rank < 1 || Rank > (*NodeSize) + 1)
		InvalidRank();
	else if (Rank == 1)
	{
		newnode = getnode(str);

		(*L)->prev = newnode;
		newnode->next = *L;
		*L = newnode;

		(*NodeSize)++;
	}
	else
	{
		ptr = MoveNode(*L, Rank - 2); // 넣어야할 Rank 이전 노드의 위치로 이동 : 넣어야할 Rank 노드의 위치로 이동하면 마지막 노드 추가할 때, 오류 발생

		newnode = getnode(str);

		newnode->next = ptr->next;
		newnode->prev = ptr;
		(ptr->next)->prev = newnode;
		ptr->next = newnode;

		(*NodeSize)++;
	}
}

void Remove(NODE_DPTR L, int Rank, int* NodeSize)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > * NodeSize)
		InvalidRank();
	else if (Rank == 1)
	{
		ptr = *L;

		*L = (*L)->next;

		free(ptr);

		(*NodeSize)--;
	}
	else
	{
		ptr = MoveNode(*L, Rank - 1);

		(ptr->prev)->next = ptr->next;

		if(ptr->next != NULL) // 만약 마지막 노드를 제거하게 될 때 오류 방지
			(ptr->next)->prev = ptr->prev;

		free(ptr);

		(*NodeSize)--;
	}
}

char* get(NODE_PTR L, int Rank, int NodeSize)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > NodeSize)
		InvalidRank();
	else
	{
		ptr = MoveNode(L, Rank - 1);

		printf("%s\n", ptr->str);

		return ptr->str;
	}
}

void set(NODE_PTR L, int Rank, char* str, int NodeSize)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > NodeSize)
		InvalidRank();
	else
	{
		ptr = MoveNode(L, Rank - 1);

		strcpy(ptr->str, str);
	}
}

void traverse(NODE_PTR L)
{
	NODE_PTR ptr = L;

	while (ptr != NULL)
	{
		printf(" %s", ptr->str);

		ptr = ptr->next;
	}

	printf("\n");
}

void putnode(NODE_PTR L)
{
	NODE_PTR ptr = L, tmp;

	while (ptr != NULL)
	{
		tmp = ptr;

		ptr = ptr->next;

		free(tmp);
	}
}

void TotalFunction()
{
	NODE_PTR L;
	int NodeSize; // 일단, 전체 노드의 개수를 함수에 저장
	int N, Rank;
	char str[11];
	char Type;

	initial(&L, &NodeSize);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%c", &Type);

		if (Type == 'A')
		{
			scanf("%d %s", &Rank, str);

			add(&L, Rank, str, &NodeSize);
		}
		else if (Type == 'G')
		{
			scanf("%d", &Rank);

			strcpy(str, get(L, Rank, NodeSize));
		}
		else if (Type == 'S')
		{
			scanf("%d %s", &Rank, str);

			set(L, Rank, str, NodeSize);
		}
		else if (Type == 'R')
		{
			scanf("%d", &Rank);

			Remove(&L, Rank, &NodeSize);
		}
		else if (Type == 'P')
		{
			traverse(L);
		}
		else
			InvalidType();
	}

	putnode(L);
}

int main()
{
	TotalFunction();
	
	return 0;
}