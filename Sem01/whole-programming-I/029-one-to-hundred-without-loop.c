// 29. Write a program to print series of number from 1-100 without using loop.
#include <stdio.h>

int print_to_hundred(int);

int main()
{
    print_to_hundred(1);
    return 0;   
}

int print_to_hundred(int n)
{
    if (n > 100) {
        return 0;
    }
    else {
        printf("%d ", n);
        print_to_hundred(n+1);
    }
}