#include <stdio.h>

void main() {
    int a[2][2], transpose[2][2];
    int i, j;
    printf("Enter the elements of first matrix\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            transpose[i][j] = a[j][i];
        }
    }
    
    printf("Transpose of the matrix is \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
}