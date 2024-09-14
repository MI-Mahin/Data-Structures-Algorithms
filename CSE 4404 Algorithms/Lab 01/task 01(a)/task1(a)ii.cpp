#include <iostream>
#include <chrono>

int find_peak_divide_conquer(int arr[], int low, int high) {
    int mid = (low + high) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == high || arr[mid + 1] <= arr[mid])) {
        return arr[mid];
    }

    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return find_peak_divide_conquer(arr, low, mid - 1);
    } else {
        return find_peak_divide_conquer(arr, mid + 1, high);
    }
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

    int result = find_peak_divide_conquer(arr, 0, n - 1);
    std::cout << "Peak element using Divide and Conquer Approach: " << result << std::endl;



     auto end = std::chrono::high_resolution_clock::now();


    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;


    return 0;
}

