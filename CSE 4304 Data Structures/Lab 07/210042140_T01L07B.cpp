#include <iostream>

void replaceOccurrences(int arr[], int n, int x, int y) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            arr[i] = y;
        }
    }
}

int main() {
    int t; // Number of test cases
    std::cin >> t;

    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int n, q;
        std::cin >> n >> q; // Input array size and number of operations
        int arr[n];

        for (int i = 0; i < n; i++) {
            std::cin >> arr[i]; // Input the initial array elements
        }

        std::cout << "Case " << caseNum << ":" << std::endl;

        for (int i = 0; i < q; i++) {
            int opType;
            std::cin >> opType;
            if (opType == 1) {
                // Type 1 operation: Replace all occurrences of x with y
                int x, y;
                std::cin >> x >> y;
                replaceOccurrences(arr, n, x, y);
            } else if (opType == 2) {
                // Type 2 operation: Output the value at index idx
                int idx;
                std::cin >> idx;
                std::cout << arr[idx] << std::endl;
            }
        }
    }

    return 0;
}


