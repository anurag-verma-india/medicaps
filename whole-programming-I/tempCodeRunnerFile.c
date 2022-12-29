// 11. Write a program to print the following pattern:
// *      *
// **    **
// ***  ***
// ********
#include <stdio.h>

int main() {
    int i, j, k, l, rows = 4;

    i = 1;
    while ( i <= rows ){
        j = 1;
        while ( j <= i) { printf("*"); j++; }
        k = 1;
        while ( k <= 2 * (rows - i) ) { printf(" "); k++; }
        l = 1;
        while ( l <= i ) { printf("*"); l++; }

        printf("\n");
        i++;
    }


    return 0;
}