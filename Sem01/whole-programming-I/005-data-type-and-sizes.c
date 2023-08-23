// 4 basic data types int, float, double, char
#include <stdio.h>

int main()
{
    int inInt;
    float inFloat;
    double inDouble;
    char inChar;
    printf("Enter an integer: ");
    scanf("%d", &inInt);
    printf("Enter a float: ");
    scanf("%f", &inFloat);
    printf("Enter a double: ");
    scanf("%lf", &inDouble);
    printf("Enter a char: ");
    scanf(" %c", &inChar);

    printf("\n\nInt %d size of Int is %d \nFloat %f size of Float is %d \nDouble %lf size of Double is %d \nChar %c size of Char is %d\n", inInt, sizeof(inInt), inFloat, sizeof(inFloat), inDouble, sizeof(inDouble), inChar, sizeof(inChar));
    return 0;
}