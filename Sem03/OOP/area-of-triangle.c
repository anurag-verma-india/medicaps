// this program is incomplete
// The God knows how to complete it

#include <stdio.h>
#include <math.h>

typedef struct triangle
{
    int side1;
    int side2;
    int side3;
} triangle;

float area(triangle T)
{
    float area, s;
    if (T.side1 + T.side2 <= T.side3)
    {
        printf("This is not a valid triangle, the third side is smaller than the first two");
    }
    else
    {
        s = (T.side1 + T.side2 + T.side3) / 2;
        area = sqrt(s * (s - T.side1) * (s - T.side1) * (s - T.side1));
    }
    return area;
}

void main()
{
    triangle t1;
    float area_of_triangle;
    printf("Enter the three sides of a triangle in order: ");
    scanf(" %d %d %d", t1.side1, t1.side2, t1.side3);

    area_of_triangle = area(t1);
}