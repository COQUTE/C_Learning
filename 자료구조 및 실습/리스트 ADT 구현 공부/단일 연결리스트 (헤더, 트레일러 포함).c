#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	struct NODE* next;
	int Element;
}NODE, * NODE_PTR, ** NODE_DPTR;

void InvalidRank()
{
	printf("invalid position\n");	//입력된 rank가 범위 밖일 경우 예외 발생
}

void InvalidType()
{
	printf("invalid type\n"); //입력된 type과 맞는 함수가 존재하지 않을 경우 예외 발생
}

NODE_PTR getnode(int Element)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->Element = Element;

	return ptr;
}

void initial(NODE_DPTR H, NODE_DPTR T)
{
	*H = getnode(0);
	*T = getnode(0);

	(*H)->next = *T;
}

NODE_PTR MoveNode(NODE_PTR ptr, int Rank) // Rank만큼 노드의 위치를 순방향으로 이동
{
	for (int i = 0; i < Rank; i++)
	{
		ptr = ptr->next;
	}

	return ptr;
}

void add(NODE_PTR H, int Rank, int Element)
{
	NODE_PTR ptr;
	NODE_PTR newnode;

	if (Rank < 1 || Rank > (H->Element) + 1)
		InvalidRank();
	else
	{
		newnode = getnode(Element);

		ptr = MoveNode(H, Rank - 1);

		newnode->next = ptr->next;
		ptr->next = newnode;

		(H->Element)++;
	}
}

void Remove(NODE_PTR H, int Rank)
{
	NODE_PTR ptr, before;

	if (Rank < 1 || Rank > (H->Element))
		InvalidRank();
	else
	{
		ptr = MoveNode(H, Rank);

		before = MoveNode(H, Rank - 1);

		before->next = ptr->next;

		free(ptr);

		(H->Element)--;
	}
}

int get(NODE_PTR H, int Rank)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > (H->Element))
		InvalidRank();
	else
	{
		ptr = MoveNode(H, Rank);

		printf("%d\n", ptr->Element);

		return ptr->Element;
	}
}

void set(NODE_PTR H, int Rank, int Element)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > (H->Element))
		InvalidRank();
	else
	{
		ptr = MoveNode(H, Rank);

		ptr->Element = Element;
	}
}

void traverse(NODE_PTR H, NODE_PTR T)
{
	NODE_PTR ptr = H->next;

	while (ptr != T)
	{
		printf(" %d", ptr->Element);

		ptr = ptr->next;
	}

	printf("\n");
}

void putnode(NODE_PTR H)
{
	NODE_PTR ptr = H, tmp;

	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;

		free(tmp);
	}
}

void TotalFunction()
{
	NODE_PTR H, T;
	int N, Rank, Element;
	char Type;

	initial(&H, &T);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%c", &Type);

		if (Type == 'A')
		{
			scanf("%d %d", &Rank, &Element);

			add(H, Rank, Element);
		}
		else if (Type == 'G')
		{
			scanf("%d", &Rank);

			Element = get(H, Rank);
		}
		else if (Type == 'S')
		{
			scanf("%d %d", &Rank, &Element);

			set(H, Rank, Element);
		}
		else if (Type == 'R')
		{
			scanf("%d", &Rank);

			Remove(H, Rank);
		}
		else if (Type == 'P')
		{
			traverse(H, T);
		}
		else
			InvalidType();
	}

	putnode(H);
}

int main()
{
	TotalFunction();

	return 0;
}