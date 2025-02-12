#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
	char name[20];
	int age;
	char address[100];
};

struct Person* allocPerson()
{
	struct Person* p = malloc(sizeof(struct Person));

	strcpy(p->name, "홍길동");
	p->age = 30;
	strcpy(p->address, "서울시 용산구 한남동");
	
	return p;
}

int main()
{
	struct Person* p1;

	p1 = allocPerson();

	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);

	free(p1);

	return 0;
}