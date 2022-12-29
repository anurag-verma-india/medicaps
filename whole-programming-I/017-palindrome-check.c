// 17. Write a program to check given number is palindrome or not.
#include <stdio.h>

int main()
{
    int n, reverse = 0;
    printf("Enter a numeber to check for palindrome: ");
    scanf(" %d", &n);

    int OGnum = n;

    while ( n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    if (reverse == OGnum ) {
        printf("\nPalindrome");
    }
    else {printf("\nNot Palindrome"); }

    return 0;
}