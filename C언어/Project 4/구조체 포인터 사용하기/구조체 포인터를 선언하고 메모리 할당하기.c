#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
	char name[20];
	int age;
	char address[100];
};

int main() {
	struct Person* p1 = malloc(sizeof(struct Person)); // 별칭 Person으로 포인터 선언하고 메모리 할당할 경우 Person *p1 = malloc(sizeof(Person));

	strcpy(p1->name, "홍길동");
	p1->age = 30;
	strcpy(p1->address, "서울시 용산구 한남동");

	printf("이름: %s\n", p1->name);
	printf("나이: %d\n", p1->age);
	printf("주소: %s\n", p1->address);

	free(p1);

	return 0;
}