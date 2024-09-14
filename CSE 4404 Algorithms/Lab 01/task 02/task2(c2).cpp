#include <iostream>
#include <chrono>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;


    srand(time(0));
    int *arr = new int[n];



    //int arr[n];
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    insertionSort(arr, n);

    std::cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;


    return 0;
}


