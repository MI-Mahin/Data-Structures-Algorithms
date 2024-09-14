#include <iostream>

void countingSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array to store the count of each element
    int count[max + 1] = {0};

    // Populate the count array
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Modify the count array to store the actual position of each element
    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    int output[n];

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int n;

    // Input the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];

    // Input array elements
    std::cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Perform counting sort
    countingSort(arr, n);

    // Display sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
