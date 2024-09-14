#include <iostream>
#include <algorithm>

// Function to perform insertion sort on a bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    const int numBuckets = 10;  // You can adjust the number of buckets as needed

    // Create buckets as arrays
    int buckets[numBuckets][n];
    int bucketSize[numBuckets] = {0};

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / numBuckets;
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], bucketSize[i]);
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

