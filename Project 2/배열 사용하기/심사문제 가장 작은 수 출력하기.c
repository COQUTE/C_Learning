#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int numArr[5];
    int smallestNumber;

    scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
    {
        if (i == 0)
            smallestNumber = numArr[i];
        else if (smallestNumber > numArr[i])
            smallestNumber = numArr[i];
    }

    printf("%d\n", smallestNumber);

    return 0;
}