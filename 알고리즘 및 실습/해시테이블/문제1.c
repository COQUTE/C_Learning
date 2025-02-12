#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* next;
}Node;

int hash(int x, int M);
Node* getNode(int key);

int main() {
	int x, M;
	int rank = 1; // 리스트의 순위 출력을 위한 rank 변수를 1로 초기화
	char type;

	Node* table;
	Node* new_node, * ptr, * tmp;

	scanf("%d", &M);
	getchar();

	// 메모리 할당
	table = (Node*)malloc(sizeof(Node) * M);

	// table 초기화
	for (int i = 0; i < M; i++) {
		(table + i)->key = 0;
		(table + i)->next = NULL;
	}

	do {
		scanf("%c", &type);

		// 바뀌었을 수도 있는 rank를 초기화
		rank = 1;

		if (type == 'i') {
			scanf("%d", &x);
			getchar();

			// 새로운 노드를 맨 앞에 삽입
			new_node = getNode(x);
			ptr = table + hash(x, M);
			if (ptr->next == NULL)
				ptr->next = new_node;
			else {
				new_node->next = ptr->next;
				ptr->next = new_node;
			}
		}
		else if (type == 's') {
			scanf("%d", &x);
			getchar();

			ptr = table + hash(x, M);

			while (1) {
				if (ptr->next == NULL) {
					printf("%d\n", 0);
					break;
				}

				ptr = ptr->next;
				if (ptr->key == x) {
					printf("%d\n", rank);
					break;
				}
				rank++;
			}
		}
		else if (type == 'd') {
			scanf("%d", &x);
			getchar();

			ptr = table + hash(x, M);

			while (1) {
				if (ptr->next == NULL) {
					printf("%d\n", 0);
					break;
				}

				tmp = ptr;
				ptr = ptr->next;
				if (ptr->key == x) {
					tmp->next = ptr->next;
					free(ptr);
					printf("%d\n", rank);
					break;
				}
				rank++;
			}
		}
		else if (type == 'p') {
			// 순회하며 출력
			for (int i = 0; i < M; i++) {
				ptr = table + i;
				while (ptr->next != NULL) {
					ptr = ptr->next;
					printf(" %d", ptr->key);
				}
			}
			printf("\n");
		}
	} while (type != 'e');

	// 메모리 해제
	for (int i = 0; i < M; i++) {
		ptr = table + i;

		if (ptr->next != NULL) {
			ptr = ptr->next;

			while (1) {
				tmp = ptr;
				ptr = ptr->next;
				free(tmp);

				if (ptr == NULL)
					break;
			}
		}
	}
	free(table);

	return 0;
}

int hash(int x, int M) {
	return x % M;
}

Node* getNode(int key) {
	Node* ptr = (Node*)malloc(sizeof(Node));

	ptr->key = key;
	ptr->next = NULL;

	return ptr;
}