#include <iostream>

using namespace std;

int rodCutting(int prices[], int n)
{
    if (n <= 0)
        return 0;

    int maxPrice = INT_MIN;


    for (int i = 1; i <= n; i++)
    {
        int currentPrice = prices[i - 1] + rodCutting(prices, n - i);
        maxPrice = max(maxPrice, currentPrice);
    }

    return maxPrice;
}

int main()
{
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;

    int prices[n];
    cout << "Enter the prices for rods of lengths 1 to " << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Price for rod of length " << (i + 1) << ": ";
        cin >> prices[i];
    }

    int maxPrice = rodCutting(prices, n);

    cout << "Maximum obtainable value by cutting the rod: " << maxPrice << endl;

    return 0;
}
