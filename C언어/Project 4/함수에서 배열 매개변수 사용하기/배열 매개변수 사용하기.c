#include <stdio.h>

void swapElement(int arr[], int first, int second)    // 배열의 포인터와 인덱스를 받음
                                                      // 여기서 int arr[]를 int arr* 포인터로 해도 무관함
{
    int temp;

    temp = arr[first];
    arr[first] = arr[second];   // 메모리에 직접 접근하여 값을 바꾸기 때문에 함수 바깥에서도 적용됨
    arr[second] = temp;
}

int main()
{
    int numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    swapElement(numArr, 0, 1);    // 배열과 값을 서로 바꿀 인덱스를 넣음

    printf("%d %d\n", numArr[0], numArr[1]); // 2 1: swapElement에 의해서 배열 요소의 값이 서로 바뀜
    return 0;
}