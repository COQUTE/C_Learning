#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Incidence {
	struct Line* line;
	struct Incidence* next;
} Incidence;
typedef struct Vertex {
	Incidence* incidence;
	int num;
	struct Vertex* next;
} Vertex;
typedef struct Line {
	Vertex* first, * second;
	int value;
	struct Line* next;
} Line;

// 정점 하나를 만들어서 반환 (인접 헤더노드도 정점에 미리 만듦)
Vertex* getVertex(int num);
// 정점 리스트를 만든 후, 헤드노드포인터 vertexL을 반환
Vertex* initVertexList();
// 라인 하나를 만들어서 반환
Line* getLine(Vertex* vertexL, int firstNum, int secondNum, int value);
// 라인 리스트의 헤드노드포인터 lineL을 반환
Line* initLineList(Vertex* vertexL);
// Incidence 하나를 만들어서 반환
Incidence* getIncidence(Line* linePtr);
// 특정 라인이 가지고 있는 정점(포인터) 속 헤더노드 뒤에 그 라인 포인터를 가지는 Incedence 하나를 이어줌
void addIncidence(Line* lineL);
// 라인 리스트를 순회하며 addIncidence()를 수행
void initIncidence(Line* lineL);
// 라인 리스트 속에서 특정 라인을 삭제 (그 라인이 부착된 정점의 인점 정보를 먼저 삭제)
void removeLine(Line** lineL, Line* linePtr);

// 제자리 선택 오름차순 정렬
void inPlaceSelectionSort(int** arr, int n);
// 인접한 정점들 번호를 기준해서 오름차순으로, 인접정점 num과 인접정점이랑 연결된 라인의 가중치를 모두 인쇄
void printIncidence(Vertex* vertexL);
// 현재 라인 리스트에서 원하는 라인 추가 혹은, 기존 라인 삭제를 수행 (찾는 정점이 없을 경우 -1 출력 후 종료)
void updateLine(Vertex* vertexL, Line** lineL);

// 전체 그래프의 메모리를 해제해줌
void freeMemory(Vertex* vertexL, Line* lineL);

int main() {
	Vertex* vertexL;
	Line* lineL;
	char type;

	vertexL = initVertexList();
	lineL = initLineList(vertexL);
	initIncidence(lineL);

	do {
		scanf("%c", &type);
		switch (type) {
		case 'a':
			printIncidence(vertexL);
			break;
		case 'm':
			updateLine(vertexL, &lineL);
			break;
		}
	} while (type != 'q');

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
Vertex* initVertexList() {
	Vertex* vertexL = NULL;
	Vertex* newNode;

	for (int i = 6; i >= 1; i--) {
		newNode = getVertex(i);
		newNode->next = vertexL;
		vertexL = newNode;
	}

	return vertexL;
}
// 라인 하나를 만들어서 반환
Line* getLine(Vertex* vertexL, int firstNum, int secondNum, int value) {
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
	lPtr->value = value;
	lPtr->next = NULL;

	return lPtr;
}
// 라인 리스트의 헤드노드포인터 lineL을 반환
Line* initLineList(Vertex* vertexL) {
	Line* lineL = NULL;
	Line* newNode;

	int lArray[8][3] = { {1, 2, 1}, {1, 3, 1}, {1, 4, 1}, {1, 6, 2}, {2, 3, 1}, {3, 5, 4}, {5, 6, 3}, {5, 5, 4} };

	for (int i = 0; i < 8; i++) {
			newNode = getLine(vertexL, lArray[i][0], lArray[i][1], lArray[i][2]);
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
// 라인 리스트 속에서 특정 라인을 삭제 (그 라인이 부착된 정점의 인점 정보를 먼저 삭제)
void removeLine(Line** lineL, Line* linePtr) {
	Line* ptrL;
	Line* prevLinePtr;
	Incidence* ptrI;
	Incidence* prevRemovePtr;
	int firstNum, secondNum;

	firstNum = linePtr->first->num;
	secondNum = linePtr->second->num;

	// 첫번째 부착된 정점 속, 없애야 할 Incidence를 포함한 인접 리스트의 헤더노드
	ptrI = linePtr->first->incidence;
	// 특정 Incidence 이전 Incidence를 찾음
	while (ptrI->next->line != linePtr)
		ptrI = ptrI->next;
	prevRemovePtr = ptrI;

	// 링크 조정 및 삭제
	ptrI = prevRemovePtr->next;
	prevRemovePtr->next = ptrI->next;
	free(ptrI);
	
	// 루프일 경우는 두번째 생략
	if (firstNum != secondNum) {
		// 두번째 부착된 정점 속, 없애야 할 Incidence를 포함한 인접 리스트의 헤더노드
		ptrI = linePtr->second->incidence;
		// 특정 Incidence 이전 Incidence를 찾음
		while (ptrI->next->line != linePtr)
			ptrI = ptrI->next;
		prevRemovePtr = ptrI;

		// 링크 조정 및 삭제
		ptrI = prevRemovePtr->next;
		prevRemovePtr->next = ptrI->next;
		free(ptrI);
	}

	// 삭제하려는 라인이 맨 처음 라인일 경우
	if (*lineL == linePtr) {
		*lineL = (*lineL)->next;
		free(linePtr);
		return;
	}

	ptrL = *lineL;
	// 특정 라인 이전 라인을 찾음 (라인 삭제시 링크 조정을 위함)
	while (ptrL->next != linePtr)
		ptrL = ptrL->next;
	prevLinePtr = ptrL;

	// 링크 조정 및 삭제
	ptrL = prevLinePtr->next;
	prevLinePtr->next = ptrL->next;
	free(ptrL);
}

// 제자리 선택 오름차순 정렬
void inPlaceSelectionSort(int** arr, int n) {
	int index, minLoc;
	int tmp;

	for (index = 0; index < n - 1; index++) {
		minLoc = index;
		for (int j = index + 1; j < n; j++) {
			if (arr[minLoc][0] > arr[j][0])
				minLoc = j;
		}
		for (int k = 0; k < 2; k++) {
			tmp = arr[index][k];
			arr[index][k] = arr[minLoc][k];
			arr[minLoc][k] = tmp;
		}
	}
}
// 인접한 정점들 번호를 기준해서 오름차순으로, 인접정점 num과 인접정점이랑 연결된 라인의 가중치를 모두 인쇄
void printIncidence(Vertex* vertexL) {
	Vertex* ptr = vertexL;
	Incidence* ptrI, *p;
	int num, cnt = 0;
	int index = 0;
	int** VLarray;

	scanf("%d", &num);
	getchar();

	// num을 번호로 갖는 정점을 찾음
	while (ptr != NULL && ptr->num != num)
		ptr = ptr->next;

	// num을 번호로 갖는 정점이 없는 경우
	if (ptr == NULL) {
		printf("-1\n");
		return;
	}

	// p와 ptrI는 num을 번호로 갖는 정점 속 인접 리스트의 헤더 노드
	p = ptr->incidence->next;
	ptrI = p;

	// 인접 리스트에서 헤더 노드를 제외한 나머지 노드들의 개수를 cnt에 저장
	while (p != NULL) {
		cnt++;
		p = p->next;
	}

	VLarray = (int**)malloc(sizeof(int*) * cnt);
	for (int i = 0; i < cnt; i++)
		VLarray[i] = (int*)malloc(sizeof(int) * 2);

	index = 0;

	// 이차원 배열 VLarray에 { 노드 번호, 라인 가중치 }와 같은 식으로 계속 저장 (횟수는 cnt와 같음)
	while (ptrI != NULL) {
		VLarray[index][1] = ptrI->line->value;

		if (ptrI->line->first == ptr)
			VLarray[index][0] = ptrI->line->second->num;
		else
			VLarray[index][0] = ptrI->line->first->num;

		index++;
		ptrI = ptrI->next;
	}

	// 이차원 배열 속의 노드 번호만을 비교해서 { 노드 번호, 라인 가중치 }의 두 가지 값을 모두 제자리 선택 오름차순 정렬
	inPlaceSelectionSort(VLarray, cnt);

	// 정렬된 이차원 배열을 출력
	printf(" ");
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d", VLarray[i][j]);
		}
	}
	printf("\n");

	// 동적할당한 이차원 배열 메모리 해제
	for (int i = 0; i < cnt; i++)
		free(VLarray[i]);
	free(VLarray);
}
// 라인 리스트를 순회해서 원하는 라인 추가 혹은, 기존 라인 삭제를 수행 (찾는 정점이 없을 경우 -1 출력 후 종료)
void updateLine(Vertex* vertexL, Line** lineL) {
	Vertex* vPtr = vertexL;
	Line* ptr = *lineL;
	Line* newNode;
	int firstNum, secondNum, w;
	int cnt = 0;

	scanf("%d %d %d", &firstNum, &secondNum, &w);
	getchar();

	// firstNum 혹은 secondNum를 번호로 가진 정점이 없을 경우를 체크
	while (vPtr != NULL) {
		if (vPtr->num == firstNum && firstNum == secondNum)
			cnt = 2;
		else if (vPtr->num == firstNum || vPtr->num == secondNum)
			cnt++;

		if (cnt == 2)
			break;
		vPtr = vPtr->next;
	}
	if (vPtr == NULL) {
		printf("-1\n");
		return;
	}

	// 무방향 그래프이기 때문에 부착점의 순서가 바뀌어도 같은 라인으로 취급함 예) (1, 2) == (2, 1)
	while (ptr != NULL) {
		if ((ptr->first->num == firstNum && ptr->second->num == secondNum) || (ptr->first->num == secondNum && ptr->second->num == firstNum))
			break;
		ptr = ptr->next;
	}

	// 찾는 라인이 없으면 추가
	if (ptr == NULL && w != 0) {
		newNode = getLine(vertexL, firstNum, secondNum, w);
		newNode->next = *lineL;
		*lineL = newNode;

		addIncidence(newNode);
	}
	// 찾는 라인이 존재하고 w가 0이 아니면 가중치를 w로 바꿈
	else if (ptr != NULL && w != 0)
		ptr->value = w;
	// 찾는 라인이 존재하고 w가 0이면 라인을 없앰
	else if (ptr != NULL && w == 0)
		removeLine(lineL, ptr);
	// 찾는 라인이 없는데 라인을 없애려고 하는 경우
	else // ptr == NULL && w == 0
		printf("-1\n");
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