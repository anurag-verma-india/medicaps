#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define SIZE 1000
// #define SIZE 2000
// #define SIZE 5000
// #define SIZE 10000
// #define SIZE 15000
// #define SIZE 20000
// #define SIZE 50000
// #define SIZE 75000
// #define SIZE 100000
// #define SIZE 200000
#define INPUTS 10

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
}

// Bubble Sort function
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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