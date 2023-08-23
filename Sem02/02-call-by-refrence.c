#include<stdio.h>

void swap(int *, int *);

void main()
{
    int a, b;
    printf("Enter 2 numbers: ");
    scanf(" %d%d", &a, &b);
    printf("Beforre swapping\n");
    printf("a = %d\nb= %d\n", a, b);
    printf("after swapping\n");
    swap(&a, &b);
    printf("a = %d\nb = %d", a, b);
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
