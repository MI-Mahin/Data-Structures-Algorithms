#include <iostream>
#include <chrono>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(arr, n);

    std::cout << "Sorted array using Bubble Sort: ";
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


