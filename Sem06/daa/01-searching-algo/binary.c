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
// int linearSearch(int* arr, int n, int key) {
//     // Starting the loop and looking for the key in arr
//     for (int i = 0; i < n; i++) {
//         // If key is found, return key
//         if (arr[i] == key) {
//             return i;
//         }
//     }

//     // If key is not found, return some value to indicate
//     // end
//     return -1;
// }

int binarySearch(int arr[], int left, int right, int key) {
    // Loop will run till left > right. It means that there
    // are no elements to consider in the given subarray
    while (left <= right) {
        // calculating mid point
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key greater than arr[mid], ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }

        // If key is smaller than or equal to arr[mid],
        // ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then element was not present
    return -1;
}

void insertionSort(int* arr, int N) {
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
    // double cpu_time_used;
    long double cpu_time_used;

    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers
    generateRandomNumbers(arr, size, size);
    insertionSort(arr, size);
    int key = rand() % size;  // Random number between 0 and size

    // Record start time
    start = clock();

    int index = binarySearch(arr, 0, size - 1, key);

    // Record end time
    end = clock();

    // Calculate elapsed time
    cpu_time_used = ((long double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d, %Lf, %d\n", size, cpu_time_used, key);

    return 0;
}

int main() {
    // int sizes[10] = {1000, 2000, 3000, 5000, 10000, 20000, 50000, 60000, 75000, 100000};
    printf("No of Inputs, time (s), index\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}