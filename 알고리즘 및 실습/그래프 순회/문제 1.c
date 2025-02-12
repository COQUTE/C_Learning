#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Incidence {
	struct Line* line;
	struct Incidence* next;
} Incidence;
typedef struct Vertex {
	Incidence* incidence;
	int label;
	int num;
	struct Vertex* next;
} Vertex;
typedef struct Line {
	Vertex* first, * second;
	int label;
	struct Line* next;
} Line;

// 정점 하나를 만들어서 반환 (인접 헤더노드도 정점에 미리 만듦)
Vertex* getVertex(int num);
// 정점 리스트를 만든 후, 헤드노드포인터 vertexL을 반환
Vertex* initVertexList(int n);
// 라인 하나를 만들어서 반환
Line* getLine(Vertex* vertexL, int firstNum, int secondNum);
// 라인 리스트의 헤드노드포인터 lineL을 반환
Line* initLineList(Vertex* vertexL, int m);
// Incidence 하나를 만들어서 반환
Incidence* getIncidence(Line* linePtr);
// 인접 정점들의 숫자를 헤더부터 순회하며 비교하여 오름차순으로 Incidence를 붙여줌
void addToProperPosition(Line* linePtr, int type);
// 특정 라인이 가지고 있는 정점(포인터) 속 헤더노드 뒤에 그 라인 포인터를 가지는 Incedence 하나를 이어줌
void addIncidence(Line* lineL);
// 라인 리스트를 순회하며 addIncidence()를 수행
void initIncidence(Line* lineL);

// 특정 정점과 인접한 정점의 포인터를 반환 (번호가 작은 정점부터 조사)
Vertex* opposite(Vertex* vPtr, Incidence* iPtr);

void DFS(Vertex* vertexL, Line* lineL, int s);
// 특정 정점에 대해서 재귀작업 실행
void rDFS(Vertex* vPtr);

// 전체 그래프의 메모리를 해제해줌
void freeMemory(Vertex* vertexL, Line* lineL);

int main() {
	Vertex* vertexL;
	Line* lineL;
	int n, m, s;

	scanf("%d %d %d", &n, &m, &s);

	vertexL = initVertexList(n);
	lineL = initLineList(vertexL, m);
	initIncidence(lineL);

	DFS(vertexL, lineL, s);

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
Line* getLine(Vertex* vertexL, int firstNum, int secondNum) {
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
	lPtr->next = NULL;

	return lPtr;
}
// 라인 리스트의 헤드노드포인터 lineL을 반환
Line* initLineList(Vertex* vertexL, int m) {
	Line* lineL = NULL;
	Line* newNode;
	int firstNum, secondNum;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &firstNum, &secondNum);

		newNode = getLine(vertexL, firstNum, secondNum);
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
// 인접 정점들의 숫자를 헤더부터 순회하며 비교하여 오름차순으로 Incidence를 붙여줌
void addToProperPosition(Line* linePtr, int type) {
	Incidence* ptr, * newNode;
	int vertexNum, oppositeNum, firstNum, secondNum;

	if (type == 1) {
		ptr = linePtr->first->incidence;
		vertexNum = linePtr->first->num;
		oppositeNum = linePtr->second->num;
	}
	else { // type == 2
		ptr = linePtr->second->incidence;
		vertexNum = linePtr->second->num;
		oppositeNum = linePtr->first->num;
	}

	newNode = getIncidence(linePtr);

	if (ptr->next == NULL) {
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	else { // ptr->next != NULL
		while (ptr->next != NULL) {
			firstNum = ptr->next->line->first->num;
			secondNum = ptr->next->line->second->num;

			if (firstNum == vertexNum) {
				if (secondNum > oppositeNum)
					break;
				else // secondNum < oppositeNum
					ptr = ptr->next;
			}
			else { // secondNum == oppositeNum
				if (firstNum > oppositeNum)
					break;
				else // firstNum < oppositeNum
					ptr = ptr->next;
			}
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}
// 특정 라인이 가지고 있는 정점(포인터) 속 헤더노드 뒤에 (오름차순으로) 그 라인 포인터를 가지는 Incedence 하나를 추가함
void addIncidence(Line* linePtr) {
	if (linePtr->first->num == linePtr->second->num)
		addToProperPosition(linePtr, 1);
	else {
		addToProperPosition(linePtr, 1);
		addToProperPosition(linePtr, 2);
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
void DFS(Vertex* vertexL, Line* lineL, int s) {
	Vertex* vPtr = vertexL;
	Line* lPtr = lineL;
	Vertex* w;

	while (vPtr != NULL) {
		vPtr->label = 0; // Fresh
		vPtr = vPtr->next;
	}
	while (lPtr != NULL) {
		lPtr->label = 0; // Fresh
		lPtr = lPtr->next;
	}

	// 번호가 s인 정점을 찾음
	vPtr = vertexL;
	while (vPtr != NULL) {
		if (vPtr->num == s)
			break;
		vPtr = vPtr->next;
	}

	if (vPtr->label == 0)
		rDFS(vPtr);
}
// 특정 정점에 대해서 재귀작업 실행
void rDFS(Vertex* vPtr) {
	Incidence* iPtr = vPtr->incidence->next;
	Vertex* w;

	vPtr->label = 1; // Visited
	printf("%d\n", vPtr->num);
	while (iPtr != NULL) {
		if (iPtr->line->label == 0) {
			w = opposite(vPtr, iPtr);
			if (w->label == 0) {
				iPtr->line->label = 1; // Tree
				rDFS(w);
			}
			else
				iPtr->line->label = 2; // Back
		}
		iPtr = iPtr->next;
	}
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