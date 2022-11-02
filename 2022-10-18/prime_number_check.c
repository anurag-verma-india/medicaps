#include <stdio.h>

int main() {
    // To check whether a number is palindrome or not
    int n, i, c = 0;
    printf("Enter a numnber: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            c++;
        }
    }
        if (c == 2)
        {
            printf("n is prime number");
        }
        else
        {
            printf("n is not a prime number");
        }
}