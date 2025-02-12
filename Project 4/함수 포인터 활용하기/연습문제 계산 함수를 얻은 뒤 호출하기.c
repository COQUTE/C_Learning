#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

struct Calc {
    int (*fp[2])(int, int); // ([1]의 결과 : 함수 포인터를 멤버로 가지고 있음), ([2]의 결과 : 함수 포인터 배열)
};

int executer(int (*fp)(int, int), int a, int b)
{
    return fp(a, b); // [4] fp(a, b)와 같이 함수를 호출하기 때문에 int형 반환값, int형 매개변수 두 개인 함수 포인터를 받을 수 있도록 한다.
}

int (*getFunc(struct Calc *c, int index))(int, int) // [3] 함수 안에서는 구조체 포인터 c, 정수 index를 매개변수로 사용한다.
                                                    // fp[index] : int형 반환값, int형 매개변수 두 개인 함수 포인터를 반환
{
    return c->fp[index]; // [2] 구조체 포인터 c와 구조체 멤버 fp의 index를 매개변수로 쓴다.
                         // 또한, 구조체 포인터 c의 멤버 fp의 인덱스로 접근하여 요소를 반환하기 때문에 구조체 Calc의 멤버 fp는 함수 포인터 배열이다.
}

int main()
{
    struct Calc c = { { add, sub } }; // [1] 구조체 Calc를 선언할 때 add, sub의 메모리 주소를 저장 즉, 함수 포인터를 멤버로 가지고 있다.

    printf("%d\n", executer(getFunc(&c, 0), 10, 20)); // 가장 안쪽에 있는 getFunc 함수부터 살펴본다.
    printf("%d\n", executer(getFunc(&c, 1), 10, 20)); // 그 이후 executer 함수를 살펴본다.

    return 0;
}