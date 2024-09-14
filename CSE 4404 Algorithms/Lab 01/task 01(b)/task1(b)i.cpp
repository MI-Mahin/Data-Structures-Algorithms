#include <iostream>

using namespace std;

// Function to find a peak element in a 2D array
// Brute-force approach
pair<int, int> findPeakBruteForce(int arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isPeak = true;

            // Check if the current element is less than its top neighbor
            if (i > 0 && arr[i][j] < arr[i - 1][j]) {
                isPeak = false;
            }

            // Check if the current element is less than its bottom neighbor
            if (i < rows - 1 && arr[i][j] < arr[i + 1][j]) {
                isPeak = false;
            }

            // Check if the current element is less than its left neighbor
            if (j > 0 && arr[i][j] < arr[i][j - 1]) {
                isPeak = false;
            }

            // Check if the current element is less than its right neighbor
            if (j < cols - 1 && arr[i][j] < arr[i][j + 1]) {
                isPeak = false;
            }

            // If the current element is a peak, return its coordinates
            if (isPeak) {
                return make_pair(i, j);
            }
        }
    }

    // If no peak is found, return {-1, -1}
    return make_pair(-1, -1);
}

int main() {
    int rows, cols;

    // Get user input for the number of rows and columns
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    // Get user input for the 2D array
    int arr[rows][cols];
    cout << "Enter the elements of the 2D array:" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // Find the peak using brute-force approach
    pair<int, int> peakCoordinates = findPeakBruteForce(arr, rows, cols);

    // Display the result
    if (peakCoordinates.first != -1 && peakCoordinates.second != -1) {
        cout << "Peak element found at position (" << peakCoordinates.first << ", " << peakCoordinates.second << ")" << endl;
    } else {
        cout << "No peak element found in the 2D array." << endl;
    }

    return 0;
}

