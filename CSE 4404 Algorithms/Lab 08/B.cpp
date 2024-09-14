#include <iostream>
#include <algorithm>

using namespace std;

int knapsack_max_value(int N, int W, int weights[], int values[]) {
    int dp[N + 1][W + 1];

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;
    cin >> N >> W;

    int weights[N], values[N];
    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
    }

    cout << knapsack_max_value(N, W, weights, values) << endl;

    return 0;
}

