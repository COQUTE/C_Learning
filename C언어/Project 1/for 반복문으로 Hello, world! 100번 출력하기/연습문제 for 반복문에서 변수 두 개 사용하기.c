#include <stdio.h>

int main()
{
    for (int i = 2, j = 5; j >= 1; i *= 2, j--)
    {
        printf("%d %d\n", i, j);
    }

    return 0;
}