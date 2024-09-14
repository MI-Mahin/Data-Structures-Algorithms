#include <iostream>
#include <algorithm>

void merge(int arr[], int indices[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    int L_indices[n1], R_indices[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
        L_indices[i] = indices[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
        R_indices[j] = indices[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            indices[k] = L_indices[i];
            ++i;
        } else {
            arr[k] = R[j];
            indices[k] = R_indices[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        indices[k] = L_indices[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        indices[k] = R_indices[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int indices[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, indices, left, mid);
        mergeSort(arr, indices, mid + 1, right);

        merge(arr, indices, left, mid, right);
    }
}

int main() {
    int n;
    std::cin >> n;

    int prices[n];
    int qualities[n];
    int indices[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i] >> qualities[i];
        indices[i] = i;
    }

    mergeSort(prices, indices, 0, n - 1);

    // Check if there exists a laptop with higher quality and lower price than the next one
    for (int i = 0; i < n - 1; ++i) {
        if (qualities[indices[i]] > qualities[indices[i + 1]]) {
            std::cout << "Happy Alex" << std::endl;
            return 0;
        }
    }

    std::cout << "Poor Alex" << std::endl;
    return 0;
}
