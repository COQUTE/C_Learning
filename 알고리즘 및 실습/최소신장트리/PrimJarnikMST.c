#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Incidence {
	struct Line* line;
	struct Incidence* next;
} Incidence;
typedef struct Vertex {
	Incidence* incidence;
	int distance;
	int num;
	struct Line* parentLine;
	struct Vertex* next;
} Vertex;
typedef struct Line {
	Vertex* first, * second;
	int weight;
	struct Line* next;
} Line;

// 정점 하나를 만들어서 반환 (인접 헤더노드도 정점에 미리 만듦)
Vertex* getVertex(int num);
// 정점 리스트를 만든 후, 헤드노드포인터 vertexL을 반환
Vertex* initVertexList(int n);
// 라인 하나를 만들어서 반환
Line* getLine(Vertex* vertexL, int firstNum, int secondNum, int weight);
// 라인 리스트의 헤드노드포인터 lineL을 반환
Line* initLineList(Vertex* vertexL, int m);
// Incidence 하나를 만들어서 반환
Incidence* getIncidence(Line* linePtr);
// 특정 라인이 가지고 있는 정점(포인터) 속 헤더노드 뒤에 그 라인 포인터를 가지는 Incedence 하나를 이어줌
void addIncidence(Line* lineL);
// 라인 리스트를 순회하며 addIncidence()를 수행
void initIncidence(Line* lineL);

// 특정 정점과 인접한 정점의 포인터를 반환 (번호가 작은 정점부터 조사)
Vertex* opposite(Vertex* vPtr, Incidence* iPtr);

void buildQ(Vertex* Q, Vertex* start, int n);
// 업힙
void upHeap(Vertex* Q, int i);
// 다운힙
void downHeap(Vertex* Q, int size, int i);
// MST 생성시 추가되는 정점과 MST 총무게를 출력
void PrimJarnikMST(Vertex* vertexL, int n);

// 전체 그래프의 메모리를 해제해줌
void freeMemory(Vertex* vertexL, Line* lineL);

int main() {
	// 그래프는 인접리스트 구조, 우선순위 큐는 힙으로 구현
	Vertex* vertexL;
	Line* lineL;
	int n, m;

	scanf("%d %d", &n, &m);

	vertexL = initVertexList(n);
	lineL = initLineList(vertexL, m);
	initIncidence(lineL);

	PrimJarnikMST(vertexL, n);

	freeMemory(vertexL, lineL);

	return 0;
}

// 정점 하나를 만들어서 반환 (인접 헤더노드도 정점에 미리 만듦)
Vertex* getVertex(int num) {
	Vertex* vPtr = (Vertex*)malloc(sizeof(Vertex));
	Incidence* iPtr = getIncidence(NULL);

	vPtr->incidence = iPtr;
	vPtr->num = num;
	vPtr->next = NULL;

	return vPtr;
}
// 정점 리스트를 만든 후, 헤드노드포인터 vertexL을 반환
Vertex* initVertexList(int n) {
	Vertex* vertexL = NULL;
	Vertex* newNode;

	for (int i = n; i >= 1; i--) {
		newNode = getVertex(i);
		newNode->next = vertexL;
		vertexL = newNode;
	}

	return vertexL;
}
// 라인 하나를 만들어서 반환
Line* getLine(Vertex* vertexL, int firstNum, int secondNum, int weight) {
	Line* lPtr = (Line*)malloc(sizeof(Line));
	Vertex* ptr = vertexL;
	int cnt = 0;

	while (ptr != NULL && cnt < 2) {
		if (ptr->num == firstNum && ptr->num == secondNum) {
			lPtr->first = ptr;
			lPtr->second = ptr;
			cnt = 2;
		}
		else if (ptr->num == firstNum) {
			lPtr->first = ptr;
			cnt++;
		}
		else if (ptr->num == secondNum) {
			lPtr->second = ptr;
			cnt++;
		}
		ptr = ptr->next;
	}
	lPtr->weight = weight;
	lPtr->next = NULL;

	return lPtr;
}
// 라인 리스트의 헤드노드포인터 lineL을 반환
Line* initLineList(Vertex* vertexL, int m) {
	Line* lineL = NULL;
	Line* newNode;
	int firstNum, secondNum, weight;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &firstNum, &secondNum, &weight);

		newNode = getLine(vertexL, firstNum, secondNum, weight);
		newNode->next = lineL;
		lineL = newNode;
	}

	return lineL;
}
// Incidence 하나를 만들어서 반환
Incidence* getIncidence(Line* linePtr) {
	Incidence* ptr = (Incidence*)malloc(sizeof(Incidence));

	ptr->line = linePtr;
	ptr->next = NULL;

	return ptr;
}
// 특정 라인이 가지고 있는 정점(포인터) 속 헤더노드 뒤에 그 라인 포인터를 가지는 Incedence 하나를 이어줌
void addIncidence(Line* linePtr) {
	Incidence* ptr;
	Incidence* newNode;

	if (linePtr->first->num == linePtr->second->num) {
		ptr = linePtr->first->incidence;
		newNode = getIncidence(linePtr);
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	else {
		ptr = linePtr->first->incidence;
		newNode = getIncidence(linePtr);
		newNode->next = ptr->next;
		ptr->next = newNode;

		ptr = linePtr->second->incidence;
		newNode = getIncidence(linePtr);
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}
// 라인 리스트를 순회하며 addIncidence()를 수행
void initIncidence(Line* lineL) {
	Line* ptr = lineL;

	while (ptr != NULL) {
		addIncidence(ptr);
		ptr = ptr->next;
	}
}

// 특정 정점과 인접한 정점의 포인터를 반환 (번호가 작은 정점부터 조사)
Vertex* opposite(Vertex* vPtr, Incidence* iPtr) {
	int vertexNum;
	Line* lPtr;

	vertexNum = vPtr->num;
	lPtr = iPtr->line;

	if (lPtr->first->num == vertexNum)
		return lPtr->second;
	else // lPtr->second->num == vertexNum
		return lPtr->first;
}

// start를 제외한 정점들의 distance가 모두 10000이기 때문에 비교가 필요없이 바로 힙생성
void buildQ(Vertex* Q, Vertex* start, int n) {
	Vertex* ptr = start;

	for (int i = 1; i <= n; i++) {
		Q[i] = *ptr;
		ptr = ptr->next;
	}
}
// 업힙
void upHeap(Vertex* Q, int i) {
	Vertex tmp;

	if (i == 1)
		return;

	if (Q[i / 2].distance <= Q[i].distance)
		return;

	tmp = Q[i / 2];
	Q[i / 2] = Q[i];
	Q[i] = tmp;

	upHeap(Q, i / 2);
}
// 다운힙
void downHeap(Vertex* Q, int size, int i) {
	Vertex tmp;
	int left = i * 2, right = (i * 2) + 1;
	int smaller;

	if (left > size)
		return;

	smaller = left;
	if (right <= size && Q[right].distance < Q[smaller].distance)
		smaller = right;
	if (Q[i].distance <= Q[smaller].distance)
		return;
	tmp = Q[i];
	Q[i] = Q[smaller];
	Q[smaller] = tmp;

	downHeap(Q, size, smaller);
}
// MST 생성시 추가되는 정점과 MST 총무게를 출력
void PrimJarnikMST(Vertex* vertexL, int n) {
	Vertex* ptr = vertexL, * start = vertexL;
	Vertex u, tmp;
	Vertex* z;
	Vertex* Q = (Vertex*)malloc(sizeof(Vertex) * (n + 1));
	int size = n, total = 0;

	while (ptr != NULL) {
		ptr->distance = 10000;
		ptr->parentLine = NULL;
		ptr = ptr->next;
	}

	start->distance = 0;
	buildQ(Q, start, n);
	while (size != 0) {
		tmp = Q[1];
		Q[1] = Q[size];
		Q[size] = tmp;
		u = Q[size];
		size--;
		downHeap(Q, size, 1);

		for (Incidence* iPtr = u.incidence->next; iPtr != NULL; iPtr = iPtr->next) {
			z = opposite(&u, iPtr);
			for (int i = 1; i <= size; i++) {
				if (Q[i].num == z->num && iPtr->line->weight < z->distance) {
					z->distance = iPtr->line->weight;
					Q[i].distance = z->distance;
					z->parentLine = iPtr;
					Q[i].parentLine = z->parentLine;
					upHeap(Q, i);
					break;
				}
			}
		}
	}
	for (int i = n; i >= 1; i--)
		printf(" %d", Q[i].num);
	printf("\n");

	for (int i = 1; i <= n; i++)
		total += Q[i].distance;
	printf("%d\n", total);
	free(Q);
}

// 전체 그래프의 메모리를 해제해줌
void freeMemory(Vertex* vertexL, Line* lineL) {
	Vertex* ptr = vertexL;
	Incidence* tmpI, * ptrI;
	Vertex* tmpV, * ptrV;
	Line* tmpL, * ptrL;

	tmpV = vertexL;
	tmpL = lineL;

	while (ptr != NULL) {
		tmpI = ptr->incidence;

		do {
			ptrI = tmpI->next;
			free(tmpI);
			tmpI = ptrI;
		} while (ptrI != NULL);

		ptr = ptr->next;
	}

	do {
		ptrV = tmpV->next;
		free(tmpV);
		tmpV = ptrV;
	} while (ptrV != NULL);
	do {
		ptrL = tmpL->next;
		free(tmpL);
		tmpL = ptrL;
	} while (ptrL != NULL);
}