#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Person {
    char name[30];
    int age;
    void (*print)(struct Person*); // 구조체 포인터로 형변환된 포인터 print가 멤버로 되어있음.
};

void print(struct Person* p)
{
    printf("%s %d\n", p->name, p->age);
}

void executer(void (*fp[])(struct Person*), struct Person p[], int count)
{
    for (int i = 0; i < count; i++)
    {
        fp[i](&p[i]); // 중요 포인트 2
    }
}

void (*getPrintFunc(struct Person* p))(struct Person*)
{
    return p->print;
}

int main()
{
    struct Person p[3];
    p[0].print = print;
    p[1].print = print;
    p[2].print = print;

    scanf("%s %d %s %d %s %d",
        p[0].name, &p[0].age,
        p[1].name, &p[1].age,
        p[2].name, &p[2].age
    );

    void (*fp[3])(struct Person*); // 반환값이 void 함수 포인터, 매개변수 자료형이 구조체 포인터인 함수 포인터 배열 fp 선언

    for (int i = 0; i < sizeof(p) / sizeof(struct Person); i++)
    {
        fp[i] = getPrintFunc(&p[i]); // 중요 포인트 1 반환값이 void 함수 포인터, 함수 속 매개변수가 &p[i] : 구조체 포인터, 구조체 포인터 매개변수가 하나인 함수 포인터
    }

    executer(fp, p, sizeof(p) / sizeof(struct Person)); //

    return 0;
}