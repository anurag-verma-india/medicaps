// 22. Write a program to print Fibonacci series
#include <stdio.h>

int main() {

    int i, n, this_term, previous_term = 1, second_prev_term = 1;
    printf("Enter how many numbers do you want to calculate: ");
    scanf(" %d", &n);

    printf("1 1 ");

    for (i = 1; i <= (n - 2); i++)
    {
        this_term = previous_term + second_prev_term;
        printf("%d ", this_term);
        second_prev_term = previous_term;
        previous_term = this_term;
    }

    return 0;
}