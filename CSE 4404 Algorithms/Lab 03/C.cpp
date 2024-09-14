#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int points[n];

    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }


    sort(points, points + n);


    int median_index = n % 2 == 0 ? n / 2 - 1 : n / 2;

    cout << points[median_index] << endl;

    return 0;
}

