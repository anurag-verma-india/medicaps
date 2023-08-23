// WAP to change the value of constant integer using pointer

#include<stdio.h>

void main()
{
    int *ptr;
    const int a = 20;
    ptr = &a;
    printf("Before change value of a: %d\n", a);
    *ptr = 40;
    printf("After change value of a: %d\n", a);
    printf("Value has changed");
}