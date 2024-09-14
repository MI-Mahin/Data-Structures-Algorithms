#include <iostream>

using namespace std;

int main() {
    int sz;
    cin >> sz;

    int a[sz], i = 0;

    while (true) {
        int n;
        cin >> n;

        if (n == -1)
            break;

        if (n == 1) { // push
            int x;
            cin >> x;

            if (i == sz)
                cout << "Overflow\n";
            else {
                a[i] = x;
                if (i < sz)
                    i++;

                for (int k = 0; k < i; k++)
                    cout << a[k] << " ";

                cout << endl;
            }
        } else if (n == 2) { // pop
            if (i == 0)
                cout << "Underflow\n";
            else {
                if (i > 0)
                    i--;
                for (int k = 0; k < i; k++)
                    cout << a[k] << " ";
                cout << endl;
            }
        } else if (n == 3) { // isEmpty
            cout << (!i ? "True" : "False") << endl;
        } else if (n == 4) { // isFull
            cout << (i == sz ? "True" : "False") << endl;
        } else if (n == 5) { // size
            cout << i << endl;
        } else { // top
            if (i >= 1)
                cout << a[i - 1] << endl;
            else
                cout << "Underflow\n";
        }
    }

    return 0;
}
