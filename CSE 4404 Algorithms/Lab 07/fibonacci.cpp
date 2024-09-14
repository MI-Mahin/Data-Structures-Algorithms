#include <iostream>


int fibonacci(int n, int memo[])
{

    if (n <= 1)
        return n;


    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int memo[n + 1] = {0, 1};
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n, memo) << std::endl;

    return 0;
}

