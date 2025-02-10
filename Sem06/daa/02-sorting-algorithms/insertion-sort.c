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
void insertionSort(int arr[], int N) {
    // Starting from the second element
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are
        // greater than key, to one position to
        // the right of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Move the key to its correct position
        arr[j + 1] = key;
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

    insertionSort(arr, size);

    // Record end time
    end = clock();

    // Calculate elapsed time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d, %f\n", size, cpu_time_used);

    return 0;
}

int main() {
    printf("No of Inputs, Insertion Sort - time (sec)\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}
