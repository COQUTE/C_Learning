#include <stdio.h>

int main()
{
    int numArr[5] = { 11, 22, 33, 44, 55 };
    int* numPtrA;

    numPtrA = numArr;    // 배열 첫 번째 요소의 주소를 포인터에 저장

    printf("%d\n", *(numPtrA + 1));    // 22: numPtrA에서 순방향으로 4바이트만큼 떨어진
                                       // 메모리에 주소에 접근. numArr[1]과 같음

    printf("%d\n", *(numPtrA + 2));    // 33: numPtrA에서 순방향으로 8바이트만큼 떨어진
                                       // 메모리에 주소에 접근. numArr[2]와 같음

    return 0;
}

// *(++포인터), *(--포인터)는 증가, 감소 이후 역참조
// 하지만 *(포인터++), *(포인터--)는 역참조 이후 증가, 감소 [즉, 출력값의 변화 X]