#include <stdio.h>

int main()
{
    int writtenTest = 78;
    int toeic = 870;

    if (writtenTest >=80 && toeic >= 850)
        printf("합격\n");
    else
        printf("불합격\n");

    return 0;
}