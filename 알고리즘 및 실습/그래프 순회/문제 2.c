#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertex {
	int num;
	int label;
} Vertex;
typedef struct Line {
	int first, second;
	int label;
} Line;
typedef struct Queue {
	Vertex* arr;
	int size, front, rear;
} Queue;

int sum(int n);

Vertex* initVertexList(int n);
Line* initLineList(int maxSize, int m);
int** initMatrix(Line* arrL, int n, int m);

Queue* initQueue(int size);
void enqueue(Queue* queue, Vertex* vPtr);
Vertex* dequeue(Queue* queue);

void BFS(Vertex* arrV, Line* arrL, int** matrix, int n, int m, int s);
void BFS1(Vertex* arrV, Line* arrL, int** matrix, int i, int n);

void freeMemory(Vertex* arrV, Line* arrL, int** matrix, int n);

int main() {
	Vertex* arrV;
	Line* arrL;
	int** matrix;

	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);

	arrV = initVertexList(n);
	arrL = initLineList(sum(n), m);
	matrix = initMatrix(arrL, n, m);

	BFS(arrV, arrL, matrix, n, m, s);

	freeMemory(arrV, arrL, matrix, n);

	return 0;
}

int sum(int n) {
	if (n == 1)
		return 1;
	else
		return n + sum(n - 1);
}

Vertex* initVertexList(int n) {
	Vertex* ptr = (Vertex*)malloc(sizeof(Vertex) * n);

	for (int i = 1; i <= n; i++)
		(ptr + i - 1)->num = i;

	return ptr;
}
Line* initLineList(int maxSize, int m) {
	Line* ptr = (Line*)malloc(sizeof(Line) * maxSize);
	int f, s;
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &f, &s);

		// 입력받은 정점 번호를 인덱스로 변환하여 저장
		(ptr + i)->first = f - 1;
		(ptr + i)->second = s - 1;
	}

	return ptr;
}
int** initMatrix(Line* arrL, int n, int m) {
	int indexF, indexS;

	int** matrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = -1;
		}
	}

	for (int i = 0; i < m; i++) {
		indexF = arrL[i].first;
		indexS = arrL[i].second;

		matrix[indexF][indexS] = i;
		matrix[indexS][indexF] = i;
	}

	return matrix;
}

Queue* initQueue(int size) {
	Queue* ptr = (Queue*)malloc(sizeof(Queue));

	ptr->arr = (Vertex*)malloc(sizeof(Vertex) * size);
	memset(ptr->arr, NULL, sizeof(Vertex) * size);
	
	ptr->size = size;
	ptr->front = ptr->rear = 0;

	return ptr;
}
void enqueue(Queue* queue, Vertex* vPtr) {
	Vertex* arr = queue->arr;
	
	queue->rear = (queue->rear + 1) % queue->size;
	arr[queue->rear] = *vPtr;
}
Vertex* dequeue(Queue* queue) {
	Vertex* arr = queue->arr;
	Vertex* ptr;

	queue->front = (queue->front + 1) % queue->size;
	ptr = &arr[queue->front];

	return ptr;
}

void BFS(Vertex* arrV, Line* arrL, int** matrix, int n, int m, int s) {
	int i;

	for (i = 0; i < n; i++)
		(arrV + i)->label = 0; // Fresh
	for (i = 0; i < m; i++)
		(arrL + i)->label = 0; // Fresh
	for (i = 0; i < n; i++) {
		if (arrV[i].num == s)
			break;
	}

	if (arrV[i].label == 0)
		BFS1(arrV, arrL, matrix, i, n);
}
void BFS1(Vertex* arrV, Line* arrL, int** matrix, int i, int n) {
	Queue* queue = initQueue(n);
	Vertex* vPtr, * w;
	int vNum, iValue;
	
	(arrV + i)->label = 1; // Visited
	enqueue(queue, arrV + i);
	printf("%d\n", (arrV + i)->num);
	while (queue->front != queue->rear) {
		vPtr = dequeue(queue);
		vNum = vPtr->num;

		// 정점을 1부터 오름차순으로 배열에 저장했기 때문에 인덱스는 vPtr->num - 1 이다.
		for (int index = 0; index < n; index++) {
			if (matrix[vPtr->num - 1][index] != -1) // 간선이 부착되어 있다면
				iValue = matrix[vPtr->num - 1][index];
			else // 간선이 부착되어 있지 않다면
				continue;

			if (arrL[iValue].label == 0) {
				if (arrL[iValue].first + 1 == vNum)
					w = arrV + arrL[iValue].second;
				else // arrL[iValue].second + 1 == vNum
					w = arrV + arrL[iValue].first;

				if (w->label == 0) { // Fresh
					(arrL + iValue)->label = 1; // Tree
					w->label = 1; // Visited
					printf("%d\n", w->num);
					enqueue(queue, w);
				}
				else // w->label == 1 (Visited)
					(arrL + iValue)->label = 2; // Cross
			}
		}
	}
}

void freeMemory(Vertex* arrV, Line* arrL, int** matrix, int n) {
	free(arrV);
	free(arrL);

	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
}