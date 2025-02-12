#include <stdio.h>

int main()
{
    unsigned char flag1 = 1 << 7; // 1000 0000
    unsigned char flag2 = 1 << 3; // 0000 1000

    flag1 |= 1 << 2; 
    flag1 &= ~(1 << 7);
    flag2 ^= 1 << 3;

    printf("%u %u\n", flag1, flag2);

    return 0;
}