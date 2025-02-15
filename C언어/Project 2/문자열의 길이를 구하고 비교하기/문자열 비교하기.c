#include <stdio.h>
#include <string.h>    // strcmp 함수가 선언된 헤더 파일

int main()
{
    char s1[10] = "Hello";
    char* s2 = "Hello";

    int ret = strcmp(s1, s2);    // 두 문자열이 같은지 문자열 비교

    printf("%d\n\n", ret);         // 0: 두 문자열이 같으면 0

    // aaa는 ASCII 코드로 97 97 97
    // aab는 ASCII 코드로 97 97 98
    // aac는 ASCII 코드로 97 97 99

    printf("%d\n", strcmp("aaa", "aaa"));    //  0: aaa와 aaa는 같으므로 0
    printf("%d\n", strcmp("aab", "aaa"));    //  1: aab와 aaa 중에서 aab가 크므로 1
    printf("%d\n", strcmp("aab", "aac"));    // -1: aab와 aac 중에서 aac가 크므로 -1

    return 0;
}