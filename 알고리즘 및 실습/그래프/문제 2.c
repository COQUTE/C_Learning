#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {
	int num;
} Vertex;
typedef struct Line {
	int first, second;
	int value;
} Line;

int sum(int n);

Vertex* initVertexList(int n);
Line* initLineList(int m);
int** initMatrix(Line* arrL, int n, int m);

void inPlaceSelectionSort(int** arr, int n);
void print(Vertex* arrV, Line* arrL, int** matrix, int n, int m);
void update(Vertex* arrV, Line* arrL, int** matrix, int n, int* m);

void freeMemory(Vertex* arrV, Line* arrL, int** matrix, int n);

int main() {
	Vertex* arrV;
	Line* arrL;
	int** matrix;

	int n, m;
	n = 6; m = 8;
	
	arrV = initVertexList(n);
	arrL = initLineList(sum(n));
	matrix = initMatrix(arrL, n, m);

	char type;

	do {
		scanf("%c", &type);

		switch (type) {
		case 'a':
			print(arrV, arrL, matrix, n, m);
			break;
		case 'm':
			update(arrV, arrL, matrix, n, &m);
			break;
		}
	} while (type != 'q');

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
Line* initLineList(int m) {
	Line* ptr = (Line*)malloc(sizeof(Line) * m);

	int lArray[8][3] = { {0, 1, 1}, {0, 2, 1}, {0, 3, 1}, {0, 5, 2}, {1, 2, 1}, {2, 4, 4}, {4, 5, 3}, {4, 4, 4} };

	for (int i = 0; i < m; i++) {
		(ptr + i)->first = lArray[i][0];
		(ptr + i)->second = lArray[i][1];
		(ptr + i)->value = lArray[i][2];
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
void print(Vertex* arrV, Line* arrL, int** matrix, int n, int m) {
	int num;
	int indexV;
	int cnt, index;
	int** VLarray;

	scanf("%d", &num);
	getchar();

	// 특정한 정점이 없는 경우
	for (indexV = 0; indexV < n; indexV++) {
		if (arrV[indexV].num == num)
			break;
	}
	if (indexV == n) {
		printf("-1\n");
		return;
	}

	// 인접한 것들의 개수를 cnt에 저장
	cnt = 0;
	for (int i = 0; i < m; i++) {
		if (arrL[i].first == indexV || arrL[i].second == indexV)
			cnt++;
	}

	// cnt를 활용해서 이중배열 생성
	VLarray = (int**)malloc(sizeof(int*) * cnt);
	for (int i = 0; i < cnt; i++)
		VLarray[i] = (int*)malloc(sizeof(int) * 2);
	
	index = 0;
	for (int i = 0; i < m; i++) {
		if (arrL[i].first == indexV || arrL[i].second == indexV) {
			VLarray[index][1] = arrL[i].value;

			// first 혹은 second가 indexV와 같을 때, first면 second를 인덱스로 second면 first를 인덱스로 사용
			if (arrL[i].first == indexV)
				VLarray[index][0] = arrV[arrL[i].second].num;
			else if (arrL[i].second == indexV)
				VLarray[index][0] = arrV[arrL[i].first].num;

			index++;
		}
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
void update(Vertex* arrV, Line* arrL, int** matrix, int n, int* m) {
	int firstNum, secondNum, w;
	int indexL, j;
	int indexV1, indexV2;
	int cnt;

	scanf("%d %d %d", &firstNum, &secondNum, &w);
	getchar();

	// firstNum 혹은 secondNum를 번호로 가진 정점이 없을 경우를 체크
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arrV[i].num == firstNum && firstNum == secondNum)
			cnt = 2;
		else if (arrV[i].num == firstNum || arrV[i].num == secondNum)
			cnt++;

		if (cnt == 2)
			break;
	}
	if (cnt != 2) {
		printf("-1\n");
		return;
	}

	// 무방향 그래프이기 때문에 부착점의 순서가 바뀌어도 같은 라인으로 취급함 예) (1, 2) == (2, 1)
	for (indexL = 0; indexL < *m; indexL++) {
		if (arrV[arrL[indexL].first].num == firstNum && arrV[arrL[indexL].second].num == secondNum)
			break;
		if (arrV[arrL[indexL].first].num == secondNum && arrV[arrL[indexL].second].num == firstNum)
			break;
	}
	
	// 찾는 라인이 없으면 추가
	cnt = 0;
	if (indexL == *m && w != 0) {
		// 정점 리스트의 인덱스 두 개를 알아내면 바로 종료 (cnt 활용)
		for (int i = 0; i < n; i++) {
			if (arrV[i].num == firstNum) {
				indexV1 = i;
				cnt++;
			}
			if (arrV[i].num == secondNum) {
				indexV2 = i;
				cnt++;
			}
			if (cnt == 2)
				break;
		}
		// 값 수정
		(arrL + indexL)->first = indexV1;
		(arrL + indexL)->second = indexV2;
		(arrL + indexL)->value = w;

		// 행렬 내용 갱신
		matrix[indexV1][indexV2] = indexL;
		matrix[indexV2][indexV1] = indexL;
		
		*m = *m + 1;
	}
	// 찾는 라인이 존재하고 w가 0이 아니면 가중치를 w로 바꿈
	else if (indexL != *m && w != 0)
		(arrL + indexL)->value = w;
	// 찾는 라인이 존재하고 w가 0이면 라인을 없앰
	else if (indexL != *m && w == 0) {
		*m = *m - 1;
		
		// 라인 리스트 중 마지막 인덱스의 행렬 내용을 -1로 초기화
		matrix[arrL[*m].first][arrL[*m].second] = -1;
		matrix[arrL[*m].second][arrL[*m].first] = -1;

		// 라인 리스트 중 indexL 인덱스의 내용을 삭제
		// 현재 indexL부터 *m - 1까지의 값들을 통해 행렬 내용을 갱신
		for (int i = indexL; i < *m; i++) {
			j = i + 1;

			// 라인 삭제 (덮어씌우기)
			(arrL + i)->first = (arrL + j)->first;
			(arrL + i)->second = (arrL + j)->second;
			(arrL + i)->value = (arrL + j)->value;

			// 행렬 갱신
			matrix[arrL[i].first][arrL[i].second] = i;
			matrix[arrL[i].second][arrL[i].first] = i;
		}
	}
	// 찾는 라인이 없는데 라인을 없애려고 하는 경우
	else // indexL == m && w == 0
		printf("-1\n");
}

void freeMemory(Vertex* arrV, Line* arrL, int** matrix, int n) {
	free(arrV);
	free(arrL);

	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
}