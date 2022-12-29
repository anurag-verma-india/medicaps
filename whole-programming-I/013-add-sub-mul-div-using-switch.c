// 13. Write a program for addition subtraction multiplication division using switch case.
#include <stdio.h>

int main()
{
    double num1, num2;
    char operation;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Enter two numebers (with space in between): ");
    scanf(" %lf %lf", &num1, &num2);

    switch(operation)
    {
        case '+':
            printf("Addition of %.1lf and %.1lf is %.1lf", num1, num2, num1 + num2);
            break;
        case '-':
            printf("Subtraction of %.1lf and %.1lf is %.1lf", num2, num1, num1 - num2);
            break;
        case '*':
            printf("Multiplication of %.1lf and %.1lf is %.1lf", num1, num2, num1 * num2);
            break;
        case '/':
            printf("Division of %.1lf and %.1lf is %.1lf", num1, num2, num1 / num2);
            break;
        default:
            printf("Invalid operation, try again");
            break;
    }
    return 0;
}