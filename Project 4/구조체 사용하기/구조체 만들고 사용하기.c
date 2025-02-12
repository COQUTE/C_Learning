#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Person {
	char name[20];
	int age;
	char address[100];
}; // } p1; 이런 식으로 구조체를 정의하면서 변수 p1을 지정할 수 있다. (이 때, 변수 p1은 전역 변수)

int main()
{
	struct Person p1; // 구조체 변수 선언

	// 점으로 구조체 멤버에 접근하여 값 할당
	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	return 0;
}