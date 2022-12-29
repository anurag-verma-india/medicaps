// 3. Write a program to find sum of individual digits of any three digits number.
#include <stdio.h>

int getSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum  = sum + n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n = 69;
    // printf("Enter the three digit number you want the sum of: ");
    // scanf("%d", &n);
    printf("The sum of %d is %d", n, getSum(n));
}