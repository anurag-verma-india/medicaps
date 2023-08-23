#include <stdio.h>

int main() {
    // To check whether a number is palindrome or not
    int n, remainder;
    int reversed = 0;
    printf("Enter a number: ");
    scanf("%d", n);
    int original = n;
    while (n!= 0){
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

        if (original == reversed)
        {
            printf("%d is palindrome", original);
        }
        else {
            printf("%d is not palindrome", original);
        }
    return 0;
}