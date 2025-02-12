#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Line {
	int fromIndex, toIndex;
} Line;
typedef struct Incidence {
	int lIndex;
	struct Incidence* next;
} Incidence;
typedef struct Vertex {
	char name;
	int inDegree;
	Incidence* outLine, * inLine;
} Vertex;
typedef struct Queue {
	int* vIndexArr;
	int front, rear;
} Queue;
typedef struct Graph {
	Vertex* vertices;
	Line* lines;
} Graph;

// 표준입력으로부터 방향그래프 정보를 읽어 들여 그래프 G에 저장
void buildGraph();
// vName 정점 i를 G의 정점리스트에 삽입하고 i의 진입차수를 초기화
void insertVertex(char vName, int i);
// uName 정점 u를 시점으로, wName 정점 w를 종점으로 하는 방향간선 i를, G의 간선리스트, u의 진출간선리스트, 그리고 w의 진입간선리스트에 각각 삽입하고 w의 진입차수를 갱신
void insertDirectedEdge(char uName, char wName, int i);
// vName에 해당하는 정점의 인덱스를 찾아 반환
int index(char vName);
// (인접리스트의 헤더노드)H의 첫 노드 위치에 정수 i를 원소로 하는 노드를 삽입
void addFirst(Incidence* H, int i);
// G로부터 위상순서를 구하거나 방향싸이클이 존재함을 보고
void topologicalSort();

// Q가 비어 있으면 True, 아니면 False를 반환
bool isEmpty();
// v를 Q에 삽입
void enqueue(int vIndex);
// Q로부터 정점을 삭제하여 반환
int dequeue();

void freeMemory();

Graph G;
int n, m;
int* in, * topOrder;
Queue Q;

int main() {
	
	buildGraph();

	topologicalSort();

	if (topOrder[0] == 0)
		printf("0");
	else
		for (int i = 1; i <= n; i++) {
			printf("%c", G.vertices[topOrder[i]].name);
			if (i != n)
				printf(" ");
		}
	printf("\n");

	freeMemory();

	return 0;
}

// 표준입력으로부터 방향그래프 정보를 읽어 들여 그래프 G에 저장
void buildGraph() {
	char vName, uName, wName;

	scanf("%d", &n);
	getchar();

	G.vertices = (Vertex*)malloc(sizeof(Vertex) * n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &vName);
		insertVertex(vName, i);
	}

	scanf("%d", &m);
	getchar();

	G.lines = (Line*)malloc(sizeof(Line) * m);

	for (int i = 0; i < m; i++) {
		scanf("%c %c", &uName, &wName);
		getchar();
		insertDirectedEdge(uName, wName, i);
	}
}
// vName 정점 i를 G의 정점리스트에 삽입하고 i의 진입차수를 초기화
void insertVertex(char vName, int i) {
	(G.vertices + i)->name = vName;

	(G.vertices + i)->inLine = (Incidence*)malloc(sizeof(Incidence));
	(G.vertices + i)->inLine->next = NULL;

	(G.vertices + i)->outLine = (Incidence*)malloc(sizeof(Incidence));
	(G.vertices + i)->outLine->next = NULL;

	(G.vertices + i)->inDegree = 0;
}
// uName 정점 u를 시점으로, wName 정점 w를 종점으로 하는 방향간선 i를, G의 간선리스트, u의 진출간선리스트, 그리고 w의 진입간선리스트에 각각 삽입하고 w의 진입차수를 갱신
void insertDirectedEdge(char uName, char wName, int i) {
	int u, w;

	u = index(uName);
	w = index(wName);

	(G.lines + i)->fromIndex = u;
	(G.lines + i)->toIndex = w;

	addFirst(G.vertices[u].outLine, i);
	addFirst(G.vertices[w].inLine, i);

	(G.vertices + w)->inDegree++;
}
// vName에 해당하는 정점의 인덱스를 찾아 반환
int index(char vName) {
	for (int i = 0; i < n; i++) {
		if (G.vertices[i].name == vName)
			return i;
	}
}
// (인접리스트의 헤더노드)H의 첫 노드 위치에 정수 i를 원소로 하는 노드를 삽입
void addFirst(Incidence* H, int i) {
	Incidence* node = (Incidence*)malloc(sizeof(Incidence));

	node->lIndex = i;
	node->next = H->next;
	H->next = node;
}
// G로부터 위상순서를 구하거나 방향싸이클이 존재함을 보고
void topologicalSort() {
	int t, u, w;

	Q.vIndexArr = (int*)malloc(sizeof(int) * n);

	in = (int*)malloc(sizeof(int) * n);
	topOrder = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 0; i < n; i++) {
		in[i] = G.vertices[i].inDegree;
		if (in[i] == 0)
			enqueue(i);
	}

	t = 1;

	while (!isEmpty()) {
		u = dequeue();
		topOrder[t] = u;
		t++;

		for (Incidence* ptr = G.vertices[u].outLine->next; ptr != NULL; ptr = ptr->next) {
			w = G.lines[ptr->lIndex].toIndex;
			in[w] -= 1;
			if (in[w] == 0)
				enqueue(w);
		}
	}

	if (t <= n)
		topOrder[0] = 0;
	else
		topOrder[0] = 1;
}

// Q가 비어 있으면 True, 아니면 False를 반환
bool isEmpty() {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// v를 Q에 삽입
void enqueue(int vIndex) {
	Q.rear = (Q.rear + 1) % n;
	Q.vIndexArr[Q.rear] = vIndex;
}
// Q로부터 정점을 삭제하여 반환
int dequeue() {
	Q.front = (Q.front + 1) % n;
	return Q.vIndexArr[Q.front];
}

void freeMemory() {
	Incidence* tmp, * ptr;
	
	for (int i = 0; i < n; i++) {
		tmp = (G.vertices + i)->inLine;
		do {
			ptr = tmp->next;
			free(tmp);
			tmp = ptr;
		} while (ptr != NULL);

		tmp = (G.vertices + i)->outLine;
		do {
			ptr = tmp->next;
			free(tmp);
			tmp = ptr;
		} while (ptr != NULL);
	}

	free(G.vertices);
	free(G.lines);
	free(Q.vIndexArr);
	free(in);
	free(topOrder);
}