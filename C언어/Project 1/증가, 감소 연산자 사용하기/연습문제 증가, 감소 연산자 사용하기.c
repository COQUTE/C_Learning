#include <stdio.h>

int main()
{
    int num1 = 2;
    int num2 = 8;
    int num3;
    int num4;

    num1++;
    num3 = --num1;

    --num2;
    num4 = num2++;

    printf("%d\n", num3);
    printf("%d\n", num4);

    return 0;
}