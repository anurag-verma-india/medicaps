#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print a matrix
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to split a matrix into four quadrants
void splitMatrix(int** matrix, int** a, int** b, int** c, int** d, int n) {
    int m = n / 2;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = matrix[i][j];              // Top left
            b[i][j] = matrix[i][j + m];          // Top right
            c[i][j] = matrix[i + m][j];          // Bottom left
            d[i][j] = matrix[i + m][j + m];      // Bottom right
        }
    }
}

// Function to join four matrices into a single matrix
void joinMatrix(int** a, int** b, int** c, int** d, int** matrix, int n) {
    int m = n / 2;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = a[i][j];              // Top left
            matrix[i][j + m] = b[i][j];          // Top right
            matrix[i + m][j] = c[i][j];          // Bottom left
            matrix[i + m][j + m] = d[i][j];      // Bottom right
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassenMultiply(int** A, int** B, int** C, int n) {
    // Base case: If matrix is 1x1, perform simple multiplication
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    
    int m = n / 2;
    
    // Allocate memory for sub-matrices
    int** A11 = allocateMatrix(m);
    int** A12 = allocateMatrix(m);
    int** A21 = allocateMatrix(m);
    int** A22 = allocateMatrix(m);
    
    int** B11 = allocateMatrix(m);
    int** B12 = allocateMatrix(m);
    int** B21 = allocateMatrix(m);
    int** B22 = allocateMatrix(m);
    
    int** C11 = allocateMatrix(m);
    int** C12 = allocateMatrix(m);
    int** C21 = allocateMatrix(m);
    int** C22 = allocateMatrix(m);
    
    // Allocate memory for temporary matrices
    int** P1 = allocateMatrix(m);
    int** P2 = allocateMatrix(m);
    int** P3 = allocateMatrix(m);
    int** P4 = allocateMatrix(m);
    int** P5 = allocateMatrix(m);
    int** P6 = allocateMatrix(m);
    int** P7 = allocateMatrix(m);
    
    int** temp1 = allocateMatrix(m);
    int** temp2 = allocateMatrix(m);
    
    // Split matrices A and B into 4 sub-matrices each
    splitMatrix(A, A11, A12, A21, A22, n);
    splitMatrix(B, B11, B12, B21, B22, n);
    
    // Calculate 7 products according to Strassen's algorithm
    
    // P1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, temp1, m);
    addMatrix(B11, B22, temp2, m);
    strassenMultiply(temp1, temp2, P1, m);
    
    // P2 = (A21 + A22) * B11
    addMatrix(A21, A22, temp1, m);
    strassenMultiply(temp1, B11, P2, m);
    
    // P3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, temp1, m);
    strassenMultiply(A11, temp1, P3, m);
    
    // P4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, temp1, m);
    strassenMultiply(A22, temp1, P4, m);
    
    // P5 = (A11 + A12) * B22
    addMatrix(A11, A12, temp1, m);
    strassenMultiply(temp1, B22, P5, m);
    
    // P6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, temp1, m);
    addMatrix(B11, B12, temp2, m);
    strassenMultiply(temp1, temp2, P6, m);
    
    // P7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, temp1, m);
    addMatrix(B21, B22, temp2, m);
    strassenMultiply(temp1, temp2, P7, m);
    
    // Calculate C11, C12, C21, C22
    
    // C11 = P1 + P4 - P5 + P7
    addMatrix(P1, P4, temp1, m);
    subtractMatrix(temp1, P5, temp2, m);
    addMatrix(temp2, P7, C11, m);
    
    // C12 = P3 + P5
    addMatrix(P3, P5, C12, m);
    
    // C21 = P2 + P4
    addMatrix(P2, P4, C21, m);
    
    // C22 = P1 - P2 + P3 + P6
    subtractMatrix(P1, P2, temp1, m);
    addMatrix(temp1, P3, temp2, m);
    addMatrix(temp2, P6, C22, m);
    
    // Join the 4 sub-matrices C11, C12, C21, C22 to form matrix C
    joinMatrix(C11, C12, C21, C22, C, n);
    
    // Free memory
    freeMatrix(A11, m);
    freeMatrix(A12, m);
    freeMatrix(A21, m);
    freeMatrix(A22, m);
    
    freeMatrix(B11, m);
    freeMatrix(B12, m);
    freeMatrix(B21, m);
    freeMatrix(B22, m);
    
    freeMatrix(C11, m);
    freeMatrix(C12, m);
    freeMatrix(C21, m);
    freeMatrix(C22, m);
    
    freeMatrix(P1, m);
    freeMatrix(P2, m);
    freeMatrix(P3, m);
    freeMatrix(P4, m);
    freeMatrix(P5, m);
    freeMatrix(P6, m);
    freeMatrix(P7, m);
    
    freeMatrix(temp1, m);
    freeMatrix(temp2, m);
}

// Function to pad matrix with zeros to make its size a power of 2
int** padMatrix(int** matrix, int original_size, int new_size) {
    int** padded = allocateMatrix(new_size);
    
    // Initialize with zeros
    for (int i = 0; i < new_size; i++) {
        for (int j = 0; j < new_size; j++) {
            padded[i][j] = 0;
        }
    }
    
    // Copy original matrix
    for (int i = 0; i < original_size; i++) {
        for (int j = 0; j < original_size; j++) {
            padded[i][j] = matrix[i][j];
        }
    }
    
    return padded;
}

// Function to get the next power of 2
int nextPowerOf2(int n) {
    return pow(2, ceil(log2(n)));
}

// Main function to handle matrix multiplication with Strassen's algorithm
int** matrixMultiply(int** A, int** B, int n) {
    // Get the next power of 2
    int padded_size = nextPowerOf2(n);
    
    // Pad matrices if necessary
    int** A_padded = A;
    int** B_padded = B;
    
    if (padded_size > n) {
        A_padded = padMatrix(A, n, padded_size);
        B_padded = padMatrix(B, n, padded_size);
    }
    
    // Allocate memory for result matrix
    int** C_padded = allocateMatrix(padded_size);
    
    // Perform Strassen's multiplication
    strassenMultiply(A_padded, B_padded, C_padded, padded_size);
    
    // Extract the result (remove padding)
    int** C = allocateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = C_padded[i][j];
        }
    }
    
    // Free memory if we created padded matrices
    if (padded_size > n) {
        freeMatrix(A_padded, padded_size);
        freeMatrix(B_padded, padded_size);
    }
    freeMatrix(C_padded, padded_size);
    
    return C;
}

int main() {
    int n;
    printf("Enter the size of the matrix (n for n x n): ");
    scanf("%d", &n);
    
    // Allocate memory for matrices A and B
    int** A = allocateMatrix(n);
    int** B = allocateMatrix(n);
    
    // Input matrix A
    printf("Enter elements of matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    // Input matrix B
    printf("Enter elements of matrix B (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    // Perform matrix multiplication
    int** C = matrixMultiply(A, B, n);
    
    // Print the result
    printf("Matrix A:\n");
    printMatrix(A, n);
    
    printf("\nMatrix B:\n");
    printMatrix(B, n);
    
    printf("\nResult Matrix C = A * B:\n");
    printMatrix(C, n);
    
    // Free memory
    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);
    
    return 0;
}