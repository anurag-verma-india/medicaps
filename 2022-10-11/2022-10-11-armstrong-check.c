#include <stdio.h>

int main(){
    int n, i, num, temp, r;
    int sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    for (temp = num; num != 0; num = num / 10)
    {
        r = num % 10;
        sum = sum + (r*r*r);
    }
    if (sum == temp)
    {
        printf("%d is an armstrong number\n", n);
    }
    else {
        printf("%d is not an armstrong number\n", n);
    }
    return 0;
}