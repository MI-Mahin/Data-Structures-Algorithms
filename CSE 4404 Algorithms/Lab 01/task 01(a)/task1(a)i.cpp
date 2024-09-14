#include <iostream>
#include <chrono>

int find_peak_linear(int arr[], int n) {
    for (int i = 0; i < n ; ++i) {
        if (arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) {
            return arr[i];
        }
    }
    // Check the edge elements
    if (arr[0] >= arr[1]) {
        return arr[0];
    }
    if (arr[n - 1] >= arr[n - 2]) {
        return arr[n - 1];
    }
    //return -1;  // No peak found
}

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }



    int result = find_peak_linear(arr, n);
    std::cout << "Peak element using Linear Approach: " << result << std::endl;

    auto end = std::chrono::high_resolution_clock::now();


    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;



    return 0;
}

