#include <stdlib.h>
#include <time.h>

#define INPUTS 20

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size, int max_val) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_val);  // Random numbers between 0 and max_val
    }
}
int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }
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

    printf("%d, %Lf\n", size, cpu_time_used);

    return 0;
}

int main() {
    printf("No of Inputs, Time (sec)\n");
    for (int i = 1; i < INPUTS + 1; i++) {
        checkProgramWithSize(i * 10000);
    }
}