// Addition of two numbers using functions

#include <stdio.h>

int addNumbers(int a, int b); // Func prototype
int main(){
    printf("\n\n--------------------\n"); // For styling

    int n1, n2, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);
    sum = addNumbers(n1, n2);
    printf("Sum = %d", sum);

    printf("\n--------------------\n\n"); // For styling
    return 0;
}

int addNumbers(int a, int b)
{
    int result;
    result = a+b;
    return result;
}