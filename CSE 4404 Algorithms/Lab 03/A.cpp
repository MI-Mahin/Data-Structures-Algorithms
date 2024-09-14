#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int start = -1, end = -1;


    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            start = i;
            break;
        }
    }

    for (int i = n - 1; i > 0; --i) {
        if (a[i] < a[i - 1]) {
            end = i;
            break;
        }
    }


    if (start == -1 && end == -1) {
        cout << "yes\n1 1" << endl;
        return 0;
    }


    for (int i = start, j = end; i < j; ++i, --j) {
        swap(a[i], a[j]);
    }


    bool sorted = true;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        cout << "yes\n" << start + 1 << " " << end + 1 << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}

