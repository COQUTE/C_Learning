#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int elem;
	struct NODE* prev, * next;
} NODE;

NODE* getnode(int elem)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->prev = ptr->next = NULL;
	ptr->elem = elem;

	return ptr;
}

void add_front(NODE** front, NODE** rear, int elem)
{
	NODE* newnode = getnode(elem);

	if (*front == NULL)
	{
		*front = *rear = newnode;

		return;
	}

	newnode->next = *front;
	(*front)->prev = newnode;
	(*front) = newnode;
}

void add_rear(NODE** front, NODE** rear, int elem)
{
	NODE* newnode = getnode(elem);

	if (*rear == NULL)
	{
		*front = *rear = newnode;

		return;
	}

	newnode->prev = *rear;
	(*rear)->next = newnode;
	*rear = newnode;
}

void delete_front(NODE** front, NODE** rear)
{
	NODE* tmp;

	if (*front == *rear)
	{
		free(*front);

		*front = *rear = NULL;

		return;
	}

	tmp = *front;
	*front = (*front)->next;
	(*front)->prev = NULL;

	free(tmp);
}

void delete_rear(NODE** front, NODE** rear)
{
	NODE* tmp;

	if (*front == *rear)
	{
		free(*front);

		*front = *rear = NULL;

		return;
	}

	tmp = *rear;
	*rear = (*rear)->prev;
	(*rear)->next = NULL;

	free(tmp);
}

void print(NODE* front)
{
	while (front != NULL)
	{
		printf(" %d", front->elem);

		front = front->next;
	}
	printf("\n");
}

void FreeMemory(NODE* front)
{
	NODE* tmp;

	while (front != NULL)
	{
		tmp = front;

		front = front->next;

		free(tmp);
	}
}

int main()
{
	NODE* front = NULL, * rear = NULL;
	int n, elem;
	char type[3];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", type);
		
		if (strcmp(type, "AF") == 0)
		{
			scanf("%d", &elem);

			add_front(&front, &rear, elem);
		}
		else if (strcmp(type, "AR") == 0)
		{
			scanf("%d", &elem);

			add_rear(&front, &rear, elem);
		}
		else if (strcmp(type, "DF") == 0)
		{
			if (front == NULL)
			{
				printf("underflow\n");
				break;
			}

			delete_front(&front, &rear);
		}
		else if (strcmp(type, "DR") == 0)
		{
			if (rear == NULL)
			{
				printf("underflow\n");
				break;
			}

			delete_rear(&front, &rear);
		}
		else if (strcmp(type, "P") == 0)
		{
			print(front);
		}
	}

	FreeMemory(front);

	return 0;
}