#include <stdio.h>

int main()
{
    int num1 = 1;
    int num2 = 1;
    int num3;

    num3 = 2 * ((1 << num1) + (2 >> num2)); // 2 * ((1 << 1) + (2 >> 1))

    printf("%d\n", num3);

    return 0;
}