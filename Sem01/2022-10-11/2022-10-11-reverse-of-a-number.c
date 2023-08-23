// Print reverse of any number
#include <stdio.h>

int main(){
    int n, i, remainder, reverse;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n/=10;
    }
    printf("Reverse no. is %d", reverse);
    return 0;
}