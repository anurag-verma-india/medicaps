// 12. Write a program to print grade of student on the basis of percentage:
// i.If per greater than or equal to 75 ➔ A grade
// ii.If per between 60-75 ➔ B grade
// iii.If per between 50-60 ➔ C grade
// v.If per between 40-50 ➔ D grade
// v.If per less than 40 ➔ Fail

#include <stdio.h>

int main() 
{
    int marks;
    printf("Enter your percentage: ");
    scanf(" %d", &marks);
    
    if ( marks >= 75 ) { printf("A grade"); }
    else if ( marks >= 60 ) { printf("B grade"); }
    else if ( marks >= 50 ) { printf("C grade"); }
    else if ( marks >= 40 ) { printf("D grade"); }
    else { printf("Fail"); }

    return 0;
}