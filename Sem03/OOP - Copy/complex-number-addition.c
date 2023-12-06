// write a program to take input in two complex number, calculate the sum of and print that

#include <stdio.h>

typedef struct complex
{
    int real;
    int imag;
} complex;

complex add(complex c1, complex c2)
{
    complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}

void main()
{
    complex c1, c2, sum;

    printf("\nEnter the 1st complex number: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("\nEnter the 2nd complex number: ");
    scanf("%d %d", &c2.real, &c2.imag);

    sum = add(c1, c2);

    printf("\nThe sum of the two complex numbers is: %d+i%d\n\n", sum.real, sum.imag);
}
