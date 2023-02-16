#include <stdio.h>

typedef struct point
{
    double x, y;
} point;

void add_points(point *p1, point *p2, point *sum)
{
    sum->x = p1->x + p2->x;
    sum->y = p1->y + p2->y;
}