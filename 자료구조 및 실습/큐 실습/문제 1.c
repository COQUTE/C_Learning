#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
	int* arr;
	int size, front, rear;
} Queue;

Queue* init(int q)
{
	Queue* ptr = (Queue*)malloc(sizeof(Queue));

	ptr->arr = (int*)malloc(sizeof(int) * q);
	memset(ptr->arr, 0, sizeof(int) * q);

	ptr->size = q;
	ptr->front = ptr->rear = 0;

	return ptr;
}

void print(Queue* queue)
{
	for (int i = 0; i < queue->size; i++)
	{
		printf(" %d", queue->arr[i]);
	}
	printf("\n");
}

void enqueue(Queue* queue, int elem)
{
	queue->rear = (queue->rear + 1) % queue->size;

	queue->arr[queue->rear] = elem;
}

void dequeue(Queue* queue)
{
	queue->front = (queue->front + 1) % queue->size;

	queue->arr[queue->front] = 0;
}

int main()
{
	int q, n, elem;
	char type;
	Queue* queue;

	scanf("%d", &q);
	scanf("%d", &n);

	queue = init(q);

	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &type);

		if (type == 'I')
		{
			scanf("%d", &elem);

			if ((queue->rear + 1) % queue->size == queue->front)
			{
				printf("overflow");
				print(queue);

				break;
			}

			enqueue(queue, elem);
		}
		else if (type == 'D')
		{
			if (queue->front == queue->rear)
			{
				printf("underflow\n");

				break;
			}

			dequeue(queue);
		}
		else if (type == 'P')
		{
			print(queue);
		}
	}

	free(queue);

	return 0;
}