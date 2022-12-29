// 14. Write a program to check given number is Armstrong or not.
#include <stdio.h>

int main()
{
    int n, OGnum, sum = 0, remainder;
    printf("Enter a number: ");
    scanf(" %d", &n);

    OGnum = n;
    // printf("\n\n%d\n\n", OGnum);
    // printf("\n\n%d\n\n", &OGnum);
    // printf("\n\n%d\n\n", &n);

    while ( n != 0) {
        remainder = n % 10;
        sum += (remainder * remainder * remainder);
        n /= 10;
    }
    if (OGnum == sum) { printf("The given number is armstrong number."); }
    else { printf("The given number is not armstrong number."); }

    return 0;
}   