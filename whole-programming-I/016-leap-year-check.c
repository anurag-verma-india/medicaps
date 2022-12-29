// 15. Write a program to check given number is power of two or not using bitwise operation.
#include <stdio.h>

int main()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    switch(year % 4) {
        case 0:
            printf("%d is a leap year", year);
            break;
        default :
            printf("%d is not a leap year", year);
    }
    return 0;
}