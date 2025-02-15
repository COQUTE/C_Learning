#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Point3D {
    float x;
    float y;
    float z;
};

struct Point3D* allocPoint3D(float a, float b, float c)
{
    struct Point3D* p = malloc(sizeof(struct Point3D));

    p->x = a;
    p->y = b;
    p->z = c;

    return p;
}

int main()
{
    float x, y, z;
    struct Point3D* pos1;

    scanf("%f %f %f", &x, &y, &z);

    pos1 = allocPoint3D(x, y, z);

    printf("%f %f %f\n", pos1->x, pos1->y, pos1->z);

    free(pos1);

    return 0;
}