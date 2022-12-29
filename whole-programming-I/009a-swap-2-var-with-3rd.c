// 9. (a) Write a program to swap any two numbers using third variable
#include <stdio.h>

int main(){
    int var1 = 1, var2 = 2, var3 = 3;

    printf("Before swap var1 = %d, var2 = %d\n", var1, var2);

    var3 = var1;
    var1 = var2;
    var2 = var3; 

    printf("After swap var1 = %d, var2 = %d\n", var1, var2);
    return 0;
}