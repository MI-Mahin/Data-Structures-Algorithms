#include <iostream>
#include <algorithm>

void merge(std::pair<int, int> arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::pair<int, int> L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::pair<int, int> arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int s, n;
    std::cin >> s >> n;

    std::pair<int, int> dragons[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> dragons[i].first >> dragons[i].second;
    }

    mergeSort(dragons, 0, n - 1);

    // Iterate through the dragons and check if Kirito can defeat them
    for (int i = 0; i < n; ++i) {
        if (s > dragons[i].first) {
            // Kirito defeats the dragon and gains bonus strength
            s += dragons[i].second;
        } else {
            // Kirito loses the duel and can't move on to the next level
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    // If Kirito successfully defeats all dragons, print "YES"
    std::cout << "YES" << std::endl;

    return 0;
}
