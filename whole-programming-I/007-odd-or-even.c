// 7. Write a program to check weather a number is even or odd
#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf(" %d", &n);

    if (n % 2 == 0) { printf("%d is even\n", n); }
    else { printf("%d is odd\n", n); }

    return 0;
}