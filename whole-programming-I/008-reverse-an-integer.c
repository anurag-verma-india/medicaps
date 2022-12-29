// 8. Write a program to reverse an integer.
#include <stdio.h>

int main()
{
    int n, OGnum, reverse = 0, remainder = 0;
    printf("Enter a number: ");
    scanf(" %d", &n);

    OGnum = n;

    while ( n != 0 ){
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    printf("Reverse of %d is %d", OGnum, reverse);

    return 0;
}