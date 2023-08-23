#include <stdio.h>

void main() {
    int i, j, k, a[2][2], b[2][2], c[2][2], len_matrix = 1;

    
    printf("Enter first matrix\n");
    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

        // print first matrix
    //     for(i = 0; i <= len_matrix; i++) {
    //     for(j = 0; j <= len_matrix; j++) {
    //         printf("%d\t", a[i][j]);
    //     }
    //     printf("\n");
    // }



    printf("\n");
    printf("Enter second matrix\n");
    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // print second 
    //         for(i = 0; i <= len_matrix; i++) {
    //     for(j = 0; j <= len_matrix; j++) {
    //         printf("%d\t", b[i][j]);
    //     }
    //     printf("\n");
    // }


    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            c[i][j] = 0;
            for(k = 0; k <= len_matrix; k++){
                c[i][j] += a[i][k] * a[k][j];
            }
        }
    }


    // Multiplied Matrix
    printf("\nThe multiplication of the first and second matrix is: \n");
    for(i = 0; i <= len_matrix; i++) {
        for(j = 0; j <= len_matrix; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}