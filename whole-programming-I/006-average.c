// 6. Write a program to take three numbers and print their average up to two decimals.

#include <stdio.h>

int main()
{
    int num1, num2, num3;
    double average;
    printf("Enter any three numbers: ");
    scanf(" %d %d %d", &num1, &num2, &num3);
    printf("%d %d %d", num1, num2, num3);

    average = (num1 + num2 + num3) / 3;

    printf("\n\nAverage of %d, %d and %d is %.2lf", num1, num2, num3, average);
    return 0;
}