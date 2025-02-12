#define _CRT_SECURE_NO_WARNINGS

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
	int key, height;
	struct NODE* lChild, * parent, * rChild;
} NODE;

void findElement(NODE* root, int k);	// 트리를 순회하여 키 값 k를 가진 원소(키)를 출력 or (없다면) X 출력
NODE* treeSearch(NODE* node, int k);	// 키 값 k를 가진 내부 노드 반환 or (없다면) 그 위치의 외부 노드 반환
void preOrderPrint(NODE* node);			// 루트부터 전위순회 인쇄

void insertItem(NODE** root, int k);		// 키 값 k를 가진 노드를 삽입
void expandExternal(NODE* z, int key);
void searchAndFixAfterInsertion(NODE** root, NODE* w); // 균형 검사 & 높이 균형 회복
bool updateHeight(NODE* w);
bool isBalanced(NODE* w);
NODE* restructure(NODE* x, NODE* y, NODE* z);

void init(NODE** root);
NODE* getNode(int k);
bool isExternal(NODE* w);
bool isInternal(NODE* w);

void freeMemory(NODE* node); // 후위순회 메모리 해제

int main() {
	NODE* root;
	char type;
	int key;

	init(&root);

	do {
		scanf("%c", &type);

		switch (type) {
		case 'i':
			scanf("%d", &key);
			getchar();
			insertItem(&root, key);
			break;
		case 's':
			scanf("%d", &key);
			getchar();
			findElement(root, key);
			break;
		case 'p':
			preOrderPrint(root);
			printf("\n");
			break;
		}
	} while (type != 'q');

	freeMemory(root);

	return 0;
}

void findElement(NODE* root, int k) {
	NODE* w = treeSearch(root, k);

	if (isInternal(w))
		printf("%d\n", w->key);
	else
		printf("X\n");
}

NODE* treeSearch(NODE* node, int k) {
	if (isExternal(node))
		return node;

	if (node->key == k)
		return node;
	else if (node->key > k)
		return treeSearch(node->lChild, k);
	else
		return treeSearch(node->rChild, k);
}

void preOrderPrint(NODE* node) {
	if (isExternal(node))
		return;

	printf(" %d", node->key);
	preOrderPrint(node->lChild);
	preOrderPrint(node->rChild);
}

void insertItem(NODE** root, int k) {
	NODE* w = treeSearch(*root, k);

	if (isInternal(w))
		return;
	else {
		expandExternal(w, k);
		searchAndFixAfterInsertion(root, w);
	}
}

void expandExternal(NODE* z, int key) {
	NODE* lChild = getNode(0);
	NODE* rChild = getNode(0);

	z->key = key;
	z->height = 1;

	z->lChild = lChild;
	z->rChild = rChild;

	lChild->parent = z;
	rChild->parent = z;
}

void searchAndFixAfterInsertion(NODE** root, NODE* w) {
	NODE* z, * y, * x;
	NODE* b;

	if (w->parent == NULL)
		return;
	
	z = w->parent;
	while (updateHeight(z) && isBalanced(z)) {
		if (z->parent == NULL)
			return;
		z = z->parent;
	}

	if (isBalanced(z))
		return;

	if (z->lChild->height > z->rChild->height)
		y = z->lChild;
	else
		y = z->rChild;
	
	if (y->lChild->height > y->rChild->height)
		x = y->lChild;
	else
		x = y->rChild;

	b = restructure(x, y, z);

	if (b->parent == NULL) {
		*root = b;
		return;
	}
	if (b->parent->lChild == b)
		b->parent->lChild = b;
	else
		b->parent->rChild = b;
}

bool updateHeight(NODE* w) {
	int height = max(w->lChild->height, w->rChild->height) + 1;
	
	if (height != w->height) {
		w->height = height;
		return true;
	}
	else
		return false;
}

bool isBalanced(NODE* w) {
	if (abs(w->lChild->height - w->rChild->height) <= 1)
		return true;
	else
		return false;
}

NODE* restructure(NODE* x, NODE* y, NODE* z) {
	NODE* a, * b, * c;
	NODE* T[4];
	
	if (z->key < y->key && y->key < x->key) {
		a = z; b = y; c = x;
		T[0] = a->lChild;
		T[1] = b->lChild;
		T[2] = c->lChild;
		T[3] = c->rChild;
	}
	else if (x->key < y->key && y->key < z->key) {
		a = x; b = y; c = z;
		T[0] = a->lChild;
		T[1] = a->rChild;
		T[2] = b->rChild;
		T[3] = c->rChild;
	}
	else if (z->key < x->key && x->key < y->key) {
		a = z; b = x; c = y;
		T[0] = a->lChild;
		T[1] = b->lChild;
		T[2] = b->rChild;
		T[3] = c->rChild;
	}
	else {
		a = y; b = x; c = z;
		T[0] = a->lChild;
		T[1] = b->lChild;
		T[2] = b->rChild;
		T[3] = c->rChild;
	}

	if (z->parent == NULL) {
		z = b;
		b->parent = NULL;
	}
	else if (z->parent->lChild == z) {
		z->parent->lChild = b;
		b->parent = z->parent;
	}
	else {
		z->parent->rChild = b;
		b->parent = z->parent;
	}

	a->lChild = T[0];
	a->rChild = T[1];
	T[0]->parent = a;
	T[1]->parent = a;
	updateHeight(a);

	c->lChild = T[2];
	c->rChild = T[3];
	T[2]->parent = c;
	T[3]->parent = c;
	updateHeight(c);

	b->lChild = a;
	b->rChild = c;
	a->parent = b;
	c->parent = b;
	updateHeight(b);

	return b;
}

void init(NODE** root) {
	NODE* external_node = getNode(0);

	*root = external_node;
}

NODE* getNode(int k) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));

	new_node->key = k;
	new_node->height = 0;
	new_node->parent = NULL;
	new_node->lChild = NULL;
	new_node->rChild = NULL;

	return new_node;
}

bool isExternal(NODE* w) {
	if (w->lChild == NULL && w->rChild == NULL)
		return true;
	else
		return false;
}

bool isInternal(NODE* w) {
	if (w->lChild != NULL || w->rChild != NULL)
		return true;
	else
		return false;
}

void freeMemory(NODE* node) {
	if (isExternal(node))
		return;

	freeMemory(node->lChild);
	freeMemory(node->rChild);
	free(node);
}