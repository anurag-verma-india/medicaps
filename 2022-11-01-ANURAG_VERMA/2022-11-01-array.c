#include <stdio.h>

int main() {
    int r, c, a[100][100], b[100][100], sum[100][100], i, j;
    printf("Enter a no. of rows (between 1 and 100):");
    scanf("%d", &r);
    printf("Enter no. of columns (between 1 & 100):");
    scanf("%d", &c);

    // Getting matrix input from user
    printf("\nEnter elements of first matrix.\n");
    for (i=0; i<r; i++)
    {
        for (j=0;j<c;j++)
        {
            printf("Enter element a %d %d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter elements of second matrix\n");
    for (i=0; i<r; i++)
    {
        for (j=0;j<c;j++)
        {
            printf("Enter element a %d %d: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    // Calculating sum
    for (i=0; i<r; i++)
    {
        for (j=0;j<c;j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Printing the matrix
    printf("\nSum of two matrix: \n");
    for (i=0; i<c; i++)
    {
        for (j=0;j<r;j++)
        {
            printf("Element i = %d, j = %d is -> %d\n", i, j, sum[i][j]);
        }
    }
    return 0;
}