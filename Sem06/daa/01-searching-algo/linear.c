#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUTS 20

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size, int max_val) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_val);  // Random numbers between 0 and max_val
    }
}
int linearSearch(int* arr, int n, int key) {
    // Starting the loop and looking for the key in arr
    for (int i = 0; i < n; i++) {
        // If key is found, return key
        if (arr[i] == key) {
            return i;
        }
    }
    // If key is not found, return some value to indicate
    return -1;
}

int checkProgramWithSize(int size) {
    int arr[size];
    clock_t start, end;
    long double cpu_time_used;

    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers
    generateRandomNumbers(arr, size, size);
    int key = rand() % size;  // Random number between 0 and size

    // Record start time
    start = clock();

    int index = linearSearch(arr, size, key);

    // Record end time
    end = clock();

    // Calculate elapsed time
    cpu_time_used = ((long double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d, %Lf\n", size, cpu_time_used);

    return 0;
}

int main() {
    printf("No of Inputs, Time (sec)\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}