#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct Point2D {
    int x;
    int y;
};

int main()
{
    struct Point2D p[4];
    double length = 0.0f;

    scanf("%d %d %d %d %d %d %d %d",
        &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y
    );

    for (int i = 0; i < (sizeof(p) / sizeof(struct Point2D)) - 1; i++)
    {
        length += sqrt(pow(p[i + 1].x - p[i].x, 2) + pow(p[i + 1].y - p[i].y, 2));
    }

    printf("%f\n", length);

    return 0;
}