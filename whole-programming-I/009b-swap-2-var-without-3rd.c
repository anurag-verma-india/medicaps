// 9. Write a program to swap any two numbers without using third variable.
#include <stdio.h>

int main()
{
    int var1= 10, var2 = 2;

    printf("Before swap var1 = %d, var2 = %d\n", var1, var2);

    var1 =  var1 + var2;
    var2 = var1 - var2;
    var1 = var1-var2;

    printf("After swap var1 = %d, var2 = %d\n", var1, var2);
    return 0;
}