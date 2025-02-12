#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE *prev;
	int Element;
	struct NODE *next;
}NODE, *NODEPTR;

NODEPTR getnode(int Element) {
	NODEPTR p = malloc(sizeof(NODE));

	p->prev = NULL;
	p->next = NULL;
	p->Element = Element;

	return p;
}

void initialize(NODEPTR *H, NODEPTR *T)
{
	NODEPTR tmpH, tmpT;

	tmpH = getnode(0);
	tmpT = getnode(0);

	tmpT->prev = tmpH;
	tmpH->Element = 1;
	tmpH->next = tmpT;

	*H = tmpH;
	*T = tmpT;
}

void add(NODEPTR H, int Element, int r)
{
	
}

int main() {
	NODEPTR *H, *T;

	initialize(H, T);

	printf("%d", (*H)->Element);


	return 0;
}