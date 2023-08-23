#include <stdio.h>

void main() {
    int i, j, a[2][2], b[2][2], c[2][2], len_matrix = 1;
    
    printf("Enter first matrix\n");
    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");
    printf("Enter second matrix\n");
    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    
    printf("\nThe addition of the above two matrices is: \n");
    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }


    
}