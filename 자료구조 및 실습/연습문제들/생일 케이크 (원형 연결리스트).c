#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int fire;
	struct NODE* next;
}NODE, *NODE_PTR;

NODE_PTR getnode(int fire)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->fire = fire;
	ptr->next = NULL;

	return ptr;
}

NODE_PTR buildList(int n)
{
	NODE_PTR L, ptr, newnode;

	L = getnode(1);

	ptr = L;

	for (int i = 2; i <= n; i++)
	{
		newnode = getnode(i);

		ptr->next = newnode;

		ptr = ptr->next;
	}

	ptr->next = L;

	return L;
}

int runSimulation1(NODE_PTR L, int n, int k, int N)
{
	NODE_PTR ptr = L;
	int i, result;

	while (n > 1)
	{
		i = 0;

		while (i < k)
		{
			ptr = ptr->next;

			if (ptr->fire != 0)
				i++;
		}

		ptr->fire = 0;

		n--;

		while (ptr->fire == 0)
			ptr = ptr->next;
	}

	return ptr->fire;
}

int runSimulation2(NODE_PTR L, int n, int k)
{
	NODE_PTR ptr = L;
	NODE_PTR tmp;

	while (ptr != ptr->next)
	{
		for (int i = 0; i < k - 1; i++)
			ptr = ptr->next;

		tmp = ptr->next;
		ptr->next = (ptr->next)->next;

		free(tmp);

		ptr = ptr->next;
	}

	return ptr->fire;
}

int candle1(int n, int k)
{
	NODE_PTR L;
	int N = n;

	L = buildList(n);

	return runSimulation1(L, n, k, N);
}

int candle2(int n, int k)
{
	NODE_PTR L;

	L = buildList(n);

	return runSimulation2(L, n, k);
}

int main()
{
	printf("%d %d %d\n", candle1(10, 3), candle1(11, 4), candle1(12, 5));
	printf("%d %d %d\n", candle2(10, 3), candle2(11, 4), candle2(12, 5));

	return 0;
}