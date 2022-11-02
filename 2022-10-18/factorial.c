#include <stdio.h>

int main() {
    // factorial of a number

    int i, factorial=1, number;
    printf("Enter a number: ");
    scanf("%d", &number);
    for (i = 1; i <= number; i++)
    {
        factorial = factorial * i;
    }
    printf("Factorial of %d is %d", number, factorial);
}