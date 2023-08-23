// 20. Write a program to calculate factorial of any number
#include <stdio.h>

int factorial (int);

int main()
{
    int inputNum, i, facto;
    scanf("%s", &inputNum);

    for (i = 1; i <= inputNum; i++) {
        facto = facto * i;
    }

    printf("%d", facto);
    return 0;
}