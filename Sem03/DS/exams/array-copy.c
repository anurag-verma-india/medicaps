#include <stdio.h>
#include <string.h>

void array_copy(int* arr1, int *arr2, int size){
    for(int i = 0; i < size; i++) {
        // *(arr2+i) = *(arr1 + i);
        arr2[i] = arr1[i];
    }
}

int main() {
    int A[2], B[2];
    for(int i = 0; i < 2; i++) {
        printf("Enter element a[%d]: ", i);
        scanf(" %d", &A[i]);
    }
    array_copy(&A[0], &B[0], 2);
    printf("\n\n");
    for(int i =0; i <2;i++) {
        printf("B[%d] = %d\n", i, B[i]);
    }
    return 0;
}