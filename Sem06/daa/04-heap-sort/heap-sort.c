#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUTS 20

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;  // Random numbers between 0 and 9999
    }
}

void heapify(int arr[], int n, int i) {
    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
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

    heapSort(arr, size);

    // Record end time
    end = clock();

    // Calculate elapsed time
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("%d, %f\n", size, cpu_time_used);

    return 0;
}

int main() {
    printf("No of Inputs Heap Sort, time (sec)\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}