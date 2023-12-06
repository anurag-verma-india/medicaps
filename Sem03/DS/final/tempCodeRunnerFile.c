#include <stdio.h>

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
    
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

    
        start++;
        end--;
    }
}

int main() {

    int myArray[] = {1, 2, 3, 4, 5};
    int n = sizeof(myArray) / sizeof(myArray[0]);


    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", myArray[i]);
    }


    reverseArray(myArray, 0, n - 1);


    printf("\nReversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", myArray[i]);
    }

    return 0;
}
