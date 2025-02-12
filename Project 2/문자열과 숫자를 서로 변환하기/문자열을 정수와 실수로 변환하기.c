#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[31];
    int num1;
    int num2;
    float num3;
    char* end;

    scanf("%[^\n]s", s1);

    num1 = strtol(s1, &end, 16);
    num2 = strtol(end, &end, 10);
    num3 = strtof(end, NULL);

    printf("0x%x\n", num1);
    printf("%d\n", num2);
    printf("%f\n", num3);

    return 0;
}