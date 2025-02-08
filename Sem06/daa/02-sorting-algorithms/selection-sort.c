#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUTS 10

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
}

void selectionSort(int arr[], int N) {
    // Start with the whole array as unsored and one by
    // one move boundary of unsorted subarray towards right
    for (int i = 0; i < N - 1; i++) {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first
        // element in the unsorted part
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int checkProgramWithSize(int size) {
    int arr[size];
    clock_t start, end;
    double cpu_time_used;

    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers
    generateRandomNumbers(arr, size);

    // Record start time
    start = clock();

    // Sort the array using Bubble Sort
    selectionSort(arr, size);

    // Record end time
    end = clock();

    // Calculate elapsed time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("Time taken for Bubble Sort (input size %d): %f seconds\n", size, cpu_time_used);
    printf("%d, %f\n", size, cpu_time_used);

    return 0;
}

int main() {
    // int sizes[10] = {1000, 2000, 3000, 5000, 10000, 20000, 50000, 60000, 75000, 100000};
    printf("No. of Inputs, time (s)\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}
