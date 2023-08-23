// 4. Take three numbers as command line arguments and display the sum of those numbers.
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
    int n = 0;
    printf("Enter the three digit number you want the sum of: ");
    scanf("%d", &n);
    printf("The sum of %d is %d", n, getSum(n));
}