#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, K;
    cin >> n >> K;

    priority_queue<int, vector<int>, greater<int>> cookies; // Min-heap

    for (int i = 0; i < n; i++) {
        int sweetness;
        cin >> sweetness;
        cookies.push(sweetness);
    }

    int operations = 0;

    while (!cookies.empty() && cookies.top() < K && cookies.size() >= 2) {
        int least_sweet = cookies.top();
        cookies.pop();
        int second_least_sweet = cookies.top();
        cookies.pop();

        int combined_sweetness = least_sweet + 2 * second_least_sweet;
        cookies.push(combined_sweetness);

        operations++;
    }

    if (cookies.empty() || cookies.top() < K) {
        cout << -1 << endl;
    } else {
        cout << operations << endl;
    }

    return 0;
}

