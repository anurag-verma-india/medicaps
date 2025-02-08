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
    // end
    return -1;
}

int checkProgramWithSize(int size) {
    int arr[size];
    clock_t start, end;
    // double cpu_time_used;
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

    printf("%d, %Lf, %d\n", size, cpu_time_used, key);

    return 0;
}

int main() {
    // int sizes[10] = {1000, 2000, 3000, 5000, 10000, 20000, 50000, 60000, 75000, 100000};
    // double a = 0;
    // long double b = 0;

    // printf("sizeof double: %lu\n", sizeof(a));
    // printf("sizeof long double: %lu\n", sizeof(b));
    printf("No of Inputs, time (s), index\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}