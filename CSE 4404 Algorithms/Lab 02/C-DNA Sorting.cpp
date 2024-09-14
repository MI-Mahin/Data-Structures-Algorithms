#include <iostream>
#include <algorithm>

const int MAX_N = 50;
const int MAX_M = 100;
const int MAX_LEN = 51;

// Function to calculate the number of inversions in a string
int countInversions(const std::string& str) {
    int inversions = 0;
    int n = str.length();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (str[i] > str[j]) {
                // Increment the inversion count when a pair is out of order
                inversions++;
            }
        }
    }

    return inversions;
}

// Custom comparator function for sorting strings based on the number of inversions
bool compareStrings(const std::string& a, const std::string& b) {
    return countInversions(a) < countInversions(b);
}

int main() {
    int M;
    std::cin >> M;

    for (int t = 0; t < M; ++t) {
        int n, m;
        std::cin >> n >> m;

        std::string sequences[MAX_M];

        for (int i = 0; i < m; ++i) {
            std::cin >> sequences[i];
        }

        // Sort strings based on the number of inversions using the custom comparator
        std::sort(sequences, sequences + m, compareStrings);

        // Output the sorted strings for the current dataset
        for (int i = 0; i < m; ++i) {
            std::cout << sequences[i] << std::endl;
        }

        // Print a blank line between consecutive test cases
        if (t < M - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}

