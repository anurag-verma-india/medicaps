#include <stdio.h>

void printMatrix(int M[2][2]) {
    printf("%d\t%d\n", M[0][0], M[0][1]);
    printf("%d\t%d\n", M[1][0], M[1][1]);
}

void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;
    int temp1[2][2], temp2[2][2];
    
    // M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1])
    temp1[0][0] = A[0][0] + A[1][1];
    temp2[0][0] = B[0][0] + B[1][1];
    M1 = temp1[0][0] * temp2[0][0];
    
    // M2 = (A[1][0] + A[1][1]) * B[0][0]
    temp1[0][0] = A[1][0] + A[1][1];
    M2 = temp1[0][0] * B[0][0];
    
    // M3 = A[0][0] * (B[0][1] - B[1][1])
    temp1[0][0] = B[0][1] - B[1][1];
    M3 = A[0][0] * temp1[0][0];
    
    // M4 = A[1][1] * (B[1][0] - B[0][0])
    temp1[0][0] = B[1][0] - B[0][0];
    M4 = A[1][1] * temp1[0][0];
    
    // M5 = (A[0][0] + A[0][1]) * B[1][1]
    temp1[0][0] = A[0][0] + A[0][1];
    M5 = temp1[0][0] * B[1][1];
    
    // M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1])
    temp1[0][0] = A[1][0] - A[0][0];
    temp2[0][0] = B[0][0] + B[0][1];
    M6 = temp1[0][0] * temp2[0][0];
    
    // M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1])
    temp1[0][0] = A[0][1] - A[1][1];
    temp2[0][0] = B[1][0] + B[1][1];
    M7 = temp1[0][0] * temp2[0][0];
    
    // Calculate C matrix elements
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[2][2], B[2][2], C[2][2];
    
    // Input matrix A
    printf("\nEnter the elements of 2x2 matrix A:\n");
    scanf("%d %d %d %d", &A[0][0], &A[0][1], &A[1][0], &A[1][1]);
    
    // Input matrix B
    printf("Enter the elements of 2x2 matrix B:\n");
    scanf("%d %d %d %d", &B[0][0], &B[0][1], &B[1][0], &B[1][1]);
    
    // Multiply matrices using Strassen's algorithm
    strassenMultiply(A, B, C);
    
    // Display the matrices
    printf("\nMatrix A:\n");
    printMatrix(A);
    
    printf("\nMatrix B:\n");
    printMatrix(B);
    
    printf("\nResult Matrix C = A × B:\n");
    printMatrix(C);
    
    return 0;
}